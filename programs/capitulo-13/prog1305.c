#include <stdio.h>

#define DEBUG

void main()
{
	int i, n = 0;

	#undef DEBUG

	#ifndef DEBUG
		puts("Debug: desativado");
	#endif

	for (i=1; i<10; i++)
	{
		n += i;

		#ifdef DEBUG
			printf("DEBUG Info: i=%d n=%d\n", i, n);
		#endif
	}
	printf("Resultado: %d\n", n);
}
