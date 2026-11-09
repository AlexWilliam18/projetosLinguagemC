#include <stdio.h>
#include <string.h>

/* 
 * 1. DEFINIÇÃO DA STRUCT
 * Uma struct funciona como um "molde" para criar variáveis compostas.
 * Em vez de criar três variáveis separadas para o título, autor e ano,
 * nós agrupamos tudo dentro de um único pacote chamado "Livro".
 */
typedef struct {
    char titulo[50]; // Espaço para guardar até 49 letras + o caractere de fim de texto
    char autor[50];
    int ano;         // Guarda um número inteiro
} Livro;

int main() {
    /* 
     * 2. DECLARAÇÃO DE VARIÁVEIS DO VETOR
     * Preparamos as variáveis que o computador vai usar para guardar dados na memória.
     */
    int vetor_num[5]; // Cria uma lista (vetor) com 5 "gavetas" para guardar números inteiros
    int aux;          // Variável "auxiliar" usada como um copo extra para trocar os valores de lugar
    int i, j;         // Variáveis de controle usadas para contar as voltas dos laços de repetição (for)

    /* 
     * 3. DECLARAÇÃO DA VARIÁVEL DA STRUCT
     * Criamos uma variável chamada 'livro_atual' usando aquele "molde" que definimos lá em cima.
     */
    Livro livro_atual;

    // =========================================================================
    // CONCEITO 1: VETOR ORDENADO
    // =========================================================================
    
    printf("--- ORDENACAO DE VETOR ---\n");
    printf("Digite 5 numeros inteiros:\n");
    
    /* 
     * LAÇO DE LEITURA
     * O laço 'for' vai rodar 5 vezes (de 0 até 4). 
     * Em cada volta, ele lê um número que o usuário digitou e guarda em uma "gaveta" do vetor.
     */
    for(i = 0; i < 5; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor_num[i]); 
    }
    
    /* 
     * ALGORITMO BUBBLE SORT (Ordenação Bolha)
     * Como funciona: Ele compara o número atual com o próximo. 
     * Se o atual for maior, eles trocam de lugar. Os maiores "flutuam" para o final.
     */
    for(i = 0; i < 4; i++) { // O laço de fora garante que faremos várias passagens pelo vetor
        for(j = 0; j < 4 - i; j++) { // O laço de dentro faz as comparações lado a lado
            
            if(vetor_num[j] > vetor_num[j + 1]) {
                // Se entrou aqui, é porque estão fora de ordem. Vamos trocar!
                aux = vetor_num[j];               // 1. Guarda o valor atual em um lugar seguro (aux)
                vetor_num[j] = vetor_num[j + 1];  // 2. O atual recebe o valor do próximo (que é menor)
                vetor_num[j + 1] = aux;           // 3. O próximo recebe o valor que estava guardado no aux
            }
        }
    }
    
    /* 
     * LAÇO DE APRESENTAÇÃO
     * Percorre as gavetas do vetor novamente, agora que estão ordenadas, para mostrar na tela.
     */
    printf("\nVetor ordenado: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", vetor_num[i]);
    }
    printf("\n");

    // =========================================================================
    // CONCEITO 2: STRUCT DE LIVRO
    // =========================================================================
    
    /* 
     * LIMPEZA DE BUFFER
     * O 'scanf' anterior deixou a tecla "Enter" solta na memória do teclado (buffer).
     * Se não usarmos o 'getchar()' para "engolir" esse Enter, o próximo 'fgets' vai ler
     * esse Enter e pular a leitura do título do livro.
     */
    getchar(); 

    printf("\n--- DADOS DO LIVRO ---\n");
    
    /* 
     * LEITURA DE TEXTO COM FGETS
     * fgets(onde_guardar, tamanho_maximo, de_onde_ler)
     * Lê textos garantindo que não vamos estourar o limite de memória (50 caracteres).
     */
    printf("Digite o titulo do livro: ");
    fgets(livro_atual.titulo, 50, stdin);
    
    /* 
     * REMOÇÃO DO 'ENTER' INVISÍVEL
     * O fgets pega tudo, incluindo o "Enter" (\n) no final. 
     * O strcspn acha onde está esse "Enter" e a linha abaixo substitui ele por 0 (fim de texto).
     */
    livro_atual.titulo[strcspn(livro_atual.titulo, "\n")] = 0;

    printf("Digite o autor do livro: ");
    fgets(livro_atual.autor, 50, stdin);
    livro_atual.autor[strcspn(livro_atual.autor, "\n")] = 0;

    /* 
     * LEITURA DE NÚMERO
     * Lemos o ano e usamos '&' para apontar exatamente onde na memória ele deve ser gravado.
     */
    printf("Digite o ano de publicacao: ");
    scanf("%d", &livro_atual.ano);

    // Apresenta tudo formatado
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Livro Cadastrado: %s\n", livro_atual.titulo);
    printf("Autor: %s\n", livro_atual.autor);
    printf("Ano: %d\n", livro_atual.ano);

    return 0; // Indica que o programa terminou com sucesso
}