#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "american_maid"

int data[][2] = {
    {10, 20},
    {11, 34},
    {12, 14},
    {13, 42},
    {14, 91}
};

int main(void)
{
    char s[300];
    int num, fd;

    mkfifo(FIFO_NAME, S_IFIFO | 0666);

    printf("waiting for readers...\n");
    fd = open(FIFO_NAME, O_WRONLY);
    printf("got a reader--type some stuff\n");

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        sprintf(s, "%d %d\n", data[i][0], data[i][1]);
        if ((num = write(fd, s, strlen(s))) == -1)
            perror("write");
        else
            printf("speak: wrote %d bytes\n", num);
    }

    return 0;
}