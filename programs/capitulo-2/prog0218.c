#include <stdio.h>

main()
{
	long int segundos;
	printf("Segundos: ");
	scanf("%ld", &segundos);
	printf("Hora(s): %ld\n", segundos/3600);
	printf("Minutos(s): %ld\n", segundos%3600 / 60);
	printf("Segundos(s): %ld\n", segundos%60);
}
