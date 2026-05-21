/*
 * ============================================================
 *  FILA (Queue) com Lista Encadeada
 * ============================================================
 *  Principio FIFO: First In, First Out
 *
 *  Mantemos ponteiros para cabeca E cauda para que
 *  enqueue e dequeue sejam ambos O(1).
 *
 *  Aplicacoes: escalonamento de processos, BFS em grafos,
 *              sistemas de atendimento, buffers.
 * ============================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *cabeca;
    No *cauda;
    int tamanho;
} Fila;

void inicializar(Fila *f) { f->cabeca = f->cauda = NULL; f->tamanho = 0; }
int vazia(Fila *f) { return f->cabeca == NULL; }

void enqueue(Fila *f, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor; novo->proximo = NULL;
    if (vazia(f)) f->cabeca = novo;
    else          f->cauda->proximo = novo;
    f->cauda = novo;
    f->tamanho++;
}

int dequeue(Fila *f) {
    if (vazia(f)) { fprintf(stderr, "Fila vazia!\n"); return -1; }
    No *tmp = f->cabeca;
    int val = tmp->valor;
    f->cabeca = tmp->proximo;
    if (!f->cabeca) f->cauda = NULL;
    free(tmp);
    f->tamanho--;
    return val;
}

void imprimir(Fila *f) {
    No *atual = f->cabeca;
    printf("Fila: ");
    while (atual) { printf("%d ", atual->valor); atual = atual->proximo; }
    printf("\n");
}

void liberar(Fila *f) { while (!vazia(f)) dequeue(f); }

int main(void) {
    Fila f;
    inicializar(&f);
    enqueue(&f, 10); enqueue(&f, 20); enqueue(&f, 30);
    imprimir(&f);
    printf("Dequeue: %d\n", dequeue(&f));
    printf("Dequeue: %d\n", dequeue(&f));
    imprimir(&f);
    liberar(&f);
    return 0;
}
