#include <stdio.h>


int compararCrescente(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int compararDecrescente(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}


void ordenarPorBolha(int arr[], int tamanho, int (*comparar)(const void *, const void *)) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            
            if (comparar(&arr[j], &arr[j + 1]) > 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação por bolha:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    
    ordenarPorBolha(arr, tamanho, compararCrescente);

    printf("\nArray depois da ordenação por bolha (crescente):\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    
    ordenarPorBolha(arr, tamanho, compararDecrescente);

    printf("\nArray depois da ordenação por bolha (decrescente):\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

