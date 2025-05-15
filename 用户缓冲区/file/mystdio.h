#ifndef __MYSTDIO_H__
#define __MYSTDIO_H__

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

#define SIZE 1024
#define FLUSH_NOW 1
#define FLUSH_LINE 2
#define FLUSH_ALL 4
typedef struct IO_FILE{
  int fileno;//文件描述符
  int flag;//刷新策略
 // char intbuffer[SIZE];
 // int in_pos;
  char outbuffer[SIZE];//缓冲区
  int out_pos;//缓冲区内容的末尾位置
}_FILE;

_FILE* _fopen(const char* filename,const char* flags );
int _fwrite(_FILE* filename, const char* buffer, int len);
void _fclose(_FILE* filename);











#endif
