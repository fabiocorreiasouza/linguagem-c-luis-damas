#include <stdio.h>

main()
{
	float salario;
	printf("Qual o salário: "); scanf("%f", &salario);
	if (salario > 1000)
		salario = salario * 1.05;
	else
		salario = salario * 1.07;
	printf("Novo salário: %.2f\n", salario);
}

/*
Com operador terário (?:)

main()
{
        float salario;
        printf("Qual o salário: "); scanf("%f", &salario);
        salario = salario > 1000 ? salario*1.05 : salario*1.07;
        printf("Novo salário: %.2f\n", salario);
}
*/
