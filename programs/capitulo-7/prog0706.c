#include <stdio.h>

int strcmp(char *s1, char *s2)
{
	int i = 0;
	while(s1[i]==s2[i] && s1[i]!='\0')
		i++;

	return s1[i] - s2[i];
}



void main()
{
	char nome[20];

	while (1)
	{
		printf("Escreva um nome [ou \"SAIR\"]: ");
		gets(nome);

		if (strcmp(nome, "SAIR") == 0) break;

		printf("%s\n", nome);
	}
}

