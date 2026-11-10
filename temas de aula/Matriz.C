#include <stdio.h>

int main() {

    /*
    Uma matriz é basicamente um vetor com mais de uma dimensão
    (como uma tabela bidimensional com linhas e colunas), sendo muito
    utilizada em sistemas de geolocalização e jogos 2D para mapear coordenadas
    (eixos X e Y). Para percorrê-la, utilizamos laços de repetição aninhados
    (um for dentro de outro for) para automatizar a leitura e o preenchimento
    de cada dimensão.
    */

    /* 
     * DECLARAÇÃO DA MATRIZ
     * O primeiro colchete representa a quantidade de LINHAS [3].
     * O segundo colchete representa a quantidade de COLUNAS [3].
     */
    int mtz[3][3];
    int i, j;

    printf("--- PREENCHENDO A MATRIZ 3x3 ---\n");
    
    // O laço de fora (i) controla as LINHAS
    for(i = 0; i < 3; i++) {
        // O laço de dentro (j) controla as COLUNAS daquela linha
        for(j = 0; j < 3; j++) {
            printf("Digite o valor para a posicao [Linha %d][Coluna %d]: ", i, j);
            // O '&' pega o endereço exato daquela coordenada para gravar o número
            scanf("%d", &mtz[i][j]);
        }
    }

    printf("\n--- RESULTADO DA MATRIZ ---\n");
    // Repetimos a mesma estrutura de laços duplos para exibir os dados na tela
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            // Imprime o número e um espaço, ficando um ao lado do outro
            printf("[%d] ", mtz[i][j]);
        }
        // Ao terminar de imprimir todas as colunas de uma linha, pulamos para a linha de baixo
        printf("\n");
    }

    return 0;
}