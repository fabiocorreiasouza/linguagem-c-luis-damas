#include <stdio.h>
#include <ctype.h>
#include <math.h>
int strlen(char *s) /* String Length */
{
	int i = 0;
	while (s[i]!='\0') i++;

	return i;
}

int isnull(char *s) /* Esta função não faz parte da linguagem */
{
	return s[0] == '\0';
}

char * strcpy(char *dest, char *orig) /* String Copy */
{
	int i = 0;
	while (dest[i] = orig[i]) i++;

	return dest;
}

char * strcat(char *dest, char *orig)
{
	int i, j;
	i=j=0;

	while (dest[i] != '\0') i++;

	while (dest[i+j] = orig[j]) j++;

	return dest;
}

int strcountc(char *s, char ch) /* String Count Char */
{
	int i, count;
	for (i=count=0; s[i]!='\0'; i++)
		if (s[i] == ch) count++;

	return count;
}

int strcountd(int *s) /* String Count Digits */
{
	int i, count;
	for (i=count=0; s[i]!='\0'; i++)
		if (s[i]>='0' && s[i]<='9') count++;

	return count;
}

int indchr(char *s, char ch)
{
	int i;
	for (i=0; s[i]!='\0'; i++)
		if (s[i] == ch) return i;

	return -1;
}

int strpal(char *s)
{
	int i, j;

	for (j=0; s[j]!='\0'; j++)
		;
	j--;

	for (i=0; i<j; i++, j--)
		if (s[i] != s[j]) return 0;

	return 1;
}

char * strrev(char *s) /* String Reverse  */
{
	int i, j, aux;

	for (j=0; s[j]!='\0'; j++) ;
	j--;

	for (i=0; i<j; i++,j--)
	{
		aux  = s[i];
		s[i] = s[j];
		s[j] = aux;
	}
	return s;
}

int strcmp(char *s1, char *s2)
{
	int i;

	for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++)
	{
		if (s1[i] > s2[i])
			return 1;
		else if (s1[i] < s2[i])
			return -1;
	}
	if (s1[i] > s2[i])
		return 1;
	else if (s1[i] < s2[i])
		return -1;
	else
		return 0;
}

int strcmp2(char *s1, char *s2)
{
    int i = 0;
    while (s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0') i++;

	if (s1[i] > s2[i])
		return 1;
	else if (s1[i] < s2[i])
		return -1;
	else
		return 0;
}

char * strpad(char *s)
{
	int i, j, lenAUX = strlen(s) * 2;
	char aux[lenAUX + 1];

	for (i=0; i<lenAUX; i++)
		aux[i] = ' ';
	aux[i] = '\0';

	for (i=j=0; s[i]!='\0'; i++, j+=2)
		aux[j] = s[i];

	return strcpy(s, aux);
}

char * strdelc(char *s, char ch) /* String Delete Char */
{
	int i, j;

	for (i=0; s[i]!='\0'; i++)
		if (s[i] == ch)
		{
			for (j=i; s[j]!='\0'; j++)
				s[j] = s[j+1];
			i--;
		}
	return s;
}

/* Função mygets(): implementação pessoal da função gets() */

char * mygets(char *s)
{
	int i = 0;
	while ((s[i]=getchar()) != '\n')
		i++;
	s[i] = '\0';

	return s;
}
/* Função strset(): altera as posições da string com um dado caractere */

char * strset(char *s, char ch)
{
	int i = 0;
	while (s[i] != '\0')
		s[i++] = ch;

	return s;
}

char * strupr(char *s)
{
	int i;
	for (i=0; s[i]!='\0'; i++)
		if (s[i]>='a' && s[i]<='z')
			s[i] = s[i]-'a' + 'A';

	return s;
}

/* -------------------- */
/* Exercícios Propostos */
/* -------------------- */

// 2.1
int strcounta(char *s)
{
	int i, count;

	i = count = 0;
	while(s[i] != '\0')
	{
		if (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') /* ou isalpha() */
			count++;
		i++;
	}
	return count;
}

// 2.2
char * init_str(char *s)
{
	s[0] = '\0';
	return s;
}

// 2.3
int ult_ind_chr(char *s, char ch)
{
	int i, ult_indice;
	for (i=0, ult_indice=-1; s[i]!='\0'; i++)
		if (s[i] == ch)
			ult_indice = i;

	return ult_indice;
}

// 2.4
char * strlwr(char *str)
{
	int i;

	for (i=0; str[i]!='\0'; i++)
		if (str[i]>='A' && str[i]<='Z')
			str[i] = str[i]-'A' + 'a';

	return str;
}

// 2.5
char * strnset(char *s, char ch, int n)
{
	int i;

	for (i=0; s[i]!='\0' && i<n; i++)
		s[i] = ch;

	return s;
}

// 2.6
int stricmp(char *s1, char *s2)
{
	int i = 0;
	while ((s1[i]-'A' + 'a' == s2[i] ||			/* Testa a igualdade de caracteres	 e */
			s1[i]-'a' + 'A' == s2[i] ||			/* ignora a diferença entre maiúsculos */
			s1[i] == s2[i]) && s1[i] != '\0')	/* e minúsculos.					   */
		i++;

	return s1[i] - s2[i];
}

// 3.1
char * repeticoes(char *s)
{
	int i, j, f, count;

	for (i=0; s[i]!='\0'; i++)
	{
		for (j=i+1, count=1; j!=i; j++)
		{
			if (s[j] == s[i]) count++;
			if (s[j]=='\0') j = -1;
		}

		if (count < 2)
		{
			for (f=i; s[f]!='\0'; f++)
				s[f] = s[f+1];
			i--;
		}
	}

	return s;
}
// 3.1b
char * repeticoes2(char *s)
{
	int i;

	for (i=0; s[i]!='\0'; i++)
		if (strcountc(s, s[i]) == 1)
		{
			strdelc(s, s[i]);
			i--;
		}
	return s;
}
// 3.1c
char * repeticoes3(char *s)
{
	int i, j;
	for (i=j=0; s[i]!='\0'; i++)
		if (strcountc(s, s[i]) > 1)
			s[j++] = s[i];
	s[j] = '\0';

	return s;
}

// 3.2
char n_esimo(char *s, int n)
{
	return s[n-1];
}

// 3.3
char * strpack(char *s)
{
	int i, j;
	for (i=j=0; s[j]!='\0'; j++)
		if (s[i] != s[j])
			s[++i] = s[j];
	s[++i] = s[j];

	return s;
}

// 3.4
char * Entremeado(char *s, int n)
{
	int i, j;

	i=j=0;
	while (s[j] != '\0')
	{
		if (j % (n+1) == 0)
			s[i++] = s[j];
		j++;
	}
	s[i] = s[j];

	return s;
}

// 3.5
char * xspace(char *s)
{
	int i, j;
	for (i=0, j=strlen(s); s[i]!='\0'; i++)
		if (s[i]!=' ')
		{
			while(i<j)
			{
				s[j+1] = s[j];
				j--;
			}
			s[i+1] = ' ';
			j=strlen(s);
		}
	return s;
}

// 3.6
char Max_Ascii(char *str)
{
	int i;
	char ch = '\0';
	for (i=0; str[i]!='\0'; i++)
		if (str[i] > ch) ch = str[i];

	return ch; 
}

// 3.7
char * Prox_Char(char *s)
{
	int i=0;
	while (s[i]!='\0')
		s[i++] = s[i] + 1;

	return s;
}

// 3.8
// A função anterior pode ocasionar estouro, caso o último caractere válido
// seja o último da tabela Ascii

// 3.9
char * UpDown(char *s)
{
	int i;
	for (i=0; s[i]!='\0'; i++)
		s[i] = (i%2 == 0) ? toupper(s[i]) : tolower(s[i]);

	return s;
}

// 3.10
char *allspaces(char *s)
{
	int i;
	for (i=0; s[i]!='\0'; i++)
		s[i] = ' ';
	return s;
}

// 3.11
char *strijset(char *s, int i, int j, char ch)
{
	while (i <= j)
		s[i++] = ch;
	return s;
}

// 3.12
char *strduplicar(char *s)
{
	int i, j, DIM = strlen(s);

	for (i=DIM, j=2*DIM; 0<=i; i--, j--)
		s[j] = s[i];
	return s;
}

//
int pow2 (int b, int e)
{
	int i=1;

	if (e == 0) return 1;

	while (i++ < e)
		b *= b;

	return b;
}

//


// 3.13
int atoi(char *s)
{
	int i = 0, numero = 0, exp = 0;

	while (s[i]>='0' && s[i]<='9' || s[i]=='-' || s[i]=='+')
		i++;
	i--;

	while (i > 0)
		numero += (s[i--]-'0') * (pow2(10, exp++));

	if (s[0]>='0' && s[0]<='9')
		numero += (s[0]-'0') * (pow2(10, exp));
	else if (s[0] == '-')
		numero *= (-1);

	return numero;
}

// 3.14
char *wordupr(char *s)
{
	int i;
	for (i=0; s[i]!='\0'; i++)
		s[i] = (i==0 || s[i-1]==' ') ? toupper(s[i]) : tolower(s[i]);

	return s;
}

// 3.15
char *lower_upper(char *s)
{
    int i, j;
    char aux;
    for (j=0; s[j]!='\0'; j++)
	{
		if (s[j]>='A' && s[j]<='Z') continue;

		i = j;
		while (0 < i)
		{
			if (s[i-1]>='a' && s[i-1]<='z') break;
			aux    = s[i-1];
			s[i-1] = s[i];
			s[i]   = aux;
			i--;
		}
	}
    return s;
}

// 3.16
char *All_Big(char *s)
{
	int i, j;
	for (i=0; s[i]!='\0'; i++)
	{
		if (s[i]>='A' && s[i]<='Z') continue;

		j = i;
		while (s[j] != '\0')
			s[j++] = s[j+1];

		if (s[i]>='a' && s[i]<='z') i--;
	}
	return s;
}

// 3.17
int Is_Len_OK(char *string, int comprimento)
{
	return strlen(string) == comprimento;
}

// 3.18
int Is_Alfa_Digit(char *string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (i%2 == 0 && isdigit(string[i]) || i%2 != 0 && isalpha(string[i]))
			return 0;
		i++;
	}
	return 1;		
}

// 3.19
char *Transform(char *s)
{
	int i, qtd_minusc = (int) ((float) strlen(s) / 2);

	for (i=0; s[i]!='\0'; i++)
		s[i] = (i < qtd_minusc) ? tolower(s[i]) : toupper(s[i]);

	return s;
}



// 4 (EXERCÍCIO FINAL DO CAPÍTULO)
void main()
{
	char nome_completo[60], nome[20], sobrenome[40];
	int count, i, j, ult_ind;

	while (1)
	{
		puts("Nome completo: "); mygets(nome_completo);

		if (!strcmp(strupr(nome_completo), "SAIR")) break;

		wordupr(nome_completo);

		ult_ind = ult_ind_chr(nome_completo, ' ');

		count=i=j=0;
		while (nome_completo[count] != '\0')
			if (count < ult_ind)
				nome[i++] = nome_completo[count++];
			else if (count == ult_ind)
                count++;
			else if (count > ult_ind)
				sobrenome[j++] = nome_completo[count++];
		nome[i] = sobrenome[j] = '\0';

		printf("\"%s, %s\"\n", sobrenome, nome);
	}
}
