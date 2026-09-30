#include <stdio.h>
#include <string.h>

int main()
{
    char nome[20] = "";

    float nota1;
    float nota2;
    float nota3;

    int i = 0;

    float media;

    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;

    while (1)
    {
        printf("Digite o nome do aluno: ");
        scanf("%s", nome);

        if (strcmp(nome, "fim") == 0)
        {
            break;
        }
        else
        {
            printf("Aluno: %s\n", nome);
            printf("Digite a primeira nota: ");
            scanf("%f", &nota1);

            printf("Digite a segunda nota: ");
            scanf("%f", &nota2);

            printf("Digite a terceira nota: ");
            scanf("%f", &nota3);

            media = (nota1 + nota2 + nota3) / 3;
            printf("Media das notas: %f\n", media);

            if (media >= 7)
            {
                printf("Aluno aprovado\n");
                aprovados++;
            }
            else if (media <= 6.99 && media >= 5)
            {
                printf("Aluno em recuperacao\n");
                recuperacao++;
            }
            else
            {
                printf("Aluno reprovado\n");
                reprovados++;
            }
        }
        printf("Alunos aprovados: %d\nAlunos em recuperacao: %d\nAlunos reprovados: %d\n", aprovados, recuperacao, reprovados);
    }
}
