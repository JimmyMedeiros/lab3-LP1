/**
 * @file     main1.cpp
 * @brief    Programa com uma classe Produto e suas classes herdadas: Fruta, Bebida e Roupa.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    20/10/2017
 * @date     23/10/2017
 *
 * @mainpage Laboratório 3 - Linguagem de Programação I
 *
 * @section intro_sec Introdução
 *
 * Esta é a documentação do terceiro laboratório da disciplina de Linguagem de Programação 1 do curso de Tecnologia da Informação do Instituto Metrópole Digital - Universidade Federal do Rio Grande do Norte. 
 *
 */

#include <iostream>
#include <vector>
#include <memory>
#include "produto.h"
#include "fruta.h"
#include "bebida.h"
#include "roupa.h"


using namespace std;

int main(int argc, char const *argv[])
{
	double conta = 0;
	std::vector<shared_ptr<Produto>> lista;
	
	lista.push_back(make_shared<Fruta>("001002003-45","Maca verde",8.70,"01/10/2017",18));
	lista.push_back(make_shared<Fruta>("001002004-44","Laranja",4.75,"23/09/2017",15));
	lista.push_back(make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));
	lista.push_back(make_shared<Bebida>("001002005-51","Catuaba",2.30,8));
	lista.push_back(make_shared<Roupa>("001002006-52","Camiseta",2.30,"sadkh",'M', "M"));

	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		std::cout << (**i) << std::endl;
		conta += (*i)->getPreco();
	}

	std::cout << "Total: " << conta << "\n"; 

	return 0;
}
