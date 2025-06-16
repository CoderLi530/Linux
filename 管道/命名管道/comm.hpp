#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string>

#include"log.hpp"

using namespace std;

#define FIFO_FILE "./myfifo"
//创建管道时权限：rw- rw- r--
#define MODE 0664

//管道操作失败返回错误码
enum
{
    FIFO_CREATE_ERROR = 1,
    FIFO_UNLINK_ERROR,
    FIFO_OPEN_ERROR
};

class Init
{
public:
    //创建管道
    Init()
    {
        int n = mkfifo(FIFO_FILE, MODE);
        if (n == -1)//创建管道失败打印错误信息
        {
            perror("mkfifo");
            exit(FIFO_CREATE_ERROR);
        }
    }
    //关闭管道
    ~Init()
    {
        int m = unlink(FIFO_FILE);
        if (m == -1)//关闭管道失败打印错误信息
        {
            perror("unlink");
            exit(FIFO_UNLINK_ERROR);
        }
    }
};