/*
 * ============================================================
 *  SELECTION SORT (Ordenacao por Selecao)
 * ============================================================
 *  Ideia: a cada iteracao, encontra o menor elemento da parte
 *  nao ordenada e o coloca na posicao correta.
 *
 *  Complexidade: O(n^2) em todos os casos
 *  Vantagem: numero minimo de trocas (no maximo n-1)
 * ============================================================
 */
#include <stdio.h>

void trocar(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[idx_min])
                idx_min = j;
        trocar(&arr[i], &arr[idx_min]);
    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Antes:  "); imprimir(arr, n);
    selection_sort(arr, n);
    printf("Depois: "); imprimir(arr, n);
    return 0;
}
