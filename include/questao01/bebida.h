#ifndef _BEBIDA_H_
#define _BEBIDA_H_

#include "produto.h"

class Bebida : public Produto
{
public:
	Bebida();
	Bebida(std::string _codigo, std::string _descricao, short _preco, short _teor_alcoolico);
	~Bebida();
private:
	short m_teor_alcoolico;
public:
	// getters
	short getTeorAlcoolico();
	// setters
	void setTeorAlcoolico(short _teor_alcoolico);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif
