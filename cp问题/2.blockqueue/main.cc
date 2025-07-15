#include "BlockQueue.hpp"
#include "Task.hpp"
#include <unistd.h>
#include <ctime>

void* Consumer(void* args)
{
    BlockQueue<Task>* bq = static_cast<BlockQueue<Task>*>(args);
    while (true)
    {
        //sleep(1);
        //消费者消费
        //int data = bq->Pop();
        Task t = bq->Pop();
        t();
        //std::cout << "消费了一个数据：" << data << std::endl;
        std::cout << "处理任务" << t.GetTask() << "运算结果是：" << t.GetResult() << "thread id: " << pthread_self() << std::endl; 
        // sleep(2);
       // sleep(1);
    }
}

void* Producter(void* args)
{
    BlockQueue<Task>* bq = static_cast<BlockQueue<Task>*>(args);
    //int data = 0;
    //int x = 10;
    //int y = 20;

    while (true)
    {
        //sleep(1);
        //生产者生产
        //data++;
        usleep(100);
        int x = rand() % 10 + 1;
        int y = rand() % 10;
        char op = opers[rand() % opers.size()];
        Task t(x, y, op);
        bq->Push(t);
        //std::cout << "生产了一个数据：" << data << std::endl;
        std::cout << "生产了一个任务：" << t.GetTask() << "thread id: " << pthread_self() << std::endl;
        sleep(1);
    }
}

int main()
{
    srand(time(nullptr));
    BlockQueue<Task>* bq = new BlockQueue<Task>();

    pthread_t c[3], p[5];
    for (int i = 0; i < 3; ++i)
    {
        pthread_create(c + i, nullptr, Consumer, bq);
    }
    for (int i = 0; i < 5; ++i)
    {
        pthread_create(p + i, nullptr, Producter, bq);
    }
    for (int i = 0; i < 3; ++i)
    {
        pthread_join(c[i], nullptr);
    }
    for (int i = 0; i < 5; ++i)
    {
        pthread_join(p[i], nullptr);
    }

    // pthread_t c, p;
    // pthread_create(&c, nullptr, Consumer, bq);
    // pthread_create(&p, nullptr, Producter, bq);
    // pthread_join(c, nullptr);
    // pthread_join(p, nullptr);
    delete bq;
    return 0;
}