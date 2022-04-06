#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ "DADOS.DAT"

typedef struct
{
	char nome[30+1];
	float altura;
	int idade;
} REG;

// Arquivo: variável global
FILE * fp;

void inic()
{
	if ((fp = fopen(ARQ, "r+b")) == NULL)
		if ((fp = fopen(ARQ, "w+b")) == NULL)
			fprintf(stderr, "Impossível acessar o arquivo\n");
}

void listar()
{
	REG r;
	long old_pos = ftell(fp); // Salvaguardar posição atual

	rewind(fp);
	while (fread(&r, sizeof(REG), 1, fp) == 1)
		printf("%s\n", r.nome);

	fseek(fp, old_pos, SEEK_SET); // Reposicionar arquivo
}

int n_maiores(int n)
{
	REG r;
	long old_pos = ftell(fp); // Salvaguardar posição atual
	int qtd = 0;

	rewind(fp);
	while(fread(&r, sizeof(REG), 1, fp) == 1)
		if (r.idade > n) qtd++;

	fseek(fp, old_pos, SEEK_SET); // Reposicionar arquivo

	return qtd;
}

// Devolve o nº de registros existentes no arquivo

long n_registros()
{
	long old_pos = ftell(fp); // Salvaguardar posição atual
	long qtd = 0;

	fseek(fp, 0L, SEEK_END);
	qtd = ftell(fp) / sizeof(REG);
	fseek(fp, old_pos, SEEK_SET); // Reposicionar arquivo

	return qtd;
}

REG * carregar_estrutura(REG ** p_ptr)
{
	long old_pos = ftell(fp);
	*p_ptr = calloc((int) n_registros(), sizeof(REG));
	if (*p_ptr == NULL) return NULL;

	rewind(fp);
	fread(*p_ptr, sizeof(REG), n_registros(), fp);

	// Reposicionar o arquivo
	fseek(fp, old_pos, SEEK_SET);

	return *p_ptr;
}

void main()
{
	long i;
	REG r;
	REG * v;

	inic();

	strcpy(r.nome, "Ana Raio"); r.altura = 1.60; r.idade = 20;
	fwrite(&r, sizeof(REG), 1, fp);

    strcpy(r.nome, "Ze Trovao"); r.altura = 1.70; r.idade = 30;
	fwrite(&r, sizeof(REG), 1, fp);

    strcpy(r.nome, "Fabio Correia"); r.altura = 1.80; r.idade = 24;
    fwrite(&r, sizeof(REG), 1, fp);

	listar();

	printf("Maiores que 21: %d\n", n_maiores(21));
	printf("Nº total: %ld\n", n_registros());

	carregar_estrutura(&v);

	puts("---------------");
	for (i=0; i<n_registros(); i++)
		printf("%-15s %5.2f %3d\n", v[i].nome, v[i].altura, v[i].idade);
	free(v);

	fclose(fp);
}
