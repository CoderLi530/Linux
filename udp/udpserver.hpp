#pragma once

#include "log.hpp"
#include <iostream>
#include <memory>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <functional>
#include <string>

using namespace std;

//接收缓冲区大小
#define SIZE 1024

extern Log log;

enum 
{
    SOCKET_ERR = 1,
    BIND_ERR = 2,
    SEND_ERR = 3,
};

using Func = std::function<string(const string&)>; //C++11引入的类型别名语法
// typedef std::function<string(const string&)> Func;

const uint16_t defaultport = 8080;
const string defaultip = "0.0.0.0";


class UdpServer
{
public:
    //构造函数
    UdpServer(const uint16_t& port = defaultport, const string& ip = defaultip): _port(port), _ip(ip), _isrunning(false)
    {}

    //初始化函数
    void Init()
    {
        //1. 获取socket
        _socketfd = socket(AF_INET, SOCK_DGRAM, 0);
        if(_socketfd < 0) //获取socketfd失败，进行打印错误
        {
            log(Fatal, "socket create error, errno: %d, error string: %s", errno, strerror(errno));
            exit(SOCKET_ERR);
        }
        //获取socket成功
        log(Info, "socket create success, socketfd: %d", _socketfd);
        //2. 进行bind绑定
        //绑定socket
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET; //地址类型，ipv4
        local.sin_port = htons(_port); //端口号，将端口号转换为网络字节序数值
        local.sin_addr.s_addr = inet_addr((_ip.c_str())); //inet_addr将点分十进制（如"0.0.0.0"）的ipv4地址字符串转换为32位网络字节序二进制数值
        // local.sin_addr.s_addr = htonl(INADDR_ANY);
        //bind失败返回-1，设置错误信息
        if (bind(_socketfd, (const struct sockaddr*)&local, sizeof(local)) < 0)
        {
            log(Fatal, "bind error, errno: %d, error string: %s", errno, strerror(errno));
            exit(BIND_ERR);
        }
        //bind绑定成功
        log(Info, "bind success, bind node: %d, bind string: %s", errno, strerror(errno));
    }

    //运行函数
    //对接收到的信息进行处理，写一个处理函数。对于接收信息和处理信息的解耦
    void Run(Func func)
    {
        //接收消息，发送消息，这是异步，持续性的操作，确保终止条件
        _isrunning = true;
        char buffer[SIZE];
        while (_isrunning)
        {
            struct sockaddr_in client; //发送端
            socklen_t len = sizeof(client);
            //接收发送端的消息存在缓冲区中
            ssize_t n = recvfrom(_socketfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&client, &len);
            if (n < 0)
            {
                log(Fatal, "recv error, errno: %d, error string: %s", errno, strerror(errno));
                continue;
            }
            //发送消息给发送端
            buffer[n] = 0;
            string temp = buffer;
            string echostring = func(temp);
            if (sendto(_socketfd, echostring.c_str(), echostring.size(), 0, (struct sockaddr*)&client, len) < 0)
            {
                //发送消息失败
                log(Fatal, "send error, errno: %d, error string: %s", errno, strerror(errno));
                exit(SEND_ERR);
            }
            //发送消息成功
            //log(Info, "send success, send node: %d, send string: %s", errno, strerror(errno));
        }
    }

    //析构函数
    ~UdpServer()
    {
        //_socketfd存在，关闭
        if (_socketfd < 0) close(_socketfd);
    }

private:
    int _socketfd;
    uint16_t _port;
    string _ip;
    bool _isrunning;
};
