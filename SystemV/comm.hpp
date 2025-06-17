#ifndef __COMM_HPP__
#define __COMM_HPP__

#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdio.h>

#include"log.hpp"

using namespace std;

//申请共享内存
const int size = 4096;
const char* pathname = "/home/lzh";
const int proj_id = 0x1111;
Log log;

//只要一个进程申请共享内存，其它进程只要获取描述符就行

//获取key
key_t GetKey()
{
    key_t key = ftok(pathname, proj_id);
    if (key == -1)
    {
        //错误打印日志
        log(Fatal, "ftok error: %s", strerror(errno));
        exit(1);
    }
    //获取key成功打印key
    log(Info, "ftok success, key is : 0x%x", key);
    return key;
}

//获取共享内存描述符
int GetShareMemHelper(int flag)
{
    key_t key = GetKey();
    int shmid = shmget(key, size, flag);
    if (shmid == -1)
    {
        log(Fatal, "shmget error: %s", strerror(errno));
        exit(2);
    }
    //获取共享内存描述符成功打印描述符
    log(Info, "shmget success, shmid is: %d", shmid);
    return shmid;
}

//申请创建共享内存
int CreatShm()
{
    return GetShareMemHelper(IPC_CREAT | IPC_EXCL | 0666);//不带权限时会报错不让访问
}

//获取描述符
int GetShm()
{
    return GetShareMemHelper(IPC_CREAT);
}

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

#endif