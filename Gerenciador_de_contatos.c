#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("Atingido o limite máximo de contatos!\n");
        return;
    }

    struct Contact newContact;

    printf("Nome: ");
    scanf("%s", newContact.name);

    printf("Telefone: ");
    scanf("%s", newContact.phone);

    printf("E-mail: ");
    scanf("%s", newContact.email);

    contacts[numContacts++] = newContact;

    printf("Contato adicionado com sucesso!\n");
}

void displayContacts() {
    if (numContacts == 0) {
        printf("A lista de contatos está vazia!\n");
        return;
    }

    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Nome: %s\n", contacts[i].name);
        printf("Telefone: %s\n", contacts[i].phone);
        printf("E-mail: %s\n", contacts[i].email);
        printf("--------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("Gerenciador de Contatos\n");
        printf("-----------------------\n");
        printf("1. Adicionar contato\n");
        printf("2. Exibir contatos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}
