#include <stdio.h>

main()
{
	int n, i, j;
	char c;
	printf("Introd. um No.: "); scanf(" %d", &n);
	printf("Introd. um Char: "); scanf(" %c", &c);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%c", c);
		printf("\n");
	}
}
