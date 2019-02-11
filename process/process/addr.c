/*  这是一个演示父子进程数据独有的demo
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int g_val = 20;
int main()
{
    int pid = fork();
    if (pid < 0) {
        return -1;
    }else if (pid == 0) {
        //child
        g_val = 100;
        printf("child val:%d--%p\n", g_val, &g_val);
    }else {
        //parent
        sleep(1);
        printf("parent val:%d--%p\n", g_val, &g_val);
    }
    return 0;
}
