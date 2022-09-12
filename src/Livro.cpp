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


void Livro ::saida( ostream& os) const {
	string aux = ""; // Variavel auxiliar 
	//Impre titulo
	
	aux =titulo;
	aux.resize(30, ' '); // Garante tamanho maximo e justifica à esquerda 
	os << aux; 

	os << "|"; //Imprime separador 

	aux = "";
	//Imprime escritores 
	if(escritores[0].size() < 30){
		aux.resize(30 - escritores[0].size(), ' ');
		os <<aux + escritores[0];	
	}
	else if(escritores[0].size() >= 30){
		aux = escritores[0];
		aux.resize(30, ' ');
		os <<aux;	
	}

	os << "|";
	//Imprime idioma original 
	aux = "";
	aux = idiomaOriginal;
	aux.resize(10, ' ');
	os << aux;

	os << "|";

	//Imprime quantidade de capitulos 
	aux = "";
	if(capitulos.size()<=10)
	 	os <<"00"<< capitulos.size();//Adiciona dois zeros para preencher o campo caso a quantidade
										  //não possua as casa de dezenas e centenas 
	
	else if(capitulos.size()>10 &&  capitulos.size()<100)
		os <<"0"<< capitulos.size();//Adiciona um zero para preencher o campo caso a quantidade
										  //não possua  a casa das  centenas 
	
	else
	 	os << capitulos.size();

	os << "|";

	aux = "";
	//Imprime keywords 
	 if(keywords.size()<10)
	 	os <<"0"<<keywords.size(); 
	 else
	 	os << keywords.size();

	os << "|";
}
ostream& operator<<(ostream& os, const Livro& livro) //Sobrecarga do Operador 
{
	livro.saida(os);
	os<<"\n";
	return os;
}
