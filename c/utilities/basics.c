#include "basics.h"

void swap(int *arrayPointer, int size, int a, int b) {
    if (a >= 0 && b >= 0 && a < size && b < size) {
        int c = arrayPointer[a];
        arrayPointer[a] = arrayPointer[b];
        arrayPointer[b] = c;
    }
}

void reverse(int *arrayPointer, int size, int a, int b) {
    if (a >= 0 && b >= 0 && a < size && b < size) {
        if (a < b) {
            swap(arrayPointer, size, a, b);
        }
    }
}

int partition(int *arrayPointer, int size, int a, int b) {
    if (a >= 0 && b >= 0 && a < size && b < size) {
        int pivot = arrayPointer[b];
        int i = a - 1;
        for (int j = a; j <= b; ++j) {
            if (arrayPointer[j] <= pivot) {
                ++i;
                swap(arrayPointer, size, i, j);
            }
        }
        return i;
    }
    return -1;
}

void quicksort(int *arrayPointer, int size, int a, int b) {
    if (a >= 0 && b >= 0 && a < size && b < size) {
        if (a < b) {
            int r = partition(arrayPointer, size, a, b);
            quicksort(arrayPointer, size, a, r-1);
            quicksort(arrayPointer, size, r+1, b);
        }
    }
}