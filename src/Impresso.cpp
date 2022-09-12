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


void Impresso:: saida(ostream& os)const{
	Livro::saida(os);
	//Imprime especificassões 
	if(livrarias.size() > 0)
		os << livrarias[0]<<"\n";
	else
		os << "Nenhuma"<<"\n";
}
ostream& operator<<(ostream& os, const Impresso& impresso) //Sobrecarga da classe impresso 
{   
	impresso.saida(os);		
	return os;
}