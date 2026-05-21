/*
 * ============================================================
 *  ARVORE BINARIA DE BUSCA (BST - Binary Search Tree)
 * ============================================================
 *  Propriedade BST:
 *   - Filho ESQUERDO < no atual
 *   - Filho DIREITO  > no atual
 *
 *  Operacoes: inserir, buscar, remover O(h)
 *  Percursos: in-ordem, pre-ordem O(n)
 *  Visualizacao no terminal (arvore rotacionada 90 graus)
 * ============================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int       valor;
    struct No *esq;
    struct No *dir;
} No;

No *criar_no(int v) {
    No *n = (No *) malloc(sizeof(No));
    n->valor = v; n->esq = n->dir = NULL;
    return n;
}

No *inserir(No *raiz, int valor) {
    if (!raiz) return criar_no(valor);
    if (valor < raiz->valor) raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor) raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

No *minimo(No *raiz) {
    while (raiz->esq) raiz = raiz->esq;
    return raiz;
}

No *remover(No *raiz, int valor) {
    if (!raiz) return NULL;
    if      (valor < raiz->valor) raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor) raiz->dir = remover(raiz->dir, valor);
    else {
        if (!raiz->esq && !raiz->dir) { free(raiz); return NULL; }
        if (!raiz->esq) { No *t = raiz->dir; free(raiz); return t; }
        if (!raiz->dir) { No *t = raiz->esq; free(raiz); return t; }
        No *suc     = minimo(raiz->dir);
        raiz->valor = suc->valor;
        raiz->dir   = remover(raiz->dir, suc->valor);
    }
    return raiz;
}

int buscar(No *raiz, int valor) {
    if (!raiz) return 0;
    if (valor == raiz->valor) return 1;
    if (valor <  raiz->valor) return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

void in_ordem(No *raiz) {
    if (!raiz) return;
    in_ordem(raiz->esq);
    printf("%d ", raiz->valor);
    in_ordem(raiz->dir);
}

void pre_ordem(No *raiz) {
    if (!raiz) return;
    printf("%d ", raiz->valor);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

/* Visualiza a arvore no terminal rotacionada 90 graus */
void visualizar(No *raiz, int nivel) {
    if (!raiz) return;
    visualizar(raiz->dir, nivel + 1);
    for (int i = 0; i < nivel; i++) printf("    ");
    printf("[%d]\n", raiz->valor);
    visualizar(raiz->esq, nivel + 1);
}

void liberar(No *raiz) {
    if (!raiz) return;
    liberar(raiz->esq); liberar(raiz->dir); free(raiz);
}

int main(void) {
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);
    for (int i = 0; i < n; i++) raiz = inserir(raiz, valores[i]);

    printf("In-ordem (crescente): "); in_ordem(raiz); printf("\n");
    printf("Pre-ordem: "); pre_ordem(raiz); printf("\n");
    printf("\nVisualizacao da arvore:\n"); visualizar(raiz, 0);
    printf("\nBuscar 40: %s\n", buscar(raiz, 40) ? "encontrado" : "nao encontrado");
    printf("Buscar 99: %s\n",  buscar(raiz, 99) ? "encontrado" : "nao encontrado");
    raiz = remover(raiz, 30);
    printf("\nApos remover 30:\n"); visualizar(raiz, 0);
    liberar(raiz);
    return 0;
}
