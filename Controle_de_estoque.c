#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

typedef struct {
    char nome[50];
    int quantidade;
} Produto;

void adicionarProduto(Produto estoque[], int *numProdutos) {
    if (*numProdutos < TAM_MAX) {
        printf("Digite o nome do produto: ");
        scanf("%s", estoque[*numProdutos].nome);
        printf("Digite a quantidade: ");
        scanf("%d", &estoque[*numProdutos].quantidade);
        (*numProdutos)++;
        printf("Produto adicionado com sucesso!\n");
    } else {
        printf("O estoque esta cheio. Nao e possivel adicionar mais produtos.\n");
    }
}

void removerProduto(Produto estoque[], int *numProdutos) {
    if (*numProdutos > 0) {
        char nome[50];
        printf("Digite o nome do produto a ser removido: ");
        scanf("%s", nome);

        int i, posicao = -1;
        for (i = 0; i < *numProdutos; i++) {
            if (strcmp(estoque[i].nome, nome) == 0) {
                posicao = i;
                break;
            }
        }

        if (posicao != -1) {
            for (i = posicao; i < *numProdutos - 1; i++) {
                strcpy(estoque[i].nome, estoque[i + 1].nome);
                estoque[i].quantidade = estoque[i + 1].quantidade;
            }
            (*numProdutos)--;
            printf("Produto removido com sucesso!\n");
        } else {
            printf("Produto nao encontrado no estoque.\n");
        }
    } else {
        printf("O estoque esta vazio. Nao ha produtos para remover.\n");
    }
}

void listarEstoque(Produto estoque[], int numProdutos) {
    if (numProdutos > 0) {
        printf("Estoque:\n");
        for (int i = 0; i < numProdutos; i++) {
            printf("Produto: %s - Quantidade: %d\n", estoque[i].nome, estoque[i].quantidade);
        }
    } else {
        printf("O estoque esta vazio.\n");
    }
}

int main() {
    Produto estoque[TAM_MAX];
    int numProdutos = 0;
    int opcao;

    printf("Controle de Estoque\n");

    do {
        printf("\nOpcoes:\n");
        printf("1. Adicionar produto\n");
        printf("2. Remover produto\n");
        printf("3. Listar estoque\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &numProdutos);
                break;
            case 2:
                removerProduto(estoque, &numProdutos);
                break;
            case 3:
                listarEstoque(estoque, numProdutos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
