# 📚 Algoritmos e Estruturas de Dados em C

> Implementações em linguagem C com comentários explicativos em português. Ideal para estudantes de Ciência da Computação.

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow?style=for-the-badge)

---

## 📁 Estrutura do Repositório

```
📦 Algoritmos-e-Estruturas-C
├── 📂 ordenacao/
│   ├── bubble_sort.c       — O(n²) estável, otimizado
│   ├── selection_sort.c    — O(n²), mínimo de trocas
│   ├── insertion_sort.c    — O(n) melhor caso
│   ├── merge_sort.c        — O(n log n) garantido
│   └── quick_sort.c        — O(n log n) médio, in-place
├── 📂 busca/
│   ├── busca_linear.c      — O(n), sem pré-requisitos
│   └── busca_binaria.c     — O(log n), iterativa + recursiva
├── 📂 listas/
│   ├── lista_simples.c     — encadeada simples completa
│   └── lista_dupla.c       — encadeada dupla bidirecional
├── 📂 pilhas-filas/
│   ├── pilha.c             — LIFO com lista encadeada
│   └── fila.c              — FIFO com ponteiros cabeca/cauda
└── 📂 arvores/
    └── arvore_binaria.c    — BST com visualização no terminal
```

---

## 🚀 Como Compilar

Qualquer arquivo pode ser compilado individualmente com `gcc`:

```bash
gcc -Wall -o programa ordenacao/bubble_sort.c && ./programa
```

Ou use o `Makefile` (em breve) para compilar todos de uma vez.

---

## 📊 Tabela de Complexidades

| Algoritmo | Melhor | Médio | Pior | Espaço |
|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Busca Linear | O(1) | O(n) | O(n) | O(1) |
| Busca Binária | O(1) | O(log n) | O(log n) | O(1) |
| BST Inserir | O(1) | O(log n) | O(n) | O(1) |

---

## 🧠 Conceitos Praticados

- **Ponteiros e ponteiros duplos** — listas, árvores, swap
- **Alocação dinâmica** — `malloc`, `realloc`, `free`
- **Structs** — nós de listas, árvores e filas
- **Recursão** — merge sort, quick sort, BST, busca binária
- **Divisão e Conquista** — merge sort, quick sort
- **Percursos em árvore** — in-ordem, pré-ordem, pós-ordem
- **Visualização no terminal** — árvore BST rotacionada

---

## 📌 Requisitos

- GCC (qualquer versão moderna)
- Sistema operacional: Linux, macOS ou Windows (WSL/MinGW)

---

## 👨‍💻 Autor

Feito por **Igor ASB** — estudante de Ciência da Computação.

[![GitHub](https://img.shields.io/badge/GitHub-IgorASB-181717?style=flat&logo=github)](https://github.com/IgorASB)

---

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
