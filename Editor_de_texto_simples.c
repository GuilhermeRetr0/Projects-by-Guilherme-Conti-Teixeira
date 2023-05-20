#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void openFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    char text[MAX_TEXT_LENGTH];
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF && count < MAX_TEXT_LENGTH - 1) {
        text[count] = ch;
        count++;
    }
    text[count] = '\0';

    printf("Conteúdo do arquivo:\n%s\n", text);

    fclose(file);
}

void saveFile(char *filename, char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Não foi possível salvar o arquivo.\n");
        return;
    }

    fprintf(file, "%s", text);

    printf("Arquivo salvo com sucesso.\n");

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char text[MAX_TEXT_LENGTH];
    int choice;

    printf("Editor de Texto Simples\n");
    printf("1. Abrir arquivo\n");
    printf("2. Salvar arquivo\n");
    printf("Escolha uma opção: ");
    scanf("%d", &choice);

    clearInputBuffer();

    if (choice == 1) {
        printf("Digite o nome do arquivo a ser aberto: ");
        fgets(filename, MAX_FILENAME_LENGTH, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        openFile(filename);
    } else if (choice == 2) {
        printf("Digite o nome do arquivo a ser salvo: ");
        fgets(filename, MAX_FILENAME_LENGTH, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        printf("Digite o texto a ser salvo: ");
        fgets(text, MAX_TEXT_LENGTH, stdin);
        text[strcspn(text, "\n")] = '\0';

        saveFile(filename, text);
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}
