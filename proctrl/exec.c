/*  这是一个程序替换函数介绍的demo
 *      int execl(const char *path, const char *arg, ...);
 *      int execlp(const char *file, const char *arg, ...);
 *      int execle(const char *path, const char *arg,
 *              ..., char * const envp[]);
 *      int execv(const char *path, char *const argv[]);
 *      int execvp(const char *file, char *const argv[]);
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    //execl("./bin/xiake", "xiake", "-l", "-a", NULL);
    //execlp("ls", "ls", "-l", "-a", NULL);
    char *env[5] = {NULL};
    env[0] = "MYVAL=100";
    env[1] = "HOME=/home";
    //execle("./bin/xiake", "xiake", "-l", NULL, env);
    char *argv[5] = {NULL};
    argv[0] = "xiake";
    argv[1] = "-l";
    argv[2] = "ganjinde";
    execv("./bin/xiake", argv);
    printf("-------\n");
    return 0;
}
