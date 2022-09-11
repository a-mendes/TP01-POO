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

ostream& operator<<(ostream& os, const Livro& livro) //Sobrecarga do Operador 
{
	string aux = ""; // Variavel auxiliar 
	//Impre titulo
	aux = livro.titulo;
	aux.resize(30, ' '); // Garante tamanho maximo e justifica à esquerda 
	os << aux; 

	os << "|"; //Imprime separador 

	aux = "";
	//Imprime escritores 
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
	//Imprime idioma original 
	aux = "";
	aux = livro.idiomaOriginal;
	aux.resize(10, ' ');
	os << aux;

	os << "|";

	//Imprime quantidade de capitulos 
	aux = "";
	if(livro.capitulos.size()<=10)
	 	os <<"00"<< livro.capitulos.size();//Adiciona dois zeros para preencher o campo caso a quantidade
										  //não possua as casa de dezenas e centenas 
	
	else if(livro.capitulos.size()>10 &&  livro.capitulos.size()<100)
		os <<"0"<< livro.capitulos.size();//Adiciona um zero para preencher o campo caso a quantidade
										  //não possua  a casa das  centenas 
	
	else
	 	os << livro.capitulos.size();

	os << "|";

	aux = "";
	//Imprime keywords 
	 if(livro.keywords.size()<10)
	 	os <<"00"<<livro.keywords.size(); 
	 else
	 	os << livro.keywords.size();

	os << "|";

	return os;
}
