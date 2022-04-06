#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * repete(char * string, int n)
{
	int i;
	char * tmp = (char *) malloc(n*(strlen(string) + 1));
	if (tmp == NULL) return tmp;

	tmp[0] = '\0'; i = 0;
	while (++i <= n)
	{
		strcat(tmp, string);
		if (i != n) strcat(tmp, " ");
	}

	return tmp;
}

char * metade(char * s)
{
	int i;
	size_t len = strlen(s)/2;
	char * tmp = (char *) malloc(len + 1);
	if (tmp == NULL) return tmp;

	for (i=0, tmp[0]='\0'; i<len; i++)
		tmp[i] = s[i];
	tmp[i] = '\0';
	
	return tmp;	
}

char * inverte(char * s)
{
	int i, j;
	char * new_str = (char *) malloc(strlen(s) + 1);
	if (new_str == NULL) return new_str;
	strcpy(new_str, s)
	strrev(new_str);

	return new_str;
}

void main()
{
	char s[] = "Fabio";
	printf("%s\n", inverte(s));
}
