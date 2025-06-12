#include<iostream>
#include<cstdio>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>

#define NUM 1024

using namespace std;

void Writer(int fd)
{
    string s = "i am child";
    int cnt = 0;
    char buf[NUM];
    while (true)
    {
        //循环6次的写入
        char c = 'c';
        write(fd, &c, 1);
        ++cnt;
        if (cnt > 5) break;
    }
    
}

void Reader(int fd)
{
    char buf[NUM];
    while (true)
    {
        //一个字节的读操作
        buf[0] = 0;
        ssize_t n = read(fd, buf, sizeof(buf));
        if (n > 0)
        {
            buf[n] = 0;
            cout << buf << endl;
        }
        else if (n == 0)//读端完毕
        {
            cout << "读端阅读完毕" << endl;
            break;
        }
        else break;
    }
    
}

int main()
{
    //创建管道
    int pipefd[2] = {0};
    int n = pipe(pipefd);
    if (n < 0) 
    {
        std::cout << "创建管道失败" << endl;
        return 1;
    }
    //验证管道文件的描述符
    // cout << pipefd[0] << pipefd[1] << endl;//打印出来3，4
    //创建管道成功创建子进程
    pid_t id = fork();
    if (id < 0)
    {
        cout << "创建子进程失败" << endl;
        return 2;
    } 
    else if (id)//子进程写
    {
        close(pipefd[0]);//关闭读端
        Writer(pipefd[1]);
        close(pipefd[1]);//子进程写完关闭写端
        exit(0);//子进程退出码
    }
    //父进程读
    close(pipefd[1]);//关闭写端
    Reader(pipefd[0]);
    //得到子进程的退出状态
    pid_t rid = waitpid(id, nullptr, 0);
    if (rid < 0) return 3;
    //关闭父进程的读端
    close(pipefd[0]);
    return 0;
}
