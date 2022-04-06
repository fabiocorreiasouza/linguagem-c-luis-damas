#include <stdio.h>
#include <stdlib.h>

typedef struct s_inteiro
{
	int numero;
	struct s_inteiro * anterior;
} INTEIRO;

typedef INTEIRO * PILHA;

// Inicia a pilha
void inic(PILHA * pilha)
{	// A variável que contém o endereço de um INTEIRO recebe null
	*pilha = NULL;
}


// Função push(): insere  um novo registro no topo da pilha

void push(PILHA * pilha, int i)
{
	INTEIRO * aux = (INTEIRO *) malloc(sizeof(INTEIRO));
	if (aux == NULL) return;

	aux->numero = i;
	aux->anterior = *pilha;
	*pilha = aux;
}

int empty(PILHA pilha)
{
	return pilha == NULL;
}

// Função pop(): apaga o elemento do topo da pilha (se existir)
void pop(PILHA * p_pilha)
{
	PILHA tmp = *p_pilha;

	if (empty(*p_pilha)) return;
	*p_pilha = (**p_pilha).anterior;
	free(tmp);
}

// Função top(): devolve o elemento do topo da pilha. Supõe-se todos positivos.
int top(PILHA pilha)
{
	return empty(pilha)? -1 : (*pilha).numero;
}

// Função print(): lista todos os elementos recursivamente.
void print(PILHA pilha)
{
	if (empty(pilha)) return;
	printf("%d\n", (*pilha).numero);
	print((*pilha).anterior);
}

void main()
{
	PILHA P; // Aponta para um registro INTEIRO

	inic(&P);

	printf("%s está vazia\n", empty(P)?"":"Não");
	print(P);
	puts("Push: 10");
	push(&P, 10);
	puts("Push: 20");
    push(&P, 20);
    puts("Push: 30");
    push(&P, 30);
	printf("%s está vazia\n", empty(P)?"":"Não");
	print(P);
	puts("Pop: ");
	pop(&P);
	print(P);
	puts("Pop: ");
	pop(&P);
	print(P);
	puts("Pop: ");
	pop(&P);
	print(P);
	printf("%s está vazia\n", empty(P)?"":"Não");
}
