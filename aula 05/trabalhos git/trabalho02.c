#include <stdio.h>

int main()
{
    float cofre = 0;
    char res;

    while(1)
    {
        printf("==COFRE==\n");
        printf("Digite 5 para +RS0,50\n1 para +RS1,00\n2 para +RS2,00\nN para ver valor acumulado\n");
        scanf(" %c", &res);

        if(res == '5')
        {
            cofre += 0.5;
        }
        else if(res == '1')
        {
            cofre += 1;
        }
        else if(res == '2')
        {
            cofre += 2;
        }
        else if(res == 'N')
        {
            printf("Valor acumulado: %f", cofre);
            break;
        }
        else
        {
            printf("Valor nao valido\n");
            continue;
        }
    }
}
