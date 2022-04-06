#include <stdio.h>

main()
{
	int nHoras;
	long nSegundos; // pode ser muito grande
	printf("No. de horas: "); scanf("%d", &nHoras);
	nSegundos = nHoras<0 ? 0 : (long) nHoras*3600; // ou 3600L, em que L é casting para "long", apenas em constantes
	printf("%d hora(s) tem %ld segundos\n", nHoras, nSegundos);
}
