/*  这是一个系统调用io接口的demo
 *  open    close   read    write   lseek
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    //mode_t umask(mode_t mask);
    //  设置当前进程的默认文件掩码
    umask(0);
    //int open(const char *pathname, int flags, mode_t mode);
    //  pathname:   文件路径名
    //  flags： 打开标志位
    //          O_RDONLY    只读
    //          O_WRONLY    只写
    //          O_RDWR      读写
    //          O_CREAT     文件存在则打开，不存在则创建
    //          O_EXCL      与O_CREAT同用，文件存在则报错返回
    //          O_TRUNC     打开文件同时，清空原有内容
    //          O_APPEND    追加
    //  mode：  权限
    //  返回值：文件描述符（非负整数）
    char *file = "./test.tmp";
    int fd = open(file, O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        perror("open error");
        return -1;
    }
    //ssize_t write(int fd, const void *buf, size_t count);
    //  fd:     文件描述符
    //  buf：   要写入的数据
    //  count： 要写入的数据长度
    //  返回值：实际写入的数据长度（字节） 失败：-1
    char *ptr = "touyun !! queyang!!\n";
    write(fd, ptr, strlen(ptr));

    //off_t lseek(int fd, off_t offset, int whence);
    lseek(fd, 0, SEEK_SET);

    char buff[1024] = {0};
    //ssize_t read(int fd, void *buf, size_t count);
    read(fd, buff, sizeof(buff) - 1);
    printf("buff:[%s]\n", buff);

    close(fd);

    return 0;
}
