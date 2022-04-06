#include <stdio.h>

float pot(float x, int n)
{	

	int i, resultado = 1.0;
	for (i = 1; i <= n; i++)
		resultado *= x;

	return resultado;
}

void main()
{
	printf("%f %f %f\n", pot(2.0, 4), pot(1.234, 3), pot(3.0, 0));
}
