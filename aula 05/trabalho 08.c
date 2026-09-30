#include <stdio.h>

int main()
{
    int num;
    int numSecreto = 67;
    int tentativas = 1;

    while(1)
    {
        if(tentativas < 11)
        {
           printf("Descubra o numero secreto entre 1 e 100: ");
           scanf("%d", &num);
        }
        else
        {
            printf("Tentativas acabadas! O numero secreto era: %d", numSecreto);
            break;
        }

        if(num > numSecreto)
        {
            printf("O numero secreto e menor\n");
            tentativas++;
        }
        else if(num < numSecreto)
        {
            printf("O numero secreto e maior\n");
            tentativas++;
        }
        else if(num == numSecreto)
        {
            printf("Parabens! Voce acertou!\nNumero de tentativas: %d", tentativas);
            break;
        }
    }
}
