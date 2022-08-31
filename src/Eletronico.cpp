#include "headers/Eletronico.h"
#include "headers/Utilitarios.h"

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

ostream& operator<<(ostream& cout,  Eletronico& livro){
    cout<< left <<'|'<<livro.getTitulo().erase(30);
	cout<<right <<'|'<<livro.getEscritores().front();
	cout<< left <<'|'<<livro.getIdiomaOriginal();
	if(livro.getCapitulos().size()<=10)
		cout<<'|00'<<livro.getCapitulos().size();
	
	else if(livro.getCapitulos().size()>10&&livro.getCapitulos().size()<100)
		cout<<"|0"<<livro.getCapitulos().size();
	
	else
		cout<<"|" <<livro.getCapitulos().size();

	
	if(livro.getKeywords().size()<10){
		cout<<"|0"<<livro.getKeywords().size(); }
	else{
		cout<<"|"<<livro.getKeywords().size();
	}
	
    cout<<"|"<<livro.getFormatoArquivo();
	
	return cout;