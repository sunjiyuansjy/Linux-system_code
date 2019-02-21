/*  这是一个演示进程退出方式的demo
 *      main中return 效果等同于调用exit
 *      void exit(int status);  库函数
 *          退出一个进程，退出时刷新缓冲区+很多其它释放操作
 *      void _exit(int status); 系统调用
 *          粗暴退出，直接释放所有资源
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    printf("---exit----");
    sleep(3);
    _exit(0);


    int i = 0; 
    for (i = 0; i < 255; i++) {
        //char *strerror(int errnum);
        //返回上一条系统调用的错误原因描述
        //errno每次系统调用完毕都会重置的一个全局变量
        //用于存储这个系统调用的错误原因编号
        printf("%s\n", strerror(i));
    }
    //进程的退出数据只能是一个小于256的数据
    //因为进程的退出码只使用了一个字节来存储
    return  257;
    while(1) {
        printf("-------\n");
        sleep(1);
    }
    return 0;
}
