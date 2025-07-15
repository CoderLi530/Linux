#pragma once

#include <iostream>
#include <string>

std::string opers = "+-*/%";

enum
{
    DivZero = 1,
    ModZero,
    UnKnown
};

class Task
{
public:
    Task(int x, int y, char oper):_data1(x), _data2(y), _oper(oper), _result(0), _exitcode(0) 
    {}

    void Run()
    {
        switch (_oper)
        {
            case '+':
                _result = _data1 + _data2;
                break;
            case '-':
                _result = _data1 - _data2;
                break;
            case '*':
                _result = _data1 * _data2;
                break;
            case '/':
                if (_data2 == 0) _exitcode = DivZero;
                else _result = _data1 / _data2;
                break;
            case '%':
                if (_data2 == 0) _exitcode = ModZero;
                else _result = _data1 % _data2;
                break;
            default:
                _exitcode = UnKnown;
                break; 
        }
    }

    //仿函数
    void operator()()
    {
        Run();
    }

    //得到结果(计算表达式)
    std::string GetResult()
    {
        std::string s = std::to_string(_data1);
        s += _oper;
        s += std::to_string(_data2);
        s += " = ";
        s += std::to_string(_result);
        s += " [code: ";
        s += std::to_string(_exitcode);
        s += "] ";
        return s;
    }

    std::string GetTask()
    {
        std::string s = std::to_string(_data1);
        s += _oper;
        s += std::to_string(_data2);
        s += "= ? ";
        return s;
    }

    ~Task()
    {

    }

private:
    int _data1; //数据1
    int _data2; //数据2
    char _oper; //运算符
    int _result; //计算结果
    int _exitcode; //返回码
};