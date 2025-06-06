#include "math.h"

int errno = 0;

//加法
int Add(int a, int b)
{
  return a + b;
}
//减法
int Subtract(int a, int b)
{
  return a - b;
}
//乘法
int Multiply(int a, int b)
{
  return a * b;
}
//除法
int Divide(int a, int b)
{
  //注意除0的情况
  if (b == 0)
  {
    errno = -1;
    return 0;
  }
  return a / b;
}
