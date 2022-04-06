#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[])
{
	FILE * fp = stdin; /* stdin: por padrão */
	int n_linhas = 10; /* 10 linhas: por padrão */
	char linha[80+1];

	switch(argc)
	{
		case 1: break;

		case 2:
			if (*(argv[1] + 0) == '-')
				n_linhas = atoi(argv[1] + 1);
			else
				if ((fp = fopen(argv[1], "r")) == NULL)
				{
					fprintf(stderr, "Impossível acessar %s\n", argv[1]);
					exit(1);
				}
			break;

		case 3:
			n_linhas = atoi(argv[1] + 1);
			if ((fp = fopen(argv[2], "r")) == NULL)
			{
				fprintf(stderr, "Impossível acessar %s\n", argv[2]);
				exit(2);
			}
			break;

		default:
			fprintf(stderr, "Sintaxe:\n\n $ %s [-n] [arqin]\n\n", argv[0]);
			exit(3);
	}

	while (fgets(linha, 80+1, fp) != NULL && n_linhas-- > 0)
		fputs(linha, stdout);

	fclose(fp);
}
