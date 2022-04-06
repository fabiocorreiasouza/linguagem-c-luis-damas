#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE * fp;
	int i, v[10], n;

	if ((fp = fopen("DADOS.DAT", "rb")   ) == NULL)
	{
		printf("Impossível acessar o arquivo %s\n", "DADOS.DAT");
		exit(1);
	}

	if (fread(v, sizeof(int), 10, fp) != 10)
		fprintf(stderr, "Não foi possível ler todos os itens\n");

	for (i=0, n=10; i<n; i++)
		printf("%d elemento: %d\n", i+1, v[i]);

	fclose(fp);
}
