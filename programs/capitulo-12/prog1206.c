#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int numero;
	struct no * prox;
} NO;

void inic(NO ** p_lista)
{
	*p_lista = NULL;
}

// Insere um novo registro na lista

int inserir(NO ** p_lista, unsigned int n)
{
	NO * tmp;

	if (n%2 != 0 || *p_lista==NULL) // Se for ímpar é logo inserido
	{
		tmp = (NO *) malloc(sizeof(NO));
		if (tmp == NULL) return 0;
		tmp->numero = n;
		tmp->prox = *p_lista;
		*p_lista = tmp;
		return n;
	}
	else
		return inserir(&(*p_lista)->prox, n);
}

void * buscar(NO * lista, int n)
{
	if (lista == NULL) return lista;

	if (lista->numero == n)
		return lista;
	else
		buscar(lista->prox, n);
}
/*
int retirar(NO ** p_lista, int n)
{
	NO * tmp = *p_lista;
	NO * aux;

	if (tmp == NULL) return 0;
	if (tmp->numero == n)
	{
		aux = *p_lista;
		*p_lista = tmp->prox;
		free(aux);
		return tmp->numero;
	}
	while (1)
	{
		if (tmp->prox == NULL) return 0;

		if (tmp->prox->numero == n)
		{
			aux = tmp->prox;
			tmp->prox = tmp->prox->prox;
			free(aux);
			return tmp->numero;
		}
		else
			tmp = tmp->prox;
	}
}
*/

// Retira o primeiro nó da lista (se existir)

int retirar(NO ** p_lista, int n)
{
    NO * tmp = *p_lista;
    NO * alvo = (NO *) buscar(*p_lista, n); // Aponta o nó a ser retirado

	if (alvo == NULL) return 0;
	if (*p_lista == alvo)
	{
		*p_lista = alvo->prox;
		free(alvo);
		return n;
	}
	while (1)
		if (tmp->prox == alvo)
		{
			tmp->prox = tmp->prox->prox; // Retira o nó alvo da lista e
			free(alvo);					 // libera o espaço ocupado por ele.
			break;
		}
		else tmp = tmp->prox; // Avança na lista.
	return n;
}

void listar(NO * lista)
{
	if (lista == NULL) return;
	printf("%d\n", lista->numero);
	listar(lista->prox);
}

void main()
{
	NO * L;

	inic(&L);

	puts("Inserir impares e pares aleatoriamente");
	inserir(&L, 10);
	inserir(&L, 3);
	inserir(&L, 20);
	inserir(&L, 5);
	inserir(&L, 9);

	puts("Listar valores ordenados");
	listar(L);
}
