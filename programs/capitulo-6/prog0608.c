/*
Escreva um programa que declare um vetor n=10 numeros reais e coloque na i-esima posicao o resultado de i*(n-1)
*/

#include <stdio.h>
#define DIM 10
int main()
{
	int i; int v[DIM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for (i=0; i<DIM; i++)
	{
		v[i] = i*(DIM-i);
		printf("%d\n", v[i]);
	}
}
