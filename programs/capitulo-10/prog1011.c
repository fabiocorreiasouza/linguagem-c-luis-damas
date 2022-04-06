#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE * fp;
	int i;
	float valor_corrente;


	if ((fp = fopen("DADOS.DAT", "rb")) == NULL)
	{
		fprintf(stderr, "Não foi possível ler %s\n", "DADOS.DAT");
		exit(1);
	}

	// Mostra os valores nas posições ímpares
	i = 0;
	while (1)
	{
		if (i % 2 != 0)
		{
			if (fread(&valor_corrente, sizeof(float), 1, fp) == 0)
				break; // Falhou a leitura
			printf("%f\n", valor_corrente);
		}
		i++;
		fseek(fp, (long) i*sizeof(float), SEEK_SET);
	}
}
