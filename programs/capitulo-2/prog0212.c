#include <stdio.h>
/*
main()
{
	char ch1, ch2;
	printf("Introduza um caractere: ");
	scanf("%c", &ch1);
	printf("Introduza outro caractere: ");
	scanf("%c", &ch2); // Pegará indevidamente o 'Enter' no buffer
	printf("Os caracteres introduzidos foram '%c' e '%c'\n", ch1, ch2);
}
*/

main()
{
        char ch1, ch2;
        printf("Introduza um caractere: ");
        scanf("%c", &ch1);
        printf("Introduza outro caractere: ");
	// NÃO pegará indevidamente o \n no buffer
	// O espaço em branco da formatação faz scanf ignorar \n, \t e ' ' no buffer
	scanf(" %c", &ch2);
        printf("Os caracteres introduzidos foram '%c' e '%c'\n", ch1, ch2);
}
