#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 5 // Tamanho fixo usado apenas no Exemplo 1 (Lista Simples Estática)

// =============================================================================
// DEFINIÇÃO DAS ESTRUTURAS (STRUCTS) DOS 3 TIPOS DE LISTA
// =============================================================================

/* 
 * 1. STRUCT DA LISTA SIMPLES (SEQUENCIAL / ESTÁTICA)
 * Guarda os dados em um vetor tradicional de tamanho fixo e usa uma variável
 * 'qtd' para controlar quantas posições já foram preenchidas.
 */
typedef struct {
    int item[TAM_MAX];
    int qtd;
} ListaSimples;

/* 
 * 2. STRUCT DO NÓ DA LISTA SIMPLESMENTE ENCADEADA (DINÂMICA)
 * Segue o padrão exato das aulas de Fila e Pilha: guarda o dado ('num')
 * e um ponteiro ('*prox') que aponta para o próximo nó na memória.
 */
struct No {
    int num;
    struct No *prox;
};
typedef struct No no;

/* 
 * 3. STRUCT DO NÓ DA LISTA DUPLAMENTE ENCADEADA (DINÂMICA)
 * Cada nó possui dois ponteiros: um para o nó anterior ('*ant') e outro
 * para o próximo nó ('*prox'), permitindo navegar nos dois sentidos.
 */
struct NoDuplo {
    int num;
    struct NoDuplo *ant;
    struct NoDuplo *prox;
};
typedef struct NoDuplo noDuplo;

// =============================================================================
// EXEMPLO 1: FUNÇÕES DA LISTA SIMPLES (ESTÁTICA COM VETOR)
// =============================================================================

void iniciarSimples(ListaSimples *ls) {
    ls->qtd = 0; // Começa com zero elementos armazenados
}

void inserirSimples(ListaSimples *ls) {
    // Verifica se o vetor já atingiu o limite máximo
    if (ls->qtd == TAM_MAX) {
        printf("Lista Simples cheia! (Limite de %d itens)\n", TAM_MAX);
        return;
    }

    int valor;
    printf("Digite o valor inteiro para inserir: ");
    scanf("%d", &valor);

    // Grava o valor na primeira posição livre e aumenta o contador
    ls->item[ls->qtd] = valor;
    ls->qtd++;
    printf("Valor %d inserido na posicao [%d]!\n", valor, ls->qtd - 1);
}

void removerSimples(ListaSimples *ls) {
    if (ls->qtd == 0) {
        printf("Lista Simples vazia!\n");
        return;
    }

    int pos, i;
    printf("Digite a posicao (indice de 0 a %d) que deseja remover: ", ls->qtd - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= ls->qtd) {
        printf("Posicao invalida!\n");
        return;
    }

    printf("Removido o valor: %d\n", ls->item[pos]);

    /* 
     * DESLOCAMENTO NO VETOR
     * Como os itens ficam lado a lado na memória, ao tirar um elemento do meio,
     * precisamos puxar todos os elementos da direita uma casa para a esquerda.
     */
    for (i = pos; i < ls->qtd - 1; i++) {
        ls->item[i] = ls->item[i + 1];
    }
    ls->qtd--; // Diminui a quantidade total de elementos
}

void exibirSimples(ListaSimples *ls) {
    if (ls->qtd == 0) {
        printf("Lista Simples vazia!\n");
        return;
    }

    printf("Lista Simples (Vetor): ");
    for (int i = 0; i < ls->qtd; i++) {
        printf("[%d]=%d  ", i, ls->item[i]);
    }
    printf("\n");
}

void menuSimples(ListaSimples *ls) {
    int op;
    do {
        printf("\n--- MENU: 1. LISTA SIMPLES (ESTATICA) ---\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover por posicao\n");
        printf("3. Exibir lista\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 0: break;
            case 1: inserirSimples(ls); break;
            case 2: removerSimples(ls); break;
            case 3: exibirSimples(ls); break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);
}

// =============================================================================
// EXEMPLO 2: FUNÇÕES DA LISTA SIMPLESMENTE ENCADEADA (DINÂMICA)
// =============================================================================

void iniciarEncadeada(no *LISTA) {
    // O nó cabeça começa apontando para NULL, indicando que não há elementos
    LISTA->prox = NULL;
}

int vaziaEncadeada(no *LISTA) {
    if (LISTA->prox == NULL) {
        return 1; // Verdadeiro (está vazia)
    } else {
        return 0; // Falso (tem elementos)
    }
}

no *alocarEncadeada() {
    // Reserva dinamicamente na memória RAM o espaço exato de um struct No
    no *novo = (no *) malloc(sizeof(no));
    if (!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    printf("Digite o valor do novo elemento: ");
    scanf("%d", &novo->num);
    return novo;
}

void inserirInicioEncadeada(no *LISTA) {
    no *novo = alocarEncadeada();
    
    /* 
     * INSERÇÃO NO INÍCIO
     * O novo nó passa a apontar para quem era o antigo primeiro elemento,
     * e o nó cabeça ('LISTA') passa a apontar para o novo nó.
     */
    no *antigoPrimeiro = LISTA->prox;
    LISTA->prox = novo;
    novo->prox = antigoPrimeiro;
}

void inserirFimEncadeada(no *LISTA) {
    no *novo = alocarEncadeada();
    novo->prox = NULL; // Como será o último da fila, não aponta para ninguém

    if (vaziaEncadeada(LISTA)) {
        LISTA->prox = novo;
    } else {
        // Caminha nó por nó até encontrar o último (aquele cujo 'prox' é NULL)
        no *tmp = LISTA->prox;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo; // Engata o novo nó no final da corrente
    }
}

void retirarValorEncadeada(no *LISTA) {
    if (vaziaEncadeada(LISTA)) {
        printf("Lista Encadeada vazia!\n");
        return;
    }

    int valor;
    printf("Digite o valor que deseja remover da lista: ");
    scanf("%d", &valor);

    /* 
     * BUSCA COM DOIS PONTEIROS ('anterior' e 'atual')
     * Precisamos guardar o nó anterior para refazer a ligação da corrente
     * quando o nó 'atual' for apagado da memória.
     */
    no *anterior = LISTA;
    no *atual = LISTA->prox;

    while (atual != NULL && atual->num != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor %d nao encontrado na lista!\n", valor);
    } else {
        // O nó anterior pula o nó removido e aponta direto para o próximo
        anterior->prox = atual->prox;
        printf("Elemento removido: %d\n", atual->num);
        free(atual); // Libera a memória RAM ocupada pelo nó removido
    }
}

void exibirEncadeada(no *LISTA) {
    if (vaziaEncadeada(LISTA)) {
        printf("Lista Encadeada vazia!\n");
        return;
    }

    no *tmp = LISTA->prox;
    printf("Lista Simplesmente Encadeada: ");
    while (tmp != NULL) {
        printf("%d -> ", tmp->num);
        tmp = tmp->prox; // Avança para o próximo nó
    }
    printf("NULL\n");
}

void liberarEncadeada(no *LISTA) {
    if (!vaziaEncadeada(LISTA)) {
        no *proxNo, *atual;
        atual = LISTA->prox;
        while (atual != NULL) {
            proxNo = atual->prox; // Salva o endereço do próximo antes de apagar
            free(atual);          // Libera o nó atual
            atual = proxNo;
        }
        LISTA->prox = NULL;
    }
}

void menuEncadeada(no *LISTA) {
    int op;
    do {
        printf("\n--- MENU: 2. LISTA SIMPLESMENTE ENCADEADA ---\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("1. Inserir no INICIO\n");
        printf("2. Inserir no FIM\n");
        printf("3. Remover um valor especifico\n");
        printf("4. Exibir lista\n");
        printf("5. Limpar lista\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 0: break;
            case 1: inserirInicioEncadeada(LISTA); break;
            case 2: inserirFimEncadeada(LISTA); break;
            case 3: retirarValorEncadeada(LISTA); break;
            case 4: exibirEncadeada(LISTA); break;
            case 5: liberarEncadeada(LISTA); printf("Lista limpa!\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);
}

// =============================================================================
// EXEMPLO 3: FUNÇÕES DA LISTA DUPLAMENTE ENCADEADA (DINÂMICA)
// =============================================================================

void iniciarDupla(noDuplo *LISTA_DUPLA) {
    LISTA_DUPLA->ant = NULL;
    LISTA_DUPLA->prox = NULL;
}

int vaziaDupla(noDuplo *LISTA_DUPLA) {
    return (LISTA_DUPLA->prox == NULL);
}

noDuplo *alocarDupla() {
    noDuplo *novo = (noDuplo *) malloc(sizeof(noDuplo));
    if (!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    printf("Digite o valor do novo elemento: ");
    scanf("%d", &novo->num);
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void inserirFimDupla(noDuplo *LISTA_DUPLA) {
    noDuplo *novo = alocarDupla();

    if (vaziaDupla(LISTA_DUPLA)) {
        // Primeiro elemento real da lista: não há ninguém antes dele (ant = NULL)
        LISTA_DUPLA->prox = novo;
        novo->ant = NULL;
    } else {
        noDuplo *tmp = LISTA_DUPLA->prox;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        /* 
         * DUPLA LIGAÇÃO
         * O antigo último aponta para frente ('prox') para o novo nó,
         * e o novo nó aponta para trás ('ant') para o antigo último.
         */
        tmp->prox = novo;
        novo->ant = tmp;
    }
}

void retirarValorDupla(noDuplo *LISTA_DUPLA) {
    if (vaziaDupla(LISTA_DUPLA)) {
        printf("Lista Dupla vazia!\n");
        return;
    }

    int valor;
    printf("Digite o valor que deseja remover da lista dupla: ");
    scanf("%d", &valor);

    // Como cada nó conhece seu anterior ('ant'), não precisamos de ponteiro auxiliar 'anterior'
    noDuplo *atual = LISTA_DUPLA->prox;
    while (atual != NULL && atual->num != valor) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor %d nao encontrado!\n", valor);
    } else {
        // Se for o primeiro nó real da lista
        if (atual->ant == NULL) {
            LISTA_DUPLA->prox = atual->prox;
            if (atual->prox != NULL) {
                atual->prox->ant = NULL;
            }
        } else {
            // Conecta o vizinho da esquerda diretamente ao vizinho da direita
            atual->ant->prox = atual->prox;
            if (atual->prox != NULL) {
                atual->prox->ant = atual->ant;
            }
        }
        printf("Elemento removido: %d\n", atual->num);
        free(atual);
    }
}

void exibirIdaVoltaDupla(noDuplo *LISTA_DUPLA) {
    if (vaziaDupla(LISTA_DUPLA)) {
        printf("Lista Dupla vazia!\n");
        return;
    }

    noDuplo *tmp = LISTA_DUPLA->prox;

    // 1. Percorre do início para o fim usando o ponteiro 'prox'
    printf("Sentido Normal (Inicio -> Fim): NULL <- ");
    while (tmp != NULL) {
        printf("%d", tmp->num);
        if (tmp->prox != NULL) {
            printf(" <-> ");
            tmp = tmp->prox;
        } else {
            // Para no último nó válido para podermos voltar a partir dele
            break;
        }
    }
    printf(" -> NULL\n");

    // 2. Percorre do fim para o início usando o ponteiro 'ant'
    printf("Sentido Inverso (Fim -> Inicio): ");
    while (tmp != NULL) {
        printf("%d -> ", tmp->num);
        tmp = tmp->ant; // Caminha para trás!
    }
    printf("NULL\n");
}

void liberarDupla(noDuplo *LISTA_DUPLA) {
    if (!vaziaDupla(LISTA_DUPLA)) {
        noDuplo *proxNo, *atual;
        atual = LISTA_DUPLA->prox;
        while (atual != NULL) {
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        }
        LISTA_DUPLA->prox = NULL;
    }
}

void menuDupla(noDuplo *LISTA_DUPLA) {
    int op;
    do {
        printf("\n--- MENU: 3. LISTA DUPLAMENTE ENCADEADA ---\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("1. Inserir no FIM\n");
        printf("2. Remover um valor especifico\n");
        printf("3. Exibir (Ida e Volta)\n");
        printf("4. Limpar lista\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 0: break;
            case 1: inserirFimDupla(LISTA_DUPLA); break;
            case 2: retirarValorDupla(LISTA_DUPLA); break;
            case 3: exibirIdaVoltaDupla(LISTA_DUPLA); break;
            case 4: liberarDupla(LISTA_DUPLA); printf("Lista dupla limpa!\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);
}

// =============================================================================
// FUNÇÃO PRINCIPAL (INTEGRA OS 3 EXEMPLOS EM UM ÚNICO PROGRAMA)
// =============================================================================

int main(void) {
    // 1. Prepara a Lista Simples Estática
    ListaSimples lista1;
    iniciarSimples(&lista1);

    // 2. Aloca o nó cabeça da Lista Simplesmente Encadeada
    no *LISTA2 = (no *) malloc(sizeof(no));
    if (!LISTA2) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    iniciarEncadeada(LISTA2);

    // 3. Aloca o nó cabeça da Lista Duplamente Encadeada
    noDuplo *LISTA3 = (noDuplo *) malloc(sizeof(noDuplo));
    if (!LISTA3) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    iniciarDupla(LISTA3);

    int opt;
    do {
        printf("\n============================================\n");
        printf("   ESTRUTURA DE DADOS - EXEMPLOS DE LISTAS  \n");
        printf("============================================\n");
        printf("0. Sair do programa\n");
        printf("1. Lista Simples (Sequencial / Vetor)\n");
        printf("2. Lista Simplesmente Encadeada (Dinamica)\n");
        printf("3. Lista Duplamente Encadeada (Dinamica)\n");
        printf("Escolha qual estrutura testar: ");
        scanf("%d", &opt);

        switch (opt) {
            case 0:
                // Antes de encerrar, libera toda a memória alocada dinamicamente
                liberarEncadeada(LISTA2);
                free(LISTA2);
                liberarDupla(LISTA3);
                free(LISTA3);
                printf("Memoria liberada. Encerrando...\n");
                break;
            case 1:
                menuSimples(&lista1);
                break;
            case 2:
                menuEncadeada(LISTA2);
                break;
            case 3:
                menuDupla(LISTA3);
                break;
            default:
                printf("Comando invalido!\n");
        }
    } while (opt != 0);

    return 0;
}