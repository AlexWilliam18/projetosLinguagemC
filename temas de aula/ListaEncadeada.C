#include <stdio.h>  // Biblioteca padrão para entrada e saída de dados (printf e scanf)
#include <stdlib.h> // Biblioteca necessária para alocação dinâmica de memória (malloc, free e NULL)

/* 
 * 1. DEFINIÇÃO DO NÓ (ESTRUTURA AUTO-REFERENCIADA)
 * Cada elemento da lista encadeada é chamado de "Nó".
 * Diferente de um vetor (onde os dados ficam grudados lado a lado na memória),
 * aqui cada nó pode ficar em qualquer lugar da memória, desde que guarde
 * o endereço de onde está o próximo nó.
 */
struct No
{
    int dado;            // Guarda o valor numérico útil do nó (ex: 10, 25, 40)
    struct No* proximo;  // Ponteiro que guarda o ENDEREÇO DE MEMÓRIA do próximo nó da corrente
};

/* 
 * 2. FUNÇÃO DE BUSCA NA LISTA
 * - struct No* inicio: recebe o endereço de memória do 1º nó (ponto de partida).
 * - int valorBuscado: recebe a cópia do número que o usuário digitou para procurar.
 */
void buscarNaLista(struct No* inicio, int valorBuscado)
{
    /* 
     * PONTEIRO AUXILIAR DE NAVEGAÇÃO ('atual')
     * Criamos um ponteiro chamado 'atual' que começa apontando para o mesmo lugar
     * que 'inicio'. Fazemos isso para poder "caminhar" pela lista sem perder a
     * referência de onde ela começa.
     */
    struct No* atual = inicio;
    
    int posicao = 1;     // Contador visual para mostrar em qual nó o valor está (1º, 2º, 3º...)
    int encontrado = 0;  // Variável "bandeira" (flag): 0 = não achou ainda | 1 = achou
    
    /* 
     * LAÇO DE PERCURSO
     * Enquanto 'atual' for diferente de NULL (ou seja, enquanto ainda houver um nó válido
     * e não tivermos chegado ao fim da corrente), o laço continua rodando.
     */
    while (atual != NULL)
    {
        /* 
         * OPERADOR SETA (->)
         * Como 'atual' é um ponteiro para uma struct, usamos '->' para acessar
         * o campo 'dado' dentro do endereço de memória para o qual ele aponta agora.
         */
        if(atual -> dado == valorBuscado)
        {
            printf("\nValor %d encontrado no no %d da lista!\n", valorBuscado, posicao);
            encontrado = 1; // Sinaliza que o número foi localizado
            break;          // Interrompe o 'while' imediatamente, pois não precisa procurar mais
        }
        
        /* 
         * O "PULO" PARA O PRÓXIMO NÓ
         * Esta linha faz a mágica da lista encadeada: 'atual' deixa de apontar para o
         * nó presente e passa a apontar para o endereço guardado no campo 'proximo'.
         */
        atual = atual -> proximo;
        posicao++; // Incrementa o contador para acompanhar o avanço para o próximo nó
    }
    
    /* 
     * VERIFICAÇÃO FINAL
     * Se o 'while' terminou (chegou em NULL) e a bandeira 'encontrado' continuou 0,
     * significa que percorremos todos os nós e o número não estava em nenhum deles.
     */
    if (encontrado == 0)
    {
        printf("\n Valor %d nao existe na lista.\n", valorBuscado);
    }
}

int main()
{
    /* 
     * 3. ALOCAÇÃO DINÂMICA DE MEMÓRIA (MALLOC)
     * - sizeof(struct No): calcula quantos bytes um nó ocupa na memória RAM.
     * - malloc(...): pede ao sistema operacional esse espaço livre na memória.
     * - (struct No*): converte o endereço genérico retornado pelo malloc para um ponteiro de 'No'.
     * Aqui criamos 3 "caixinhas" independentes na memória, ainda desconectadas entre si.
     */
    struct No* primeiro = (struct No*)malloc(sizeof(struct No));
    struct No* segundo = (struct No*)malloc(sizeof(struct No));
    struct No* terceiro = (struct No*)malloc(sizeof(struct No));
    
    /* 
     * 4. PREENCHIMENTO E ENCADEAMENTO (LIGAÇÃO DOS NÓS)
     * Agora conectamos os nós formando a corrente: [10] -> [25] -> [40] -> NULL
     */
    primeiro->dado = 10;          // Guarda o valor 10 dentro do 1º nó
    primeiro->proximo = segundo;  // Faz o 1º nó apontar para o endereço do 2º nó
    
    segundo->dado = 25;           // Guarda o valor 25 dentro do 2º nó
    segundo->proximo = terceiro;  // Faz o 2º nó apontar para o endereço do 3º nó
    
    terceiro->dado = 40;          // Guarda o valor 40 dentro do 3º nó
    terceiro->proximo = NULL;     // Como não há 4º nó, aponta para NULL (indica o fim da lista)
    
    /* 
     * 5. INTERAÇÃO COM O USUÁRIO
     */
    int alvo;
    printf("Lista atual: 10 -> 25 -> 40\n");
    printf("Digite um numero para buscar: ");
    scanf("%d", &alvo); // Lê o número digitado e guarda no endereço de 'alvo'
    
    // Chama a função passando o endereço do 1º nó ('primeiro') e o número procurado ('alvo')
    buscarNaLista(primeiro, alvo);
    
    /* 
     * 6. LIBERAÇÃO DE MEMÓRIA (FREE)
     * Tudo o que foi reservado manualmente com 'malloc' precisa ser devolvido
     * ao sistema operacional com 'free' antes de o programa encerrar, evitando
     * vazamento de memória (memory leak).
     */
    free(primeiro);
    free(segundo);
    free(terceiro);
    
    return 0; // Encerra o programa indicando execução bem-sucedida
}