#include <stdio.h>

int main() {
    int numeros[10];
    int i, busca, quantidade = 0, impressos = 0;

    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nArray: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("Digite um numero: ");
    scanf("%d", &busca);

    /* Conta quantas vezes o numero aparece */
    for (i = 0; i < 10; i++) {
        if (numeros[i] == busca) {
            quantidade++;
        }
    }

    if (quantidade == 0) {
        printf("O numero %d nao foi encontrado.\n", busca);
    } else {
        if (quantidade == 1) {
            printf("O numero %d foi encontrado 1 vez.\n", busca);
        } else {
            printf("O numero %d foi encontrado %d vezes.\n", busca, quantidade);
        }

        printf("Posicoes: ");
        for (i = 0; i < 10; i++) {
            if (numeros[i] == busca) {
                if (impressos > 0) {
                    printf(", ");
                }
                printf("%d", i);
                impressos++;
            }
        }
        printf("\n");
    }

    return 0;
}
