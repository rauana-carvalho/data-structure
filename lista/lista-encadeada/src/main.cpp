#include "../include/LinkedList.h"
#include <iostream>

int main() {
    std::cout << "-- Inicio dos Testes da Lista Encadeada --" << std::endl;
    
    // criacao da lista vazia
    LinkedList lista;
    std::cout << "Lista criada\n" << std::endl;

    // verificar se a lista esta vazia
    std::cout << "A lista esta vazia? \n" << (lista.estaVazia() ? "Sim." : "Nao.") << std::endl;
    std::setlocale(LC_ALL, "en_US.utf8");

    // imprimir lista vazia
    lista.imprimir();

    // inserir um elemento em uma determinada posicao
    std::cout << "\n-- Inserindo elementos --" << std::endl;
    lista.inserir(1, 10);
    lista.imprimir();
    lista.inserir(2, 30);
    lista.imprimir();
    lista.inserir(2, 20);
    lista.imprimir();
    lista.inserir(4, 40);
    lista.imprimir();
    
    // obter o tamanho da lista
    std::cout << "\nTamanho atual da lista " << lista.obterTamanho() << std::endl;
    std::cout << "A lista esta vazia? " << (lista.estaVazia() ? "Sim." : "Nao.") << std::endl;

    // Obter/modificar o valor do elemento de uma determinada posicao na lista
    std::cout << "\n-- Obtendo e modificando elementos --" << std::endl;
    std::cout << "Elemento na posicao 3 " << lista.obterElemento(3) << std::endl;
    std::cout << "Modificando elemento na posicao 3 para 99" << std::endl;
    lista.modificarElemento(3, 99);
    std::cout << "Novo elemento na posicao 3 " << lista.obterElemento(3) << std::endl;
    lista.imprimir();

    // retirar um elemento de uma determinada posicao
    std::cout << "\n-- Retirando elementos --" << std::endl;
    std::cout << "Retirando elemento da posicao 1" << std::endl;
    lista.retirar(1);
    lista.imprimir();
    std::cout << "Tamanho atual " << lista.obterTamanho() << std::endl;
    
    std::cout << "Retirando elemento da ultima posicao 3" << std::endl;
    lista.retirar(3);
    lista.imprimir();
    std::cout << "Tamanho atual " << lista.obterTamanho() << std::endl;

    std::cout << "Retirando elemento da posicao 1" << std::endl;
    lista.retirar(1);
    lista.imprimir();

    std::cout << "Retirando ultimo elemento" << std::endl;
    lista.retirar(1);
    lista.imprimir();
    std::cout << "Tamanho final " << lista.obterTamanho() << std::endl;
    std::cout << "A lista esta vazia? " << (lista.estaVazia() ? "Sim." : "Nao.") << std::endl;

    // teste de excesso de posicao
    try {
        std::cout << "\nTentando retirar de uma lista vazia" << std::endl;
        lista.retirar(1);
    } catch (const std::out_of_range& e) {
        std::cerr << "Capturada excecao esperada " << e.what() << std::endl;
    }

    std::cout << "\n-- Fim dos Testes --" << std::endl;

    return 0;
}