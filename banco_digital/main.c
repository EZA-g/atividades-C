#include <stdio.h>
#include "meuBanco.h"

int main(void)
{
    int menu;

    do
    {
        printf("\n=====|Carteira Digital|=====\n");
        printf("1 - Abrir banco\n2 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &menu) != 1)
            return 1;

        switch (menu)
        {
            case 1:
                printf("Banco aberto!\n");
                menuInicial();
                break;

            case 2:
                printf("Servico terminado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (menu != 2);

    return 0;
}
