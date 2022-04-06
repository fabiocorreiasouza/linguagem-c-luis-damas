#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 3.
// Retorna o endereço da última ocorrência de ch em s
char * my_strrchr(char * s, char ch)
{
	char * ptr = NULL;
	int i = 0;

	while (s[i]!='\0')
	{
		if (s[i] == ch)	ptr = &s[i];
		i++;
	}
	return ptr;
}

// 4.
// Retorna o endereço de str1 em que ocorre pela primeira vez
// a substring str2
char * my_strstr(char * str1, char * str2)
{
	char * p_str1 = str1;
	char * p_str2 = str2;

	while (*p_str1 != '\0')
	{
		if (*p_str1 == *p_str2)
			if (strcmp(p_str1, p_str2) >= 0)
				return p_str1;
		p_str1++;
	}
	return NULL;
}

char * my_strstr2(char *str1, char * str2)
{
	int i, ii, j, len = strlen(str1)-strlen(str2);

	for (i=0; i<=len; i++)
	{
		for (ii=i, j=0; str1[ii]==str2[j] && str2[j]!='\0'; j++, ii++)
		;
		if (str2[j]=='\0')
			return str1+i;
	}
	return NULL;
}

// 5.
// Retorna o endereço em que ocorre a primeira vogal na string s
char * First_Vogal(char * s)
{
	int i;
	char vogais[] = { 'a', 'e', 'i', 'o', 'u' };

	for (i=0; s[i]!='\0'; i++)
			if (strchr(vogais, tolower(s[i])) != NULL)
				return &s[i];
	return NULL;
}

// 6.
char * strins(char * dest, char * orig)
{
	const int len_orig  = strlen(orig);
	const int len_dest  = strlen(dest);
	const int len_total = len_orig + len_dest;
	int i, j;

	for (i=len_dest, j=len_total; 0<=i; i--, j--)
		dest[j] = dest[i];
	
	for (i=0; i<len_orig; i++)
		dest[i] = orig[i];

	return dest;
}

// 8.
// Apaga todos os caracteres maiúsculos em s
char *StrDelUpper(char * s)
{
	char * ptr_s = s;
	char * ptrii_s = NULL;

	while (*ptr_s != '\0')
	{
		if (isupper(*ptr_s))
			for (ptrii_s = ptr_s; *ptrii_s != '\0'; ptrii_s++)
				*ptrii_s = *(ptrii_s + 1);
		ptr_s++;
	}
	return s;
}

// 8 b
char *StrDelUpper2(char * s)
{
    char * ptr_s, * ptrii_s;
    ptr_s = ptrii_s = s;

    while (*ptrii_s)
    {
        if (!isupper(*ptrii_s))
			*ptr_s++ = *ptrii_s;
		ptrii_s++;		
    }

    return s;
}

// 9.
char * StrDelStr(char * s1, char * s2)
{
	char * p_s1 = strstr(s1, s2);
	int len_s2 = strlen(s2);

	if (p_s1 != NULL)
	{
		while (*(p_s1+len_s2) != '\0')
			*(p_s1++) = *(p_s1+len_s2);

		*p_s1 = *(p_s1+len_s2);
	}
	return s1;
}

void main()
{
	char string1[100] = "FabioCorreia";
	char string2[100] = "bio";
	puts(StrDelStr(string1, string2));
}
