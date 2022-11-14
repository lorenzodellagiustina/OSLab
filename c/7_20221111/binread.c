#include <stdio.h>

int main() {
    FILE *fp = fopen("/dev/urandom", "rb");
    int n[10];
    fread(n, sizeof(int), 10, fp);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", n[i]);
    }
    printf("\n");
    fclose(fp);
    return 1;
}