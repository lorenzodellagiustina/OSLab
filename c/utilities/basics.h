#include <stdio.h>

/**
 * Swaps arrayPointer[a] with arrayPointer[b] (if the contract is not respected doesn't do nothing)
 * @param arrayPointer is an address of an array
 * @param size the size of the pointed array
 * @param a is a valid index of the array pointed by arrayPointer
 * @param b is a valid index of the array pointed by arrayPointer
 */
void swap(int *arrayPointer, int size, int a, int b);

/**
 * Reverse the order of an array from a to b (only if the contract is respected)
 * @param arrayPointer is an address of an array
 * @param size the size of the pointed array
 * @param a is a valid index of the array pointed by arrayPointer (a<b)
 * @param b is a valid index of the array pointed by arrayPointer (a<b)
 */
void reverse(int *arrayPointer, int size, int a, int b);

/**
 * Given a pivot (b) and an array put all the element < pivot before it, and all the elements > pivot after it (if the contract is not respected return -1)
 * @param arrayPointer is an address of an array
 * @param size the size of the pointed array
 * @param a is a valid index of the array pointed by arrayPointer
 * @param b is a valid index of the array pointed by arrayPointer
 * @return the position of the pivot in the array or -1 if the contract is not respected
 */
int partition(int *arrayPointer, int size, int a, int b);

/**
 * Given an array orders the digits from position a to b (only if the contract is respected)
 * @param arrayPointer is an address of an array
 * @param size the size of the pointed array
 * @param a is a valid index of the array pointed by arrayPointer
 * @param b is a valid index of the array pointed by arrayPointer
 */
void quicksort(int *arrayPointer, int size, int a, int b);