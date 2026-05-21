/*
 * ============================================================
 *  LISTA DUPLAMENTE ENCADEADA
 * ============================================================
 *  Cada no possui ponteiro para o PROXIMO e para o ANTERIOR.
 *  Permite percorrer a lista nos dois sentidos e remover
 *  qualquer no em O(1) dado seu ponteiro.
 * ============================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int       valor;
    struct No *proximo;
    struct No *anterior;
} No;

No *criar_no(int v) {
    No *n = (No *) malloc(sizeof(No));
    n->valor = v; n->proximo = NULL; n->anterior = NULL;
    return n;
}

void inserir_fim(No **cabeca, int valor) {
    No *novo = criar_no(valor);
    if (!*cabeca) { *cabeca = novo; return; }
    No *atual = *cabeca;
    while (atual->proximo) atual = atual->proximo;
    atual->proximo = novo;
    novo->anterior = atual;
}

void remover(No **cabeca, int valor) {
    No *atual = *cabeca;
    while (atual && atual->valor != valor) atual = atual->proximo;
    if (!atual) { printf("Nao encontrado: %d\n", valor); return; }
    if (atual->anterior) atual->anterior->proximo = atual->proximo;
    else                 *cabeca = atual->proximo;
    if (atual->proximo)  atual->proximo->anterior = atual->anterior;
    free(atual);
}

void imprimir_frente(No *cabeca) {
    printf("Frente: ");
    while (cabeca) { printf("%d <-> ", cabeca->valor); cabeca = cabeca->proximo; }
    printf("NULL\n");
}

void imprimir_tras(No *cabeca) {
    if (!cabeca) return;
    while (cabeca->proximo) cabeca = cabeca->proximo;
    printf("Tras  : ");
    while (cabeca) { printf("%d <-> ", cabeca->valor); cabeca = cabeca->anterior; }
    printf("NULL\n");
}

void liberar(No **cabeca) {
    No *atual = *cabeca;
    while (atual) { No *t = atual->proximo; free(atual); atual = t; }
    *cabeca = NULL;
}

int main(void) {
    No *lista = NULL;
    inserir_fim(&lista, 10); inserir_fim(&lista, 20); inserir_fim(&lista, 30);
    imprimir_frente(lista); imprimir_tras(lista);
    remover(&lista, 20);
    imprimir_frente(lista);
    liberar(&lista);
    return 0;
}
