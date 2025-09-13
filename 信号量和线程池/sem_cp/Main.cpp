#include <iostream>
#include <pthread.h>

#include "RingQueue.hpp"

int main()
{
    RingQueue<int> *rq = new RingQueue<int>();
    pthread_t c, p;
    pthread_create(&c, nullptr, Consumer, nullptr);
    pthread_create(&p, nullptr, Producter, nullptr);
    pthread_join(c, nullptr);
    pthread_join(p, nullptr);
    delete rq;
    return 0;
}