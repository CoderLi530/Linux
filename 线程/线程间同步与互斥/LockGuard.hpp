#pragma once

#include <pthread.h>
#include <iostream>

class Mutex
{
public:
    Mutex(pthread_mutex_t *lock)
    :_lock(lock)
    {}

    //加锁
    void Lock()
    {
        pthread_mutex_lock(_lock);
    }

    //解锁
    void UnLock()
    {
        pthread_mutex_unlock(_lock);
    }

    ~Mutex()
    {}
private:
    pthread_mutex_t *_lock;
};

class LockGuard
{
public:
    LockGuard(pthread_mutex_t *mutex)
    :_mutex(mutex)
    {
        _mutex.Lock();
    }

    ~LockGuard()
    {
        _mutex.UnLock();
    }
    
private:
    Mutex _mutex;
};