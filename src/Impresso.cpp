#include "headers/Impresso.h"

vector<string> Impresso::getLivraria(){
    return this->livraria;
}
void Impresso::setLivraria(vector<string> livraria){
	this->livraria = livraria;
}

int Impresso::getColunas(){
    return this->colunas;
}

void Impresso::setColunas(int colunas){
    this->colunas = colunas;
}