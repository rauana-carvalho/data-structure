#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criaFila(int capacidade) {
    if (capacidade <= 0) {
        return NULL;
    }

    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) {
        return NULL;
    }

    f->dados = (int*) malloc(capacidade * sizeof(int));
    if (f->dados == NULL) {
        free(f);
        return NULL;
    }

    f->capacidade = capacidade;
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;

    return f;
}

void destroiFila(Fila* f) {
    if (f != NULL) {
        free(f->dados);
        free(f);
    }
}

int filaCheia(Fila* f) {
    if (f == NULL) {
        return -1; // Erro: fila não existe
    }
    return (f->tamanho == f->capacidade);
}

int insereFila(Fila* f, int valor) {
    if (f == NULL || filaCheia(f)) {
        return 0; // Não pode inserir em fila cheia ou nula
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade; // Incremento circular
    f->tamanho++;

    return 1;
}

int filaVazia(Fila* f) {
    if (f == NULL) {
        return -1; // Erro: fila não existe
    }
    return (f->tamanho == 0);
}

int removeFila(Fila* f, int* valor_removido) {
    if (f == NULL || filaVazia(f)) {
        return 0; // Não pode remover de fila vazia ou nula
    }

    *valor_removido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade; // Incremento circular
    f->tamanho--;

    return 1;
}

int consultaFila(Fila* f, int* valor_consultado) {
    if (f == NULL || filaVazia(f)) {
        return 0; // Não pode consultar fila vazia ou nula
    }
    *valor_consultado = f->dados[f->inicio];
    return 1;
}

void imprimeFila(Fila* f) {
    if (f == NULL) {
        printf("Fila nula.\n");
        return;
    }
    if (filaVazia(f)) {
        printf("Fila Vazia. ");
    } else {
        printf("Fila: [ ");
        int i = f->inicio;
        int count;
        for (count = 0; count < f->tamanho; count++) {
            printf("%d ", f->dados[i]);
            i = (i + 1) % f->capacidade;
        }
        printf("] ");
    }
    printf("(Inicio: %d, Fim: %d, Tamanho: %d/%d)\n", f->inicio, f->fim, f->tamanho, f->capacidade);
}