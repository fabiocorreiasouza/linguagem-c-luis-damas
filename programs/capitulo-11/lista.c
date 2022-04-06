#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define ARQ "datalist.dat"
#define MAX 10

#define INSERIR  '1'
#define SALVAR   '2'
#define CARREGAR '3'
#define LISTAR   '4'
#define SAIR     '0'

char * menu_op[] =
{
	"1. Inserir",
	"2. Salvar",
	"3. Carregar",
	"4. Listar",
	"0. Sair",
	NULL
};

// Mostra o menu de opções recebidos como parâmetro e
// retorna a opção escolhida.

char mostrar_menu(char * opcoes[])
{
	int i;
	char opcao;

	printf("\n\n\n\n\n\n\n\n\n\n");
	for (i=0; opcoes[i]!=NULL; i++)
		printf("\t\t%s\n", opcoes[i]);
	printf("\n\n\t\tOpção: ");
	opcao = getchar();
	getchar(); // Limpa o buffer

	for (i=0; opcoes[i]!=NULL; i++)
		if (opcoes[i][0] == opcao)
			return opcao;

	return SAIR;
}

struct registro
{
	char nome[40];
	int numero;
};
typedef struct registro LISTA;

LISTA lista[MAX];

FILE * fp;

// Tenta ler o arquivo de dados (r+b). Se não existir, cria um novo (w+b).

void inic()
{
	if ((fp = fopen(ARQ, "r+b")) == NULL)
		if ((fp = fopen(ARQ, "w+b")) == NULL)
		{
			fprintf(stderr, "ERRO FATAL: Impossível criar arquivo de dados!");
			exit(EXIT_FAILURE);
		}
}

// Adiciona dados de registro em um vetor do tipo LISTA e
// retorna o a posição do vetor na qual os dados foram inseridos. Caso
// o vetor tiver atingido seu tamanho máximo (MAX), retorna -1.

int inserir(LISTA * p)
{
	int dim=0;

	while ((*p).nome[0] != '\0')
	{
		p++;
		dim++;
	}

	if (dim < MAX)
	{
		printf("Nome: ");
		gets((*p).nome);
		printf("Número inteiro: ");
		scanf(" %d", &(*p).numero);
		getchar(); // Limpar buffer
		return dim;
	}
	else
		return -1;
}

// Escreve no disco rígido todos os registros existentes no vetor lista. Caso
// ocorra um problema, retorna 0; senão, retorna 1.

int salvar(LISTA * p)
{
	fseek(fp, 0L, SEEK_END);
	for ( ; (*p).nome[0] != '\0'; p++)
		if (fwrite(p, sizeof(LISTA), 1, fp)  != 1)
			return 0;
	return 1;
}

// Lê todos os registros existentes no disco rígido e os insere no vetor lista. Se
// ocorrer um problema, retorna 0; senão, retorna 1.

int carregar(LISTA * p)
{
	int i;

	fseek(fp, 0L, SEEK_SET);
	for (i=0; i<MAX; i++)
		if (fread(&p[i], sizeof(LISTA), 1, fp)  != 1)
			return 0;
	return 1;
}

// Lista todos os registros existentes no vetor lista.

void listar(LISTA * p)
{
	int i;
    int dim;
/*  LISTA * p2 = p;

    while ((*p2).nome[0] != '\0') p2++;
    dim = (p2 - p) / sizeof(LISTA);

	printf("DIM: %d\n", dim);
	for (i=0; i<dim; i++)
	{
		printf("%d: ", i+1);
		printf("%-30s %d\n", p[i].nome, p[i].numero);
	}
*/
	i=0;
	while((*p).nome[0] != '\0')
	{
		printf("%d: ", i+1);
		printf("%-30s %d\n", (*p).nome, (*p).numero);
		p++; i++;
	}
}

void main()
{
	char opcao;
	int teste;

	inic();

	while(1)
	{
		opcao = mostrar_menu(menu_op);
		if (opcao == SAIR) break;
		switch (opcao)
		{
			case INSERIR:  inserir(lista); break;
			case SALVAR:   salvar(lista); break;
			case CARREGAR: carregar(lista); break;
			case LISTAR:   listar(lista); break;
		}
	}

	fclose(fp);
	exit(EXIT_SUCCESS);
}
