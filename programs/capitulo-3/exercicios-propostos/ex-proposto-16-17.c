#include <stdio.h>
/*
main()
{
	int numero;

	printf("Insira um inteiro: ");
	scanf("%d", &numero);
	// Jeito 1
	if (numero == 0)
		printf("É igual a 0\n");
	else
		printf("Não é igual a 0\n");
	// Jeito 2
	if (numero)
		printf("Não é igual a 0\n");
	else
		printf("É igual a 0\n");
	// Jeito 3
	printf((numero==0) ? "É igual a 0\n" : "Não é igual a 0\n");
}

*/
main()
{
        int numero;

        printf("Insira um inteiro: ");
        scanf("%d", &numero);
        // Programa 17 -- Com switch
	switch ()
	{
		case 0:
			printf("É igual a 0\n");
			break;
		default:
			printf("Não é igual a 0\n");
	}
}
