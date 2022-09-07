#include "headers/Livro.h"

Livro::Livro()
{}

list<string> Livro::getEscritores()
{
	return this->escritores;
}

void Livro::setEscritores(list<string> escritores)
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

list<string> Livro::getCapitulos()
{
	return this->capitulos;
}

void Livro::setCapitulos(list<string> capitulos)
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

list<string> Livro::getKeywords()
{
	return this->keywords;
}

void Livro::setKeywords(list<string> keywords)
{
	this->keywords = keywords;
}