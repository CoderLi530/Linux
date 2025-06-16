#include"comm.hpp"
#include"log.hpp"

int main()
{
    //打开管道
    int fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1)
    {
        perror("open");
        exit(FIFO_OPEN_ERROR);
    }
    string line;
    while (true)//开始往管道写内容
    {
        cout << "Please Enter:";
        //cin >> line;
        getline(cin, line);

        write(fd, line.c_str(), line.size());
    }
    close(fd);
    return 0;
}