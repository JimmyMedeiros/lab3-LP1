#include <iomanip>
#include "bebida.h"

Bebida::Bebida() {}

Bebida::Bebida(std::string _codigo, std::string _descricao, short _preco, 
	short _teor_alcoolico):
	Produto(_codigo, _descricao, _preco), m_teor_alcoolico(_teor_alcoolico) {}

Bebida::~Bebida() {}

short 
Bebida::getTeorAlcoolico() {
	return m_teor_alcoolico;
}

void 
Bebida::setTeorAlcoolico(short _teor_alcoolico) {
	m_teor_alcoolico = _teor_alcoolico;
}

std::ostream& 
Bebida::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << m_teor_alcoolico << "%";
	return o;
}

