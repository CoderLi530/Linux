#include <iostream>
#include "log.hpp"
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "udpserver.hpp"

using namespace std;

extern Log log;

void Usage(string proc)
{
    cout << "\n\rUsage: " << proc << " serverip serverport\n" << endl;
}

// ./udpclient serverip serverport
int main(int argc, char* argv[])
{
    //获取服务端的ip和端口
    if (argc != 3)
    {
        //参数不全进行提醒
        Usage(argv[0]);
        exit(0);
    }
    //获取到ip和port，将ip和port转换为对应的网络字节序数值
    string serverip = argv[1];
    uint16_t serverport = stoi(argv[2]); //转换为uint16_t，使用stoi函数，将string类型转换为int类型
    struct sockaddr_in server;
    bzero(&server, sizeof(server)); //初始化
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    server.sin_addr.s_addr = inet_addr(serverip.c_str());
    //获取socket
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd < 0)
    {
        //获取socketfd失败
        log(Fatal, "socket create error, errno: %d, error string: %s", errno, strerror(errno));
        exit(SOCKET_ERR);
    }
    //获取socket成功
    log(Info, "socket success, socketfd: %d, socketfd string: %s", errno, strerror(errno));
    //进行bind绑定。但是客户端一般不需要显式bind绑定，OS会自动分配
    //一个端口号只能被一个进程bind
    //client的port是多少无所谓，保证主机的唯一性就可以了
    //系统什么时候bind？客户端首次发送数据（TCP是首次连接）的时候bind
    
    //进行发送信息
    string message;
    char buffer[SIZE];
    while (1)
    {
        cout << "Please Enter: ";
        cin >> message;
        //发送信息给服务端
        sendto(socketfd, message.c_str(), message.size(), 0, (struct sockaddr*)&server, sizeof(server));
        
        //从服务端接受信息
        struct sockaddr_in temp;
        socklen_t len = sizeof(temp);
        ssize_t n = recvfrom(socketfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&temp, &len);
        if (n > 0)
        {
            buffer[n] = 0;
            cout << "client encho# " << buffer << endl;
        }
    }

    //关闭socketfd
    close(socketfd);
    return 0;
}