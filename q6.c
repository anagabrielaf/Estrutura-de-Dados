#include <stdio.h>
#include <stdbool.h>


struct Posicao {
    int linha;
    int coluna;
};


bool buscarValor(int matriz[][3], int linhas, int colunas, int valor, struct Posicao *posicao) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                posicao->linha = i;
                posicao->coluna = j;
                return true;
            }
        }
    }

    return false; 
}

int main() {
    int matriz[][3] = {
        {5, 4, 3},
        {9, 8, 7},
        {2, 1, 0},
        {12, 11, 10}
    };
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    printf("Digite o valor que deseja buscar na matriz: ");
    int valorBuscado;
    scanf("%d", &valorBuscado);

    struct Posicao posicao;

    if (buscarValor(matriz, linhas, colunas, valorBuscado, &posicao)) {
        printf("O valor %d foi encontrado na posição (%d, %d) da matriz.\n", valorBuscado, posicao.linha, posicao.coluna);
    } else {
        printf("O valor %d não foi encontrado na matriz.\n", valorBuscado);
    }

    return 0;
}

