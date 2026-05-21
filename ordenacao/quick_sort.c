/*
 * ============================================================
 *  QUICK SORT (Ordenacao Rapida)
 * ============================================================
 *  Estrategia: Divisao e Conquista
 *   1. Escolhe um pivo (ultimo elemento)
 *   2. Particiona: menores a esquerda, maiores a direita
 *   3. Aplica recursivamente em cada particao
 *
 *  Complexidade:
 *   - Medio : O(n log n)
 *   - Pior  : O(n^2) -- pivo sempre minimo/maximo
 *  Espaco  : O(log n) -- pilha de recursao
 *  In-place: sim
 * ============================================================
 */
#include <stdio.h>

void trocar(int *a, int *b) { int t = *a; *a = *b; *b = t; }

int particionar(int arr[], int esq, int dir) {
    int pivo = arr[dir];
    int i    = esq - 1;
    for (int j = esq; j < dir; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[dir]);
    return i + 1;
}

void quick_sort(int arr[], int esq, int dir) {
    if (esq < dir) {
        int p = particionar(arr, esq, dir);
        quick_sort(arr, esq, p - 1);
        quick_sort(arr, p + 1, dir);
    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Antes:  "); imprimir(arr, n);
    quick_sort(arr, 0, n - 1);
    printf("Depois: "); imprimir(arr, n);
    return 0;
}
