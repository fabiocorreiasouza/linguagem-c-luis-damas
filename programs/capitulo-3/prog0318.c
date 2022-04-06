#include <stdio.h>



main()
{
	int nHoras;
	long resultado;
	char unidadeMedida;

	printf("No. de horas: ");
	scanf("%d", &nHoras);
	printf("O que mostrar (m/s/d): ");
	scanf(" %c", &unidadeMedida);

	if (unidadeMedida == 'm' || unidadeMedida == 'M')
		resultado = nHoras<0 ? 0 : (long) nHoras*60;
	else
		if (unidadeMedida == 's' || unidadeMedida == 'S')
			resultado = nHoras<0 ? 0 : (long) nHoras*3600;
		else
			if (unidadeMedida == 'd' || unidadeMedida == 'D')
				resultado = nHoras<0 ? 0 : (long) nHoras*36000;

	printf("%dh --> %ld%c\n", nHoras, resultado, unidadeMedida);
}















/*
main()
{
        int nHoras;
        long nMinutos, nSegundos, nDecimosDeSegundo; // pode ser muito grande

        printf("No. de horas: "); scanf("%d", &nHoras);

	if (nHoras >= 0)
	{
        	nMinutos = (long) nHoras*60; // ou 60L, em que L é cas>
		nSegundos = nMinutos * 60;
		nDecimosDeSegundo = nSegundos * 10;

        	printf("%d hora(s) = %ld minutos = %ld segundos = %ld décimos de segundo\n",
			nHoras, nMinutos, nSegundos, nDecimosDeSegundo);
	}
	else
		printf("Insira um valor válido.\n");
}
*/
