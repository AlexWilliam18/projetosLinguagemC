#include <stdio.h>

/*
Structs (estruturas) são blocos brutos de dados que permitem agrupar variáveis
de tipos diferentes sob um único nome. Diferente de um vetor
(onde todas as gavetas devem ser do mesmo tipo, ex: só inteiros), numa
Struct você pode ter textos, inteiros e números decimais misturados.
Para adicionar ou ler o conteúdo de um campo, referenciamos a variável
estruturada, seguida de um ponto (.) e o nome do campo.
*/

/*
 * DEFINIÇÃO DA STRUCT
 * Funciona como um "molde" ou formulário chamado 'Estudante'.
 * Ela agrupa um texto (nome), um inteiro (idade) e um decimal (nota)[cite: 134].
 */
struct Estudante {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    /* 
     * DECLARAÇÃO
     * Cria a variável 'e' usando o "molde" que acabamos de criar.
     */
    struct Estudante e;

    printf("--- CADASTRO DE ESTUDANTE ---\n");
    
    // Para acessar cada campo, usamos a variável 'e' + um ponto + o nome do campo.
    printf("Digite o nome (sem espacos): ");
    scanf("%s", e.nome); // Vetor de caracteres não precisa do '&' no scanf
    
    printf("Digite a idade: ");
    scanf("%d", &e.idade); // Variáveis comuns precisam do '&' para guardar no endereço certo
    
    printf("Digite a nota: ");
    scanf("%f", &e.nota);

    /* 
     * APRESENTAÇÃO
     * Lemos os dados exatamente da mesma forma: variável.campo
     */
    printf("\n--- DADOS CADASTRADOS ---\n");
    printf("Nome: %s\n", e.nome);
    printf("Idade: %d\n", e.idade);
    printf("Nota: %.2f\n", e.nota);

    return 0;
}