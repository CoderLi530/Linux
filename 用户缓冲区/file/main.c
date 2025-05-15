#include"mystdio.h"

#define myfile "test.txt"

int main()
{
  _FILE* fp = _fopen(myfile, "w");
  if (fp == NULL) return 1;
  const char* msg = "hello world\n";
  _fwrite(fp, msg, strlen(msg));
  _fclose(fp);
  return 0;
}
