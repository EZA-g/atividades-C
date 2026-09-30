#include <stdio.h>

int main()
{
    float media = 20;
    float consumo;
    float mediaGeral = 0;
    int i = 0;

    while(i < 5)
    {
        printf("Digite o consumo mensal de agua deste morador em ml: ");
        scanf("%f", &consumo);

        if(consumo > media)
        {
            printf("Consumo excede a media!\n");
            mediaGeral += consumo;
            i++;
            continue;
        }
        else
        {
            printf("Consumo esta dentro da media\n");
            mediaGeral += consumo;
            i++;
            continue;
        }
    }
    mediaGeral = mediaGeral / 5;
    printf("Media geral consumida por 5 moradores: %f", mediaGeral);
}
