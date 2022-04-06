#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Função exit
#include <ctype.h> // Função toupper

#define ARQ "dados.dat" // Arquivo com os dados

#define OP_INSERIR   '1'
#define OP_ALTERAR   '2'
#define OP_APAGAR    '3'
#define OP_LISTAR	 '4'
#define OP_PESQUISAR '5'

#define OP_SAIR		 '0'

#define OP_PESQ_IDADE '1'
#define OP_PESQ_NOME  '2'

char * MainMenu[] =
{
	"1. Inserir Registro",
	"2. Alterar Registro",
	"3. Apagar Registro",
	"4. Listar Registro",
	"5. Pesquisas",
	"0. Sair",
	NULL
};

char * PesqMenu[] =
{
	"1. Pesquisar por intervalo de idades",
	"2. Pesquisar por nome",
	"0. Voltar",
	NULL // Acabaram as opções
};

FILE * fp;

typedef struct
{
	char Nome[30+1];
	int Idade;
	float Salario;
	char Status; // '*' indica que o registro está apagado
} PESSOA;

void Mensagem(char *msg);

void Ler_Pessoa(PESSOA *p)
{
	printf("Nome	: "); fgets((*p).Nome, BUFSIZ+1, stdin);
	(*p).Nome[strlen((*p).Nome) - 1] = '\0'; // Retira o '\n'
	printf("Idade	: "); scanf("%d", &(*p).Idade);
	printf("Salário	: "); scanf("%f", &(*p).Salario);
	(*p).Status = ' ';
	__fpurge(stdin);
}

// Mostrar na tela, os dados existentes no registro

void Mostrar_Pessoa(PESSOA p)
{
	printf("%-30s	 %3d	%10.2f\n", p.Nome, p.Idade, p.Salario);
}

// Adicionar uma pessoa ao arquivo

void Adicionar_Pessoa(PESSOA p)
{
	fseek(fp, (long) 0, SEEK_END);
	if (fwrite(&p, sizeof(p), 1, fp) != 1)
		Mensagem("Adicionar Pessoa: Falhou a escrita do Registro");
}

// Coloca uma mensagem na tela

void Mensagem(char *msg)
{
	printf("%s", msg);
	getchar();
}

/*
 * Veriifica se o arquivo já existe. Se não existir, ele é criado
 * Se já existir, abre-o em modo de leitura e escrita (r+b)
 */

void Inic()
{
	if ((fp = fopen(ARQ, "r+b")) == NULL) // Tentar abrir
		if ((fp = fopen(ARQ, "w+b")) == NULL) // Criar o arquivo
		{
			fprintf(stderr, "ERRO FATAL: Impossível criar arquivo de dados\n");
			exit(EXIT_FAILURE);
		}
}

/*
 * Faz um menu simples com as opções do vetor de strings.
 * Seleciona a opção com o primeiro caractere de cada string.
 * Devolve o primeiro caractere da opção.
 */

char Menu(char * Opcoes[])
{
	int i;
	char ch;

	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		for (i=0; Opcoes[i]!=NULL; i++)
			printf("\t\t%s\n\n", Opcoes[i]);

		printf("\n\n\t\tOpção: ");
		ch = getchar(); __fpurge(stdin);
		for (i=0; Opcoes[i]!=NULL; i++)
			if (Opcoes[i][0] == ch)
				return ch;
	}
}

void Inserir_Pessoa()
{
	PESSOA x;
	Ler_Pessoa(&x);
	Adicionar_Pessoa(x);
}

void Alterar_Pessoa()
{
	PESSOA x;
	long int n_reg;

	printf("Qual o nº do registro: ");
	scanf("%ld", &n_reg);

	if (fseek(fp, (n_reg-1)*sizeof(PESSOA), SEEK_SET) != 0)
	{
		Mensagem("Registro inexistente ou problemas no posicionamento!");
		return;
	}
	if (fread(&x, sizeof(PESSOA), 1, fp) != 1)
	{
		Mensagem("Problemas na leitura do registro!");
		return;
	}
	if (x.Status == '*')
	{
		Mensagem("Um registro apagado não pode ser alterado!\n");
		return;
	}

	printf("\nnDados atuais\n\n");
	Mostrar_Pessoa(x);
	printf("\n\nNovos dados\n\n");
	Ler_Pessoa(&x);

	// Recuar um registro no arquivo
	fseek(fp, (long) -1*sizeof(PESSOA), SEEK_CUR);
	// Reescrever o registro
	fwrite(&x, sizeof(PESSOA), 1, fp);
	__fpurge(fp); // despejar os dados no disco rígido
}

void Apagar_Pessoa()
{
	PESSOA x;
	long int n_reg;
	char resp;

	printf("Qual o nº do registro: ");
	scanf("%ld", &n_reg); __fpurge(stdin);

	if (fseek(fp, (n_reg-1)*sizeof(PESSOA), SEEK_SET) != 1)
	{
		Mensagem("Registro inexistente ou problemas no posicionamento!");
		return;
	}
	if (fread(&x, sizeof(PESSOA), 1, fp) != 1)
	{
		Mensagem("Problemas na leitura do registro!");
		return;
	}
	if (x.Status == '*')
	{
		Mensagem("Registro já está apagado!\n\n");
		return;
	}

	printf("\n\nDados atuais\n\n");
	Mostrar_Pessoa(x);
	printf("\n\nApagar registro(s/n)? "); resp = getchar();
	__fpurge(stdin);
	if (toupper(resp) != 'S') return;

	x.Status = '*';
	// Recuar um registro no arquivo
	fseek(fp, (long) -1*sizeof(PESSOA), SEEK_CUR);
	// Reescrever o registro
	fwrite(&x, sizeof(PESSOA), 1, fp);
	__fpurge(fp); // Despejar os dados no disco rígido
}

void Listar()
{
	long int N_Linhas = 0;
	PESSOA reg;

	rewind(fp);
	while (1)
	{
		if (fread(&reg, (long) sizeof(reg), 1, fp) != 1) break; // Sair do laço
		if (reg.Status == '*') continue; // Passa ao próximo
		Mostrar_Pessoa(reg);
		N_Linhas++;
		if (N_Linhas%20 == 0)
			Mensagem("\n\nPRESSIONE <ENTER> para continuar . . . ");
	}
	Mensagem("\n\nPRESSIONE <ENTER> para continuar . . . "); // No fim da listagem
}

void Pesquisar_Idades(int ini, int fim)
{
	PESSOA reg;

	rewind(fp);
	while (fread(&reg, sizeof(PESSOA), 1, fp))
		if (reg.Status!='*' && reg.Idade>=ini && reg.Idade<=fim)
			Mostrar_Pessoa(reg);

	Mensagem("\n\nPRESSIONE <ENTER> para continuar"); // No fim da listagem
}

void Pesquisar_Nome(char *s)
{
	PESSOA reg;

	rewind(fp);
	while (fread(&reg, sizeof(PESSOA), 1, fp))
		if (reg.Status!='*' && strstr(reg.Nome, s))
			Mostrar_Pessoa(reg);

	Mensagem("\n\nPRESSIONAR <ENTER> para continuar . . . "); // O fim da listagem
}

void main()
{
	char Opcao;

	Inic();

	while ((Opcao = Menu(MainMenu)) != OP_SAIR)
		switch (Opcao)
		{
			case OP_INSERIR: Inserir_Pessoa(); break;
			case OP_ALTERAR: Alterar_Pessoa(); break;
			case OP_APAGAR: Apagar_Pessoa(); break;
			case OP_LISTAR: Listar(); break;
			case OP_PESQUISAR:
				while ((Opcao = Menu(PesqMenu)) != OP_SAIR)
					switch (Opcao)
					{
						case OP_PESQ_IDADE:
						{
							int n1, n2;
							printf("Qual o intervalo de idades: ");
							scanf("%d%d", &n1, &n2); __fpurge(stdin);
							Pesquisar_Idades(n1, n2);
							break;
						}
						case OP_PESQ_NOME:
						{
							char string[BUFSIZ+1];
							printf("Qual o nome a procurar: ");
							gets(string); __fpurge(stdin);
							Pesquisar_Nome(string);
						}
					}
		}
}
