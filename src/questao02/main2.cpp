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

	bb->depositar(114251 ,2500);

	std::cout << "=== Banco do Brazel ===\n\n";
	std::cout << *bb;

	bb->excluir_conta(6617);

	std::cout << "=== Banco do Brazel Depois de excluir conta ===\n\n";
	std::cout << *bb;

	bb->sacar(114251 ,500.0f);
	bb->depositar(60617 ,2500);

	bb->saldo( 60617 );

	std::cout << "\n\n>>>>>> IMPRIMINDO EXTRATO\n\n";

	bb->extrato( 60617 );

	bb->transferir( 60617, 114251, 20000 );

	bb->extrato( 60617 );
	bb->extrato( 114251 );

	std::cout << *bb;

	return 0;
}