#include"comm.hpp"

int main()
{
    //获取共享内存
    int shmid = GetShm();
    //打开管道
    int fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1)
    {
        log(Fatal, "error string: %s, error code: %d", strerror(errno), errno);
        exit(FIFO_OPEN_ERROR);
    }
    //获取虚拟地址，进程关联共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0);
    while (true)
    {
        //写入内容
        cout << "Please Enter: ";
        fgets(shmaddr, 4096, stdin);
        //往管道输入字符才可以进行访问共享内存
        write(fd, "c", 1);
    }
    //进程去关联
    shmdt(shmaddr);
    //删除共享内存
    shmctl(shmid, IPC_RMID, nullptr);
    close(fd);//及时关闭管道
    return 0;
}