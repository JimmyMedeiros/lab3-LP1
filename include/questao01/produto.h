/**
 * @file     produto.cpp
 * @brief    Declaração da classe Produto.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    20/10/2017
 * @date     23/10/2017
 */

#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>

class Produto
{
public:
	Produto();
	Produto(std::string _codigo, std::string _descricao, short _preco);
	virtual ~Produto();
	// getters
	std::string getCodBarras() const;
	std::string getDescricao() const;
	double getPreco() const;
	// setters
	void setCodBarras(std::string _codigo);
	void setDescricao(std::string _descricao);
	void setPreco(double _preco);
	// O operador recebe um objeto da classe Produto e chama o método print.
	// O método print precisa ser implementado na classe filha para que o operador funcione. 
	//=== Operadores
	friend std::ostream& operator<< (std::ostream &o, Produto const &t);
	//--- Soma
	double operator+ (Produto const &p1);
	double operator+ ( double const &p2 );
	friend double operator+ (double p, Produto const &p1);
	//--- Subtração
	double operator- (Produto const &p1);
	double operator- ( double const &p2 );
	friend double operator- (double p, Produto const &p1);
	//--- Comparação
	bool operator== (Produto const &p);
protected:
	std::string m_cod_barras;
	std::string m_descricao;
	double m_preco;		
private:
	virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
