#include "udpserver.hpp"

Log log;

string Handler(const string& s)
{
    cout << "server echo# " << s << endl;
    return s;
}

//解析命令去执行命令
string ExcuteCommand(const string& cmd)
{
    FILE* fp = popen(cmd.c_str(), "r");
    if (fp == nullptr)
    {
        perror("popen");
        return "error";
    }
    char buffer[SIZE];
    string result;
    while (true)
    {
        char* s = fgets(buffer, sizeof(buffer), fp);
        if (s == nullptr) break;
        result += buffer;
    }

    pclose(fp);
    cout << result << endl;
    return result;
}

static void Usage(string proc)
{
    cout << "\n\rUsage: " << proc << " serverport[1024+]\n" << endl;
}

// ./udpserver serverport
int main(int argc, char *argv[])
{
    //按照正确格式输入端口号
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }
    uint16_t serverport = stoi(argv[1]); 
    std::unique_ptr<UdpServer> udp(new UdpServer(serverport));
    // UdpServer udp;
    udp->Init();
    // udp->Run(Handler);
    udp->Run(ExcuteCommand);
    return 0;
}
