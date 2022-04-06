#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
	unsigned int N;
	char Nome[40+1];
} REGISTRO;

typedef struct
{
	REGISTRO v[MAX];
	int Conta;
} LISTA;

void Inic(LISTA * ptr)
{
	(*ptr).Conta = 0;
}

int Cheia(LISTA L)
{
	return L.Conta == MAX;
}

int Inserir(LISTA * ptr, REGISTRO r)
{
	if (Cheia(*ptr))
		return -1;
	(*ptr).v[(*ptr).Conta] = r;
	return (*ptr).Conta++;
}

int Save(LISTA L, char * Nome_Arq)
{
	int i;
	FILE * fp;

	if ((fp = fopen(Nome_Arq, "wb")) == NULL) return 0;
	for (i=0; i<L.Conta; i++)
		if (fwrite(&L.v[i], sizeof(REGISTRO), 1, fp) != 1) return 0;
	fclose(fp);
	return 1;
}

int Load(LISTA * L, FILE * fp)
{
	REGISTRO R;
	rewind(fp); // Ir para o princípio do arquivo
	while(fread(&R, sizeof(REGISTRO), 1, fp) == 1)
		if (Inserir(L, R) == -1) return -1;
	return 0;
}

void Listar(LISTA L)
{
	int i;
	for (i=0; i<L.Conta; i++)
		printf("%d %s\n", L.v[i].N, L.v[i].Nome);
}

void main()
{
	int i;
	LISTA Lista;

	REGISTRO R = { 100, "LUIS" };
	Inic(&Lista);
	Listar(Lista);
	for (i=0; i<=MAX; i++)
	{
		R.N = i;
		Inserir(&Lista, R);
	}
	Listar(Lista);
}
