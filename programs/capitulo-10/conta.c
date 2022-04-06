#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void erro_fatal(int num_erro, char * str)
{
	switch(num_erro)
	{
		case 1:
			fprintf(stderr, "Impossível acessar %s", str);
			break;
		case 2:
			fprintf(stderr, "Sintaxe:\n\n$ %s [-l] [arq]\n\n", str);
	}
	exit(num_erro);
}

void main(int argc, char * argv[])
{
	FILE * fp = stdin;     // stdin por padrão
	char linha[80+1];
	int mostra_linhas = 0; // não mostra número da linha por padrão
	int  n_linha;          // número da linha processada atual

	switch(argc)
	{
		case 1: break;
		case 2:
			if (strcmp(argv[1], "-l") == 0)
				mostra_linhas = 1;
			else
				if ((fp = fopen(argv[1], "r")) == NULL)
					erro_fatal(1, argv[1]);
			break;
		case 3:
			mostra_linhas = 1;
			if ((fp = fopen(argv[2], "r")) == NULL)
				erro_fatal(1, argv[2]);
			break;
		default:
			erro_fatal(2, argv[0]);
	}

	n_linha = 1;
	while (fgets(linha, 80+1, fp) != NULL)
	{
		linha[strlen(linha) - 1] = '\0'; // Retira o '\n'

		if (mostra_linhas)
			fprintf(stdout, "%3d: %ld\n", n_linha++, strlen(linha));
		else
			fprintf(stdout, "%ld\n", strlen(linha));
	}

	fclose(fp);
}
