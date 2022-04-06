#include <stdio.h>

char x_toupper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - 'a' + 'A';
	else
		return ch;
}

main()
{
	char c;
	while (1)
	{
		c = getchar();
		putchar(x_toupper(c));
	}
}
