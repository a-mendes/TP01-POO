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

ostream& operator<<(ostream& os, const Impresso& impresso)
{
	os << "Livraria: " << impresso.livrarias[0] << "\n";

	os << "Colunas: " << impresso.colunas << "\n";

	return os;
}