# Nome do compilador
CC = gcc

# Comando de remoção para o Windows (Quiet/Force)
RM = del /Q /F

# Flags de compilação
CFLAGS = -Wall -Iinclude

# Diretórios
SDIR = src
ODIR = obj
BDIR = bin

# Nome do executável final
TARGET = $(BDIR)/produtora

# --- ALTERAÇÃO PRINCIPAL AQUI ---
# Encontra todos os arquivos .c recursivamente dentro da pasta src
SOURCES = $(shell find $(SDIR) -name '*.c')

# Converte a lista de fontes .c para uma lista de objetos .o
# Mantendo a mesma estrutura de pastas dentro de 'obj'
OBJECTS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SOURCES))
# ---------------------------------

# Regra principal: compila o projeto
all: $(TARGET)

# Regra para criar o executável final
$(TARGET): $(OBJECTS)
	@if not exist "$(BDIR)" mkdir "$(BDIR)"
	@echo "--> Vinculando objetos para criar o executavel..."
	$(CC) $(OBJECTS) -o $@
	@echo "--> Executavel '$(TARGET)' criado com sucesso."

# --- ALTERAÇÃO NA REGRA DE COMPILAÇÃO ---
# Regra para compilar os arquivos .c em .o, criando as subpastas em 'obj'
$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(@D)
	@echo "--> Compilando $<..."
	$(CC) -c $< -o $@ $(CFLAGS)
# ----------------------------------------

# Regra para limpar o projeto (usando 'rd' para remover diretórios no Windows)
clean:
	@echo "Limpando arquivos gerados..."
	@if exist "$(ODIR)" rd /s /q "$(ODIR)"
	@if exist "$(BDIR)" rd /s /q "$(BDIR)"
	@echo "Limpeza concluida."

# Define as regras que não são arquivos
.PHONY: all clean