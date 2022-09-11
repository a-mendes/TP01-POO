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

ostream& operator<<(ostream& os, const AudioBook& audioBook)
{
    Livro livro = audioBook;
    os << livro;// Impreme dados gerais do livro 
//Imprime especificassões 
    os.setf(ios::fixed);
    os << setprecision(2) << audioBook.duracao;

	return os;
}