CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -pg
RM = rm -rf

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

.PHONY: all clean distclean doxy

all: dir questao01 questao02

# Cria os diretórios necessários
dir:
	mkdir -p bin build

# Opção para depurar (só a questão 03)
debug: CPPFLAGS += -g -O0
debug: questao01 questao02

####	Questão 01		####
questao01: $(OBJ_DIR)/main1.o $(OBJ_DIR)/bebida.o $(OBJ_DIR)/fruta.o $(OBJ_DIR)/produto.o $(OBJ_DIR)/roupa.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel questao01 criado em $(BIN_DIR)] +++"
	@echo "============="

## Arquivos objeto
$(OBJ_DIR)/main1.o: $(SRC_DIR)/questao01/main1.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

$(OBJ_DIR)/bebida.o: $(SRC_DIR)/questao01/bebida.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

$(OBJ_DIR)/fruta.o: $(SRC_DIR)/questao01/fruta.cpp 
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

$(OBJ_DIR)/produto.o: $(SRC_DIR)/questao01/produto.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

$(OBJ_DIR)/roupa.o: $(SRC_DIR)/questao01/roupa.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

####	Questão 02		####
questao02: $(OBJ_DIR)/main2.o $(OBJ_DIR)/agencia.o $(OBJ_DIR)/conta.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel questao02 criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/main2.o: $(SRC_DIR)/questao02/main2.cpp $(OBJ_DIR)/conta.o
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao02 -o $@ $<

$(OBJ_DIR)/agencia.o: $(SRC_DIR)/questao02/agencia.cpp $(OBJ_DIR)/conta.o
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao02 -o $@ $<

$(OBJ_DIR)/conta.o: $(SRC_DIR)/questao02/conta.cpp
	$(CC) -c $(CPPFLAGS) -I$(INC_DIR)/questao02 -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Limpar os arquivos objetos e executáveis
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
