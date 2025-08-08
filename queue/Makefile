# Nome do compilador
CC = gcc

# Flags de compilação
# -Iinclude informa ao compilador para procurar por arquivos de cabeçalho no diretório 'include'
CFLAGS = -Wall -g -Iinclude

# Diretórios
SRCDIR = src
INCDIR = include
BINDIR = bin

# Encontra todos os arquivos .c no diretório de fontes
SRCS = $(wildcard $(SRCDIR)/*.c)

# Gera a lista de arquivos objeto, colocando-os no diretório bin
OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))

# Nome do executável final, que será criado no diretório bin
TARGET = $(BINDIR)/programa_fila

# Regra principal: compila tudo
all: $(TARGET)

# Regra para criar o executável a partir dos arquivos objeto
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR) # Garante que o diretório bin exista
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "Executável '$(TARGET)' criado com sucesso."

# Regra para compilar cada arquivo .c em um arquivo .o no diretório bin/
# $< é a primeira dependência (o arquivo .c)
# $@ é o nome do alvo (o arquivo .o)
$(BINDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BINDIR) # Garante que o diretório bin exista
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados no diretório bin
clean:
	@rm -rf $(BINDIR)
	@echo "Diretório '$(BINDIR)' removido."

# Phony targets não representam arquivos
.PHONY: all clean