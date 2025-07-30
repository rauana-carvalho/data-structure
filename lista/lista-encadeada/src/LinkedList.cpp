#include "../include/LinkedList.h"
#include <iostream>
#include <stdexcept>

LinkedList::LinkedList() {
    head = nullptr;
    list_size = 0;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
}

// verifica se a lista está vazia
bool LinkedList::estaVazia() {
    return list_size == 0;
}

// retorna o tamanho da lista
int LinkedList::obterTamanho() {
    return list_size;
}

// obtém o valor de um elemento em uma dada posição
int LinkedList::obterElemento(int posicao) {
    // Validação da posição [cite: 17, 18]
    if (posicao < 1 || posicao > list_size) {
        throw std::out_of_range("Posição inválida para obterElemento.");
    }

    Node* current = head;
    for (int i = 1; i < posicao; ++i) {
        current = current->next;
    }
    return current->data;
}

// modifica o valor de um elemento em uma dada posição
void LinkedList::modificarElemento(int posicao, int valor) {
    // Validação da posição [cite: 17, 18]
    if (posicao < 1 || posicao > list_size) {
        throw std::out_of_range("Posição inválida para modificarElemento.");
    }
    
    Node* current = head;
    for (int i = 1; i < posicao; ++i) {
        current = current->next;
    }
    current->data = valor;
}

// insere um elemento em uma dada posição
void LinkedList::inserir(int posicao, int valor) {
    if (posicao < 1 || posicao > list_size + 1) {
        throw std::out_of_range("Posição inválida para inserção.");
    }

    Node* new_node = new Node(valor);
    
    if (posicao == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        Node* prev = head;
        for (int i = 1; i < posicao - 1; ++i) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
    list_size++;
}

// retira um elemento de uma dada posição
void LinkedList::retirar(int posicao) {
    if (posicao < 1 || posicao > list_size) {
        throw std::out_of_range("Posição inválida para retirada.");
    }
    
    Node* to_delete = nullptr;
    if (posicao == 1) {
        to_delete = head;
        head = head->next;
    } else {
        Node* prev = head;
        for (int i = 1; i < posicao - 1; ++i) {
            prev = prev->next;
        }
        to_delete = prev->next;
        prev->next = to_delete->next;
    }
    
    delete to_delete;
    list_size--;
}

// imprime todos os elementos da lista
void LinkedList::imprimir() {
    if (estaVazia()) {
        std::cout << "Lista Vazia." << std::endl;
        return;
    }

    Node* current = head;
    std::cout << "Lista: [ ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "]" << std::endl;
}