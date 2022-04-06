#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main(int argc, char * argv[])
{
	FILE * fin;
	char expressao[10+1];
	int num1, num2, i;
	float res_total = 0;
	float res = 0;
	char operacao = '+'; /* Soma: por padrão, mesmo entre números negativos */

	if (argc < 2 || argc > 3)
	{
		fprintf(stderr, "Sintaxe:\n\n%s [-t] <Arquivo>\n\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fin = fopen(argv[argc - 1], "r")) == NULL)
	{
		fprintf(stderr, "Não foi possível ler %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(expressao, 10+1, fin) != NULL)
	{
		expressao[strlen(expressao)-1] = '\0'; /* Retirar o '\n' */

		i = strlen(expressao);
		while (isdigit(expressao[--i])) ;

		if (expressao[i] == '/' || expressao[i] == '*') i++;

		num2 = atoi(&expressao[i]);
		expressao[i] = '\0';

		if (!isdigit(expressao[--i]))
		{
			operacao = expressao[i];
			expressao[i] = '\0';
		}

		num1 = atoi(&expressao[0]);

		switch(operacao)
		{
			case '/':
				res_total += res = (float) num1 / num2;
				break;
			case '*':
				res_total += res = num1 * num2;
				break;
			case '+':
				res_total += res = num1 + num2;
				break;
		}

		if (strncmp(argv[1], "-t", 2) != 0)
			printf("%d %c %d = %.1f\n", num1, operacao, num2, res);
		operacao = '+';
	}
	printf("%.1f\n", res_total);

	exit(EXIT_SUCCESS);
}
