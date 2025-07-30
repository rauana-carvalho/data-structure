#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// classe que representa um nó individual da lista
class Node {
public:
    int data;
    Node* next;

    // construtor para inicializar um nó com um dado e um ponteiro para o próximo
    Node(int data_val, Node* next_ptr = nullptr) {
        data = data_val;
        next = next_ptr;
    }
};

class LinkedList {
private:
    Node* head; // ponteiro para o primeiro nó da lista
    int list_size;

public:

    LinkedList();

    ~LinkedList();
    
    bool estaVazia();

    int obterTamanho();

    int obterElemento(int posicao);
    
    void modificarElemento(int posicao, int valor);

    void inserir(int posicao, int valor);

    void retirar(int posicao);

    void imprimir();
};

#endif