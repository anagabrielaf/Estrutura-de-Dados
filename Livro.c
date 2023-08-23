#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

typedef struct {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
} Livro;

void adicionarLivro(Livro livros[], int *numLivros) {
    if (*numLivros < MAX_LIVROS) {
        Livro novoLivro;
        
        printf("Título: ");
        fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
        novoLivro.titulo[strlen(novoLivro.titulo) - 1] = '\0'; 
        
        printf("Autor: ");
        fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
        novoLivro.autor[strlen(novoLivro.autor) - 1] = '\0'; 
        
        printf("Ano de Publicação: ");
        scanf("%d", &novoLivro.anoPublicacao);
        getchar(); 
        
        livros[(*numLivros)++] = novoLivro;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("A lista de livros esta cheia.\n");
    }
}

void listarLivros(Livro livros[], int numLivros) {
    printf("Lista de Livros:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano de Publicacao: %d\n", livros[i].anoPublicacao);
        printf("--------------------------\n");
    }
}

void buscarLivroPorAutor(Livro livros[], int numLivros, const char autorBusca[]) {
    printf("Livros por Autor %s:\n", autorBusca);
    int encontrado = 0;
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(autorBusca, livros[i].autor) == 0) {
            printf("Título: %s\n", livros[i].titulo);
            printf("Ano de Publicação: %d\n", livros[i].anoPublicacao);
            printf("--------------------------\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum livro encontrado para esse autor.\n");
    }
}

int main() {
    Livro livros[MAX_LIVROS];
    int numLivros = 0;
    
    while (1) {
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar Livro\n");
        printf("2 - Listar Livros\n");
        printf("3 - Buscar Livro por Autor\n");
        printf("4 - Sair\n");
        
        int opcao;
        scanf("%d", &opcao);
        getchar(); 
        
        switch (opcao) {
            case 1:
                adicionarLivro(livros, &numLivros);
                break;
            case 2:
                if (numLivros > 0) {
                    listarLivros(livros, numLivros);
                } else {
                    printf("A lista de livros esta vazia.\n");
                }
                break;
            case 3:
                if (numLivros > 0) {
                    char autorBusca[50];
                    printf("Informe o autor do livro: ");
                    fgets(autorBusca, sizeof(autorBusca), stdin);
                    autorBusca[strlen(autorBusca) - 1] = '\0'; 
                    
                    buscarLivroPorAutor(livros, numLivros, autorBusca);
                } else {
                    printf("A lista de livros esta vazia.\n");
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opcaoo invalida.\n");
        }
    }

    return 0;
}

