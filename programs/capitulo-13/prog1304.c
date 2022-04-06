#include <stdio.h>

#define DEBUG

void main()
{
	int i, n = 0;

	for (i=1; i<10; i++)
	{
		n += i;
		#ifdef DEBUG
		printf("DEBUG Info: i=%d n=%d\n", i, n);
		#endif
	}
	printf("Resultado: %d\n", n);
}
