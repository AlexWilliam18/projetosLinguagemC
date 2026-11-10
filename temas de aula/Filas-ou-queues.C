#include <stdio.h>
#define TAM_MAX 5

/*
A Fila é uma estrutura baseada no princípio FIFO
(First Input, First Output - o primeiro que entra é o primeiro que sai).
Imagine uma fila de banco: a primeira pessoa que chegou será a primeira
a ser atendida e sair. Na programação, inserimos dados no final
e retiramos sempre do início.
*/

/*
 * ESTRUTURA DA FILA ESTÁTICA
 * Usamos um vetor para guardar os itens e duas variáveis (frente e tras)
 * para marcar onde a fila começa e onde ela termina.
 */
typedef struct {
    int item[TAM_MAX];
    int frente;
    int tras;
} Fila;

void inicializarFila(Fila *f) {
    // -1 indica que a fila está vazia (não aponta para nenhum índice válido)
    f->frente = -1;
    f->tras = -1;
}

void enfileirar(Fila *f, int valor) {
    // Verifica se o marcador de trás já chegou no limite do vetor
    if (f->tras == TAM_MAX - 1) {
        printf("A Fila esta cheia!\n");
    } else {
        // Se for o primeiro elemento, a frente passa a ser 0
        if (f->frente == -1) {
            f->frente = 0;
        }
        // O marcador 'tras' anda uma casa para frente
        f->tras++;
        // Guardamos o valor na nova casa
        f->item[f->tras] = valor;
        printf("Enfileirado: %d\n", valor);
    }
}

void desenfileirar(Fila *f) {
    if (f->frente == -1) {
        printf("A Fila esta vazia!\n");
    } else {
        printf("Desenfileirado: %d\n", f->item[f->frente]);
        
        // Se a frente alcançou a parte de trás, significa que era o último elemento
        if (f->frente == f->tras) {
            // Esvazia a fila resetando os marcadores
            f->frente = -1;
            f->tras = -1;
        } else {
            // O próximo da fila passa a ser a nova frente (FIFO)
            f->frente++;
        }
    }
}

int main() {
    Fila minha_fila;
    inicializarFila(&minha_fila);

    printf("--- TESTANDO A FILA (FIFO) ---\n");
    enfileirar(&minha_fila, 10);
    enfileirar(&minha_fila, 20);
    enfileirar(&minha_fila, 30);
    
    printf("\n");
    
    desenfileirar(&minha_fila); // Vai remover o 10 (primeiro a entrar)
    desenfileirar(&minha_fila); // Vai remover o 20

    return 0;
}