#include "agencia.h"

Agencia::Agencia();
Agencia::void criar_conta(){
	this.contas.push_back(std::unique_ptr<Conta>(new Conta()));
}

Agencia::void excluir_conta();
Agencia::void sacar();
Agencia::void depositar();
Agencia::void saldo();
Agencia::void extrato();
Agencia::void transferir();
