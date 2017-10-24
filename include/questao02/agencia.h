#ifndef _AGENCIA_H
#define _AGENCIA_H

#include <vector>
#include <memory>
#include "conta"

class Agencia
{
public:
	Agencia();
	~Agencia();
/**
Usando as classes implementadas, escreva um programa em C++ para simular uma agência
bancária. Uma agência bancária deve armazenar um conjunto de contas e permitir as seguintes
operações básicas: criações de conta, exclusão de contas, saques (respeitando o saldo e o limite),
depósitos, emissão de saldo e extrato, além de transferência entre contas.
**/
	
	void criar_conta();
	void excluir_conta();
	void sacar();
	void depositar();
	void saldo();
	void extrato();
	void transferir();
private:
	std::vector<unique_ptr<Conta>> contas;
};

#endif
