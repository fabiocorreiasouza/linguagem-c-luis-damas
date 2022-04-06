/*
Exercicios propostos | capitulo 5
*/
#include <stdio.h>

int Abs(int x)
{
    if (x >= 0)
		return x;
    else
		return x *= (-1);
}

int Pot(int base, int exp)
{
	int i, resultado;
	for(i = 1, resultado = 1; i <= exp; i++)
		resultado *= base;
	return resultado;
}

long int nSegundos(int nHoras)
{
	return nHoras * 3600;
}

long int num1(int nHoras, char unidadeMedida)	/* 7. [Exercício de Exame] */
{
	if      (unidadeMedida == 'h') return nHoras;
	else if (unidadeMedida == 'm') return nHoras*60;
	else if (unidadeMedida == 's') return nHoras*3600;
}

long int num2(int nHoras, char unidadeMedida)   /* 7. [Exercício de Exame] */
{
    switch(unidadeMedida)
	{	
		case 'h':
			return nHoras;
			break;
		case 'm':
			return nHoras*60;
			break;
		case 's':
			return nHoras*3600;
	}
}

long int num3(int nHoras, char unidadeMedida)   /* 7. [Exercício de Exame] */
{
    switch(unidadeMedida)
    {
        case 's':
			nHoras *= 60;
        case 'm':
            nHoras *= 60;
        case 'h':
            return nHoras;
    }
}

float max(float x, float y, float w)	/* 8. [Exercício de Exame] */
{
	float maxValor = x;
	
	if (y > maxValor) maxValor = y;
	if (w > maxValor) maxValor = w;
	
	return maxValor;
}

int impar(int x)	/* 9. [Exercício de Exame] */
{
	return x % 2 != 0;
}

int entre(int x, int limInferior, int limSuperior)
{
	return x >= limInferior && x <= limSuperior;
}

/* 11 */
int isdigit(char c)	/* 11.1 */
{
	return c >= '0' && c <= '9';
}

int isalpha(char c) /* 11.2 */
{
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int isalnum(char c) /* 11.3 */
{
	return c>= 0  && c<= 9	||
		   c>='0' && c<='9' ||
		   c>='a' && c<='z' ||
		   c>='A' && c<='Z';
}

int  islower(char c) /* 11.4 */
{
	return c>='a' && c<='z';
}

int isupper(char c) /* 11.5 */
{
	return c>='A' && c<='Z';
}

int isspace(char c) /* 11.6 */
{
	return c==' ' || c=='\t';
}

char tolower(char c) /* 11.7 */
{
	if (c>='a' && c<='z')
		return c;
	else
		return c - 'A' + 'a';
}

char toupper(char c) /* 11.8 */
{
	if (c>='A' && c<='Z')
		return c;
	else
		return c - 'a' + 'A';
}

int is_square(int x, int y) /* 12 */
{
	return x == y*y;
}

int minus(int x) /* 13 */
{
	if (x <= 0)
		return x;
	else
		return -x;
}

int is_special(int x) /* 14 */
{
	return 2*x == x*x;
}

int cubo(int x) /* 15 */
{
	return x*x*x;
}

int isVogal(char c) /* 16 */
{
	if (c>='A' && c<='Z')
		c = c - 'A' + 'a';

	return c=='a' ||
		   c=='e' ||
		   c=='i' ||
		   c=='o' ||
		   c=='u';
}

void main()
{
	printf("%d\n", isdigit('5'));
}
