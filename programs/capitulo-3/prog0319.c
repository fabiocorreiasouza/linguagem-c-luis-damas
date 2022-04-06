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

        switch (unidadeMedida)
	{
		case 'm':
		case 'M':
                	resultado = nHoras<0 ? 0 : (long) nHoras*60;
			break;
		case 's':
		case 'S':
			resultado = nHoras<0 ? 0 : (long) nHoras*3600;
			break;
		case 'd':
	        case 'D':
			resultado = nHoras<0 ? 0 : (long) nHoras*36000;
			break;
	}

	printf("%dh --> %ld%c\n", nHoras, resultado, unidadeMedida);
}
