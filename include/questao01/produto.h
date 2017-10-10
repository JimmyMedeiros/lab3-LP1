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
	std::string getCodBarras();
	std::string getDescricao();
	double getPreco();
	// setters
	void setCodBarras(std::string _codigo);
	void setDescricao(std::string _descricao);
	void setPreco(double _preco);
	// O operador recebe um objeto da classe Produto e chama o método print.
	// O método print precisa ser implementado na classe filha para que o operador funcione. 
	friend std::ostream& operator<< (std::ostream &o, Produto const &t);  
protected:
	std::string m_cod_barras;
	std::string m_descricao;
	double m_preco;		
private:
	virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
