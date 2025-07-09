#include <iostream>
#include <pthread.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include "LockGuard.hpp"

using namespace std;

// pthread_mutex_lock函数
//  int pthread_mutex_lock(pthread_mutex_t *mutex); //加锁函数
//  int pthread_mutex_trylock(pthread_mutex_t *mutex); //非阻塞加锁
//  int pthread_mutex_unlock(pthread_mutex_t *mutex); //解锁

// int pthread_mutex_destroy(pthread_mutex_t *mutex); //锁的销毁函数 -- 析构函数
// int pthread_mutex_init(pthread_mutex_t *restrict mutex,
//                        const pthread_mutexattr_t *restrict attr); //锁的初始化函数 -- 构造函数
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //全局锁的设置

#define NUM 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// 电影院抢票，票数量1000张
class threadData
{
public:
    threadData(int number /*, pthread_mutex_t *mutex*/)
    {
        threadname = "thread-" + to_string(number);
        // lock = mutex;
    }

public:
    string threadname;
    // pthread_mutex_t *lock;
};

int tickets = 100; // 用多线程，模拟一轮抢票

void *getTicket(void *args)
{

    // pthread_detach(pthread_self()); //分离线程，主线程不必等待新线程返回，新线程会自动释放空间。并不是真的分离线程，还是会共享资源
    threadData *td = static_cast<threadData *>(args);
    const char *name = td->threadname.c_str();
    // 从这里加锁：只有第一个申请加锁成功的线程执行获取ticket操作，其它线程无法申请加锁
    //  pthread_mutex_lock(td->lock);
    while (true)
    {
        // 从这里加锁
        // pthread_mutex_lock(td->lock);
        // pthread_mutex_lock(&mutex);
        {
            LockGuard lockguard(&mutex);
            if (tickets > 0)
            {
                usleep(10000);
                printf("who=%s, get a ticket: %d\n", name, tickets); // ?
                tickets--;
                // pthread_mutex_unlock(td->lock);
                // pthread_mutex_unlock(&mutex);
            }
            else
            {
                // pthread_mutex_unlock(&mutex);
                // pthread_mutex_unlock(td->lock);
                break;
            }
        }
        usleep(200); // 让线程停一会，不要立即去申请加锁，给其它线程加锁
        // pthread_mutex_unlock(td->lock);
    }

    // pthread_mutex_unlock(td->lock);
    printf("%s ... quit\n", name);
    return nullptr;
}

int main()
{
    // pthread_mutex_t mutex;
    // pthread_mutex_init(&mutex, nullptr);
    vector<pthread_t> tids;
    vector<threadData *> thread_datas;
    for (int i = 1; i <= NUM; i++)
    {
        pthread_t tid;
        threadData *td = new threadData(i /*, &mutex*/);
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

    // pthread_mutexattr_destroy(&mutex);
    return 0;
}

// #define NUM 5

// // 电影院抢票，票数量1000张
// class threadData
// {
// public:
//     threadData(int number, pthread_mutex_t *mutex)
//     {
//         threadname = "thread-" + to_string(number);
//         lock = mutex;
//     }

// public:
//     string threadname;
//     pthread_mutex_t *lock;
// };

// int tickets = 100; // 用多线程，模拟一轮抢票

// void *getTicket(void *args)
// {

//     // pthread_detach(pthread_self()); //分离线程，主线程不必等待新线程返回，新线程会自动释放空间。并不是真的分离线程，还是会共享资源
//     threadData *td = static_cast<threadData *>(args);
//     const char *name = td->threadname.c_str();
//     // 从这里加锁：只有第一个申请加锁成功的线程执行获取ticket操作，其它线程无法申请加锁
//     //  pthread_mutex_lock(td->lock);
//     while (true)
//     {
//         // 从这里加锁
//         pthread_mutex_lock(td->lock);
//         if (tickets > 0)
//         {
//             usleep(10000);
//             printf("who=%s, get a ticket: %d\n", name, tickets); // ?
//             tickets--;
//             pthread_mutex_unlock(td->lock);
//         }
//         else
//         {
//             pthread_mutex_unlock(td->lock);
//             break;
//         }
//         usleep(10); //让线程停一会，不要立即去申请加锁，给其它线程加锁
//         // pthread_mutex_unlock(td->lock);
//     }
//     // pthread_mutex_unlock(td->lock);
//     printf("%s ... quit\n", name);
//     return nullptr;
// }

// int main()
// {
//     pthread_mutex_t mutex;
//     pthread_mutex_init(&mutex, nullptr);
//     vector<pthread_t> tids;
//     vector<threadData *> thread_datas;
//     for (int i = 1; i <= NUM; i++)
//     {
//         pthread_t tid;
//         threadData *td = new threadData(i, &mutex);
//         thread_datas.push_back(td);
//         pthread_create(&tid, nullptr, getTicket, thread_datas[i - 1]);
//         tids.push_back(tid);
//     }

//     for (auto thread : tids)
//     {
//         pthread_join(thread, nullptr);
//     }

//     for (auto td : thread_datas)
//     {
//         delete td;
//     }
//     return 0;
// }
