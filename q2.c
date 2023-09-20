#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void gerarArrayAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 10000; 
    }
}


void ordenarPorBolha(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}


int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}


void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo = particionar(arr, baixo, alto);
        quicksort(arr, baixo, pivo - 1);
        quicksort(arr, pivo + 1, alto);
    }
}


void fundir(int arr[], int esquerda, int meio, int direita) {
    
}


void mergesort(int arr[], int esquerda, int direita) {
    
}


double medirTempo(void (*funcaoOrdenacao)(int[], int), int arr[], int tamanho) {
    clock_t inicio = clock();
    funcaoOrdenacao(arr, tamanho);
    clock_t fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL)); 

    int tamanhos[] = {1000, 5000, 10000, 50000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("Comparação de desempenho de ordenação:\n");

    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        int *arr_bolha = (int *)malloc(tamanho * sizeof(int));
        int *arr_quicksort = (int *)malloc(tamanho * sizeof(int));
        int *arr_mergesort = (int *)malloc(tamanho * sizeof(int));

        gerarArrayAleatorio(arr_bolha, tamanho);
        memcpy(arr_quicksort, arr_bolha, tamanho * sizeof(int));
        memcpy(arr_mergesort, arr_bolha, tamanho * sizeof(int));

        printf("\nTamanho do array: %d\n", tamanho);

        double tempo_bolha = medirTempo(ordenarPorBolha, arr_bolha, tamanho);
        printf("Tempo de execução do Bubble Sort: %.6f segundos\n", tempo_bolha);

        double tempo_quicksort = medirTempo(quicksort, arr_quicksort, tamanho);
        printf("Tempo de execução do Quick Sort: %.6f segundos\n", tempo_quicksort);

        double tempo_mergesort = medirTempo(mergesort, arr_mergesort, tamanho);
        printf("Tempo de execução do Merge Sort: %.6f segundos\n", tempo_mergesort);

        free(arr_bolha);
        free(arr_quicksort);
        free(arr_mergesort);
    }

    return 0;
}

