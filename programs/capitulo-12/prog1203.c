#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char * str;

	// Cria a string str
	str = (char *) malloc(10);

	// Coloca "Maria" na string str
	strcpy(str, "Maria");

	printf("String: %s\nEndereço: %p\n", str, str);
	str = (char *) realloc(str, 100);
	printf("String: %s\nEndereço: %p\n", str, str);

	// Liberar memória
	free(str);

	exit(EXIT_SUCCESS);
}
