#include <stdio.h>

int main()
{
	long wc = 0;
	for(char c = getchar(); c != EOF; c = getchar())
	{
		if ( (c == ' ') || (c == '\t') || (c == '\n') )
		{
			wc++;
		}
	}
	printf("Whitespace characters: %ld\n" , wc);
	return 0;
}
