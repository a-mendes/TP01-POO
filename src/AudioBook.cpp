#include "headers/AudioBook.h"

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