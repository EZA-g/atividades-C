#include <stdio.h>

int main()
{
    int passos;
    int total = 0;
    int horas = 0;

    while(1)
    {
        printf("Digite a quantidade de passos dada essa hora: ");
        scanf("%d", &passos);

        total += passos;
        horas++;
        printf("Total de passos atualmente: %d\n", total);

        if(total <= 10000)
        {
            continue;
        }
        else
        {
            printf("Ultrapassou 10000 passos!\n");
            printf("Total de horas necessarias: %d", horas);
            break;
        }
    }
}
