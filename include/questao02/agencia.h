/**
 * @file     agencia.h
 * @brief    Declaração da classe Agencia.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    20/10/2017
 * @date     26/10/2017
 */

#ifndef _AGENCIA_H
#define _AGENCIA_H

#include <vector>
#include <string>
#include <memory>
#include "conta.h"

using num_type = unsigned int;
//#define std::vector<std::unique_ptr<Conta>>::iterator iter_Conta;
using iter_Conta = __gnu_cxx::__normal_iterator<std::unique_ptr<Conta>*, std::vector<std::unique_ptr<Conta>> >;

class Agencia
{
public:
/**
 * @brief Construtor padrão
 */
	Agencia();
/**
 * @brief Construtor com número da agência
 */
	Agencia(num_type _numero);
/**
 * @brief Destrutor padrão
 */
	~Agencia();

/**
 * @brief	Permite criar uma conta passandos os dados da conta como parâmetros.
 * @param	_titular O nome do titular da conta.
 * @param	_numero O número da conta.
 * @param 	status Um bool que indica se a conta é especial, caso true, ou não, caso false.  
 */
	void criar_conta(std::string _titular, num_type _numero, bool _status=false);
/**
 * @brief	Permite criar uma conta passado o objeto Conta como parâmetro.
 * @details	O campo c1.agencia é alterado para o número da agência atual.  
 */
	void criar_conta(Conta & c1);
/**
 * @brief	Exclui uma conta.
 * @brief	O número da conta a ser excluída.
 */
	void excluir_conta(num_type _numero);
	void sacar(num_type _numero);
	void depositar();
	void saldo();
	void extrato();
	void transferir();

	std::vector<std::unique_ptr<Conta>> contas;
private:
	iter_Conta procurar(num_type _numero);
	num_type numero;
};

#endif
