#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 20

int main() {
    char palavra[MAX_PALAVRA];
    char palavraOculta[MAX_PALAVRA];
    int letrasRestantes;
    int tentativas = 0;
    char letra;
    int i;

    printf("Jogo da Forca\n\n");

    // Solicitar a palavra a ser adivinhada
    printf("Digite a palavra a ser adivinhada (em letras maiusculas): ");
    scanf("%s", palavra);

    // Limpar o buffer do teclado
    while (getchar() != '\n');

    // Inicializar a palavra oculta com asteriscos
    letrasRestantes = strlen(palavra);
    for (i = 0; i < letrasRestantes; i++) {
        palavraOculta[i] = '*';
    }
    palavraOculta[i] = '\0';

    // Loop principal do jogo
    while (tentativas < MAX_TENTATIVAS && letrasRestantes > 0) {
        printf("\nPalavra: %s\n", palavraOculta);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = toupper(letra);  // Converter a letra para maiúscula

        // Verificar se a letra já foi tentada
        if (strchr(palavraOculta, letra) != NULL) {
            printf("Essa letra ja foi tentada. Tente novamente.\n");
            continue;
        }

        // Verificar se a letra está na palavra
        int acertou = 0;
        for (i = 0; i < strlen(palavra); i++) {
            if (palavra[i] == letra) {
                palavraOculta[i] = letra;
                letrasRestantes--;
                acertou = 1;
            }
        }

        if (acertou) {
            printf("Voce acertou uma letra!\n");
        } else {
            printf("Essa letra nao faz parte da palavra.\n");
            tentativas++;
        }
    }

    // Verificar o resultado do jogo
    printf("\nPalavra: %s\n", palavra);
    if (letrasRestantes == 0) {
        printf("Parabens! Voce adivinhou a palavra corretamente.\n");
    } else {
        printf("Voce perdeu! A palavra correta era: %s\n", palavra);
    }

    return 0;
}
