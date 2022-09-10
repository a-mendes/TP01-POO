#include "headers/Livro.h"
#include <iostream>
#include <string>
#include<cstring>

using namespace std;

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

ostream& operator<<(ostream& os, const Livro& livro)
{
	string aux = "";

	aux = livro.titulo;
	aux.resize(30, ' ');
	os << aux;

	os << "|";

	aux = "";
	if(livro.escritores[0].size() < 30){
		aux.resize(30 - livro.escritores[0].size(), ' ');
		os <<aux + livro.escritores[0];	
	}
	else if(livro.escritores[0].size() >= 30){
		aux = livro.escritores[0];
		aux.resize(30, ' ');
		os <<aux;	
	}

	os << "|";

	aux = "";
	aux = livro.idiomaOriginal;
	aux.resize(10, ' ');
	os << aux;

	os << "|";

	aux = "";
	if(livro.capitulos.size()<=10)
	 	os <<"00"<< livro.capitulos.size();
	
	else if(livro.capitulos.size()>10 &&  livro.capitulos.size()<100)
		os <<"0"<< livro.capitulos.size();
	
	else
	 	os << livro.capitulos.size();

	os << "|";

	aux = "";
	 if(livro.keywords.size()<10)
	 	os <<"00"<<livro.keywords.size(); 
	 else
	 	os << livro.keywords.size();

	//os << "|\n";

	return os;
}
