#include <stdio.h>

int main()
{
    int num;

    int i;

    int par;
    int impar;

    for (i = 0; i < 10; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num % 2 == 0)
        {
            printf("O numero %d e par\n", num);
            par++;
        }
        else
        {
            printf("O numero %d e impar\n", num);
            impar++;
        }
    }
    printf("Quantidade de numeros pares: %d\n", par);
    printf("Quantidade de numeros impares: %d\n", impar);
}