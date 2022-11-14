#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("/dev/urandom", O_RDONLY);
    int n[10];
    read(fd, n, 10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        printf("%d ", n[i]);
    }
    printf("\n");
    close(fd);
    return 1;
}