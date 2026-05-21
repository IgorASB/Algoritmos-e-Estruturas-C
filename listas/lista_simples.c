/*
 * ============================================================
 *  LISTA ENCADEADA SIMPLES
 * ============================================================
 *  Cada no guarda um valor e um ponteiro para o proximo no.
 *  Operacoes: inserir no inicio, inserir no fim,
 *             remover por valor, buscar, imprimir, liberar.
 * ============================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int       valor;
    struct No *proximo;
} No;

No *criar_no(int valor) {
    No *novo = (No *) malloc(sizeof(No));
    if (!novo) { fprintf(stderr, "Erro de alocacao.\n"); exit(1); }
    novo->valor   = valor;
    novo->proximo = NULL;
    return novo;
}

void inserir_inicio(No **cabeca, int valor) {
    No *novo      = criar_no(valor);
    novo->proximo = *cabeca;
    *cabeca       = novo;
}

void inserir_fim(No **cabeca, int valor) {
    No *novo = criar_no(valor);
    if (!*cabeca) { *cabeca = novo; return; }
    No *atual = *cabeca;
    while (atual->proximo) atual = atual->proximo;
    atual->proximo = novo;
}

void remover(No **cabeca, int valor) {
    No *atual = *cabeca, *anterior = NULL;
    while (atual && atual->valor != valor) {
        anterior = atual;
        atual    = atual->proximo;
    }
    if (!atual) { printf("Valor %d nao encontrado.\n", valor); return; }
    if (!anterior) *cabeca = atual->proximo;
    else           anterior->proximo = atual->proximo;
    free(atual);
}

void imprimir(No *cabeca) {
    printf("Lista: ");
    while (cabeca) { printf("%d -> ", cabeca->valor); cabeca = cabeca->proximo; }
    printf("NULL\n");
}

void liberar(No **cabeca) {
    No *atual = *cabeca;
    while (atual) { No *tmp = atual->proximo; free(atual); atual = tmp; }
    *cabeca = NULL;
}

int main(void) {
    No *lista = NULL;
    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_inicio(&lista, 5);
    imprimir(lista);
    remover(&lista, 20);
    imprimir(lista);
    liberar(&lista);
    printf("Memoria liberada.\n");
    return 0;
}
