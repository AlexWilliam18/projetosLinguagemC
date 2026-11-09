#include <stdio.h>

/* 
 * DEFINE CONSTANTE
 * Cria uma regra que diz: "Sempre que aparecer MAX, troque por 5".
 * Isso facilita se quisermos mudar o tamanho máximo da fila no futuro.
 */
#define MAX 5

/* 
 * ESTRUTURA DA FILA (QUEUE)
 * A fila segue a regra FIFO (First In, First Out) = O primeiro a entrar é o primeiro a sair.
 * Ela precisa de um vetor para guardar os dados e dois marcadores (inicio e fim).
 */
typedef struct {
    int dados[MAX]; // O vetor onde as pessoas/dados vão "esperar"
    int inicio;     // Indica onde está o "primeiro da fila"
    int fim;        // Indica o final da fila (onde o próximo a chegar vai ficar)
} Fila;

/* 
 * FUNÇÃO ENFILEIRAR
 * Coloca um valor no final da fila, caso ela não esteja cheia.
 */
void enfileirar(Fila *f, int val) {
    // Se o marcador 'fim' ainda for menor que o limite máximo...
    if(f->fim < MAX) {
        // Coloca o valor na posição que o 'fim' aponta e, depois, soma 1 no 'fim' (f->fim++)
        f->dados[f->fim++] = val;
    } else {
        printf("A fila esta cheia!\n");
    }
}

int main() {
    /* 
     * INICIALIZAÇÃO DA FILA
     * Cria a fila e ajusta os marcadores de inicio e fim para 0.
     * Isso significa que a fila está vazia.
     */
    Fila fila_num = {.inicio = 0, .fim = 0};
    
    /* 
     * DECLARAÇÃO DA MATRIZ
     * Uma matriz [3][3] é como uma tabela do Excel com 3 linhas e 3 colunas.
     * Ela guarda 9 números no total (3 x 3).
     */
    int matriz[3][3];
    int i, j, valor;

    // =========================================================================
    // CONCEITO 1: FILA
    // =========================================================================
    
    printf("--- INSERINDO NA FILA ---\n");
    printf("Digite 3 valores inteiros para entrar na fila:\n");
    
    // O usuário vai digitar 3 valores para entrar na fila
    for(i = 0; i < 3; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        enfileirar(&fila_num, valor); // Passa a fila e o valor para a função
    }

    printf("\nResultado da Fila (Ordem de Chegada): ");
    // Percorre a fila desde onde ela inicia até onde ela termina
    for(i = fila_num.inicio; i < fila_num.fim; i++) {
        printf("%d ", fila_num.dados[i]);
    }
    printf("\n\n");

    // =========================================================================
    // CONCEITO 2: MATRIZ 3X3
    // =========================================================================
    
    printf("--- PREENCHENDO A MATRIZ 3x3 ---\n");
    printf("Digite 9 valores:\n");
    
    /* 
     * LAÇO DUPLO PARA MATRIZ
     * O laço 'i' controla as Linhas (de cima para baixo).
     * O laço 'j' controla as Colunas (da esquerda para a direita).
     */
    for(i = 0; i < 3; i++) {       // Para cada linha...
        for(j = 0; j < 3; j++) {   // Percorra todas as colunas dessa linha...
            printf("Linha %d, Coluna %d: ", i, j);
            scanf("%d", &matriz[i][j]); // Lê o valor e guarda na posição [linha][coluna]
        }
    }

    /* 
     * APRESENTANDO A MATRIZ
     * Usamos a mesma lógica de repetição dupla para imprimir na tela,
     * organizando visualmente em formato de grade.
     */
    printf("\nResultado da Matriz 3x3:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("[%d] ", matriz[i][j]); // Imprime o elemento lado a lado
        }
        printf("\n"); // Pula de linha ao terminar a leitura de todas as colunas daquela linha
    }

    return 0;
}