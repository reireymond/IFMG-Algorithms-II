# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Iinclude

# Diretórios
SDIR = src
ODIR = obj
BDIR = bin

# Nome do executável final
TARGET = $(BDIR)/produtora

# --- CORREÇÃO AQUI ---
# Lista os arquivos .c usando wildcard, que é compatível com Windows.
SOURCES = $(wildcard src/core/*.c src/lib/*.c src/modules/cadastros/*.c src/ui/*.c)

# Converte a lista de fontes .c para uma lista de objetos .o
OBJECTS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SOURCES))

# Regra principal: compila o projeto
all: $(TARGET)

# Regra para criar o executável final
$(TARGET): $(OBJECTS)
	@if not exist "$(BDIR)" mkdir "$(BDIR)"
	@echo "--> Vinculando objetos para criar o executavel..."
	$(CC) $(OBJECTS) -o $@
	@echo "--> Executavel '$(TARGET)' criado com sucesso."

# --- CORREÇÃO NA REGRA DE COMPILAÇÃO ---
# Regra para compilar os arquivos .c em .o, com criação de pastas para Windows
$(ODIR)/%.o: $(SDIR)/%.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	@echo "--> Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar o projeto
clean:
	@echo "Limpando arquivos gerados..."
	@if exist "$(ODIR)" rmdir /s /q "$(ODIR)"
	@if exist "$(BDIR)" rmdir /s /q "$(BDIR)"
	@echo "Limpeza concluida."

# Define as regras que não são arquivos
.PHONY: all clean