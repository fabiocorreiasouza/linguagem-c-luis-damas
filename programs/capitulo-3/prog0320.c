#include <stdio.h>

/*
Utilizei o switch, sem susar break
*/
main()
{
        int nHoras;
        long resultado;
        char unidadeMedida;

        printf("No. de horas: ");
        scanf("%d", &nHoras);
        printf("O que mostrar (m/s/d): ");
        scanf(" %c", &unidadeMedida);
	resultado = (long) nHoras;

        switch (unidadeMedida)
        {
                case 'd':
                case 'D':
                        resultado *= 10;
                case 's':
                case 'S':
                        resultado *= 60;
                case 'm':
                case 'M':
                        resultado *= 60;
        }

        printf("%dh --> %ld%c\n", nHoras, resultado, unidadeMedida);
}
