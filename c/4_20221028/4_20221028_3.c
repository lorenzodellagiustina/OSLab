/**
 * Scrivere una funzione:
 *      void capitalize(char *str);
 * che sostituisca, nella stringa puntata da str, ogni occorrenza di una
 * lettera latina minuscola all’inizio di una parola con la corrispondente
 * maiuscola.
 */
#include <stdio.h>

#define MAXINPUT 100

void capitalize(char *str) {
    for (char *c = str; *c; ++c) {
        int c_ascii = *c;
        if (c_ascii >= 97 && c_ascii <= 122) {
            c_ascii = c_ascii - 32;
            *c = c_ascii;
        }
    }
}

int main(int argc, char **argv) {
    char input[MAXINPUT] = "";
    printf("Inserire una stringa:\n");
    scanf("%99s", input);
    capitalize(input);
    for (char *c = input; *c; ++c) {
        printf("%c", *c);
    }
    printf("\n");
}