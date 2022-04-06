#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[])
{
	FILE * file_in, * file_out;
	int ch;

	if (argc != 3)
	{
		printf("Sintaxe:\n\n%s <Origem> <Destino>\n\n", argv[0]);
		exit(0);
	}

	file_in = fopen(argv[1], "rb");

	if (file_in == NULL)
	{
		printf("Não foi possível acessar %s\n", argv[1]);
		exit(0);
	}

	file_out = fopen(argv[2], "wb");

	if (file_out == NULL)
	{
		printf("Não foi possível acessar %s\n", argv[2]);
		exit(0);
	}

	while ((ch = fgetc(file_in)) != EOF)
		fputc(ch, file_out);

	fclose(file_in);
	fclose(file_out);
}
