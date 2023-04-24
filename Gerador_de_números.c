#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed para a função rand() com base no tempo atual
    srand(time(0));

    int num_aleatorio;

    // Gerar um número aleatório entre 1 e 100
    num_aleatorio = rand() % 100 + 1;

    printf("Número aleatório: %d\n", num_aleatorio);

    return 0;
}
