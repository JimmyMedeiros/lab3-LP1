#ifndef _CONTA_H
#define _CONTA_H

#include <iostream>

class conta
{
private:
/**	a) Uma conta corrente possui uma agência, um número, um saldo, um status que informa se ela é
especial ou não, um limite (e o limite disponível) e um conjunto de movimentações (normalmente
em grande número e variável entre contas).**/

/** b) Uma movimentação possui uma descrição, um valor e uma indicação se ela é uma movimentação
de crédito ou débito. **/
	//=== Atributos
	unsigned int agencia;
	unsigned int numero;
	float saldo;
	bool status;
	float limite;
public:
	conta();
	~conta();
	//=== Movimentações
	void movimentação();
};

#endif
