#include <stdio.h>

/*
É um algoritmo básico para colocar vetores em ordem crescente (ou decrescente).
Para ordenar o vetor, utiliza-se uma variável auxiliar para armazenar temporariamente
o maior valor. Isso é feito navegando pelo vetor repetidas vezes com dois
laços de repetição aninhados, empurrando (como uma bolha flutuando)
os maiores valores para o fim do vetor.
*/

int main() {
    int vetor[5] = {7, 2, 4, 1, 9};
    int aux; // Variável auxiliar que funciona como um "copo extra" para ajudar na troca
    int i, j;

    printf("Vetor original: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    /*
     * ALGORITMO BUBBLE SORT
     * O laço 'i' garante que passaremos pelo vetor quantidade de vezes suficiente.
     */
    for(i = 0; i < 5; i++) {
        /*
         * O laço 'j' compara os vizinhos de dois em dois.
         * Ele vai até 4 porque sempre comparamos 'j' com 'j+1'.
         */
        for(j = 0; j < 4; j++) {
            
            // Se o número atual for maior que o vizinho da direita, eles estão fora de ordem
            if (vetor[j] > vetor[j + 1]) {
                
                // PASSO 1: O 'copo extra' guarda o número maior para não o perdermos
                aux = vetor[j];
                
                // PASSO 2: O número menor passa para a casa da esquerda
                vetor[j] = vetor[j + 1];
                
                // PASSO 3: O número maior, que estava no copo, vai para a casa da direita
                vetor[j + 1] = aux;
            }
        }
    }

    printf("Valores em ordem crescente: \n");
    for(i = 0; i < 5; i++) {
        printf("%d\n", vetor[i]);
    }

    return 0;
}