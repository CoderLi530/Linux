#pragma once

#include<iostream>
#include<string.h>
#include<time.h>
#include<errno.h>
#include<stdio.h>
#include<stdarg.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

//日志等级
#define Info 0
#define Debug 1
#define Warning 2
#define Error 3
#define Fatal 4

//往哪里打印日志
#define Screen 1
#define OneFile 2
#define ClassFile 3

#define LogFile "log.txt"
#define SIZE 1024

class Log
{
private:
    int printMethod;//打印方式
    string path;//路径
public:
    //构造函数。默认在屏幕上打印
    Log()
    {
        printMethod = Screen;
        path = "./log/";
    }

    //修改打印位置
    void Enable(int method)
    {
        printMethod = method;
    }

//打印形式：[日志等级][时间][传过来的字符串]
//将打印的数据以什么方式打印

    //返回日志等级
    string LevelToString(int level)
    {
        switch(level)
        {
            case Info:
                return "Info";
            case Debug:
                return "Debug";
            case Warning:
                return "Warning";
            case Error:
                return "Error";
            case Fatal:
                return "Fatal";
            default:
                return "None";
        }
    }

    //在一个文件中进行打印
    void PrintOneFile(const string& logname, const string& buffer)
    {
        //创建日志文件
        string log_name = path + logname;
        int fd = open(log_name.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0664);
        if(fd == -1)
        {
            perror("open");
            exit(-1);
        }
        int n = write(fd, buffer.c_str(), buffer.size());
        if (n == -1)    
        {
            perror("write");
            exit(-1);   
        }
        close(fd);//关闭文件  
    }

    //分开不同日志等级的文件
    void PrintClassFile(int level, const string& buffer)
    {
        //调用PrintOneFile
        string filename = LogFile;
        filename += ".";
        filename += LevelToString(level);
        PrintOneFile(filename, buffer);
    }

    //根据打印方式去打印
    void PrintLog(int level, const string& buffer)
    {
        switch(printMethod)
        {
            case Screen:
                cout << buffer << endl;
                break;
            case OneFile:
                PrintOneFile(LogFile, buffer);
                break;
            case ClassFile:
                PrintClassFile(level, buffer);
                break;
            default:
                break;
        }
    }

    //构建日志
    void operator()(int level, const char* format, ...)//可变参数
    {
        //函数LevelToString打印日志等级
        //获取时间
        time_t t = time(nullptr);
        struct tm* tm = localtime(&t);
        //分成两部分进行打印
        //左边部分打印
        char leftbuffer[SIZE];
        snprintf(leftbuffer, sizeof(leftbuffer), "[%s][%d-%d-%d %d:%d:%d]", LevelToString(level).c_str(),
                 tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
                 tm->tm_hour, tm->tm_min, tm->tm_sec);
        //右边部分打印
        //使用va_list接受可变参数
        char rightbuffer[SIZE];
        va_list s;
        va_start(s, format);
        vsnprintf(rightbuffer, sizeof(rightbuffer), format, s);
        va_end(s);

        //两个部分合成一个部分
        char buffer[SIZE * 2];
        snprintf(buffer, sizeof(buffer), "%s %s\n", leftbuffer, rightbuffer);

        //将buffer写进日志文件中
        PrintLog(level, buffer);
    }    
    //析构函数
    ~Log()
    {}
};