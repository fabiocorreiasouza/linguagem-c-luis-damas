#include <stdio.h>

typedef struct
{
	int dia, mes, ano;
} DATA;

typedef struct pessoa
{
	char nome[100];
	int idade;
	float salario;
	DATA nasc;
} PESSOA;

void mostrar(PESSOA x) /* ou void mostrar(struct pessoa x) */
{
	printf("Nome	: %s\n", x.nome);
	printf("Idade	: %d\n", x.idade);
	printf("Salario	: %.2f\n", x.salario);
	printf("Dt. nasc: %d/%d/%d\n", x.nasc.dia, x.nasc.mes, x.nasc.ano);
}

void main()
{
	struct pessoa p = { "Carlos", 23, 12345.67, { 23, 5, 1954 } };
	mostrar(p);
}
