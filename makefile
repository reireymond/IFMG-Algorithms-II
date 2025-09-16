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

# Encontra todos os arquivos .c e os converte para .o
SOURCES = $(wildcard $(SDIR)/*.c)
OBJECTS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SOURCES))

# Regra principal: compila o projeto
all: $(TARGET)

# Regra para criar o executável final
$(TARGET): $(OBJECTS)
	@if not exist "$(BDIR)" mkdir "$(BDIR)"
	$(CC) $(OBJECTS) -o $@

# Regra para compilar os arquivos .c em .o
$(ODIR)/%.o: $(SDIR)/%.c
	@if not exist "$(ODIR)" mkdir "$(ODIR)"
	$(CC) -c $< -o $@ $(CFLAGS)

# Regra para limpar o projeto (usando 'rd' para remover diretórios no Windows)
clean:
	@echo "Limpando arquivos gerados..."
	@if exist "$(ODIR)" rd /s /q "$(ODIR)"
	@if exist "$(BDIR)" rd /s /q "$(BDIR)"
	@echo "Limpeza concluida."

# Define as regras que não são arquivos
.PHONY: all clean