/*  获取进程id的demo
 */
#include <stdio.h>
#include <unistd.h>

int main()
{
    //pid_t getpid(void);
    //  获取调用进程的pid，谁调用返回谁的pid

    pid_t pid = getpid();
    printf("pid:%d\n", pid);
    while(1) {
        sleep(1);
    }
    return 0;
}
