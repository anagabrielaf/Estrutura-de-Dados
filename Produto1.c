#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidadeEstoque;
} Produto;

void comprarProduto(Produto *produto, int quantidade) {
    if (quantidade <= produto->quantidadeEstoque) {
        produto->quantidadeEstoque -= quantidade;
        printf("Compra de %d unidades de %s realizada com sucesso.\n", quantidade, produto->nome);
    } else {
        printf("Estoque insuficiente para a compra.\n");
    }
}

int main() {
    Produto produto1 = {"Camiseta", 29.99, 10};
    Produto produto2 = {"Calça", 49.99, 5};
    Produto produto3 = {"Tênis", 79.99, 3};

    printf("Bem-vindo à loja!\n");

    while (1) {
        int opcao;
        printf("\nMenu:\n");
        printf("1. Comprar produto\n");
        printf("2. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int escolha;
            printf("\nProdutos disponíveis:\n");
            printf("1. %s - R$%.2f - Estoque: %d\n", produto1.nome, produto1.preco, produto1.quantidadeEstoque);
            printf("2. %s - R$%.2f - Estoque: %d\n", produto2.nome, produto2.preco, produto2.quantidadeEstoque);
            printf("3. %s - R$%.2f - Estoque: %d\n", produto3.nome, produto3.preco, produto3.quantidadeEstoque);
            printf("Escolha um produto (1-3): ");
            scanf("%d", &escolha);

            int quantidade;
            printf("Quantidade desejada: ");
            scanf("%d", &quantidade);

            if (escolha == 1) {
                comprarProduto(&produto1, quantidade);
            } else if (escolha == 2) {
                comprarProduto(&produto2, quantidade);
            } else if (escolha == 3) {
                comprarProduto(&produto3, quantidade);
            } else {
                printf("Opção inválida.\n");
            }
        } else if (opcao == 2) {
            printf("Obrigado por comprar conosco!\n");
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }

    return 0;
}

