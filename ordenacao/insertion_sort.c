/*
 * ============================================================
 *  INSERTION SORT (Ordenacao por Insercao)
 * ============================================================
 *  Ideia: como ordenar cartas na mao -- pega um elemento e
 *  o insere na posicao correta dentro da parte ja ordenada.
 *
 *  Complexidade:
 *   - Melhor caso : O(n)   -- array quase ordenado
 *   - Pior caso   : O(n^2) -- array invertido
 *  Estavel: sim
 * ============================================================
 */
#include <stdio.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Antes:  "); imprimir(arr, n);
    insertion_sort(arr, n);
    printf("Depois: "); imprimir(arr, n);
    return 0;
}
