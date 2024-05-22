#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "american_maid"

int main(void)
{
    char s[300];
    int num, fd;

    // mkfifo(FIFO_NAME, S_IFIFO | 0666);

    printf("waiting for writers...\n");
    fd = open(FIFO_NAME, O_RDONLY);
    printf("got a writer\n");

    do {
        if ((num = read(fd, s, 300)) == -1)
            perror("read");
        else {
            s[num] = '\0';
            int a, b, c;
            sscanf(s, "%d %d %d", &a, &b, &c);
            printf("tick: read %d bytes: \"%d %d %d\"\n", num, a, b, c);
        }
    } while (num > 0);

    return 0;
}