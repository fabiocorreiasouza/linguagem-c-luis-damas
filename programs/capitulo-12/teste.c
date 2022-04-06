#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void * my_calloc(size_t num, size_t size)
{
	void * tmp;
	tmp = malloc(num*size);
	if (tmp != NULL)
		memset(tmp, '\0', num*size);
	return tmp;
}

char * my_strdup(char * s)
{
	char * tmp = (char *) malloc(strlen(s) + 1);
	if (tmp != NULL) strcpy(tmp, s);
	return tmp;
}

char * Ascii_Create(int n, char inic)
{
	int i; char * str;

	str = (char *) malloc(n + 1);
	if (str == NULL) return str;

	for (i=0; i<n; i++)
		*(str + i) = inic + i;
	*(str + i) = '\0';

	return str;
}

void main()
{
	char * str = Ascii_Create(3, 'A');
	puts(str);
}
