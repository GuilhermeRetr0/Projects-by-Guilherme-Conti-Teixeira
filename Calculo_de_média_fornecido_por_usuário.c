#include <stdio.h>

int main() {
    int quantidade, i;
    float numero, soma = 0, media;

    printf("Quantos números deseja calcular a média? ");
    scanf("%d", &quantidade);

    for (i = 1; i <= quantidade; i++) {
        printf("Digite o número %d: ", i);
        scanf("%f", &numero);
        soma += numero;
    }

    media = soma / quantidade;

    printf("A média dos números fornecidos é: %.2f\n", media);

    return 0;
}
