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


void Eletronico:: saida(ostream& os)const{
	
    Livro::saida(os);
//Imprime especificassões 
	os << formatoArquivo<<"\n";
    }



ostream& operator<<(ostream& os, const Eletronico& eletronico) //Sobrecarga do operador na classe eletronico
{
   eletronico.saida(os);		
	
	return os;
}