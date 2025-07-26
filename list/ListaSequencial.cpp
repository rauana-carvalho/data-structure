#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::runtime_error;
using std::out_of_range;



class ListaSequencial {
private:
    static const size_t CAPACIDADE = 10;
    int vetor[CAPACIDADE];
    size_t tamanho;

public:
    ListaSequencial() : tamanho(0) {}

    bool estaVazia() const {
        return tamanho == 0;
    }

    bool estaCheia() const {
        return tamanho == CAPACIDADE;
    }

    size_t obterTamanho() const {
        return tamanho;
    }

    int obterElemento(size_t pos) const {
        validarPosicao(pos);
        return vetor[pos - 1];
    }

    void modificarElemento(size_t pos, int novoValor) {
        validarPosicao(pos);
        vetor[pos - 1] = novoValor;
    }

    void inserir(size_t pos, int valor) {
        if (estaCheia()) {
            throw std::runtime_error("A lista está cheia. Não é possível inserir.");
        }
        if (pos < 1 || pos > tamanho + 1) {
            throw std::out_of_range("Posição de inserção inválida.");
        }
        for (size_t i = tamanho; i >= pos; --i) {
            vetor[i] = vetor[i - 1];
        }
        vetor[pos - 1] = valor;
        ++tamanho;
    }

    void remover(size_t pos) {
        if (estaVazia()) {
            throw std::runtime_error("A lista está vazia. Não é possível remover.");
        }
        validarPosicao(pos);
        for (size_t i = pos; i < tamanho; ++i) {
            vetor[i - 1] = vetor[i];
        }
        --tamanho;
    }

private:
    void validarPosicao(size_t pos) const {
        if (pos < 1 || pos > tamanho) {
            throw std::out_of_range("Posição inválida.");
        }
    }
};



int main() {
    ListaSequencial lista;

    cout << "### TESTE 1: Lista vazia ###" << endl;
    cout << "A lista está vazia? " << (lista.estaVazia() ? "Sim" : "Não") << endl;
    cout << "Tamanho da lista: " << lista.obterTamanho() << endl << endl;

    cout << "### TESTE 2: Inserindo elementos ###" << endl;
    try {
        lista.inserir(1, 10);
        lista.inserir(2, 20);
        lista.inserir(3, 30);
        lista.inserir(2, 15);
    }
    catch (const std::exception& e) {
        cout << "Erro ao inserir: " << e.what() << endl;
    }

    cout << "Elementos após inserções: ";
    for (size_t i = 1; i <= lista.obterTamanho(); i++) {
        cout << lista.obterElemento(i) << " ";
    }
    cout << endl;

    cout << "\n### TESTE 3: Modificando elemento ###" << endl;
    try {
        lista.modificarElemento(2, 999);
    }
    catch (const std::exception& e) {
        cout << "Erro ao modificar: " << e.what() << endl;
    }
    cout << "Elementos após modificação: ";
    for (size_t i = 1; i <= lista.obterTamanho(); i++) {
        cout << lista.obterElemento(i) << " ";
    }
    cout << endl;

    cout << "\n### TESTE 4: Removendo elemento ###" << endl;
    try {
        lista.remover(2);
    }
    catch (const std::exception& e) {
        cout << "Erro ao remover: " << e.what() << endl;
    }
    cout << "Elementos após remoção: ";
    for (size_t i = 1; i <= lista.obterTamanho(); i++) {
        cout << lista.obterElemento(i) << " ";
    }
    cout << endl;

    cout << "\n### TESTE 5: Verificando lista cheia ###" << endl;
    cout << "A lista está cheia? " << (lista.estaCheia() ? "Sim" : "Não") << endl;
    try {
        while (!lista.estaCheia()) {
            lista.inserir(lista.obterTamanho() + 1, 999);
        }
    }
    catch (const std::exception& e) {
        cout << "Erro ao inserir: " << e.what() << endl;
    }
    cout << "A lista está cheia agora? " << (lista.estaCheia() ? "Sim" : "Não") << endl;
    cout << "Tamanho da lista: " << lista.obterTamanho() << endl;

    cout << "\n### TESTE 6: Tentando inserir em lista cheia ###" << endl;
    try {
        lista.inserir(1, 12345);
    }
    catch (const std::exception& e) {
        cout << "Erro ao inserir em lista cheia: " << e.what() << endl;
    }

    cout << "\nEstado final da lista: ";
    for (size_t i = 1; i <= lista.obterTamanho(); i++) {
        cout << lista.obterElemento(i) << " ";
    }
    cout << endl;

    return 0;
}
