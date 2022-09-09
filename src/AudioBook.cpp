#include "headers/AudioBook.h"
#include <iostream>

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
	os << "Duracao: " << audioBook.duracao << "\n";

	os << "FormatoArquivo: " << audioBook.formatoArquivo << "\n";

	return os;
}