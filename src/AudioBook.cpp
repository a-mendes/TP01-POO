#include "headers/AudioBook.h"
#include "headers/Utilitarios.h"
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



ostream& operator<<(ostream& cout,  AudioBook& livro){
	cout<< left <<'|'<<livro.getTitulo().erase(30);
	cout<<right <<'|'<<livro.getEscritores().front();
	cout<< left <<'|'<<livro.getIdiomaOriginal();
	if(livro.getCapitulos().size()<=10)
		cout<<"|00"<<livro.getCapitulos().size();
	
	else if(livro.getCapitulos().size()>10&&livro.getCapitulos().size()<100)
		cout<<"|0"<<livro.getCapitulos().size();
	
	else
		cout<<"|" <<livro.getCapitulos().size();

	
	if(livro.getKeywords().size()<10){
		cout<<"|0"<<livro.getKeywords().size(); }
	else{
		cout<<"|"<<livro.getKeywords().size();
	}
	cout<<"|"<<livro.getDuracao();
}