/*  这是一个进程创建的demo
 */
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    printf("hello bit!!pid:%d\n", getpid());
    if (pid == 0) {
        printf("i am child!!pid:%d\n", getpid());
    }else if (pid > 0) {
        printf("i am parent!! pid:%d\n", getpid());
    }

    while(1) {
        sleep(1);
    }
    return 0;
}
