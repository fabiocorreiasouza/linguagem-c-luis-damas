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

/* Carrega a estrutura passada por parâmetro */

void ler(PESSOA * ptr)
{
    printf("Nome    :"); gets((*ptr).nome); // ou ptr->nome
    printf("Idade   :"); scanf("%d", &(*ptr).idade); // &ptr->idade
    printf("Salario :"); scanf("%f", &(*ptr).salario); // ou &ptr->salario
    printf("Dt. nasc (dd/mm/aaaa):"); scanf("%d/%d/%d", &(*ptr).nasc.dia, &(*ptr).nasc.mes,
													  &(*ptr).nasc.ano);
	// ou &ptr->nasc.dia, &ptr->nasc.mes, &ptr->nasc.ano
}

/* Mostra a estrutura passada por parâmetro */

void mostrar(PESSOA x)
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
	puts("\n");
	ler(&p);
	puts("\n");
	mostrar(p);
}
