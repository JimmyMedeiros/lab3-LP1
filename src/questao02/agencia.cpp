/**
 * @file     agencia.cpp
 * @brief    Implementação dos métodos da classe Agencia.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    20/10/2017
 * @date     25/10/2017
 */

#include "agencia.h"
using iter_Conta = __gnu_cxx::__normal_iterator<std::unique_ptr<Conta>*, std::vector<std::unique_ptr<Conta>> >;

#define ACCOUNT_NOT_FOUND "Conta não encontrada\n";

//=== Funcções Privadas
iter_Conta Agencia::procurar( num_type _numero )
{
	for (auto it = contas.begin(); it != contas.end(); ++it)
	{
		if ((*it)->get_numero() == _numero)
		{
			return it;
		}
	}
	return iter_Conta(nullptr);
}
//=== Funções Públicas

Agencia::Agencia( num_type _numero ) : numero(_numero){ /* vazio */ }

void Agencia::criar_conta(Conta & c1)
{
	this->contas.push_back(std::unique_ptr<Conta>(&c1));
	c1.set_agencia(numero);
}

void Agencia::criar_conta( std::string _titular, num_type _numero, bool _status )
{
	if (procurar(_numero) != iter_Conta(nullptr))
	{
		std::cerr << "Já existe uma conta com esse número na Agência" << std::endl;
		return;
	}
	this->contas.push_back(std::unique_ptr<Conta>(new Conta(_titular, this->numero, _numero, 0.0, _status, 1000.0 )));
}

void Agencia::excluir_conta( num_type _numero )
{
	auto conta_it = procurar(_numero);
	if (conta_it != iter_Conta(nullptr))
	{
		contas.erase(conta_it);
		return;
	}
	std::cerr << ACCOUNT_NOT_FOUND;
}

void Agencia::sacar( num_type _numero, float valor )
{
	auto conta_it = procurar(_numero);
	if (conta_it != iter_Conta(nullptr))
	{
		(*conta_it)->tirar_dinheiro( valor );
		return;
	}
	std::cerr << ACCOUNT_NOT_FOUND;
	return;
}
void Agencia::depositar( num_type _numero, float valor )
{
	auto conta_it = procurar(_numero);
	if (conta_it != iter_Conta(nullptr))
	{
		(*conta_it)->depositar_dinheiro( (*conta_it)->get_saldo() + valor );
		return;
	}
	std::cerr << ACCOUNT_NOT_FOUND;
	return;
}
void Agencia::saldo( num_type _numero )
{
	auto conta_it = procurar(_numero);
	if (conta_it != iter_Conta(nullptr))
	{
		std::cout << "O saldo da conta " << std::to_string(_numero) << " é: R$ " << (*conta_it)->get_saldo() << "\n";
		return;
	}
	std::cerr << ACCOUNT_NOT_FOUND;
	return;
}
void Agencia::extrato( num_type _numero )
{
	auto conta_it = procurar(_numero);
	if (conta_it != iter_Conta(nullptr))
	{
		auto i = 0u;
		for (auto rit = (*conta_it)->movimentacao.rbegin(); i < 3 and 
			rit != (*conta_it)->movimentacao.rend(); ++rit)
		{
	 		std::cout << *rit << "\n";
	 		++i;
		}
		return;
	}
	std::cerr << ACCOUNT_NOT_FOUND;
	return;
}
void Agencia::transferir( num_type conta1, num_type conta2, float valor )
{
	auto conta_it1 = procurar( conta1 );
	auto conta_it2 = procurar( conta2 );
	
	if (conta_it1 != iter_Conta(nullptr) and
		conta_it2 != iter_Conta(nullptr))
	{
		(*conta_it1)->tirar_dinheiro( valor, conta2 );
		(*conta_it2)->depositar_dinheiro( valor, conta1 );
		return;
	}
	std::cerr << ACCOUNT_NOT_FOUND;
	return;
}

//=== Operadores

std::ostream& operator<< (std::ostream &o, Agencia const &a) {
	o << ">>> Contas na Agência " << a.numero << "\n";
	for (auto it = a.contas.begin(); it != a.contas.end(); ++it)
	{
		std::cout << **it;
	}
	return o;
}