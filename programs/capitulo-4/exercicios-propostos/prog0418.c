#include <stdio.h>

main()
{
	int numero;

	printf("Introd. um No.: "); scanf("%d", &numero);
	while (numero%10 != 0)
	{
		/*if (numero%10 == 0) break;*/
		if (numero%3 != 0) printf("%d\n", numero);
		numero++;
	}
}
