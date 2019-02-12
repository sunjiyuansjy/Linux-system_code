#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    printf("printf  test");
    fwrite("fwrite test", 10, 1, stdout);
    write(1, "write test", 10);
    sleep(3);
    return 0;
}
