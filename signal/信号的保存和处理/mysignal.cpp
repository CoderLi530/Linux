#include<iostream>
#include<signal.h>
#include<unistd.h>

using namespace std;

void PrintPending(sigset_t& pending)
{
    for (int signo = 31; signo >= 1; --signo)
    {
        if (sigismember(&pending, signo))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n";
}

int main()
{
    //测试：1~31种信号是否都可以被屏蔽？经过测试，只有9号和19号信号不可被屏蔽
    sigset_t bset;
    sigset_t oset;
    sigemptyset(&bset);
    sigemptyset(&oset);
    //对所有的信号进行屏蔽
    for (int signo = 1; signo <= 31; ++signo)
    {
        sigaddset(&bset, signo); //bset中所有比特位都进行了屏蔽
    }
    sigprocmask(SIG_SETMASK, &bset, &oset);
    sigset_t pending;
    while (true)
    {
        int n = sigpending(&pending);
        if (n < 0) continue;
        PrintPending(pending);
        sleep(1);
    }
    // //1. 对2号信号进行屏蔽 -- 这三条语句实际上在栈上进行操作，用户态进行操作，而进程是在内核中的，信号在进程中的数据结构中
    // sigset_t bset; //sigset_t实际上是一个位图数据结构
    // sigset_t oset; 
    // sigemptyset(&bset); //进行初始化
    // sigemptyset(&oset);
    // sigaddset(&bset, 2); //把2号信号加入到bset中
    // //需要将2号信号保存到内核中才算是屏蔽操作
    // //1.1 使用系统调用，将数据设置到内核中
    // sigprocmask(SIG_SETMASK, &bset, &oset); //在内核中把2号信号屏蔽，oset保存修改前的信号，bset保存修改后的信号
    // //发送2号信号并打印信号
    // sigset_t pending;
    // while (true)
    // {
    //     //打印信号得先获取信号
    //     int n = sigpending(&pending);
    //     if (n < 0) continue; //获取失败重新获取
    //     PrintPending(pending);
    //     sleep(1);
    // }
    return 0;
}