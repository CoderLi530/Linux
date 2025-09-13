#pragma once

static int defaultnum = 5;

template<class T>
class RingQueue
{
public:
    RingQueue(int cap = defaultnum):_cap(cap), _c_step(0), _p_step(0), _cdata_sem(0), _pspace_sem(cap)
    {}
    ~RingQueue()
private:
    std::vecotr<T> _ringqueue; //使用vector实现环形队列
    int _cap; //环形队列的容量

    int _c_step; //消费者下标
    int _p_step; //生产者下标

    sem_t _cdata_sem; //消费者关注的数据资源
    sem_t _pspace_sem; //生产者关注的空间资源
};