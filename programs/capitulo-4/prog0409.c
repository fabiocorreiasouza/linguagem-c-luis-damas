#include <stdio.h>

main()
{
    char opcao;

    do
    {
        printf("\tM E N U   P R I N C I P A L\n");
        printf("\n\n\t(C)lientes");
        printf("\n\n\t(F)ornecedores");
        printf("\n\n\t(E)ncomendas");
        printf("\n\n\t(S)air");
        printf("\n\n\tOpção:");
        scanf(" %c", &opcao);

        switch (opcao)
        {
            case 'c':
            case 'C':
                puts("Opção CLIENTES"); break;
            case 'f':
            case 'F':
                puts("Opção FORNECEDORES"); break;
            case 'e':
            case 'E':
                puts("Opção ENCOMENDAS"); break;
            case 's':
            case 'S':
                puts("Opção SAIR"); break;
            default:
                puts("Opção INVÁLIDA!!!");
        }
        getchar();
    }
    while (opcao != 's' && opcao != 'S');
}