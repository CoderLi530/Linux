#include "udpserver.hpp"

Log log;

int main()
{

  std::unique_ptr<UdpServer> udp(new UdpServer());
  //UdpServer udp;
  udp->Init();
  udp->Run();
  return 0;
}
