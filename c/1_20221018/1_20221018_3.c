#include <stdio.h>

int main()
{
	int previus_whitespace = 0;
	for(char c = getchar(); c != EOF; c = getchar())
	{
		if ( ( (c == ' ') || (c == '\t') || (c == '\n') ) && !previus_whitespace)
		{
			printf("\n");
			previus_whitespace = 1;
		}
		else if ( !( (c == ' ') || (c == '\t') || (c == '\n') ) )
		{
			printf("-");
			previus_whitespace = 0;
		}
	}
	return 0;
}
