#include <stdio.h>

int main()
{
    int nota;
    int media = 0;
    int i = 0;

    for(int i = 0; i < 11; i++)
    {
        printf("Digite a nota de atendimento do cliente de 0 a 10: ");
        scanf("%d", &nota);

        if(nota >= 0 && nota <= 10)
        {
            media += nota;
        }
        else
        {
            printf("Nota nao valida!\n");
        }
    }
    media = media / 10;
    printf("Media de notas; %d\n", media);
    if (media >= 7)
    {
        printf("Media de notas dentro da media!");
    }
    else
    {
        printf("Media de notas abaixo da media!");
    }
}
