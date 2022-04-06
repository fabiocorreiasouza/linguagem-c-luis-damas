#include <stdio.h>

void main(int argc, char * argv[])
{
	int i = 0, j = argc-1;
	char * aux = NULL;

	while (i < j)
	{
		aux     = argv[i];
		argv[i++] = argv[j];
		argv[j--] = aux;
	}

	for (i=0; i<argc; i++)
		printf("%s ", argv[i]);

	putchar('\n');
}
