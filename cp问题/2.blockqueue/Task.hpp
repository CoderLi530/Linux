#pragma once

#include <iostream>

class Task
{
private:
    int a;
    int b;

public:
    Task(int x, int y):a(x), b(y)
    {}

    void Run()
    {
        std::cout << "run task: " << a << " + " << b << " = " << a + b << std::endl;
    }

    ~Task()
    {

    }
};