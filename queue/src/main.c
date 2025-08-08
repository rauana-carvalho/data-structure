#include <stdio.h>
#include "fila.h"

void linha() {
    printf("\n--------------------------------------------------\n");
}

int main() {
    printf("Iniciando testes da Fila Circular.\n");
    linha();

    // Teste 1: Criar fila com capacidade 5
    printf("Criando uma fila com capacidade para 5 elementos...\n");
    Fila* minha_fila = criaFila(5);
    imprimeFila(minha_fila);

    // Teste 2: Verificar se a fila recém-criada está vazia
    printf("A fila esta vazia? %s\n", filaVazia(minha_fila) ? "Sim" : "Nao"); // Deve ser "Sim"
    printf("A fila esta cheia? %s\n", filaCheia(minha_fila) ? "Sim" : "Nao"); // Deve ser "Nao"
    linha();

    // Teste 3: Inserir elementos na fila
    printf("Inserindo os valores 10, 20, 30:\n");
    insereFila(minha_fila, 10);
    insereFila(minha_fila, 20);
    insereFila(minha_fila, 30);
    imprimeFila(minha_fila);

    // Teste 4: Consultar o início da fila
    int valor_consultado;
    if (consultaFila(minha_fila, &valor_consultado)) {
        printf("Consulta do inicio da fila: %d\n", valor_consultado); // Deve ser 10
    }
    imprimeFila(minha_fila); // Garante que a consulta não alterou a fila
    linha();

    // Teste 5: Remover um elemento
    int valor_removido;
    if (removeFila(minha_fila, &valor_removido)) {
        printf("Valor removido do inicio: %d\n", valor_removido); // Deve ser 10
    }
    imprimeFila(minha_fila);

    // Teste 6: Consultar novamente o início
    if (consultaFila(minha_fila, &valor_consultado)) {
        printf("Consulta do inicio da fila apos remocao: %d\n", valor_consultado); // Deve ser 20
    }
    linha();

    // Teste 7: Encher a fila para testar o incremento circular
    printf("Inserindo 40, 50, 60 para encher a fila...\n");
    insereFila(minha_fila, 40);
    insereFila(minha_fila, 50);
    insereFila(minha_fila, 60);
    imprimeFila(minha_fila);
    printf("A fila esta cheia? %s\n", filaCheia(minha_fila) ? "Sim" : "Nao"); // Deve ser "Sim"

    // Teste 8: Tentar inserir em uma fila cheia
    printf("Tentando inserir o valor 70 em uma fila cheia...\n");
    if (!insereFila(minha_fila, 70)) {
        printf("Falha ao inserir: a fila esta cheia, como esperado.\n");
    }
    linha();

    // Teste 9: Remover todos os elementos para testar o incremento circular do início
    printf("Removendo todos os elementos da fila...\n");
    while (!filaVazia(minha_fila)) {
        removeFila(minha_fila, &valor_removido);
        printf("Removeu: %d. ", valor_removido);
        imprimeFila(minha_fila);
    }
    printf("A fila esta vazia? %s\n", filaVazia(minha_fila) ? "Sim" : "Nao"); // Deve ser "Sim"
    linha();

    // Teste 10: Tentar remover e consultar em fila vazia
    printf("Tentando remover de uma fila vazia...\n");
    if (!removeFila(minha_fila, &valor_removido)) {
        printf("Falha ao remover: a fila esta vazia, como esperado.\n");
    }
    printf("Tentando consultar uma fila vazia...\n");
    if (!consultaFila(minha_fila, &valor_consultado)) {
        printf("Falha ao consultar: a fila esta vazia, como esperado.\n");
    }
    linha();
    
    // Teste 11: Reutilizar a fila após esvaziar
    printf("Reutilizando a fila. Inserindo 100 e 200...\n");
    insereFila(minha_fila, 100);
    insereFila(minha_fila, 200);
    imprimeFila(minha_fila);
    linha();

    // Teste Final: Liberar a memória
    printf("Testes concluidos. Liberando memoria...\n");
    destroiFila(minha_fila);
    printf("Memoria liberada.\n");

    return 0;
}