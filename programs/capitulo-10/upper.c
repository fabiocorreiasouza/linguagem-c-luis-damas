#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main(int argc, char * argv[])
{
	FILE * fp;
	int ch;

	switch(argc)
	{
		case 1:
			fp = stdin;
			break;
		case 2:
			if ((fp = fopen(argv[1], "r")) == NULL)
			{
				fprintf(stderr, "Impossível abrir o arq %s\n", argv[1]);
				exit(1);
			}
			break;
		default:
			fprintf(stderr, "Sintaxe:\n\n%s [Arquivo]\n\n", argv[0]);
			exit(2);
	}

	while ((ch = fgetc(fp)) != EOF)
		putchar(toupper(ch));

	fclose(fp);
}
