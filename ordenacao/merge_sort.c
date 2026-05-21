/*
 * ============================================================
 *  MERGE SORT (Ordenacao por Mescla)
 * ============================================================
 *  Estrategia: Divisao e Conquista
 *   1. Divide o array ao meio recursivamente
 *   2. Ordena cada metade
 *   3. Mescla (merge) as duas metades ordenadas
 *
 *  Complexidade: O(n log n) em todos os casos
 *  Espaco extra : O(n) -- precisa de array auxiliar
 *  Estavel: sim
 * ============================================================
 */
#include <stdio.h>
#include <stdlib.h>

void mesclar(int arr[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int *L = (int *) malloc(n1 * sizeof(int));
    int *R = (int *) malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[esq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[meio + 1 + j];
    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void merge_sort(int arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        merge_sort(arr, esq, meio);
        merge_sort(arr, meio + 1, dir);
        mesclar(arr, esq, meio, dir);
    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Antes:  "); imprimir(arr, n);
    merge_sort(arr, 0, n - 1);
    printf("Depois: "); imprimir(arr, n);
    return 0;
}
