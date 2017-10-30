#ifndef _CONTA_CORRENTE_H_
#define _CONTA_CORRENTE_H_

#include "conta.h"

class Conta_Corrente : public Conta
{
public:
	Conta_Corrente();
	Conta_Corrente(std::string _titular, num_type _agencia, num_type _numero, float _saldo, 
		bool _status, float _limite);
	~Conta_Corrente();
private:
	float limite_emprestimo;
	float juros_emprestimo;
public:
	
};

#endif
