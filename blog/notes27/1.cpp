#include <sys/un.h>
#include <sys/socket.h>

int main()
{
    // 宣告
    sockaddr_un s;
    // 設定型態
    s.sun_family = AF_UNIX;
    // Unix domain socket的路徑
    // s.sun_path = ;
    return 0;
}