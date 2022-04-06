#include <stdio.h>

long Qtos_Reais(FILE * fp)
{
	long n_floats, pos_antiga;

	pos_antiga = ftell(fp); // Posição corrente

	fseek(fp, (long) 0*sizeof(float), SEEK_END);

	n_float = ftell(fp) / sizeof(float);

	fseek(fp, (long) pos_antiga, SEEK_SET); // Repor estado inicial

	return n_floats;
}

void main()
{
	// Algum código aqui
}
