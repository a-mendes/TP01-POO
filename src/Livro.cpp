#include "headers/Livro.h"
#include "headers/Utilitarios.h"
Livro::Livro()
{}

vector<string> Livro::getEscritores()
{
	return this->escritores;
}

void Livro::setEscritores(vector<string> escritores)
{
	this->escritores = escritores;
}

string Livro::getTitulo()
{
	return this->titulo;
}

void Livro::setTitulo(string titulo)
{
	this->titulo = titulo;
}

vector<string> Livro::getCapitulos()
{
	return this->capitulos;
}

void Livro::setCapitulos(vector<string> capitulos)
{
	this->capitulos = capitulos;
}

int Livro::getAnoPublicacao()
{
	return this->anoPublicacao;
}

void Livro::setAnoPublicacao(int anoPublicacao)
{
	this->anoPublicacao = anoPublicacao;
}

string Livro::getIdiomaOriginal()
{
	return this->idiomaOriginal;
}

void Livro::setIdiomaOriginal(string idiomaOriginal)
{
	this->idiomaOriginal = idiomaOriginal;
}

vector<string> Livro::getKeywords()
{
	return this->keywords;
}

void Livro::setKeywords(vector<string> keywords)
{
	this->keywords = keywords;
}

ostream& operator<<(ostream& cout,  Livro& livro){
	cout<< left <<'|'<<livro.getTitulo().erase(30);
	cout<<right <<'|'<<livro.getEscritores().front();
	cout<< left <<'|'<<livro.getIdiomaOriginal();
	if(livro.getCapitulos().size()<=10)
		cout<<"|00"<<livro.getCapitulos().size();
	
	else if(livro.getCapitulos().size()>10&&livro.getCapitulos().size()<100)
		cout<<"|0"<<livro.getCapitulos().size();
	
	else
		cout<<"|"<<livro.getCapitulos().size();

	
	if(livro.getKeywords().size()<10){
		cout<<"|0"<<livro.getKeywords().size(); }
	else{
		cout<<"|"<<livro.getKeywords().size();
	}
	
	return cout;