#ifndef _ROUPA_H_
#define _ROUPA_H_

#include "produto.h"

class Roupa : public Produto
{
public:
	Roupa();
	Roupa(std::string _codigo, std::string _descricao, short _preco, 
std::string _marca, char _sexo, std::string _tamanho);
	~Roupa();
private:
	std::string m_marca;
	char m_sexo;
	std::string m_tamanho;
public:
	// getters
	std::string getMarca();
	char getSexo();
	std::string getTamanho();
	// setters
	void setMarca(std::string _marca);
	void setSexo(char _sexo);
	void setTamanho(std::string _tamanho);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif
