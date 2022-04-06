#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE * fp;
	float v[10];
	int i = 0;
	float valor_corrente;

	// Acessa o arquivo DADOS.DAT para escrita/leitura
	if ((fp = fopen("DADOS.DAT", "w+b")) == NULL) // Binário
	{
		fprintf(stderr, "Não foi possível escrever o arquivo %s\n", "DADOS.DAT");
		exit(2);
	}

	// Lê os dados a partir do teclado
	while (i < 10)
	{
		printf("Insira o %d-ésimo nº real: ", i+1);
		fscanf(stdin, " %f", &v[i++]);
	}
	putchar('\n');

	if (fwrite(v, sizeof(float), 10, fp) != 10)
		fprintf(stderr, "Alguns  valores não foram escritos!\n");

	printf("Qual a ordem do número que pretende ver 1..10? ");
	scanf("%d", &i);
	i--; // índice escolhido: n-ésima posição - 1
	putchar('\n');

	// Mostra o valor escolhido
	fseek(fp, (long) i*sizeof(float), SEEK_SET);
	fread(&valor_corrente, sizeof(float), 1, fp);
	printf("O %dº valor introduzido foi %f\n", i, valor_corrente);

	// Mostra o primeiro valor
	rewind(fp);
	fread(&valor_corrente, sizeof(float), 1, fp);
	printf("O 1º valor introduzido foi %f\n", valor_corrente);
	
	// Mostra o último valor
	fseek(fp, (long) -1*sizeof(float), SEEK_END);
	fread(&valor_corrente, sizeof(float), 1, fp);
	printf("O último valor introduzido foi %f\n", valor_corrente);

	fclose(fp);
}
