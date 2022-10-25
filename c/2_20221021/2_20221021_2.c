#include <stdio.h>

/**
 * Given two ints returns their power (m^n)
 * @param m an int
 * @param n an int
 * @return an int (m^n)
 */
int power(int m, int n)
{
	int p = 1;
	for (int i = 0; i < n; ++i)
		p = p * m;
	return p;
}

/**
 * Finds the max number m for which 10^m <= n
 * @param n an int >= 0
 * @return an int (floor(log(n)))
 */
int lg(int n)
{
	int m = 0;
	while (power(10, m) <= n)
		m++;
	return --m;
}

int main()
{
	int inputInt;
	scanf("%d", &inputInt);
	int result = lg(inputInt);
	printf("lg(%d) >= %d\n", inputInt, result);
	return 0;
}
