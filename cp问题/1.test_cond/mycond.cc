#include <iostream>
#include <unistd.h>
#include <pthread.h>

int cnt = 0; //公共资源

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


void* Count(void* args)
{
    pthread_detach(pthread_self()); //线程自己释放
    uint64_t number = (uint64_t)args;
    std::cout << "pthread: " << number << " create success" << std::endl;
    while (true)
    {
        //sleep(1);
        pthread_mutex_lock(&mutex);
        //让线程去休眠，临界资源被使用，临界资源是有状态的
        //临界资源不就绪，要访问临界资源判断是否就绪
        //所以先解锁判断，然后进入队列，最后进行加锁
        pthread_cond_wait(&cond, &mutex);
        std::cout << "pthread: " << number << ", cnt: " << cnt++ << std::endl;
        pthread_mutex_unlock(&mutex);
    }

}

int main()
{
    for (uint64_t i = 0; i < 10; ++i)
    {
        pthread_t tid;
        pthread_create(&tid, nullptr, Count, (void*)i); //传递(void*)&i会导致所有线程收到同一种变量地址
        usleep(1000);
    }
    sleep(3);
    std::cout << "main thread ctrl begin:" << std::endl;
    while (true)
    {
        sleep(1);
        //pthread_cond_broadcast(&cond);
        pthread_cond_signal(&cond); //唤醒线程，默认第一个线程
        std::cout << "signal one thread" << std::endl;
    }
    return 0;
}