#include <stdio.h>
// onde fica armazenado o valor de um vetor v, isto é, &v[0] ?

void main(void)
{
	char ch[4] = { 'a', 'b', 'c' };

	printf("%d\n", ch==&ch[0]);
}
