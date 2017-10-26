/**
 * @file     main2.cpp
 * @brief    Programa para testar as classes Conta e Agencia.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    20/10/2017
 * @date     25/10/2017
 */

#include <iostream>

#include "agencia.h"

int main(int argc, char const *argv[])
{
	auto bb = new Agencia(1668u);
	//std::string _titular, unsigned int _numero, bool _status=false
	
	bb->criar_conta("Teobaldo Stallman da Silva", 114251);
	bb->criar_conta("Pedrinho Estacionador (aka Homem Aranha)", 60617);

	std::cout << "=== Banco do Brazel ===\n";
	for (auto i = bb->contas.begin(); i != bb->contas.end(); ++i)
	{
		std::cout << **i;
	}
	bb->excluir_conta(60617);

	std::cout << "=== Banco do Brazel Depois de excluir conta ===\n";
	for (auto i = bb->contas.begin(); i != bb->contas.end(); ++i)
	{
		std::cout << **i;
	}
	return 0;
}