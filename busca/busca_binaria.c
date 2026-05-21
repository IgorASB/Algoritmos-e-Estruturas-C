/*
 * ============================================================
 *  BUSCA BINARIA (Binary Search)
 * ============================================================
 *  Pre-requisito: array ORDENADO.
 *
 *  Ideia: a cada passo, descarta metade do array comparando
 *  o elemento do meio com o valor buscado.
 *
 *  Complexidade: O(log n)
 *  Exemplo: em 1.000.000 de elementos, no maximo ~20 comparacoes
 * ============================================================
 */
#include <stdio.h>

/* Versao iterativa */
int busca_binaria(int arr[], int n, int alvo) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (arr[meio] == alvo) return meio;
        if (arr[meio] <  alvo) esq = meio + 1;
        else                   dir = meio - 1;
    }
    return -1;
}

/* Versao recursiva */
int busca_binaria_rec(int arr[], int esq, int dir, int alvo) {
    if (esq > dir) return -1;
    int meio = esq + (dir - esq) / 2;
    if (arr[meio] == alvo) return meio;
    if (arr[meio] <  alvo) return busca_binaria_rec(arr, meio + 1, dir, alvo);
    return busca_binaria_rec(arr, esq, meio - 1, alvo);
}

int main(void) {
    int arr[] = {2, 3, 4, 10, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int alvo = 10;
    printf("-- Iterativa --\n");
    printf("Elemento %d: indice %d\n", alvo, busca_binaria(arr, n, alvo));
    printf("-- Recursiva --\n");
    printf("Elemento %d: indice %d\n", alvo, busca_binaria_rec(arr, 0, n - 1, alvo));
    return 0;
}
