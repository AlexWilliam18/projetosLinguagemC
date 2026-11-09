#include <stdio.h>
#include <stdlib.h> // Biblioteca necessária para usar o 'malloc' (alocação dinâmica de memória)

/* 
 * ESTRUTURA DE UM "NÓ" DA LISTA
 * Diferente de um vetor, que é um bloco único de gavetas grudadas, 
 * a lista encadeada é como uma corrente. Cada "Nó" é um elo que contém:
 * 1. O dado que você quer guardar (valor).
 * 2. Um ponteiro que aponta para o próximo elo da corrente (struct No *proximo).
 */
typedef struct No {
    int valor;
    struct No *proximo;
} No;

/* 
 * FUNÇÃO PARA INSERIR NA LISTA
 * Recebe o "Nó Cabeça" (o primeiro elo da corrente) e o valor a ser guardado.
 * Usa um ** (ponteiro duplo) porque a função precisa alterar o início da lista original caso ela esteja vazia.
 */
void inserirLista(No **cabeca, int val) {
    /* 
     * MALLOC (Memory Allocation)
     * Pede ao computador para separar (alocar) um pedaço de memória exatamente do 
     * tamanho de um "Nó" enquanto o programa está rodando. É assim que a lista cresce.
     */
    No *novo_elo = (No*)malloc(sizeof(No));
    
    // Prepara o elo novo
    novo_elo->valor = val;       // Guarda o valor que o usuário digitou
    novo_elo->proximo = NULL;    // Como vai ficar no final, não aponta para ninguém ainda (NULL)
    
    /* 
     * Se a lista estiver totalmente vazia (*cabeca == NULL), 
     * esse elo novo passa a ser o elo principal (a cabeça da corrente).
     */
    if(*cabeca == NULL) {
        *cabeca = novo_elo;
    } else {
        /* 
         * Se já existirem elos, usamos um ponteiro 'atual' para "caminhar" pela 
         * corrente até encontrar o último elo (aquele que aponta para NULL).
         */
        No *atual = *cabeca;
        while(atual->proximo != NULL) {
            atual = atual->proximo; // Pula para o próximo elo
        }
        /* 
         * Ao achar o final da corrente, faz o antigo último elo apontar 
         * para o novo elo que acabamos de criar.
         */
        atual->proximo = novo_elo;
    }
}

int main() {
    int vetor_num[5], i, val;
    
    // Inicia a lista encadeada vazia apontando para o Vazio (NULL)
    No *lista_num = NULL; 

    // =========================================================================
    // CONCEITO 1: VETOR FIXO (Estático)
    // Tamanho travado desde o início. Não pode crescer.
    // =========================================================================
    
    printf("--- TESTE COM VETOR ESTÁTICO ---\n");
    printf("Digite 5 numeros para preencher o vetor fixo:\n");
    
    for(i = 0; i < 5; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor_num[i]);
    }
    
    printf("Resultado do Vetor: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", vetor_num[i]);
    }
    printf("\n\n");

    // =========================================================================
    // CONCEITO 2: LISTA SIMPLES (Dinâmica)
    // Cresce sob demanda criando novos espaços na memória.
    // =========================================================================
    
    printf("--- TESTE COM LISTA ENCADEADA DINÂMICA ---\n");
    printf("Digite 3 numeros para inserir como elos na lista:\n");
    
    for(i = 0; i < 3; i++) {
        printf("Valor do Elo %d: ", i + 1);
        scanf("%d", &val);
        inserirLista(&lista_num, val); // Chama a função que fabrica os elos na memória
    }

    /* 
     * PERCORRENDO E APRESENTANDO A LISTA
     * O ponteiro "atual" recebe a primeira posição (cabeça) e vai pulando 
     * de "próximo" em "próximo" até cair no Vazio (NULL), imprimindo tudo pelo caminho.
     */
    printf("\nResultado da Lista Encadeada: ");
    No *atual = lista_num;
    while(atual != NULL) {
        printf("[%d] -> ", atual->valor);
        atual = atual->proximo; // Pula pro próximo
    }
    printf("NULL (Fim da lista)\n"); // Mostra visualmente que a corrente acabou

    return 0;
}