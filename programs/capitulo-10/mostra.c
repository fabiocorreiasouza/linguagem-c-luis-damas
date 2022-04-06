#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MENOS '-'

void main(int argc, char * argv[])
{
	FILE * fin;
	FILE * fout = stdout; /* stdout: por padrão */
	char param = 'M';	  /* Maiúsculas: por padrão */
	char ch;
	int i;

	/* Caso o último parâmetro tenha o formato -oArquivo (redirecionamento de saída-padrão) */
	if (argv[argc-1][0] == MENOS && argv[argc-1][1] == 'o')
		if ((fout = fopen(&argv[argc-1][2], "w")) == NULL)
		{
			fprintf(stderr, "Não foi possível criar o arquivo %s\n", &argv[argc-1][2]);
			exit(1);
		}
		else
			argc--; //* O último parâmetro já foi tratado

	i = 1;
	while (i++ < argc)
	{
		/* Caso o seja uma opção de saída */
		if (argv[i][0] == MENOS)
		{
			if (argv[i][1] != 'o')
				param = argv[i][1]; /* Grava a opção de saída */
			continue;
		}

		if ((fin = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Não foi possível abrir o arquivo %s\n", argv[i]);
			exit(2);
		}

		/* Escreve o conteúdo de um arquivo de acordo com a opção de saída */
		switch(param)
		{
			case 'M':
				while ((ch = fgetc(fin)) != EOF)
					if (isupper(ch) && ch != '\n')
						fprintf(fout, "%c", ch);
				break;
			case 'm':
				while ((ch = fgetc(fin)) != EOF)
					if (islower(ch) && ch != '\n')
						fprintf(fout, "%c", ch);
				break;
			case 'd':
			case 'D':
				while ((ch = fgetc(fin)) != EOF)
					if (isdigit(ch) && ch != '\n')
						fprintf(fout, "%c", ch);
				break;
			default:
				fprintf(stderr, "Opção de saída inválida. Opções dispoíveis: -M, -m, -d/-D.\n");
				exit(3);
		}
		fprintf(fout, "\n");
		fclose(fin);
	}
	fclose(fout);
	exit(0);
}
