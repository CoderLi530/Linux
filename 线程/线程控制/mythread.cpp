#include<iostream>
#include<pthread.h>
#include<thread>
#include<unistd.h>

using namespace std;

//C++也有thread库
//C++的thread库具有跨平台性，可以在windows系统和Linux系统执行
//Linux上的原pthread库不具有跨平台性，只能在Linux上执行
//根据不同情况选择库

void threadRun()
{   
    while (true)
    {
        cout << "i am a thread for C++" << endl;
        sleep(1);
    }

}

int main()
{
    thread t1(threadRun);
    t1.join();
    return 0;
}

// class Request
// {
// public:
//     Request(int start, int end, string threadname)
//     :
//         _start(start),
//         _end(end),
//         _threadname(threadname)
//     {}

// public:
//     int _start;
//     int _end;
//     string _threadname;
// };

// class Response
// {
// public:
//     Response(int result, int exitcode)
//     :
//         _result(result),
//         _exitcode(exitcode)
//     {}

// public:
//     int _result;
//     int _exitcode;

// };

// void *threadRun(void *args) //不仅仅传递参数，也可以传递类
// {
//     Request *rq = static_cast<Request*>(args); //Request *rq = (Request *)args;
//     Response *rsp = new Response(0, 0);
//     for (int i = rq->_start; i <= rq->_end; ++i)
//     {
//         cout << "rq->threadname: " << rq->_threadname << "is running, calling ... ... " << i << endl;
//         rsp->_result += i;
//         usleep(10000); //微秒，10^-6秒
//     }
//     //创建rq记得释放
//     delete(rq);
//     return rsp;
// }

// int main()
// {
//     pthread_t tid;
//     Request *rq = new Request(1, 100, "Thread 1: "); //为什么new对象，不直接创建对象 -- new对象是在堆上开辟空间，堆是线程所共享的，如果直接创建对象，就会在线程栈上创建对象，其它线程无法访问该线程栈
//     pthread_create(&tid, nullptr, threadRun, rq);

//     void *ret;
//     pthread_join(tid, &ret);

//     Response *rsp = static_cast<Response*>(ret);
//     cout << "rsp->result: " << rsp->_result << ", rsp->_exitcode: " << rsp->_exitcode << endl;
//     delete rsp;
//     return 0;
// }

//1. 主线程和新线程打印同一个pid，说明线程是在同一个进程中执行的
//2. 由pthread_create传给threadRun的参数可以进行打印
//3. 当新线程退出时，主线程才能退出。那么新线程没有退出还在执行时，主线程就要进行等待pthread_join
// void *threadRun(void *args)
// {
//     const string name = (const char *)args;
//     int cnt = 5;
//     while (true)
//     {
//         cout << name << "i am a new thread, pid: " << getpid() << endl;
//         sleep(2);
//         //return nullptr;
//         //exit(0); //终止进程，进程中的所有线程都会终止
//         --cnt;
//         if (cnt == 0) break;
//     }
//     pthread_exit((void *)11); //终止该线程而不影响其它线程
// }

// int main()
// {
//     pthread_t tid; //pthread_t --> unsigned long int
//     pthread_create(&tid, nullptr, threadRun, (void*)"Thread 1: "); //线程的创建

//     //pthread_cancel(tid); //给线程发送取消线程请求，并将retval设置为(void *)-1 --> PTHREAD_CANCELED
//     //主线程继续执行
//     int cnt = 10;
//     while (true)
//     {
//         cout << "i am a main thread, pid: " << getpid() << ", id: " << tid << endl;
//         printf("thread address: %p\n", tid);
//         sleep(1);
//         --cnt;
//         if (cnt == 0) break;
//     }
//     void *retval;
//     pthread_join(tid, &retval); //如果线程使用了pthread_exit，retval会被设置为pthread_exit值；使用了pthread_cancel，retval会被设置为(void*)-1
//     printf("retval: %d\n", retval);
//     return 0;
// }