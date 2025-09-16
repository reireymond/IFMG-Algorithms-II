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

# Regra principal
all: $(TARGET)

# Regra para criar o executável final
$(TARGET): $(OBJECTS)
	@-mkdir -p $(BDIR)
	$(CC) $(OBJECTS) -o $@

# Regra para compilar os arquivos .c em .o
$(ODIR)/%.o: $(SDIR)/%.c
	@-mkdir -p $(ODIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Regra para limpar a tela e rodar o programa
run: all
	@echo "Iniciando o programa..."
	cls
	$(TARGET).exe

# Regra para limpar o projeto
clean:
	@echo "Limpando arquivos gerados..."
	rm -f $(ODIR)/*.o $(TARGET).exe
	@echo "Limpeza concluída."

# Define as regras que não são arquivos
.PHONY: all clean run