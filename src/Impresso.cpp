#include "headers/Impresso.h"

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