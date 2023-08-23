#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    int telefone;
};

void imprimirContato(struct Contato contato) {
    printf("Nome: %s\n", contato.nome);
    printf("Telefone: %d\n", contato.telefone);
    printf("--------------------------\n");
}

int main(void) {
    struct Contato agenda[100]; 
    int numContatos = 0;
    
    while (1) {
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar Contato\n");
        printf("2 - Listar Contatos\n");
        printf("3 - Buscar Contato por Nome\n");
        printf("4 - Sair\n");
        
        int opcao;
        scanf("%d", &opcao);
        getchar(); 
        
        switch (opcao) {
            case 1:
                if (numContatos < 100) {
                    printf("Nome: ");
                    fgets(agenda[numContatos].nome, sizeof(agenda[numContatos].nome), stdin);
                    agenda[numContatos].nome[strlen(agenda[numContatos].nome) - 1] = '\0'; // Remover a quebra de linha
                    
                    printf("Telefone: ");
                    scanf("%d", &agenda[numContatos].telefone);
                    
                    numContatos++;
                    printf("Contato adicionado com sucesso!\n");
                } else {
                    printf("A agenda esta cheia.\n");
                }
                break;
            case 2:
                if (numContatos > 0) {
                    printf("Lista de Contatos:\n");
                    for (int i = 0; i < numContatos; i++) {
                        imprimirContato(agenda[i]);
                    }
                } else {
                    printf("A agenda esta vazia.\n");
                }
                break;
            case 3:
                if (numContatos > 0) {
                    char nomeBusca[50];
                    printf("Informe o nome do contato: ");
                    fgets(nomeBusca, sizeof(nomeBusca), stdin);
                    nomeBusca[strlen(nomeBusca) - 1] = '\0'; // Remover a quebra de linha
                    
                    int encontrado = 0;
                    for (int i = 0; i < numContatos; i++) {
                        if (strcmp(nomeBusca, agenda[i].nome) == 0) {
                            printf("Contato encontrado:\n");
                            imprimirContato(agenda[i]);
                            encontrado = 1;
                            break;
                        }
                    }
                    
                    if (!encontrado) {
                        printf("Contato nao encontrado.\n");
                    }
                } else {
                    printf("A agenda esta vazia.\n");
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}

