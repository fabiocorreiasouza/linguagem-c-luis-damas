#include <stdio.h>
#include <string.h>

typedef struct
{
	char nome[30+1];
	int idade;
	float salario;
	char status; // '*' indica que o registro está apagado
} PESSOA;

void mostrar_menu()
{
    printf("------ M E N U -----\n");
    printf("1. Inserir Registro\n");
    printf("2. Alterar Registro\n");
    printf("3. Apagar Registro\n");
    printf("4. Listar Registros\n");
    printf("5. Pesquisas\n");
    printf("0. Sair\n");
    printf("--------------------\n");
}

void mostrar_submenu()
{
	printf("------- P E S Q U I S A R ----------\n");
	printf("1. Pesquisar por Intervalo de Idades\n");
	printf("2. Pesquisar por nome\n");
	printf("0. Voltar\n");
	printf("------------------------------------\n");
}

void mostrar_pessoa(PESSOA p)
{
	printf("%-15s %2d %5.2f\n", p.nome, p.idade, p.salario);
}

void inserir_registro(){}
void alterar_registro(){}
void apagar_registro(){}

void listar_registro(int categoria, PESSOA * p_registros)
{
	int i;
	int DIM = sizeof(p_registros) / sizeof(PESSOA);
	int idade_min, idade_max;
	char nome[30+1];

	switch (categoria)
	{
		case 0:
			for (i=0; i<DIM; i++)
				mostrar_pessoa(p_registros[i]);
			break;
		case 1:
			printf("Intervalo [min max]: ");
			scanf("%d %d", &idade_min, &idade_max);
			for (i=0; i<DIM; i++)
				if (p_registros[i].idade >= idade_min && p_registros[i].idade <= idade_max)
					mostrar_pessoa(p_registros[i]);
			break;
		case 2:
			printf("Nome: ");
			gets(nome);
			for (i=0; i<DIM; i++)
				if (strcmp(p_registros[i].nome, nome) >= 0)
					mostrar_pessoa(p_registros[i]);
	}
}

void pesquisar(PESSOA * p_registros)
{
	int res;

	while (1)
	{
		mostrar_submenu();
		scanf(" %d", &res);
		getchar();

		if (res == 0) break;

		switch (res)
		{
			case 1:
				listar_registro(1, p_registros);
				break;
			case 2:
				listar_registro(2, p_registros);
				break;
			default:
				printf("Escolha uma alternativa válida\n");
		}
	}
}


void main()
{
	PESSOA registros[10];
	int res;

	while(1)
	{
		mostrar_menu();
		scanf(" %d", &res);
		getchar();

		if (res == 0) break;

		switch (res)
		{
			case 1:
				inserir_registro();
				break;
			case 2:
				alterar_registro();
				break;
			case 3:
				apagar_registro();
				break;
			case 4:
				listar_registro(0, registros);
				break;
			case 5:
				pesquisar(registros);
				break;
			default:
				printf("Escolha uma alternativa válida\n");
		}
	}
}
