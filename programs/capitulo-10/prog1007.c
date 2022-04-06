#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[])
{
	FILE * fp;
	int conta = 0;
	char ch;

	if (argc != 2)
	{
		printf("Sintaxe:\n\n%s <Arquivo>", argv[0]);
		exit(1);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		printf("Impossível acessar o %s\n", argv[1]);
		exit(2);
	}

	while ((ch = fgetc(fp)) != EOF)
		conta++;
	fclose(fp);

	printf("Dim. do arquivo: %d\n", conta);
}
