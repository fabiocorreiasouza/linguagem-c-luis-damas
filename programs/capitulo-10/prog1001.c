#include <stdio.h>

void main()
{
	FILE * fp;
	char s[100];

	puts("Insira o nome do arquivo:");
	gets(s);

	/* Abrir o arquivo */
	fp = fopen(s, "r");

	/* Verificar se a abertura foi feita com sucesso */
	if (fp == NULL)
		printf("Impossível abrir o arquivo %s\n", s);
	else
	{
		printf("Arquivo %s aberto com sucesso!\n", s);
		fclose(fp);
	}
}
