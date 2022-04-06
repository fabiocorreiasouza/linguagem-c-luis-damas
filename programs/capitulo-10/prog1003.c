#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE * fp;
	int i, v[10];

	for (i=0; i<10; i++)
	{
		printf("Introd. o %d-ésimo número: ", i+1);
		scanf("%d", &v[i]);
	}

	if ((fp = fopen("DADOS.DAT", "wb")) == NULL)
	{
		printf("Impossível criar o arquivo %s\n", "DADOS.DAT");
		exit(1);
	}

	if (fwrite(v, sizeof(int), 10, fp) != 10)
		fprintf(stderr, "Não foram escritos todos os elementos!\n");

	fclose(fp);
}
