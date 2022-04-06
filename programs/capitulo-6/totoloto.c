#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMS 49			/* Total de No.s do Jogo */
#define MIN_APOSTA 6	/* Aposta Minima -> 6 No.s */
#define NUM_LIN 7		/* No.s de no.s apresentados por linha no volante */

/* Declaração das funções */
void Inic_Random();
void Inic(int v[NUMS]);
int Ler_Ns_Apostar();
void Gerar(int *v, int n);
void Apresentar(int res[]);

/*
Iniciar o gerador de no.s aleatórios com um no. que depende
da hora que se executa a função
*/
void Inic_Random()
{
	long ultime;
	time(&ultime);
	srand((unsigned) ultime);
}

/* Inic. com ZERO o vetor de controle dos no.s selecionados */
void Inic(int v[])
{
	int i;

	for (i = 0; i < NUMS; i++)
		v[i] = 0;
}

/*
Lê o no. de números a apostar. Aceita valores entre MIN_APOSTA e NUMS.
Aceita o valor ZERO para indicar que se quer terminar o programa.
*/
int Ler_Ns_Apostar()
{
	int n;

	do
	{
		printf("Quantos no.s quer apostar(0 -> terminar): ");
		scanf("%d", &n);
	}
	while ((n<MIN_APOSTA || n>NUMS) && n!=0);

	return n;
}

/*
Gera n números aleatórios e coloca a respectiva posição do vetor
com o valor 1 que indica que esse no. foi selecionado
*/
void Gerar(int *v, int n)
{
	int i, indice;

	for (i=1; i<=n; i++)
	{
		indice = rand() % NUMS; /* Devolve o no. aleatório entre 0 e NUMS-1 */
		if (v[indice] == 0)		/* Não foi selecionado */
			v[indice] = 1;
		else		/* Este no. já tinha sido selecionado, */
			i--;	/* logo decrementa-se o contador para voltar a */
	}				/* calcular mais uma vez o i-ésimo no. aleatório */
}

/*
Apresenta o formato do volante colocando XX nos no.s
selecionados para a aposta
*/
void Apresentar(int res[])
{
	int i;

	for (i=0; i<NUMS; i++)
	{
		if (res[i]==0)
			printf(" %2d", i+1);
		else
			printf(" XX");
		
		if ((i+1) % NUM_LIN == 0) putchar('\n');
	}
	putchar('\n');
}

void main()
{
	int vetor[NUMS];
	int n_nums;			/* No. de números para jogar no jogo 6..49 */

	Inic_Random();
	while(1)
	{
		Inic(vetor);
		if ((n_nums = Ler_Ns_Apostar()) == 0) break;
		Gerar(vetor, n_nums); /* Gerar os no.s a apostar */
		Apresentar(vetor);
	}
}
