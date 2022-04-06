#include <stdio.h>

void main()
{
	printf("Estou na linha %d\n", __LINE__);

	#line 8000
	printf("Estou na linha %d\n", __LINE__);
}
