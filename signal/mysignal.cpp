#include<iostream>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>

using namespace std;

void myhandler(int signo)
{
    cout << "get a sig, number: " << signo << endl;
    exit(1);
}

int main()
{
    //signal(SIGALRM, myhandler); //接收alarm信号，进行修改操作
    alarm(5);
    while(1)
    {
        cout << "proc is running... , pid: " << getpid() << endl;
        sleep(1);
    }

    // signal(SIGFPE, myhandler);
    // cout << "before" << endl;
    // int a = 10;
    // a /= 0; //会报错，出异常，浮点数异常。8号信号（SIGFPE）
    // cout << "after" << endl;

    // pid_t id = fork();
    // if (id == 0)
    // {
    //     int cnt = 5;
    //     while (cnt--)
    //     {
    //         cout << "i am a child process, pid: " << getpid() << " cnt: " << cnt << endl;
    //         sleep(1); 
    //     }
    //     exit(0);
    // }
    // int status = 0;
    // pid_t rid = waitpid(id, &status, 0);
    // if (rid == id)
    // {
    //     cout << "child quit info, rid: " << rid << " exit code: " <<
    //     ((status>>8)&0xFF) << " exit signal: " << (status&0x7F) << " core dump: " << ((status>>7)&1) << endl;
    // }
    return 0;
}