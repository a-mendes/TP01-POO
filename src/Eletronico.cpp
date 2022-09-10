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

ostream& operator<<(ostream& os, const Eletronico& eletronico)
{
	os << eletronico.formatoArquivo << "\n";

	return os;
}