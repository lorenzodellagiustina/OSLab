#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("2 arguments expected: <file_path> <seconds>\n");
    } else {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL) {
            if(errno == EACCES)
                fprintf(stderr, "Read permission access of file %s denied\n", argv[1]);
            if(errno == EISDIR)
                fprintf(stderr, "%s is a directory\n", argv[1]);
        } else {
            int s = 0;
            if (sscanf(argv[2], "%d", &s) == 1) {
                if (s >= 0) {
                    // Here we are sure the input is correct
                } else {
                    printf("Expected arguments: <file_path> <seconds>. Seconds must be a positive integer\n");
                }
            } else {
                printf("Expected arguments: <file_path> <seconds>\n");
            }
            fclose(fp);
        }
    }
}