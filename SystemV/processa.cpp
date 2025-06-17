#include"comm.hpp"

int main()
{
    Init init;
    //创建共享内存
    int shmid = CreatShm();
    //打开管道
    int fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1)
    {
        log(Fatal, "error string: %s, error code: %d", strerror(errno), errno);
        exit(FIFO_OPEN_ERROR);
    }
    //获取虚拟地址，进程关联共享内存
    char* shmaddr = (char*)shmat(shmid, nullptr, 0);
    //创建共享内存的属性结构体
    struct shmid_ds shmds;
    while (true)
    {
        //在管道中接收了字符才可以访问共享内存
        char c;
        ssize_t n = read(fd, &c, 1);
        if (n == 0) break;
        else if (n < 0) break; 
        cout << "Client say: " << shmaddr << endl;
        sleep(2);
        shmctl(shmid, IPC_STAT, &shmds);
        cout << "shm size: " << shmds.shm_segsz << endl;
        cout << "shm nattch: " << shmds.shm_nattch << endl;
        cout << "shm mode: " << shmds.shm_perm.mode << endl;
        // cout << "shm key: " << shmds.shm_perm.__key << endl;
        //打印十六进制
        printf("shm key: 0x%x\n", shmds.shm_perm.__key);
    }
    //去关联
    shmdt(shmaddr);
    //删除共享内存
    shmctl(shmid, IPC_RMID, nullptr);
    close(fd);//及时关闭管道
    return 0;
}