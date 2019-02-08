/*  自主完成minishell---熟悉shell的运行原理
 */
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    while(1) {
        char cmd[1024] = {0};
        printf("minishell: ");
        fflush(stdout);
        //scanf读取缓冲区数据时候，默认遇到空格终止
        //%[^\n]:将\n之前的数据放入到cmd中 设置遇到\n终止
        //%*c:将剩下的字符全都从缓冲区取出来，丢弃
        if (scanf("%[^\n]%*c", cmd) != 1) {
            getchar();
        }
        //fgets(stdin, 1023, cmd);
        //cmd[strlen(cmd) - 1] = '\0';
        printf("cmd:[%s]\n", cmd);
        //      ls  -l -a  
        char *ptr = cmd;
        char *argv[32] = {NULL};
        int argc = 0;
        while(*ptr != '\0') {
            //*ptr非空白字符则为参数首地址 l位置
            //isspace判断字符是否是空白字符
            if (!isspace(*ptr)) {
                argv[argc++] = ptr;
                //将参数主体走完 ls
                while(!isspace(*ptr) && *ptr != '\0')
                    ptr++;
                //意味着第一次得到ls    第二次进来得到 -l
                continue;
            }else {
                *ptr = '\0';
            }
            ptr++;
        }
        int pid = fork();
        if (pid < 0) {
            exit(-1);
        }else if (pid == 0) {
            execvp(argv[0], argv);
            exit(-1);
        }else {
            waitpid(pid, NULL, 0);
        }
    }
    return 0;
}

