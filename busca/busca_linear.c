/*
 * ============================================================
 *  BUSCA LINEAR (Sequential Search)
 * ============================================================
 *  Ideia: percorre o array do inicio ao fim comparando cada
 *  elemento com o valor buscado.
 *
 *  Complexidade: O(n)
 *  Funciona em arrays nao ordenados.
 * ============================================================
 */
#include <stdio.h>

int busca_linear(int arr[], int n, int alvo) {
    for (int i = 0; i < n; i++)
        if (arr[i] == alvo)
            return i;
    return -1;
}

int main(void) {
    int arr[] = {4, 2, 7, 1, 9, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int alvo = 9;
    int idx = busca_linear(arr, n, alvo);
    if (idx >= 0)
        printf("Elemento %d encontrado no indice %d.\n", alvo, idx);
    else
        printf("Elemento %d nao encontrado.\n", alvo);
    return 0;
}
