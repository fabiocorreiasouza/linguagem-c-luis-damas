#include <stdio.h>

char * strchr(char * s, char ch)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch) return &s[i];
		i++;
	}
	return NULL;
}

void main()
{
	char s[100], c;

	puts("Introduza uma string: "); gets(s);
	puts("Introduza um char: "); scanf(" %c", &c);

	printf("%s\n", strchr(s, c));
}
