#include <stdio.h>
#include <string.h>

/* 
 * DEFINIÇÃO DA STRUCT (Molde do Vinho)
 */
typedef struct {
    char nome[50];
    char tipo[30];
    float preco; // float é usado para números com casas decimais (dinheiro, medidas)
} Vinho;

/* 
 * FUNÇÃO DE LEITURA (Usando Ponteiros)
 * Em vez de criar um Vinho novo aqui dentro, a função recebe um "Ponteiro" (*v).
 * Um ponteiro é como um endereço de GPS. A função sabe onde a variável original está 
 * guardada na memória principal e vai até lá alterar os dados diretamente.
 */
void lerDadosVinho(Vinho *v) {
    /*
     * Quando usamos ponteiros para structs, não podemos usar o ponto (v.nome).
     * Devemos usar a setinha (v->nome). A setinha significa: 
     * "Vá até o endereço de memória e acesse o campo 'nome'".
     */
    printf("Digite o nome do vinho: ");
    fgets(v->nome, 50, stdin);
    v->nome[strcspn(v->nome, "\n")] = 0; // Limpa o "Enter" do final do texto

    printf("Digite o tipo do vinho (Ex: Seco, Suave, Tinto): ");
    fgets(v->tipo, 30, stdin);
    v->tipo[strcspn(v->tipo, "\n")] = 0;

    printf("Digite o preco: ");
    // O '&' não vai antes do 'v->' porque a setinha já está apontando para o endereço exato.
    scanf("%f", &v->preco); 
}

/* 
 * FUNÇÃO DE EXIBIÇÃO
 * Também recebe o endereço do Vinho, apenas para ler os dados sem precisar copiá-los.
 */
void exibirDadosVinho(Vinho *v) {
    printf("\n--- DADOS CADASTRADOS DO VINHO ---\n");
    // O %.2f obriga o programa a mostrar apenas duas casas decimais no preço.
    printf("Nome: %s\nTipo: %s\nPreco: R$ %.2f\n", v->nome, v->tipo, v->preco);
}

int main() {
    // Aqui criamos a variável original na memória da função principal
    Vinho meu_vinho;
    
    printf("--- CADASTRO DE VINHOS ---\n");
    
    /* 
     * CHAMADA DE FUNÇÃO COM PASSAGEM POR REFERÊNCIA
     * O símbolo '&' significa "endereço de". 
     * Nós passamos o "endereço de meu_vinho" para as funções. 
     * Assim, elas sabem exatamente onde gravar ou ler os dados.
     */
    lerDadosVinho(&meu_vinho);
    exibirDadosVinho(&meu_vinho);
    
    return 0;
}