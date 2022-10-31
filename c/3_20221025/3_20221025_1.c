/**
 * Scrivere un programma che legga dallo standard input dei
 * numeri e ne stampi la somma totale.
 */
 
#include <stdio.h>

int main() {
	int x = 0;
	char y;
	int sum = 0;
	while(y != EOF) {
		sum += x;
		y = scanf("%d ", &x);
	}
	printf("Somma: %d\n", sum);
    return 0;
}
