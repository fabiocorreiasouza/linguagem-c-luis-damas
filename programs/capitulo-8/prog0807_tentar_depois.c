#include <stdio.h>

void main()
{
	char vetor[3][20] =
	{
		"Fabio",
		"Correia",
		"Souza"
	};
	char (* ptr)[20] = vetor;
	char * p;

	while (ptr - vetor < 3)
	{
		p = &vetor[0][0];
		while (*p)
			putchar(*p++);
		putchar('\n');
		ptr++;
	}
	
}
