/*
 * ============================================================
 *  PILHA (Stack) com Lista Encadeada
 * ============================================================
 *  Principio LIFO: Last In, First Out
 *
 *  Operacoes: push O(1), pop O(1), peek O(1)
 *
 *  Aplicacoes: desfazer acoes (Ctrl+Z), chamadas de funcao,
 *              avaliacao de expressoes, backtracking.
 * ============================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int tamanho;
} Pilha;

void inicializar(Pilha *p) { p->topo = NULL; p->tamanho = 0; }
int vazia(Pilha *p) { return p->topo == NULL; }

void push(Pilha *p, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
}

int pop(Pilha *p) {
    if (vazia(p)) { fprintf(stderr, "Pilha vazia!\n"); return -1; }
    No *tmp = p->topo;
    int val = tmp->valor;
    p->topo = tmp->proximo;
    free(tmp);
    p->tamanho--;
    return val;
}

int peek(Pilha *p) {
    if (vazia(p)) { fprintf(stderr, "Pilha vazia!\n"); return -1; }
    return p->topo->valor;
}

void liberar(Pilha *p) { while (!vazia(p)) pop(p); }

int main(void) {
    Pilha p;
    inicializar(&p);
    push(&p, 10); push(&p, 20); push(&p, 30);
    printf("Topo: %d\n", peek(&p));
    printf("Pop: %d\n",  pop(&p));
    printf("Pop: %d\n",  pop(&p));
    printf("Tamanho: %d\n", p.tamanho);
    liberar(&p);
    return 0;
}
