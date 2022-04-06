#include <stdio.h>

#define DIM 3
#define ESPACO ' '


/* Função inic(): inicia o tabuleiro do jogo da velha com espaços em branco */

void inic(char v[DIM][DIM])
{
	int i, j;

	for (i=0; i<DIM; i++)
		for (j=0; j<DIM; j++)
			v[i][j] = ESPACO;
}

/* 
Função perguntar():
Pergunta, recebe e retorna a posição na qual a jogada deve ser marcada no jogo da velha
*/

int perguntar()
{
	int resposta;

	printf("\nPosição da jogada: ");
	scanf("%d", &resposta);

	return resposta;
}

/* Função marcar(): marca a jogada na devida posição enviada pelo jogador */

void marcar(int opcaoEscolhida, char vez, char v[DIM][DIM])
{
	int i, j, posicao=1;

	for (i=0; i<DIM; i++)
		for (j=0; j<DIM; posicao++, j++)
			if (posicao == opcaoEscolhida)
			{
				v[i][j] = vez;
				return;
			}
}

/* Função teste(): checa se o jogo chegou ao fim. */

int teste(char v[DIM][DIM])
{
	int i, j, contador=1;
	char trio[3];


	if (v[0][0]!=ESPACO && v[0][0]==v[1][1] && v[0][0]==v[2][2] ||
		v[0][2]!=ESPACO && v[0][2]==v[1][1] && v[0][2]==v[2][0])
		return 1;

	while(contador <= 2)
	{
		for (i=0; i<DIM; i++)
		{
			for (j=0; j<DIM; j++)
				trio[j] = v[i][j];

			if (trio[0]!=ESPACO && trio[0]==trio[1] && trio[0]==trio[2]) return 1;
		}
		transporMatriz(v);
		
		contador++;
	}

	return 0;
}

/* 
Função mostrar():
Apresenta a matriz formatada em jogo da velha.

Se uma dada posição na matriz estiver em branco, será apresentada com a sua
respectiva posição no tabuleiro de 1..9. Senão, mostrará o X ou O marcado.
*/

void mostrar(char v[DIM][DIM])
{
	int i, j, posicao=1;

	for (i=0; i<DIM; i++)
	{
		for (j=0; j<DIM; posicao++, j++)
		{
			if (v[i][j] == ESPACO)
				printf(" %d ", posicao);
			else 
				printf(" %c ", v[i][j]);

			if (j < DIM-1) putchar('|');			
		}

		putchar('\n');
		if (i < DIM-1) puts("------------");
	}
}

/* Função transporMatriz(): transpõe uma matriz */

void transporMatriz(char v[DIM][DIM])
{
	int i, j, aux;

	for (i=0; i<DIM; i++)
		for(j=i+1; j<DIM; j++)
		{
			aux = v[i][j];
			v[i][j] = v[j][i];
			v[j][i] = aux;
		}
}

void main()
{
	char velha[3][3];
	char vez = 'X';
	int resposta;

	inic(velha);
	mostrar(velha);

	while(1)
	{
		if (vez == 'X')
			vez = 'O';
		else
			vez = 'X';

		resposta = perguntar();
		marcar(resposta, vez, velha);
		mostrar(velha);

		if (teste(velha))
		{
			puts("\nFim!");
			break;
		}
	}
}
