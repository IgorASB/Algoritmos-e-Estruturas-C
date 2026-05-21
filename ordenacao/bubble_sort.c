/*
 * ============================================================
 *  BUBBLE SORT (Ordenacao por Bolha)
 * ============================================================
 *  Ideia: percorre o array comparando pares adjacentes e
 *  "borbulha" o maior elemento para o final a cada passagem.
 *
 *  Complexidade:
 *   - Melhor caso  : O(n)   -- array ja ordenado
 *   - Medio/Pior   : O(n^2) -- array invertido
 *   - Espaco extra : O(1)   -- in-place
 * ============================================================
 */
#include <stdio.h>

/* Troca dois inteiros usando ponteiros */
void trocar(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Bubble Sort com otimizacao: para se nenhuma troca ocorreu */
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
                trocou = 1;
            }
        }
        if (!trocou) break; /* array ja ordenado: para cedo */
    }
}

void imprimir_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Antes: "); imprimir_array(arr, n);
    bubble_sort(arr, n);
    printf("Depois: "); imprimir_array(arr, n);
    return 0;
}
