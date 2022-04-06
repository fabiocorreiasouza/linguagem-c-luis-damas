#include <stdio.h>

main()
{
	int a, b, resultado;
	char operador;
	printf("Expressão: ");
	scanf("%d%c%d", &a, &operador, &b);

	switch (operador)
	{
		case '+':
			resultado = a + b;
			break;
		case '-':
			resultado = a - b;
			break;
		case '*':
		case 'x':
		case 'X':
			resultado = a * b;
			break;
		case '/':
		case '\\':
		case ':':
			resultado = a / b;
			//break;
	}

	printf("Resultado: %d\n", resultado);
}
