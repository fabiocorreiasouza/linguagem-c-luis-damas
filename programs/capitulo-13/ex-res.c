#include <stdio.h>

// 1.1
#define TAXA_ICMS1 5
#define TAXA_ICMS2 17
#define val_icms(salario) (((salario) < 10000) ? \
								((salario)*(TAXA_ICMS1/100.0)) : \
								((salario)*(TAXA_ICMS2/100.0)))
// 3.a)
#define MAX 43
#define MIN -1
#define zap(x, v1, v2) (((x) <= 0) ? (x)*(v1) : (x)*(-(v2)))

// 4.2
#define FIRST 'A'
#define LAST 'Z'
#define toupper(ch) ((ch) >= 'A' && (ch) <= 'Z' ? (ch) : (ch)-'a' + 'A')

void main()
{
// 1.2
	int x, y = 2;
	printf("\nSalario=%f\n", val_icms(x+y));
// (((x+y) < 10000) ? (x+y)*(5/100.0) : (x+y)*(17/100.0))


// 3.b)
	int i, j = (int) 'a';
	i = zap(i+j, MAX-1, MIN-1);
//	(((i+j) <= 0) ? ((i+j)*(43-1)) : ((i+j)*(-(-1-1))))


// 4.3
	int ch = 65; // ASCII do 'A'
	printf("%c %c", toupper(FIRST+2), toupper(LAST+'a'-ch));
//	(('A'+2) >= 'A' && ('A'+2) <= 'Z' ? ('A'+2) : ('A'+2)-'a' + 'A')
//  (((('Z'+'a'-ch) >= 'A') && (('Z'+'a'-ch) <= 'Z')) ? ('Z'+'a'-ch) : (('Z'+'a'-ch)-'a' + 'A'))

// 4.4 Saída de 4.3
// C Z
}

/*  2)
*	Ordem em que as operações são realizadas no desenvolvimento
*
* Edição do código
* Pré-processamento
* Compilação
* Linkagem
* Execução da aplicação
*/

/*	4.1)
* Os parâmetros das macros não possuem tipos, pois apenas são substituídos,
* isto é, os dados não são copiados e alocados na memória.
*/

/* 4.2)
* 
*
*/
