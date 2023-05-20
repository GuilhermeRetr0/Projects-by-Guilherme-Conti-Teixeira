#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    int opcao;
    float temperatura;

    printf("Conversor de Temperatura\n");
    printf("1. Celsius para Fahrenheit\n");
    printf("2. Fahrenheit para Celsius\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a temperatura em Celsius: ");
            scanf("%f", &temperatura);
            printf("Temperatura em Fahrenheit: %.2f\n", celsiusToFahrenheit(temperatura));
            break;
        case 2:
            printf("Digite a temperatura em Fahrenheit: ");
            scanf("%f", &temperatura);
            printf("Temperatura em Celsius: %.2f\n", fahrenheitToCelsius(temperatura));
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}
