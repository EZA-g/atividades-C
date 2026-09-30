#include <stdio.h>

int main()
{
    int produtos[10];
    int i;
    int maior;
    int indiceMaior;
    int acimaDe20 = 0;

    printf("Digite a quantidade em estoque dos 10 produtos:\n");

    for(i = 0; i < 10; i++)
    {
        printf("Produto %d: ", i + 1);
        scanf("%d", &produtos[i]);
    }

    printf("\nQuantidade de cada produto:\n");

    for(i = 0; i < 10; i++)
    {
        printf("Produto %d: %d unidades\n", i + 1, produtos[i]);
    }

    printf("\nProdutos com estoque baixo (< 5):\n");

    for(i = 0; i < 10; i++)
    {
        if(produtos[i] < 5 && produtos[i] > 0)
        {
            printf("Produto %d\n", i + 1);
        }
    }

    printf("\nProdutos esgotados:\n");

    for(i = 0; i < 10; i++)
    {
        if(produtos[i] == 0)
        {
            printf("Produto %d\n", i + 1);
        }
    }

    for(i = 0; i < 10; i++)
    {
        if(produtos[i] > 20)
        {
            acimaDe20++;
        }
    }

    printf("\nQuantidade de produtos com mais de 20 unidades: %d\n", acimaDe20);

    maior = produtos[0];
    indiceMaior = 0;

    for(i = 1; i < 10; i++)
    {
        if(produtos[i] > maior)
        {
            maior = produtos[i];
            indiceMaior = i;
        }
    }

    printf("\nProduto com maior quantidade em estoque: Produto %d\n", indiceMaior + 1);
    printf("Quantidade: %d unidades\n", maior);

    return 0;
}
