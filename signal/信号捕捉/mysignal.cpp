#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <cstring>
#include <sys/types.h>
#include <wait.h>

using namespace std;

void myhandler(int signo)
{
    sleep(5);
    while (pid_t rid = waitpid(-1, nullptr, WNOHANG)) //非阻塞轮询
        cout << "i get a signo: " << signo << "child process quit: " << rid << endl;
}

// 子进程退出时，会给父进程发送信号（SIGCHLD） 验证后：正确
// 如果有10个子进程，子进程退出时同时发送信号给父进程，那么父进程可能只会收到1~2个信号，因为执行递达操作时pending会被锁住（block)（屏蔽）
// 如何解决这个问题？子进程发送信号给父进程时让子进程自己退出
int main()
{
    signal(17, SIG_IGN); //让子进程自己退出，不存在僵尸进程
    signal(17, myhandler);
    for (int i = 0; i < 10; ++i)
    {
        pid_t id = fork();
        // child
        if (id == 0)
        {
            cout << "i am a child process, pid: " << getpid() << endl;
            sleep(1);
            exit(0);
        }
    }
    // father
    cout << "i am a father process, pid: " << getpid() << endl;
    sleep(5);
    return 0;
}

// //volatile 强制CPU往内存中取值，不往寄存器中取值
// volatile int flag = 0;

// void myhandler(int signo)
// {
//     cout << "i get a signo, signo: " << signo << endl;
//     flag = 1; //当在makefile中添加-O3 -g时，进行了优化：main函数中flag没有进行算术操作，CPU中的寄存器保存了原来的值，之后取flag值只会取寄存器的值，不管flag是否变化！！！
// }

// int main()
// {
//     signal(2, myhandler);
//     while (!flag) ; //输入ctrl + c，flag被修改成1，跳出循环
//     cout << "process quit normal" << endl;
//     return 0;
// }

// void PrintPending()
// {
//     sigset_t bset;
//     sigpending(&bset); //返回当前进程的信号集给bset
//     for (int signo = 31; signo >= 1; --signo)
//     {
//         if (sigismember(&bset, signo)) cout << "1";
//         else cout << "0";
//     }
//     cout << "\n";
// }

// void myhandler(int signo)
// {
//     //假设：先1->0，再进行递达操作
//     //PrintPending();
//     //cout << "i get a signo, signo: " << signo << endl;

//     cout << "i get a signo, signo: " << signo << endl;
//     while (true)
//     {
//         PrintPending();
//         sleep(1);
//     }
// }

// //1. 信号递达时，pending表在什么时候1->0？验证后：pending表在递达操作之前置0，然后进行递达操作
// //2. 如果正在执行信号的处理函数，这个信号会被屏蔽吗？验证：会被屏蔽，直到该处理函数执行完毕，才会进行递达操作

// int main()
// {
//     struct sigaction act, oldact;
//     //不进行内存设置会发生段错误，Segmentation fault
//     memset(&act, 0, sizeof(act));
//     memset(&oldact, 0, sizeof(oldact));
//     act.sa_handler = myhandler;
//     sigaction(2, &act, &oldact);
//     while (true)
//     {
//         cout << "i am a process, pid: " << getpid() << endl;
//         sleep(1);
//     }
//     return 0;
// }