#include <stdio.h>

/**
 * Given an array swaps the digits in position a and b
 * @param arrayPointer is an address of an array
 * @param a is a valid intex of the array pointed by arrayPointer
 * @param b is a valid intex of the array pointed by arrayPointer
 */
void swap(int *arrayPointer, int a, int b) {
	int c = arrayPointer[a];
	arrayPointer[a] = arrayPointer[b];
	arrayPointer[b] = c;
}

/**
 * Given an array orders the digits from position a to b
 * @param arrayPointer is an address of an array
 * @param a is a valid intex of the array pointed by arrayPointer
 * @param b is a valid intex of the array pointed by arrayPointer
 */
void insertion_sort(int *arrayPointer, int a, int b) {
	if (b-a > 1) {
		for (int i = a+1; i<=b; i++) {
			for (int j = i; (j > a) && (arrayPointer[j]<arrayPointer[j-1]); j--) {
				swap(arrayPointer, j, j-1);
			}
		}
	}
}

int main() {
	int random[10] = {100, 8, 2, -1, 9, 0, -678, 7, 9, 1};
	int *pointer = &random[0];
	insertion_sort(pointer, 0, 9);
	//swap(pointer, 0, 9);
	for(int i = 0; i < 10; i++) {
		printf("%d ", random[i]);
	}
	printf("\n");
}
