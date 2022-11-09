/**
 * Scrivere un programma che legga una sequenza di numeri dallo standard
 * input, e:
 *      I Se l’utente ha passato l’opzione -r sulla riga di comando,
 *        stampi i numeri in ordine inverso.
 *      I Se l’utente ha passato l’opzione -s, stampi i numeri ordinati in
 *        senso crescente.
 *      I Se l’utente ha passato l’opzione -S, stampi i numeri ordinati in
 *        senso decrescente.
 *      I Se l’utente non ha passato alcuna opzione, stampare un
 *        messaggio di errore e non fare nulla (ancora prima di leggere
 *        alcunché).
 */

#include <stdio.h>
#include <string.h>
#include "../utilities/basics.h"

int main(int argc, char **argv) {
    if (argc != 2) { // ERROR: invalid arguments
        printf("Inserire un argomento tra i seguenti (uno e uno solo):\n\t-r per stampare i numeri in ordine inverso;\n\t-s per stampare i numeri in ordine crescente\n\t-S per stampare i numeir in ordine decrescente\n");
        return 1;
    } else if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "-S") == 0) { // valid input
        // COMMON PART
        // array initialization
        printf("Inserire la lunghezza della sequenza di numeri di inserire: ");
        int n = 0;
        scanf("%d", &n);
        int arraylength = n;
        if (n <= 0) {
            printf("%d input non valido; inserire un numero positivo", n);
            scanf("%d", &n);
        }
        int A[n];
        // filling array in reverse
        int x = 0;
        --n;
        while (n >= 0) {
            scanf("%d", &x);
            A[n] = x;
            --n;
        }
        if (strcmp(argv[1], "-r") == 0) { // -r OPTION: reverse
            // nothing to do here, the array was filled as reversed
        } else if (strcmp(argv[1], "-s") == 0) { // -s OPTION: ascending order
            quicksort(A, arraylength, 0, arraylength-1);
        } else { // -S OPTION: descending order
            quicksort(A, arraylength, 0, arraylength-1);;
            reverse(A, arraylength, 0, arraylength-1);
        }
        // OUTPUT
        printf("OUTPUT:\n");
        for (int  i = 0; i < arraylength; ++i) {
            printf("%d ", A[i]);
        }
        printf("\n");
        return 0;
    } else { // ERROR: invalid arguments
        printf("Inserire un argomento tra i seguenti (uno e uno solo):\n\t-r per stampare i numeri in ordine inverso;\n\t-s per stampare i numeri in ordine crescente\n\t-S per stampare i numeir in ordine decrescente\n");
        return 1;
    }

}