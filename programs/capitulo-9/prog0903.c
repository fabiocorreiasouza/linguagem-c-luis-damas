#include <stdio.h>

void Calc(float * v, int num, float * xmin, float * xmax)
{
	int i;
	*xmin = *xmax = *v;

	for (i=0; i<num; i++)
	{
		if (v[i] < *xmin) *xmin = v[i];
		if (v[i] > *xmax) *xmax = v[i];
	}
}

void main()
{
	float Vetor[] = { 10, 20, 30, 40, 50, 11, 12, 5, -33 };
	float Maior, Menor;

	Calc(Vetor, 9, &Menor, &Maior);

	printf("Maior Elemento %f\nMenor Elemento %f\n", Maior, Menor);
}
