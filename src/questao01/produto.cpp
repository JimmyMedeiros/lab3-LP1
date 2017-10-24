/**
 * @file     produto.cpp
 * @brief    Implementação dos métodos da classe Produto.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    20/10/2017
 * @date     23/10/2017
 */

#include <iostream>
#include "produto.h"

Produto::Produto() {}

Produto::~Produto(){}

Produto::Produto(std::string _codigo, std::string _descricao, short _preco):
	m_cod_barras(_codigo), m_descricao(_descricao), m_preco(_preco) {}
/**
* @brief	Função que pega o Código de barras.
* @return 	Retorna uma std::string com o código de barras do produto.
*/
std::string 
Produto::getCodBarras() const
{
	return m_cod_barras;
}
/**
* @brief	Função que dá uma breve descrição.
* @return 	Retorna uma std::string com a descrição do produto.
*/
std::string 
Produto::getDescricao() const
{
	return m_descricao;
}
/**
* @brief	Função para pegar o preço.
* @return 	Retorna um valor double com o preço do produto.
*/
double 
Produto::getPreco() const
{
	return m_preco;
}
/**
* @brief	Modifica o valor do código de barras.
* @details	Substitui o antigo código de barras do Produto com o valor informado.
* @param	_codigo Uma std::string com o novo valor do código de barras.
* @return 	A função não retorna valor.
*/
void 
Produto::setCodBarras(std::string _codigo) {
	m_cod_barras = _codigo;
}
/**
* @brief	Modifica a descrição.
* @details	Substitui a antiga descrição do Produto com o valor informado.
* @param	_descricao Uma std::string com a nova descrição.
* @return 	A função não retorna valor.
*/	
void 
Produto::setDescricao(std::string _descricao) {
	m_descricao = _descricao;
}
/**
* @brief	Modifica o preço.
* @details	Substitui o antigo preço do Produto com o valor informado.
* @param	_preco Um valor double com o novo preço.
* @return 	A função não retorna valor.
*/
void 
Produto::setPreco(double _preco) {
	m_preco = _preco;
}

std::ostream& operator<< (std::ostream &o, Produto const &p) {
	return p.print(o);
}
double Produto::operator+ (Produto const &p1)
{
	return p1.getPreco() + this->getPreco();
}
double Produto::operator+ ( double const &p1 )
{
	return this->getPreco() + p1;
}
double operator+ (double p, Produto const &p1)
{
	return p + p1.getPreco();
}

double Produto::operator- (Produto const &p1)
{
	return p1.getPreco() - this->getPreco();
}
double Produto::operator- ( double const &p1 )
{
	return this->getPreco() - p1;
}
double operator- (double p, Produto const &p1)
{
	return p - p1.getPreco();
}

bool Produto::operator== (Produto const &p)
{
	return p.getCodBarras() == this->getCodBarras();
}