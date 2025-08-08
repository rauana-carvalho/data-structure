#ifndef FILA_H
#define FILA_H

// Estrutura que representa a Fila
typedef struct fila {
    int *dados;      // Vetor que armazena os elementos da fila
    int inicio;      // Índice do primeiro elemento da fila
    int fim;         // Índice da próxima posição livre no fim da fila
    int capacidade;  // Capacidade máxima do vetor
    int tamanho;     // Quantidade atual de elementos na fila
} Fila;

// Protótipos das Funções

/**
 * @brief Cria e inicializa uma nova fila.
 * @param capacidade O número máximo de elementos que a fila pode conter.
 * @return Um ponteiro para a fila criada ou NULL em caso de erro.
 */
Fila* criaFila(int capacidade);

/**
 * @brief Libera a memória alocada para a fila.
 * @param f Ponteiro para a fila a ser destruída.
 */
void destroiFila(Fila* f);

/**
 * @brief Insere um elemento no fim da fila.
 * @param f Ponteiro para a fila.
 * @param valor O inteiro a ser inserido.
 * @return 1 em caso de sucesso, 0 se a fila estiver cheia.
 */
int insereFila(Fila* f, int valor); // Inserir no fim da fila [cite: 7]

/**
 * @brief Remove e retorna o elemento do início da fila.
 * @param f Ponteiro para a fila.
 * @param valor_removido Ponteiro para a variável que armazenará o valor removido.
 * @return 1 em caso de sucesso, 0 se a fila estiver vazia.
 */
int removeFila(Fila* f, int* valor_removido); // Remover do início da fila [cite: 8]

/**
 * @brief Consulta o valor do elemento no início da fila sem removê-lo.
 * @param f Ponteiro para a fila.
 * @param valor_consultado Ponteiro para a variável que armazenará o valor consultado.
 * @return 1 em caso de sucesso, 0 se a fila estiver vazia.
 */
int consultaFila(Fila* f, int* valor_consultado); // Consultar o início da fila [cite: 9]

/**
 * @brief Verifica se a fila está vazia.
 * @param f Ponteiro para a fila.
 * @return 1 se a fila estiver vazia, 0 caso contrário.
 */
int filaVazia(Fila* f); // Indicar se a fila está vazia [cite: 10]

/**
 * @brief Verifica se a fila está cheia.
 * @param f Ponteiro para a fila.
 * @return 1 se a fila estiver cheia, 0 caso contrário.
 */
int filaCheia(Fila* f); // Indicar se a fila está cheia [cite: 11]

/**
 * @brief Imprime o estado atual da fila (para depuração).
 * @param f Ponteiro para a fila.
 */
void imprimeFila(Fila* f);

#endif // FILA_H