#include <stdio.h>
#include <stdlib.h>


struct LinhaMatriz {
    int* elementos;
    int tamanho;
};


void ordenarLinhaPorInsercao(struct LinhaMatriz* linha) {
    for (int i = 1; i < linha->tamanho; i++) {
        int chave = linha->elementos[i];
        int j = i - 1;

        while (j >= 0 && linha->elementos[j] < chave) {
            linha->elementos[j + 1] = linha->elementos[j];
            j--;
        }

        linha->elementos[j + 1] = chave;
    }
}

int main() {
    struct LinhaMatriz matriz[] = {
        {{5, 4, 3}, 3},
        {{9, 8, 7}, 3},
        {{2, 1, 0}, 3},
        {{12, 11, 10}, 3}
    };
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = matriz[0].tamanho;

    printf("Matriz antes da ordenação:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i].elementos[j]);
        }
        printf("\n");
    }

    
    for (int i = 0; i < linhas; i++) {
        ordenarLinhaPorInsercao(&matriz[i]);
    }

    printf("\nMatriz depois da ordenação por inserção (em ordem decrescente):\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i].elementos[j]);
        }
        printf("\n");
    }

    return 0;
}

