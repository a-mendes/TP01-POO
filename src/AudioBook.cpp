#include "headers/AudioBook.h"
#include <iostream>
#include <iomanip>

Livro::~Livro()
{}

float AudioBook::getDuracao(){
    return this->duracao;
}

void AudioBook::setDuracao(float duracao){
    this->duracao = duracao;
}

string AudioBook::getFormatoArquivo(){
    return this->formatoArquivo;
}
void AudioBook::setFormatoArquivo(string formatoArquivo){
    this->formatoArquivo = formatoArquivo;
}	

void AudioBook:: saida(ostream& os)const{
     Livro::saida(os);
    
//Imprime especificassões 
    os.setf(ios::fixed);
    os << setprecision(2) << duracao<<"\n";
}


ostream& operator<<(ostream& os, const AudioBook& audioBook)
{
   
    audioBook.saida(os);
	return os;
}