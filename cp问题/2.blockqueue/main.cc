#include "BlockQueue.hpp"
#include "Task.hpp"
#include <unistd.h>

void* Consumer(void* args)
{
    BlockQueue<Task>* bq = static_cast<BlockQueue<Task>*>(args);
    while (true)
    {
        //消费者消费
        //int data = bq->Pop();
        Task t = bq->Pop();
        t.Run();
        //std::cout << "消费了一个数据：" << data << std::endl;
        // sleep(2);
    }
}

void* Producter(void* args)
{
    BlockQueue<Task>* bq = static_cast<BlockQueue<Task>*>(args);
    //int data = 0;
    int x = 20;
    int y = 10;
    while (true)
    {
        // sleep(2);
        //生产者生产
        //data++;
        Task t(x, y);
        bq->Push(t);
        //std::cout << "生产了一个数据：" << data << std::endl;
        std::cout << "生产了一个任务：" << std::endl;
    }
}

int main()
{
    BlockQueue<Task>* bq = new BlockQueue<Task>();
    pthread_t c, p;
    pthread_create(&c, nullptr, Consumer, bq);
    pthread_create(&p, nullptr, Producter, bq);
    pthread_join(c, nullptr);
    pthread_join(p, nullptr);
    delete bq;
    return 0;
}