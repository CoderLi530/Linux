#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  //int fd = open("log.txt", O_CREAT|O_WRONLY|O_TRUNC, 0666);
  const char* message = "hello fwrite\n";
  const char* str = "hello write\n";
  printf("hello printf\n");
  fprintf(stdout, "hello fprintf\n");
  fwrite(message, strlen(message), 1, stdout);
  write(1, str, strlen(str));
  //close(1); 
  //close(fd);
  fork();
  return 0;
}
