#include "headers/Livro.h"
#include <iostream>

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
	os << "Titulo: " << livro.titulo << "\n";

	os << "Escritores: " << livro.escritores[0] << "\n";

	os << "Ano: " << livro.anoPublicacao << "\n";

	os << "Idioma: " << livro.idiomaOriginal << "\n";
	
	os << "Keywords: " << livro.keywords[0] << "\n";

	os << "Capitulos: " << livro.capitulos[0] << "\n";

	return os;
}