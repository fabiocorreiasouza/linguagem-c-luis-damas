#include <stdio.h>

main()
{
	int ano;

	printf("Insira um ano:");
	scanf("%d", &ano);

	if ((ano%4 == 0 && ano%100 != 0) ||  ano%400 == 0)
		printf("É bissexto\n");
	else
		printf("Não é bissexto\n");
}
