#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100000

void readline(FILE *fp, char *s) {
    int len = 0;
    for (char c = fgetc(fp); c != '\n' && !feof(fp); c = fgetc(fp)) {
        s[len] = c;
        len++;
    }
    s[len] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Inserire il path dei due file da confrontare\n");
    } else {
        char *mode = "r";
        FILE *fp1 = fopen(argv[1], mode);
        FILE *fp2 = fopen(argv[2], mode);
        if (!fp1) {
            fprintf(stderr, "File %s non esistente\n", argv[1]);
        } else if (!fp2) {
            fprintf(stderr, "File %s non esistente\n", argv[2]);
        } else if (ferror(fp1)) {
            fprintf(stderr, "La lettura del file %s ha causato un errore\n", argv[1]);
        } else if (ferror(fp2)) {
            fprintf(stderr, "La lettura del file %s ha causato un errore\n", argv[2]);
        } else {
            char s1[MAX_LINE_LENGTH];
            char s2[MAX_LINE_LENGTH];
            int bool = 1;
            /*
            readline(fp1, s1);
            readline(fp1, s1);
            readline(fp1, s1);
            printf("%s", s1);
             */

            while (!feof(fp1) && !feof(fp2) && bool) {
                readline(fp1, s1);
                readline(fp2, s2);
                if (strcmp(s1, s2)) {
                    bool = 0;
                    fprintf(stdout, "%s", s1);
                }
            }
            if (bool) {
                printf("File uguali");
            }
            printf("\n");
            fclose(fp1);
            fclose(fp2);
        }
    }
}