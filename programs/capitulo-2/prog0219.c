#include <stdio.h>

main()
{
	float numero;
	printf("Insira um número real: ");
	scanf("%f", &numero);
	printf("Parte inteira: %d\n", (int) numero);
	printf("Parte fracionária: %f\n", numero - ((int) numero));
}
