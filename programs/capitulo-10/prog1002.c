#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE * fin;
	const char fname[18+1] = "notas_prog1002.txt";
	char aluno[100];
	int nota;

	if ((fin = fopen(fname, "rb")) == NULL)
	{
		printf("Não foi possível acessar %s", fname);
		exit(0);
	}

	while (fscanf(fin, "%s %d", aluno, &nota) != EOF)
		if (nota >= 5)
			printf("%s %d", aluno, nota);

	fclose(fin);
}
