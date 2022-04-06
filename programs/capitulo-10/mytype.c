#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[])
{
	FILE * fp;
	int ch;

	if (argc != 2)
	{
		printf("Sintaxe: \n\n%s <Arquivo>\n\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Impossível abrir o arquivo %s\n", argv[1]);
		exit(2);
	}

	while ((ch = fgetc(fp)) != EOF)
		putchar(ch);
	fclose(fp);
}
