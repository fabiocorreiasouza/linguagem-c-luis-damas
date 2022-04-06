#include <stdio.h>

main()
{
	int numero, i, j;

	puts("Introd. um No.: "); scanf(" %d", &numero);
	for (i=1, j=numero; i<=numero; i++, j--)
		printf("%2d %2d\n", i, j);
}
