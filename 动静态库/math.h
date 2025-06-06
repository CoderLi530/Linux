#pragma once 
#include<stdio.h>

//外部文件声明errno，其它文件可以访问该变量
extern int errno;

//加法
int Add(int a, int b);
//减法
int Subtract(int a, int b);
//乘法
int Multiply(int a, int b);
//除法
int Divide(int a, int b);
