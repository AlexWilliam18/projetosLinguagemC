#include <stdio.h>

/*
A memória do computador tem posições únicas chamadas "endereços".
Um ponteiro é uma variável especial que não guarda um número ou texto
comum, mas sim o endereço de memória de outra variável. Eles são fundamentais
para modificar variáveis fora do escopo local da função (passagem por referência)
e para criar estruturas de dados dinâmicas que crescem e diminuem durante
a execução do programa.
*/

/*
 * FUNÇÃO DE DOBRAR (PASSAGEM POR REFERÊNCIA)
 * O asterisco (*) indica que estamos recebendo um PONTEIRO.
 * Ou seja, não recebemos uma cópia do número, mas o endereço original dele.
 */
void dobrar(int *num) {
    // (*num) significa "Vá até o endereço apontado e pegue/modifique o valor guardado lá"
    *num = (*num) * 2;
}

int main() {
    int x = 10;
    // O asterisco na declaração cria a variável ponteiro
    int *p;
    
    /* 
     * O 'e' comercial (&) significa "O endereço de".
     * Aqui dizemos que o ponteiro 'p' vai apontar para o endereço da variável 'x'.
     */
    p = &x; 

    printf("Valor de x inicial: %d\n", x);
    // Para ver o endereço na memória, usamos %p (ou %d para ver o número bruto do endereço)
    printf("Endereco de x na memoria: %p\n", p); 
    
    /*
     * Chamamos a função passando o endereço de 'x'. 
     * Sem o uso de ponteiros, a função não conseguiria alterar a variável 'x' original[cite: 144].
     */
    dobrar(&x);
    
    printf("\nValor de x apos a funcao: %d\n", x);

    return 0;
}