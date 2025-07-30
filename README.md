# Data Structures

This repository contains implementations of classic data structures, including:

- **Sorting Algorithms (Algorítimos de Ordenação)**:  Classic sorting algorithms.
- **Tic Tac Toe (Jogo da Velha)**: Command-line Tic Tac Toe game.
- **Sequential List (Lista Sequencial)**: Array-based list.
- **Linked List (Lista Encadeada)**: Singly linked list.

## Folder Structure

```
data-structures/
  algoritimos-de-ordenacao/
    instancias-num/
    selection-vs-insertion.py
    ...
  jogo-da-velha/
    src/
      main.py
      ...
  lista/
    lista-sequencial/
      src/
        ListaSequencial.cpp
        ...
    lista-encadeada/
      src/
        main.cpp
        LinkedList.cpp
      include/
        LinkedList.h
```

## How to Compile and Run

### Requirements
- GCC (g++)

### Compile and Run Linked List Example

From the root of the repository, run:

```sh
cd lista/lista-encadeada
mkdir -p bin
cd bin
# Compile:
g++ ../src/main.cpp ../src/LinkedList.cpp -I../include -o main.exe
# Run:
./main.exe
```

### Compile and Run Sequential List Example

From the root of the repository, run:

```sh
cd lista/lista-sequencial
# Compile:
g++ src/ListaSequencial.cpp -o ListaSequencial.exe
# Run:
./ListaSequencial.exe
```

## Notes
- All code is in Portuguese for academic purposes.
- Exception messages and output use UTF-8. If you see strange characters, set your terminal to UTF-8 or use `std::setlocale(LC_ALL, "en_US.utf8");` in your `main()`.

## Author

GitHub: [@rauana-carvalho](https://github.com/rauana-carvalho)  
LinkedIn: [Rauana Carvalho](https://www.linkedin.com/in/rauana-carvalho-8a61241b9/)


Feel free to open issues or contribute! 🍅

##### data-structures