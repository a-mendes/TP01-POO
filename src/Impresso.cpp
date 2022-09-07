#include "headers/Impresso.h"

list<string> Impresso::getLivrarias(){
    return this->livrarias;
}
void Impresso::setLivrarias(list<string> livrarias){
	this->livrarias = livrarias;
}

int Impresso::getColunas(){
    return this->colunas;
}

void Impresso::setColunas(int colunas){
    this->colunas = colunas;
}