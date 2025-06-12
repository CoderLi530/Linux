#include"Task.hpp"
#include<iostream>
#include<unistd.h>
#include<vector>
#include<cassert>
#include<string>
#include<sys/wait.h>
#include<sys/stat.h>


using namespace std;

vector<task_t> tasks;

class channel
{
public:
    int _cmdfd;//文件的描述符
    pid_t _slaverid;//子进程的pid
    string _processname;//进程名称
public:
    //构造函数，使用初始化列表
    channel(int cmdfd, pid_t slaverid, string processname)
    :
        _cmdfd(cmdfd),
        _slaverid(slaverid),
        _processname(processname)
    {}
};

void Slaver()
{
    //查看管道文件中的任务并执行
    while (true)
    {
        int cmdcode = 0;
        int n = read(0, &cmdcode, sizeof(cmdcode));//从管道文件中获取任务
        //执行任务
        if (n == sizeof(int))//n是read读到的字节
        {
            // cmdcode必须是有效任务号
            if (cmdcode >= 0 && cmdcode < tasks.size()) tasks[cmdcode]();
        }
        //n == 0说明读端已完全读完，跳出循环
        if (n == 0) break;
    }
}

//初始化进程池
void InitProcessPool(vector<channel>* channels)
{
    vector<int> oldfds;
    for (int i = 0; i < 10; ++i)
    {
        //创建管道
        int pipefd[2];
        int n = pipe(pipefd);
        assert(!n);
        (void)n;
        //创建子进程
        pid_t id = fork();
        //if (id < 0) return 1;//创建失败，返回-1
        if (id == 0)//子进程，关闭写端
        {
            for (auto fd : oldfds) close(fd);//关闭子进程的写端
            // sleep(1);
            close(pipefd[1]);//只会关闭第一个子进程的写端，从第二个子进程开始写端没有关闭，会造成进程无法回收的情况
            //为了方便管道文件的获取，将 管道文件标识符 拷贝到 键盘文件标识符（0） 中
            dup2(pipefd[0], 0);
            close(pipefd[0]);
            Slaver();//子进程执行
            exit(0);
        }
        //父进程，关闭读端
        close(pipefd[0]);
        //写入进程名字
        string name = "process-" + to_string(i);
        channels->push_back(channel(pipefd[1], id, name));
        oldfds.push_back(pipefd[1]);
        sleep(1);
    }
}

void Menu()
{
    cout << "########################" << endl;
    cout << "1. 逐日          2. 燃己" << endl;
    cout << "3. 困奋          4. 诈降" << endl;
    cout <<  "        0. 退出        " << endl;
    cout << "########################" << endl;
}

void CtrlSlaver(vector<channel>& channels)
{
    //往管道文件发送任务，任务有四个
    int which = 0;
    while (true)
    {
        int select = 0;
        Menu();
        cout << "请输入：";
        cin >> select;

        //输入的select不对就退出
        if (select <= 0 || select >= 5) break;
        //注意：任务的下标是0 - 4，所以select要-1才能得到正确任务下标
        int cmdcode = select - 1;
        //发送任务
        write(channels[which]._cmdfd, &cmdcode, sizeof(cmdcode));
        sleep(1);
        //which往后++，注意范围
        ++which;
        which %= channels.size();
    }
}

//测试
void Debug(const vector<channel>& channels)
{
    for (const auto& c : channels)
    {
        cout << c._cmdfd << " " << c._slaverid << " " << c._processname << endl; 
    }
}

void QuitProcess(const vector<channel>& channels)
{
    //
    for (const auto& c : channels)
    {
        close(c._cmdfd);
        waitpid(c._slaverid, nullptr, 0);
    }
    // for (int i = channels.size(); i >= 0; ++i)
    // {
    //     close(channels[i]._cmdfd);
    //     waitpid(channels[i]._slaverid, nullptr, 0);
    // }
}

int main()
{
    //初始化任务
    LoadTasks(&tasks);
    vector<channel> channels;
    //假设有10个子进程，那么就有10个管道文件
    InitProcessPool(&channels);
    //往管道文件发送任务，让子进程去执行任务
    CtrlSlaver(channels);
    //测试
    //Debug(channels);
    //清理收尾
    QuitProcess(channels);
    return 0;
}
