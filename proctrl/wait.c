/*  这是一个演示进程等待的demo：避免产生僵尸进程
 *  wait    waitpid
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();
    if (pid < 0) {
        //直接打印上一条系统调用的错误信息，可以自带一些自己的提示
        //信息，真正的错误信息会写入到提示信息之后
        perror("fork error");
        exit(-1);
    }else if (pid == 0) {
        sleep(5);
        exit(233);
    }
    //pid_t wait(int *status);
    //  等待子进程退出获取退出返回值，允许操作系统释放子进程资源
    //  status：输出型参数，用于获取子进程的退出返回值
    //  返回：退出子进程的pid
    //  wait是一个阻塞型函数，没有子进程退出则一直等待
    //wait(NULL);
    //pid_t waitpid(pid_t pid, int *status, int options);
    //  pid:    等待指定子进程， -1：等待任意子进程
    //  status：输出型参数，用于获取子进程的退出返回值
    //  options:    WNOHANG---设置waitpid为非阻塞函数
    //      waitpid默认等待子进程退出，WNOHANG：没有子进程退出则立
    //      即报错返回
    //  返回：退出子进程的pid  0-当前没有子进程退出 <0-出错
    int statu;
    while(waitpid(pid, &statu, WNOHANG) == 0) {
        //do    anything
        printf("-------why???\n");
        sleep(1);
    } 
    if (WIFEXITED(statu)) {
        printf("exit code:%d\n", WEXITSTATUS(statu));
    }
    //00000000 00000000 233 00000000    01111111
    //原始四个字节与上01111111，得到低7位的数据
    //将statu右移8，将退出码转换到低8位，再与上0xff得仅剩的低8位
    if ((statu & 0x7f) == 0) {
        printf("exit code:%d\n", (statu >> 8) & 0xff);
    }
    printf("child exit code:%d\n", statu);
    while(1) {
        printf("-------\n");
        sleep(1);
    }
    return 0;
}
