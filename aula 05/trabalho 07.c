#include <stdio.h>

int main()
{
    int num;
    int i = 0;
    int fat = 1;

    while(i < 1)
    {
        printf("Digite um numero inteiro entre 0 e 10: ");
        scanf("%d", &num);

        if (num < 0 || num > 10)
        {
            printf("numero fora do intervalo sugerido! Tente denovo\n");
        }
        else
        {
            for (int j = 1; j < num + 1; j++)
            {
                fat = fat * j;
            }
            i = 1;
        }
    }

    printf("O fatorial de %d e %d", num, fat);
}
