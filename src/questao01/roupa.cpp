#include <iomanip>
#include "roupa.h"

/**
* @brief	Construtor padrão.
*/
Roupa::Roupa() {}
/**
* @brief	Construtor por parâmetros.
* @param	_codigo Uma std::string com o novo valor do código de barras.
* @param	_descricao Uma std::string com a descrição da roupa.
* @param	_preco Uma std::string com a descrição da roupa.
* @param	_marca Uma std::string com a marca da roupa.
* @param	_sexo Um char que indica o sexo, M para masculino e F para feminino.
* @param	_tamanho Uma std::string com o tamanho, ex: PP, P, M, G, etc.
*/
Roupa::Roupa(std::string _codigo, std::string _descricao, short _preco, 
	std::string _marca, char _sexo, std::string _tamanho):
	Produto(_codigo, _descricao, _preco), m_marca(_marca), m_sexo(_sexo), m_tamanho(_tamanho) {}

Roupa::~Roupa() {}

std::string
Roupa::getMarca() {
	return m_marca;
}
char
Roupa::getSexo() {
	return m_sexo;
}

std::string
Roupa::getTamanho() {
	return m_tamanho;
}

void 
Roupa::setMarca(std::string _marca) {
	m_marca = _marca;
}

void 
Roupa::setSexo(char _sexo) {
	m_sexo = _sexo;
}

void 
Roupa::setTamanho(std::string _tamanho) {
	m_tamanho = _tamanho;
}

std::ostream& 
Roupa::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << m_marca << " | "
		<< std::setfill (' ') << std::setw (10) << m_sexo << " | "
		<< std::setfill (' ') << std::setw (10) << m_tamanho;
	return o;
}

