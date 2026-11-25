#include <stdio.h>

int calcularDobro(int numero) {
    return numero * 2;
}

int main() {
    int numero, resultado;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    resultado = calcularDobro(numero);
    printf("O dobro de %d e %d\n", numero, resultado);

    return 0;
}
