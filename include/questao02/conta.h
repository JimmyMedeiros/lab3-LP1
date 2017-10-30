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
#include <vector>
#include <string>

using num_type = unsigned int;

class Conta
{
private:

	//=== Atributos
	std::string titular; /**< O nome do titular da conta */
	num_type agencia;
	num_type numero;
	float saldo;
	bool status; /**< O status da conta indica se ela é ou não conta especial */ 
	float limite;
public:
	std::vector<std::string> movimentacao; /**< Todas as movimentações realizadas na conta */
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
/**
 * @brief	Subtrai um valor do saldo da conta.
 */
	void tirar_dinheiro(float valor);
	void tirar_dinheiro(float valor, num_type conta);
/**
 * @brief	Soma um valor do saldo da conta.
 */
	void depositar_dinheiro(float valor);
	void depositar_dinheiro(float valor, num_type conta);

/**
 * @brief	Retorna o número da Conta.
 */
	num_type get_numero();
/**
 * @brief	Retorna o saldo da Conta.
 */
	float get_saldo();
//=== Movimentações
	void add_movimentacao(std::string mv);

//=== Operadores
	friend std::ostream& operator<< (std::ostream &o, Conta const &c);
};

#endif
