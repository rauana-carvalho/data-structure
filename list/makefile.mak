# Nome do compilador
CXX = g++

# Flags de compilação (ex: -Wall -Wextra -g)
CXXFLAGS = -Wall -Wextra -std=c++11

# Nome do executável
TARGET = ListaSequencial

# Regra padrão: compilar e linkar
all: $(TARGET)

# Regras de compilação
$(TARGET): ListaSequencial.o
    $(CXX) $(CXXFLAGS) ListaSequencial.o -o $(TARGET)

ListaSequencial.o: ListaSequencial.cpp
    $(CXX) $(CXXFLAGS) -c ListaSequencial.cpp

# Limpeza
clean:
    rm -f *.o $(TARGET)