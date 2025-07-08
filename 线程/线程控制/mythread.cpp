#include <iostream>
#include <pthread.h>
#include <thread>
#include <unistd.h>
#include <vector>

using namespace std;

#define NUM 10

// 电影院抢票，票数量1000张
class threadData
{
public:
    threadData(int number)
    {
        threadname = "thread-" + to_string(number);
    }

public:
    string threadname;
};

int tickets = 1000; // 用多线程，模拟一轮抢票

void *getTicket(void *args)
{
    //pthread_detach(pthread_self()); //分离线程，主线程不必等待新线程返回，新线程会自动释放空间。并不是真的分离线程，还是会共享资源
    threadData *td = static_cast<threadData *>(args);
    const char *name = td->threadname.c_str();
    while (true)
    {
        if(tickets > 0)
        {
            usleep(1000);
            printf("who=%s, get a ticket: %d\n", name, tickets); // ?
            tickets--;
        }
        else
            break;
    }
    printf("%s ... quit\n", name);
    return nullptr;
}

int main()
{
    vector<pthread_t> tids;
    vector<threadData *> thread_datas;
    for (int i = 1; i <= NUM; i++)
    {
        pthread_t tid;
        threadData *td = new threadData(i);
        thread_datas.push_back(td);
        pthread_create(&tid, nullptr, getTicket, thread_datas[i - 1]);
        tids.push_back(tid);
    }

    for (auto thread : tids)
    {
        pthread_join(thread, nullptr);
    }

    for (auto td : thread_datas)
    {
        delete td;
    }
    return 0;
} 


// #define NUM 10

// int *p = NULL;

// //int g_val = 100; //全局变量在进程为所有线程所共享，g_val++和--，线程也会变化
// __thread int g_val = 100; //添加__thread，实现了线程的局部存储变量，是独立的资源，但是只能是内置类型，不能使用自定义类型

// struct threadData
// {
//     string threadname;
// };

// void InitThreadData(threadData *td, int number)
// {
//     td->threadname = "Thread-" + to_string(number);
// }

// string toHex(pthread_t tid)
// {
//     char buffer[1024];
//     snprintf(buffer, sizeof(buffer), "0x%x", tid);
//     return buffer;
// }

// void *threadRun(void *args)
// {
//     int test_i = 0; //在线程栈上创建，是该线程独有的资源，其它线程能否访问？可以
//     threadData *td = static_cast<threadData *>(args);
//     if (td->threadname == "Thread-1") p = &test_i;
//     int i = 2;
//     while (i--)
//     {
//         // cout << "i am a new thread, tid: " << pthread_self() << endl;
//         cout << td->threadname << ", tid: " << toHex(pthread_self()) << ", g_val:" << g_val <<endl;
//         sleep(1);
//         //g_val++;

//     }
//     sleep(2);
//     //pthread_exit((void *)1);
// }

// int main()
// {
//     vector<threadData> tds;
//     for (int i = 0; i < NUM; ++i)
//     {
//         threadData *td = new threadData;
//         InitThreadData(td, i);
//         pthread_t tid;
//         pthread_create(&tid, nullptr, threadRun, td);
//         sleep(1);
//         // while (true)
//         // {
//         //     // int cnt = 2;
//         //     cout << "i am a main thread, tid: " << &tid << endl;
//         //     sleep(1);
//         //     // if (--cnt == 0)
//         //     //     break;
//         // }

//         cout << "main thread get a thread val, val: " << p << endl;
//         sleep(1);
//         // void *retval;
//         // pthread_join(tid, &retval);
//         // cout << "thread-tid: " << &tid << "is quit, exitcode: ";
//         // printf("%d\n", retval);
//     }
//     return 0;
// }

// C++也有thread库
// C++的thread库具有跨平台性，可以在windows系统和Linux系统执行
// Linux上的原pthread库不具有跨平台性，只能在Linux上执行
// 根据不同情况选择库

// void threadRun()
// {
//     while (true)
//     {
//         cout << "i am a thread for C++" << endl;
//         sleep(1);
//     }

// }

// int main()
// {
//     thread t1(threadRun);
//     t1.join();
//     return 0;
// }

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

// 1. 主线程和新线程打印同一个pid，说明线程是在同一个进程中执行的
// 2. 由pthread_create传给threadRun的参数可以进行打印
// 3. 当新线程退出时，主线程才能退出。那么新线程没有退出还在执行时，主线程就要进行等待pthread_join
//  void *threadRun(void *args)
//  {
//      const string name = (const char *)args;
//      int cnt = 5;
//      while (true)
//      {
//          cout << name << "i am a new thread, pid: " << getpid() << endl;
//          sleep(2);
//          //return nullptr;
//          //exit(0); //终止进程，进程中的所有线程都会终止
//          --cnt;
//          if (cnt == 0) break;
//      }
//      pthread_exit((void *)11); //终止该线程而不影响其它线程
//  }

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