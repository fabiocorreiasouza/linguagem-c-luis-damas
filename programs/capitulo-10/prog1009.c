#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[])
{
	FILE * fp;

	if (argc != 2)
	{
		fprintf(stderr, "Sintaxe:\n\n%s <arquivo>\n\n", argv[0]);
		exit(1);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Impossível acessar %s\n", argv[1]);
		exit(2);
	}

	fseek(fp, 0L, SEEK_END);

	printf("Dimensão (bytes): %ld\n", ftell(fp));

	fclose(fp);
}
