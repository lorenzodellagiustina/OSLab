/**
 * Scrivere le funzioni (ispirate alla libreria standard):
 *      - char *strchr(char *str, char c);
 *      - char *strstr(char *str, char *pattern);
 * che restituiscono il puntatore rispettivamente alla prima occorrenza del
 * carattere c e alla prima occorrenza della stringa pattern all’interno della
 * stringa puntata da str. Se un’occorrenza non viene trovata, si restituisca
 * un puntatore nullo.
 */
#include <stdio.h>
#include <string.h>

char *strchr(char *str, char c) {
    for (char *current_c = str; *current_c ; ++current_c) {
        if (*current_c == c) {
            return current_c;
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc == 1 && strcmp(argv[0], "-c") == 0) {
        strchr()
    } else if (argc == 1 && strcmp(argv[0], "-s") == 0) {

    } else {
        printf("You must enter an option (-c / -s)")
    }
}