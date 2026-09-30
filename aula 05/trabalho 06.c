#include <stdio.h>

int main()
{
    int num;
    int divisores = 0;
    char res;

    while(1)
    {
        divisores = 0;

        printf("Digite um numero inteiro: ");
        scanf("%d", &num);

        printf("\nDivisores:\n");
        for (int i = 1; i < (num +1); i++)
        {

            if (num % i == 0)
            {
                printf("%d\n", i);
                divisores++;
            }
        }

        if (divisores == 2)
        {
            printf("O numero e primo\n");
        }
        else
        {
            printf("O numero nao e primo\n");
        }

        printf("Quer descobrir se outro numero e primo ou nao?: ");
        scanf(" %c", &res);

        if (res == 's' || res == 'S')
        {
            continue;
        }
        else if (res == 'n' || res == 'N')
        {
            break;
        }
        else
        {
            printf("Digite s ou n: ");
            scanf(" %c", &res);
        }
    }
}
