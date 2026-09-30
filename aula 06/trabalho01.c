#include <stdio.h>

int main()
{
    int numeros[10];
    int busca;
    int i;
    int quantidade = 0;

    printf("Digite 10 numeros inteiros:\n");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &numeros[i]);
    }

    printf("Digite um numero para pesquisar: ");
    scanf("%d", &busca);

    for(i = 0; i < 10; i++)
    {
        if(numeros[i] == busca)
        {
            quantidade++;
        }
    }

    if(quantidade == 0)
    {
        printf("O numero %d nao foi encontrado.\n", busca);
    }
    else
    {
        printf("O numero %d foi encontrado %d vez(es).\n", busca, quantidade);
        printf("Posicoes: ");

        for(i = 0; i < 10; i++)
        {
            if(numeros[i] == busca)
            {
                printf("%d ", i);
            }
        }
    }

    return 0;
}
