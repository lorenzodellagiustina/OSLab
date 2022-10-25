#include <stdio.h>

/**
 * Given an character returns 1 if is a whitespace, 0 otherwise
 * @param c is a character
 * @return a boolean int (0 -> false, 1 -> true)
 */
int is_whitespace(char c) {
	return (c == ' ' || c == '\t' || c == '\n');
}

int main() {
	int previus_whitespace = 0;
	for(char c = getchar(); c != EOF; c = getchar())
	{
		if ( is_whitespace(c) && !previus_whitespace)
		{
			printf("\n");
			previus_whitespace = 1;
		}
		else if ( !is_whitespace(c) )
		{
			printf("-");
			previus_whitespace = 0;
		}
	}
	return 0;
}
