#include <stdio.h>

int main()
{
    int num;
    int min = 0;
    int max = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);

        if (i == 0)
        {
            min = num;
            max = num;
        }

        if (num > max)
        {
            max = num;
        }

        if (num < min)
        {
            min = num;
        }
    }

    int dif = max - min;

    printf("Maior numero: %d\nMenor numero: %d\nDiferenca: %d", max, min, dif);
}
