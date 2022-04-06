#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char a, b, c;

	a = getchar();
	__fpurge(stdin);
	b = getchar();
	__fpurge(stdin);
	c = getchar();
	__fpurge(stdin);

	printf("%c %c %c\n", a, b, c);
}
