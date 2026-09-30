#include <stdio.h>

int main()
{
    int num;
    int numsPos = 0;
    int numsNeg = 0;
    int somPos = 0;
    int somNeg = 0;

    int i = 0;

    while (i < 1)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);

        if (num > 0)
        {
            printf("Numero positivo\n");
            numsPos ++;
            somPos += num;
        }
        else if (num < 0)
        {
            printf("Numero negativo\n");
            numsNeg ++;
            somNeg += num;
        }
        else
        {
            printf("Numero neutro\n");
            break;
        }
    }
    printf("Numeros Positivos: %d\nNumeros Negativos: %d\nSoma dos positivos: %d\nSoma dos negativos: %d", numsPos, numsNeg, somPos, somNeg);
}
