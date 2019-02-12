/*  这是一个c库io接口的回顾：fopen fwrite fread fseek fclose
 *      "r r+ w w+ a a+"
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char *file = "./tmp.txt";
    FILE *fp = NULL;
    //FILE *fopen(const char *path, const char *mode);
    //  path:   文件路径名
    //  mode：
    //      r   ：只读方式打开
    //      r+  ：读写方式打开
    //      w   ：只写方式代开，文件不存在则创建，存在则清空
    //      w+  ：读写方式打开，文件不存在则创建，存在则清空
    //      a   ：追加写方式打开，文件不存在则创建，
    //      a+  ：读+追加写方打开，从起始位置读，从末尾写入
    fp = fopen(file, "r+");
    if (fp == NULL) {
        return -1;
    }
    //size_t fwrite(const void *ptr, size_t size, size_t nmemb,
    //                     FILE *stream);
    //  ptr:    要写入的数据
    //  size：  每次写入的块长度
    //  nmemb： 总共写入的块个数
    //  stream：文件流指针
    //  返回值：正确返回写入的块数
    fseek(fp, 10, SEEK_END);
    char *ptr = "zhangwenchao is a good teacher!!\n";
    fwrite(ptr, strlen(ptr), 1, fp);

    //int fseek(FILE *stream, long offset, int whence);
    //  stream: 文件流指针
    //  offset：偏移大小 有正负之分
    //  whence：偏移位置
    //      SEEK_SET    文档起始位置
    //      SEEK_CUR    当前读写位置
    //      SEEK_END    文档末尾位置
    fseek(fp, 0, SEEK_SET);
    char buff[1024] = {0};
    //size_t fread(void *ptr,size_t size,size_t nmemb,FILE *stream)
    fread(buff, sizeof(buff) - 1, 1, fp);
    printf("buff:[%s]\n", buff);
    fclose(fp);
    return 0;
}
