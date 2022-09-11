#include "headers/Eletronico.h"
#include <iostream>

string Eletronico::getUrl(){
    return this->url;
}
void Eletronico::setUrl(string url){
    this->url = url;
}

string Eletronico::getFormatoArquivo(){
    return this->formatoArquivo;
}
void Eletronico::setFormatoArquivo(string formatoArquivo){
    this->formatoArquivo = formatoArquivo;
}

ostream& operator<<(ostream& os, const Eletronico& eletronico) //Sobrecarga do operador na classe eletronico
{
    Livro livro = eletronico;
    os << livro; // Imprime dados do livro

//Imprime especificassões 
	os << eletronico.formatoArquivo;

	return os;
}