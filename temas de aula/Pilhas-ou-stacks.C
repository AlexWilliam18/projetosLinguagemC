#include <stdio.h>
#define TAM_MAX 5

/*
A Pilha funciona sob o princípio LIFO
(Last Input, First Output - o último que entra é o primeiro que sai).
A analogia clássica é uma pilha de livros: o último livro que você
coloca no topo é o primeiro que você tira.
*/

/*
 * ESTRUTURA DA PILHA ESTÁTICA
 * Diferente da fila, a pilha precisa de apenas UM marcador: o 'topo'.
 */
typedef struct {
    int item[TAM_MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1; // -1 significa que não há andares construídos na pilha
}

// Push = Empurrar / Inserir no topo
void push(Pilha *p, int valor) {
    // Se o topo chegou no limite máximo, a pilha transbordou
    if (p->topo == TAM_MAX - 1) {
        printf("A Pilha esta cheia (Stack Overflow)!\n");
    } else {
        // Aumenta o andar (topo)
        p->topo++;
        // Coloca o novo livro (valor) nesse andar
        p->item[p->topo] = valor;
        printf("Inserido no topo (Push): %d\n", valor);
    }
}

// Pop = Estourar / Remover do topo
void pop(Pilha *p) {
    if (p->topo == -1) {
        printf("A Pilha esta vazia!\n");
    } else {
        // Retira o valor do topo
        printf("Removido do topo (Pop): %d\n", p->item[p->topo]);
        // Abaixa o andar (apaga o antigo topo)
        p->topo--;
    }
}

int main() {
    Pilha minha_pilha;
    inicializarPilha(&minha_pilha);

    printf("--- TESTANDO A PILHA (LIFO) ---\n");
    push(&minha_pilha, 10);
    push(&minha_pilha, 20);
    push(&minha_pilha, 30); // 30 fica no topo
    
    printf("\n");
    
    pop(&minha_pilha); // Remove o 30 (último a entrar)
    pop(&minha_pilha); // Remove o 20

    return 0;
}