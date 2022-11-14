#include <stdio.h>

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("Inserire almeno il nome di un file\n");
    } else {
        for(int i=1; i<argc; i++) {
            char *name = argv[i];
            char *mode = "r";
            FILE *fp = fopen(name, mode);
            if (!fp) {
                fprintf(stderr, "File %s non esistente\n", name);
            } else if (ferror(fp)) {
                fprintf(stderr, "La lettura del file %s ha causato un errore\n", name);
            } else {
                char c;
                while (fscanf(fp, "%c", &c) != EOF) {
                    fprintf(stdout, "%c", c);
                }
                printf("\n");
                fclose(fp);
            }
        }
    }
}