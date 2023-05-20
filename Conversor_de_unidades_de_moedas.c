#include <stdio.h>

float usdToBrl(float amount) {
    float exchangeRate = 5.25;  // Taxa de câmbio: 1 USD = 5.25 BRL
    return amount * exchangeRate;
}

float brlToUsd(float amount) {
    float exchangeRate = 1 / 5.25;  // Taxa de câmbio: 1 USD = 5.25 BRL
    return amount * exchangeRate;
}

float usdToEur(float amount) {
    float exchangeRate = 0.91;  // Taxa de câmbio: 1 USD = 0.91 EUR
    return amount * exchangeRate;
}

float eurToUsd(float amount) {
    float exchangeRate = 1 / 0.91;  // Taxa de câmbio: 1 USD = 0.91 EUR
    return amount * exchangeRate;
}

float eurToBrl(float amount) {
    float exchangeRate = 5.75;  // Taxa de câmbio: 1 EUR = 5.75 BRL
    return amount * exchangeRate;
}

float brlToEur(float amount) {
    float exchangeRate = 1 / 5.75;  // Taxa de câmbio: 1 EUR = 5.75 BRL
    return amount * exchangeRate;
}

int main() {
    float amount;
    int choice;

    printf("Conversor de Unidades de Moedas\n");
    printf("1. Dólar Americano para Real Brasileiro\n");
    printf("2. Real Brasileiro para Dólar Americano\n");
    printf("3. Dólar Americano para Euro\n");
    printf("4. Euro para Dólar Americano\n");
    printf("5. Euro para Real Brasileiro\n");
    printf("6. Real Brasileiro para Euro\n");
    printf("Escolha uma opção: ");
    scanf("%d", &choice);

    printf("Digite o valor: ");
    scanf("%f", &amount);

    switch (choice) {
        case 1:
            printf("$%.2f = R$%.2f\n", amount, usdToBrl(amount));
            break;
        case 2:
            printf("R$%.2f = $%.2f\n", amount, brlToUsd(amount));
            break;
        case 3:
            printf("$%.2f = €%.2f\n", amount, usdToEur(amount));
            break;
        case 4:
            printf("€%.2f = $%.2f\n", amount, eurToUsd(amount));
            break;
        case 5:
            printf("€%.2f = R$%.2f\n", amount, eurToBrl(amount));
            break;
        case 6:
            printf("R$%.2f = €%.2f\n", amount, brlToEur(amount));
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
