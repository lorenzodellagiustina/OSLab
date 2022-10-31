/**
 * Scrivere le seguenti funzioni che manipolino un array passato
 * come argomento (nei modi visti):
 *  -   Una funzione reverse() per invertire l’ordine degli elementi in
 *      un array.
 *  -   Una funzione sort() per ordinare un array di numeri interi
 *      (riutilizzare quanto scritto per l’esercizio 3 della Lezione 8).
 *  -   Scrivere una funzione qsort() che implementi un algoritmo di
 *      ordinamento in maniera ricorsiva.
 */

#include <stdio.h>

#define ARRAY_SIZE 10

/**
 * Given an array swaps the digits in position a and b
 * @param arrayPointer is an address of an array
 * @param size the size of the pointed array
 * @param a is a valid index of the array pointed by arrayPointer
 * @param b is a valid index of the array pointed by arrayPointer
 * @return 0 if succeeds, 1 if fails
 */
int swap(int *arrayPointer, int size, int a, int b) {
    if (a < size && b < size) {
        int c = arrayPointer[a];
        arrayPointer[a] = arrayPointer[b];
        arrayPointer[b] = c;
        return 0;
    }
    return 1;
}

/**
 *
 * @param arrayPointer
 * @param size size the size of the pointed array
 * @return 0 if succeeds, 1 if fails
 */
int reverse(int *arrayPointer, int size) {
    int k = 0;
    for (int i = 0; i < size/2; i++) {
        k += swap(arrayPointer, size, i, size-i);
    }
    return (k == 0);
}

/**
 * Given an array orders the digits from position a to b
 * @param arrayPointer is an address of an array
 * @param size the size of the pointed array
 * @param a is a valid index of the array pointed by arrayPointer
 * @param b is a valid index of the array pointed by arrayPointer
 * @return 0 if succeeds, 1 if fails
 */
int sort(int *arrayPointer, int size, int a, int b) {
    if (a < size && b < size) {
        int k = 0;
        if (b - a > 1) {
            for (int i = a + 1; i <= b; i++) {
                for (int j = i; (j > a) && (arrayPointer[j] < arrayPointer[j - 1]); j--) {
                    k += swap(arrayPointer, size, j, j - 1);
                }
            }
        }
        return (k == 0);
    }
    return 1;
}

/**
 * Merges two ordered lists in an array ([a,r] and [r+1, b]) into an ordered list
 * @param arrayPointer
 * @param size
 * @param a
 * @param r
 * @param b
 */
void merge(int *arrayPointer, int size, int a, int r, int b) {
    int i = a;
    int j = r + 1;
    int A[size];
    int k = 0;
    while (i <= r && j <= b) {
        if (arrayPointer[i] < arrayPointer[j]) {
            A[k] = arrayPointer[i];
            i++;
        } else {
            A[k] = arrayPointer[j];
            j++;
        }
        k++;
    }
    while(i <= r) {
        A[k] = arrayPointer[i];
        i++;
        k++;
    }
    while(j <= b) {
        A[k] = arrayPointer[j];
        j++;
        k++;
    }
    for (int z = 0; z <= (b-a); z++) {
        arrayPointer[a+z] = A[z];
    }
}

/**
 * Given an array orders recursively the digits from position a to b
 * @param arrayPointer is an address of an array
 * @param size the size of the pointed array
 * @param a is a valid index of the array pointed by arrayPointer
 * @param b is a valid index of the array pointed by arrayPointer
 * @return 0 if succeeds, 1 if fails
 */
void qsort(int *arrayPointer, int size, int a, int b) {
    if (b - a > 0) {
        int r = (a + b) / 2;
        qsort(arrayPointer, size, a, r);
        qsort(arrayPointer, size, r+1, b);
        merge(arrayPointer, size, a, r, b);
    }
}

int main() {
    int A[ARRAY_SIZE] = {4, 6, 9, 10, 3, 5, 7, 9, 23, 4};
    qsort(A, ARRAY_SIZE, 0, ARRAY_SIZE-1);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0; // no errors
}
