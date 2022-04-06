#include <stdio.h>
#define MAX 3


// Exercícios de Exame

// 2.
float max(float v[], int n)
{
	float n_max;
	int i;

	for (i = 1, n_max = v[0]; i < n; i++)
		if (n_max < v[i]) n_max = v[i];

	return n_max;
}

// 3.
void transpor(int v[MAX][MAX])
{
	int i, j, v_auxiliar[MAX][MAX];

	for (i=0; i<MAX; i++)
		for (j=0; j<MAX; j++)
			v_auxiliar[i][j] = v[j][i];

	for(i=0; i<MAX; i++)
		for (j=0; j<MAX; j++)
			v[i][j] = v_auxiliar[i][j];
}

// 5.
char * memcpy(char *dest, char *orig, int n)
{
	int i;

	for (i=0; i<n; i++)
		dest[i] = orig[i];

	return dest;
}

// 6.
int memcmp(char *s1, char *s2, int n)
{
	int i;

	for (i=0; i<n; i++)
		if (s1[i] != s2[i]) return 0;

	return 1;
}

// 7.
int memicmp(char *s1, char *s2, int n)
{
	int i;
	char c1, c2;

	for (i=0; i<n; i++)
	{
		if (s1[i]>='A' && s1[i]<='Z')
			c1 = s1[i]-'A' + 'a';
		else
			c1 = s1[i];

        if (s2[i]>='A' && s2[i]<='Z')
            c2 = s2[i]-'A' + 'a';
        else
            c2 = s2[i];

		if (c1 != c2) return 0;
	}
	
	return 1;
}

void main()
{
	char x[3] = { 'a', 'b', 'c' };
	char y[3] = { 'a', 'b', 'c' };

	printf("%d\n", memicmp(x, y, 2));
}
