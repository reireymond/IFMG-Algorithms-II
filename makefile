# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Iinclude -g

# Diretórios
SDIR = src
ODIR = obj
BDIR = bin

# Nome do executável final
TARGET = $(BDIR)/produtora

# Encontra TODOS os arquivos .c nos subdiretórios de 'src'
# Esta é a linha corrigida para garantir que todos os arquivos sejam incluídos.
SOURCES := $(wildcard src/core/*.c) $(wildcard src/modules/cadastros/*.c) $(wildcard src/ui/*.c)

# Converte a lista de fontes .c para uma lista de objetos .o
OBJECTS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SOURCES))

# Regra principal: compila o projeto
all: $(TARGET)

# Regra para criar o executável final (linking)
$(TARGET): $(OBJECTS)
	@if not exist "$(BDIR)" mkdir "$(BDIR)"
	@echo "--> Vinculando objetos para criar o executavel..."
	$(CC) $(OBJECTS) -o $@
	@echo "--> Executavel '$(TARGET)' criado com sucesso."

# Regra para compilar os arquivos .c em .o
$(ODIR)/%.o: $(SDIR)/%.c
	@if not exist "$(@D)" mkdir "$(@D)"
	@echo "--> Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar o projeto
clean:
	@echo "Limpando arquivos gerados..."
	@if exist "$(ODIR)" rmdir /s /q "$(ODIR)"
	@if exist "$(BDIR)" rmdir /s /q "$(BDIR)"
	@echo "Limpeza concluida."

# Regra para compilar e executar o programa
run: all
	@echo "--> Executando o programa..."
	$(TARGET)

# Define as regras que não são arquivos
.PHONY: all clean run