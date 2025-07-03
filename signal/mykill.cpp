#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

using namespace std;

void myhandler(int signo)
{
    cout << "process get a signal: " << signo << endl;
    exit(1);
}

int main()
{
    for (int i = 1; i < 32; ++i)
    {
        signal(i, myhandler);
    }
    // while (1)
    // {
    //     cout << "i am a crazy process : " << getpid() << endl;
    //     sleep(1);
    // }
    return 0;
}