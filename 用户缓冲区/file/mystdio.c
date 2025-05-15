#include"mystdio.h"

#define FILE_MODE 0666 

_FILE* _fopen(const char* filename,const char* flags )
{
  // w a r
  int fd = -1;
  if (strcmp(flags, "w") == 0)
  {
    fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, FILE_MODE);
  }
  else if (strcmp(flags, "a") == 0)
  {
    fd = open(filename, O_CREAT|O_WRONLY|O_APPEND, FILE_MODE);
  }
  else if (strcmp(flags, "r") == 0)
  {
    fd = open(filename, O_RDONLY);
  }
  else//不符合要求的操作
  {
    return NULL;
  }
  //有可能打开文件失败，失败返回-1
  if (fd == -1) return NULL;
  _FILE* fp = (_FILE*)malloc(sizeof(_FILE));
  fp->fileno = fd;
  //设置刷新策略
  fp->flag = FLUSH_ALL;
  //设置缓冲区的内容位置
  fp->out_pos = 0;
  return fp;

}
int _fwrite(_FILE* filename, const char* buffer, int len)
{
  //先将内容拷贝到缓冲区中，根据刷新策略进行写入。
  memcpy(&filename->outbuffer[filename->out_pos], buffer, len);//深拷贝
  //缓冲区更新内容位置
  filename->out_pos += len;
  if (filename->flag&FLUSH_NOW)//这就是为什么宏定义为1， 2， 4
  {
    write(filename->fileno, filename->outbuffer, filename->out_pos);
    filename->out_pos = 0;
  }
  else if (filename->flag&FLUSH_LINE)
  {
    if (filename->outbuffer[filename->out_pos - 1] == '\n')
    {
      write(filename->fileno, filename->outbuffer, filename->out_pos);
      filename->out_pos = 0;
    }
    else if (filename->flag&FLUSH_ALL)
    {
      if (filename->out_pos == SIZE)
      {
        write(filename->fileno, filename->outbuffer, filename->out_pos);
        filename->out_pos = 0;
      } 
    }
  }
  write(filename->fileno, buffer, len); 
  
  return len;
}

//进程结束时，缓冲区刷新
void _fflush(_FILE* filename)
{
  if (filename->out_pos > 0)
  {
    write(filename->fileno, filename->outbuffer, filename->out_pos);
    filename->out_pos = 0;
  }
}

void _fclose(_FILE* filename)
{
  if (filename == NULL) return;
  _fflush(filename);
  close(filename->fileno);
  free(filename);
}
