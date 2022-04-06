#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char * argv[])
{
	FILE * fin;
	char linha[80+1];
	int n_linha;

	if ((fin = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Não foi possível ler %s\n", argv[1]);
		exit(1);
	}

	n_linha = 1;
	while (fgets(linha, 80+1, fin) != NULL)
	{
		linha[strlen(linha)-1] = '\0'; /* Remove o '\n' no final da string */
		printf("%2d: %s\n", n_linha++, linha);
	}

	exit(0);
}
