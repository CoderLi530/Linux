#pragma once

#include <iostream>
#include <pthread.h>
#include <queue>

template<class T>
class BlockQueue
{
    static const int defaultnum = 20;
public:
    BlockQueue(int maxcap = defaultnum):_maxcap(maxcap)
    {
        pthread_mutex_init(&_mutex, nullptr);
        pthread_cond_init(&_c_cond, nullptr);
        pthread_cond_init(&_p_cond, nullptr);
    }

    //给消费者输出数据
    T Pop()
    {
        pthread_mutex_lock(&_mutex);
        if (_q.size() == 0) //队列中没有资源，将该线程加入到队列中，进行休眠
        {
            pthread_cond_wait(&_c_cond, &_mutex);
        }
        //队列有资源，被唤醒
        T out = _q.front();
        _q.pop();
        //消费后，生产者进行生产
        pthread_cond_signal(&_p_cond);
        pthread_mutex_unlock(&_mutex);
        return out;
    }

    void Push(const T& in)
    {
        pthread_mutex_lock(&_mutex);
        if (_q.size() == _maxcap) //队列中的数量达到上限，不能再添加了，线程进入等待队列
        {
            pthread_cond_wait(&_p_cond, &_mutex);
        }
        //队列资源没满，被唤醒
        _q.push(in);
        //生产后，消费者进行消费
        pthread_cond_signal(&_c_cond);
        pthread_mutex_unlock(&_mutex);
    }

    ~BlockQueue()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_c_cond);
        pthread_cond_destroy(&_p_cond);
    }

private:
    std::queue<T> _q;
    int _maxcap;
    pthread_mutex_t _mutex;
    pthread_cond_t _c_cond;
    pthread_cond_t _p_cond;
};