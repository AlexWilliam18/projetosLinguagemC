#include <stdio.h>
#include <string.h>

/* 
 * DEFINIÇÃO DA STRUCT DE FRUTAS
 * Criamos um modelo com 3 variáveis diferentes (textos e números) 
 * unidas sob o guarda-chuva chamado 'Fruta'.
 */
typedef struct {
    char nome[30]; // Guarda textos de até 29 letras
    char cor[20];
    float peso;    // Guarda o peso com casas decimais (ex: 1.5)
} Fruta;

int main() {
    // 1. Variável composta baseada na Struct
    Fruta fruta_atual;
    
    // 2. Variáveis para o Vetor Isolado e Ordenação
    int vetor_num[4];
    int i, j, aux;

    // =========================================================================
    // CONCEITO 1: STRUCT ISOLADA
    // O usuário preenche os 3 campos e o programa devolve a informação formatada.
    // =========================================================================
    
    printf("--- CADASTRO DA FRUTA ---\n");
    
    printf("Digite o nome da fruta: ");
    fgets(fruta_atual.nome, 30, stdin);
    fruta_atual.nome[strcspn(fruta_atual.nome, "\n")] = 0; // Limpa o "Enter" final

    printf("Digite a cor da fruta: ");
    fgets(fruta_atual.cor, 20, stdin);
    fruta_atual.cor[strcspn(fruta_atual.cor, "\n")] = 0;

    // Lembrete: Variáveis float no 'scanf' sempre pedem o '&' para saber o endereço.
    printf("Digite o peso da fruta em Kg (ex: 1.5): ");
    scanf("%f", &fruta_atual.peso);

    printf("\n--- INFORMACOES ARMAZENADAS ---\n");
    printf("Fruta: %s\nCor: %s\nPeso: %.2f kg\n\n", fruta_atual.nome, fruta_atual.cor, fruta_atual.peso);

    // =========================================================================
    // CONCEITO 2: VETOR ORDENADO ISOLADO
    // =========================================================================
    
    printf("--- ORDENACAO DE VETOR (Bubble Sort) ---\n");
    printf("Digite 4 numeros aleatorios para o vetor:\n");
    
    // Passo 1: Receber os valores soltos que o usuário digitar
    for(i = 0; i < 4; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor_num[i]);
    }

    // Passo 2: Algoritmo de Ordenação Bolha (Bubble Sort)
    // O primeiro 'for' garante que verificaremos todo o vetor as vezes que forem necessárias.
    for(i = 0; i < 3; i++) {
        // O segundo 'for' empurra o maior número da rodada para a direita.
        for(j = 0; j < 3 - i; j++) {
            
            // Se a casa atual for maior que a casa da direita...
            if(vetor_num[j] > vetor_num[j + 1]) {
                // ... elas trocam de lugar usando a variável auxiliar
                aux = vetor_num[j];
                vetor_num[j] = vetor_num[j + 1];
                vetor_num[j + 1] = aux;
            }
        }
    }

    // Passo 3: Apresentar o resultado final que já está organizado do menor pro maior
    printf("\nResultado do Vetor Ordenado: ");
    for(i = 0; i < 4; i++) {
        printf("%d ", vetor_num[i]);
    }
    printf("\n");

    return 0;
}