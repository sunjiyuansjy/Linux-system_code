// vim 常用插件：taglist ctags 自动补全 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "child.h"
int myheart()
{
    int i = 0;
    for (i = 0 ; i < 10; i++) {
        printf("wo hao e!!\n");
    }
    return 0;
}
int main()
{
    char *ptr = NULL;
    printf("hello bit!!\n");
    myheart();
    memcpy(ptr, "-------", 7);
    printf("my heart!!\n");
    print();
    return 0;
}
