/**
 * @file     conta.h
 * @brief    Declaração dos métodos e atributos da classe Conta.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    20/10/2017
 * @date     26/10/2017
 */

#ifndef _CONTA_H
#define _CONTA_H

#include <iostream>

using num_type = unsigned int;

class Conta
{
private:

/** b) Uma movimentação possui uma descrição, um valor e uma indicação se ela é uma movimentação
de crédito ou débito. **/
	//=== Atributos
	std::string titular; /**< O nome do titular da conta */
	num_type agencia;
	num_type numero;
	float saldo;
	bool status; /**< O status da conta indica se ela é ou não conta especial */ 
	float limite;
public:
/**
 * @brief	Construtor padrão.
 */
	Conta();
	Conta(std::string _titular, num_type _agencia, num_type _numero, float _saldo, bool _status, float _limite);
	~Conta();
//---Getters e Setters

/**
 * @brief	Muda a agência da conta.
 */
	void set_agencia(num_type _agencia);
	num_type get_numero();

//=== Movimentações
//	void movimentacao();

//=== Operadores
	friend std::ostream& operator<< (std::ostream &o, Conta const &c);
};

#endif
