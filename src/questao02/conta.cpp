/**
 * @file     conta.cpp
 * @brief    Implementação dos métodos da classe Conta.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    20/10/2017
 * @date     26/10/2017
 */

 #include "conta.h"

Conta::Conta()
{ /* Vazio */ }
Conta::Conta( std::string _titular, unsigned int _agencia, unsigned int _numero, float _saldo, bool _status, float _limite ) : titular(_titular), agencia(_agencia), numero(_numero), saldo(_saldo), status(_status), limite(_limite)
{ /* Vazio */ }

Conta::~Conta()
{ /* Vazio */ }

void Conta::set_agencia(unsigned int _agencia)
{
	this->agencia = _agencia;
}
num_type Conta::get_numero()
{
	return this->numero;
}


//=== Operadores
std::ostream& operator<< (std::ostream &o, Conta const &c) {
	o << "Conta Banco do Brazel\n";
	o << "Titular: " << c.titular << "\n";
	o << "Número da Conta: " << c.numero << "\n";
	return o;
}