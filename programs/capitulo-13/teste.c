#include <stdio.h>
#include <assert.h>

#define max(a, b) (((a)>(b)) ? (a) : (b))

#define min(a, b) (((a)<(b)) ? (a) : (b))

#define abs(x) (((x) > 0) ? (x) : -(x))

#define super(a, b, c) max(max(abs(a-b), abs(b-c)), abs(a-c))


void inc_idade(int *ptr_idade)
{
	assert(ptr_idade != NULL);
	assert(*ptr_idade >= 0);
	(*ptr_idade)++;
}

void main()
{
	int x = 5;
	inc_idade(&x);
	x = -5;
	inc_idade(&x);
	inc_idade(NULL);
}
