#include "headers/Impresso.h"
#include <iostream>

vector<string> Impresso::getLivrarias(){
    return this->livrarias;
}
void Impresso::setLivrarias(vector<string> livrarias){
	this->livrarias = livrarias;
}

int Impresso::getColunas(){
    return this->colunas;
}

void Impresso::setColunas(int colunas){
    this->colunas = colunas;
}

ostream& operator<<(ostream& os, const Impresso& impresso) //Sobrecarga da classe impresso 
{

    Livro livro = impresso;
    os << livro;// Impreme dados gerais do livro 

	//Imprime especificassões 
	if(impresso.livrarias.size() > 0)
		os << impresso.livrarias[0];
	else
		os << "Nenhuma";
		
	return os;
}