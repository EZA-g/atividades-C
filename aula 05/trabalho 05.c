#include <stdio.h>

int main()
{
    int num;
    char res;

    while(1)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d",&num);

        printf("Tabuada do 1 ao 10 do numero %d\n", num);
        for (int i = 1; i < 11; i++)
        {
            int mult = num * i;
            printf("%d x %d = %d\n", num, i, mult);
        }

        printf("Deseja calcular a tabuada do 1 ao 10 de outro numero?: ");
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
