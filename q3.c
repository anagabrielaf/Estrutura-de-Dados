#include <stdio.h>


void ordenarPorInsercaoDecrescente(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] < chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação por inserção decrescente:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    ordenarPorInsercaoDecrescente(arr, tamanho);

    printf("\nArray depois da ordenação por inserção decrescente:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

