/**
 * Scrivere una funzione
 *      int readline(char *line, unsigned len);
 * che riempia la stringa puntata da line con caratteri letti dallo standard
 * input, fino a che non viene letto EOF, il carattere di new line ’\n’, o
 * finché non vengono letti len caratteri. Ci si assicuri che la stringa venga
 * terminata correttamente. La funzione deve restituire il numero di
 * caratteri letti, oppure -1 se nessun carattere è stato letto perché è stata
 * trovata subito la costante EOF.
 */
#include <stdio.h>

int readline(char *line, unsigned len) {
    int len_i = len;
    int i = -1;
    for (char *current_c = line; *current_c && (i < len_i-1) ; ++current_c) {
        ++i;
        char c;
        scanf("%c", &c);
        line[i] = c;
    }
    ++i;
    return i;
}

int main(int argc, char **argv) {
    char msg[] = "ciao";
    int a = readline(msg, 3);
    for (char *current_c = msg; *current_c && a>0; ++current_c) {
        printf("%c", *current_c);
        --a;
    }
    printf("\n");
}