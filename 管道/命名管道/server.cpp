#include"comm.hpp"
#include"log.hpp"

int main()
{
    //初始化管道
    Init init;
    //创建日志类
    Log log;
    //修改打印日志的方式
    log.Enable(OneFile);
    //打开管道
    int fd = open(FIFO_FILE, O_RDONLY);//返回文件描述符
    if (fd == -1)//打开失败返回错误信息
    {
        perror("open");
        exit(FIFO_OPEN_ERROR);
    }
    log(Debug, "server open file done, error string: %s, error code: %d", strerror(errno), errno);
    //读取管道内容
    while (true)
    {
        //读取的内容存放到数组中
        char buff[1024] = {0};
        int n = read(fd, &buff, sizeof(buff));
        if (n > 0)//读到了内容
        {
            buff[n] = 0;
            cout << buff << endl;
        }
        //n == 0 或者 n < 0 都不再读取 
        else if (n == 0) break;
        else break;
    }
    close(fd);
    return 0;
}