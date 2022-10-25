#include <stdio.h>

int main()
{
	long wc = 0;
	int previus_whitespace = 0;
	for(char c = getchar(); c != EOF; c = getchar())
	{
		if ( ( (c == ' ') || (c == '\t') || (c == '\n') ) && !previus_whitespace)
		{
			wc++;
			previus_whitespace = 1;
		}
		else if ( !( (c == ' ') || (c == '\t') || (c == '\n') ) && previus_whitespace )
		{
			previus_whitespace = 0;
		}
	}
	printf("%ld\n", wc);
	return 0;
}
