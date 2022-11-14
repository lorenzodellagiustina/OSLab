#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("2 arguments expected: <file_path> <seconds>\n");
    } else {
        int s = 0;
        if (sscanf(argv[2], "%d", &s) == 1) {
            if (s > 0) {
                struct stat sb;
                if (stat(argv[1], &sb) == -1) {
                    fprintf(stderr, "%s: file %s access error: %s\n",
                            argv[0], argv[1], strerror(errno));
                    return 1;
                }
                int modtimes = 0;
                time_t stime = time(NULL);
                time_t lastmod = sb.st_mtime;
                while (stime + s > time(NULL)) {
                    stat(argv[1], &sb);
                    if (lastmod != sb.st_mtime) {
                        printf("File modified right now\n");
                        lastmod = sb.st_mtime;
                        ++modtimes;
                    }
                }
                if (modtimes == 0) {
                    printf("File %s wasn't modified\n", argv[1]);
                } else if (modtimes == 1) {
                    printf("File %s was modified %d time\n", argv[1], modtimes);
                } else {
                    printf("File %s was modified %d times\n", argv[1], modtimes);
                }
                return 0;
            } else {
                printf("Expected arguments: <file_path> <seconds>. Seconds must be a positive integer\n");
            }
        } else {
            printf("Expected arguments: <file_path> <seconds>\n");
        }
        return 1;
    }
}