#include <stdio.h>
#include <string.h>

void Down(int n)
{
	printf("%d ", n--);
	if (n == 0)
	{
		putchar('\n');
		return;	
	}
	Down(n);
}

int rec_strlen(char *s)
{
	if (*s == '\0')
		return 0;
	else
		return 1 + rec_strlen(s+1);
}

int rec_strcmp(char * s1, char * s2)
{
	if (*s1 == *s2 && *s1 != '\0')
		return rec_strcmp(s1+1, s2+1);
	else
		return *s1 - *s2;
}
int rec_strcmp2(char * s1, char * s2)
{
	if (*s1=='\0' || *s2=='\0' || *s1!=*s2)
		return *s1 - *s2;
    else
        return rec_strcmp2(s1+1, s2+1);
}

float Pot(float x, int n)
{
	if (n == 0)
		return 1.0;
	else
		return x * Pot(x, n-1);
}

float Exp(float x, int n, int t)
{
	if (n == 0)
		return 0;
	else
		return x/Pot((1+t), n) + Exp(x, n-1, t);
}

void Puts(char *s)
{
	if (*s == '\0')
		putchar('\n');
	else
	{
		putchar(*s);
		Puts(s+1);
	}
}

/*
 * Exercícios Propostos
 */

int iszero(int n)
{
	return n == 0;
}

void add1(int * ptr_n)
{
	(*ptr_n)++;
}

void zero(int * ptr_n)
{
	*ptr_n = 0;
}

int Ler_Inteiro(char * prompt)
{
	int n;
	printf("%s", prompt);
	scanf("%d", &n);
	if (n < 0)
		Ler_Inteiro(prompt);
	else
		return n;
}

void Ler_Inteiro2(char * prompt, int * ptr_n)
{
    do
	{
		puts(prompt);
		scanf("%d", ptr_n);
	}
	while (*ptr_n < 0);
}

long int Fib_ite(int n)
{
	int a, b, res;

	if (n < 0) return (long) -1;
	if (n < 2) return (long) 1;

	a = b = 1;
	res = 0;
	while(n-- >= 2)
	{
		res = a + b;
		b   = a;
		a   = res;
	}
	return res;
}

long int Fib_rec(int n)
{
	if (n < 0) return (long) -1;
	if (n < 2)
		return (long) 1;
	else
		return Fib_rec(n-1) + Fib_rec(n-2);
}

char * rec_strcat(char * dest, char * orig)
{
	if (*orig == '\0')
		return dest;
	else
	{
		*(dest + strlen(dest) + 1) = '\0';
		*(dest + strlen(dest)) = *orig;
		return rec_strcat(dest, orig+1);
	}
}

char * rec_strcat2(char * dest, char * orig)
{
	if (*dest == '\0')
		return strcpy(dest, orig);
	return rec_strcat2(dest+1, orig) - 1;
}

char * rec_strchr(char * str, char ch)
{
	if (*str == '\0') return NULL;
	if (*str == ch)
		return str;
	else
		return strchr(str+1, ch);
}

double Exp2(int a, int n)
{
	int i = 1, res = 0;

	if (n < 1) return (double) -1;

	while (i <= n)
	{
		res += Pot(a+(double)i/n, 2);
		i++;
	}
	return res;
}

void main(int argc, char  * argv[], char * arga[])
{
	int i, j;
	for (i=0; arga[i]!=NULL; i++)
	{
		j=0;
		while (arga[i][j++] != '=')
		;
		puts(&arga[i][j]);
	}
}
