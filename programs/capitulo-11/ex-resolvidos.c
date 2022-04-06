#include <stdio.h>

typedef struct
{
	char nome[100];
	int idade;
	float salario;
	char status;
} PESSOA;

void ler_pessoa(PESSOA * p)
{
	printf("Nome	:"); gets((*p).nome);
	printf("Idade	:"); scanf("%d", &(*p).idade);
	printf("Salario	:"); scanf("%f", &(*p).salario);
	(*p).status = ' ';
}

void mostrar_pessoa(PESSOA p)
{
    printf("Nome    : %-30s\n", p.nome);
	printf("Idade   : %d\n", p.idade);
    printf("Salario : %f\n", p.salario);
    printf("Status  : %c\n", p.status);
}

void main()
{
	PESSOA fabio;

	ler_pessoa(&fabio);
	mostrar_pessoa(fabio);
}
