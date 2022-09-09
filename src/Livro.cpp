#include "headers/Livro.h"
#include <iostream>
#include<cstring>

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

// ostream& operator<<(ostream& os, const Livro& livro)
// {
// 	string aux;
	
// 	os << "Titulo: " << livro.titulo << "\n";
	
// 	os << "Escritores: " << livro.escritores[0] << "\n";

// 	os << "Ano: " << livro.anoPublicacao << "\n";

// 	os << "Idioma: " << livro.idiomaOriginal << "\n";
	
// 	os << "Keywords: " << livro.keywords[0] << "\n";

// 	os << "Capitulos: " << livro.capitulos.size() << "\n";

// 	return os;
// }

ostream& operator<<(ostream& coutOS,const  Livro& livro){

	cout << "__________________________________________________________________________" << endl;
	if (livro.titulo.size()<30)
		{
			coutOS<< left<<"|"<<livro.titulo;
		}
		else {
			coutOS<<"|";
			for (int i = 0; i < 30; i++)
			{
				coutOS<< left<<""<<livro.titulo[i];
			}
			
		}

	if (livro.escritores[0].size()<30)
		{
			coutOS<< left<<"|"<<livro.escritores[0];
		}
		else {
			coutOS<<"|";
			for (int i = 0; i < 30; i++)
			{
				coutOS<< left<<""<<livro.escritores[0][i];
			}
			
		}
	

	coutOS<< left <<'|'<<livro.idiomaOriginal;
	
	if(livro.capitulos.size()<=10)
	 	coutOS<<"|00"<< livro.capitulos.size();
	
	else if(livro.capitulos.size()>10 &&  livro.capitulos.size()<100)
		coutOS<<"|0"<< livro.capitulos.size();
	
	else
	 	coutOS<<"|"<< livro.capitulos.size();

	
	 if(livro.keywords.size()<10)
	 	coutOS<<"|0"<<livro.keywords.size()<<"|"<<"\n"; 
	 else
	 	coutOS<<"|"<<livro.keywords.size()<<"|"<<"\n";
	cout << "__________________________________________________________________________" << endl; 

	
	return coutOS;
}







// ostream& operator<<(ostream& coutOS, Livro& livro){
// 	 coutOS<< left <<'|'<<livro.getTitulo().erase(30);
// 	 coutOS<<right <<'|'<<livro.getEscritores().front();
// 	 coutOS<< left <<'|'<<livro.getIdiomaOriginal();
// 	 if(livro.getCapitulos().size()<=10)
// 	 	coutOS<<"|00"<<livro.getCapitulos().size();
	
// 	// else if(livro.getCapitulos().size()>10 && livro.getCapitulos().size()<100)
// 	// 	coutOS<<"|0"<<livro.getCapitulos().size();
// 	 else if(livro.getCapitulos().size()>10&&livro.getCapitulos().size()<100)
// 	 	coutOS<<"|0"<<livro.getCapitulos().size();
	
// 	 else
// 	 	coutOS<<"|"<<livro.getCapitulos().size();

	
// 	 if(livro.getKeywords().size()<10){
// 	 	coutOS<<"|0"<<livro.getKeywords().size(); }
// 	 else{
// 	 	coutOS<<"|"<<livro.getKeywords().size();
// 	 }

// 	coutOS << "Titulo: " << livro.getTitulo() << endl;
// 	//coutOS << "Escritores: " << livro.getEscritores() << endl;
// 	//coutOS << "Capitulos: " << livro.getCapitulos() << endl;
// 	coutOS << "Ano Publicacao: " << livro.getAnoPublicacao() << endl;
// 	coutOS << "Idioma: " << livro.getIdiomaOriginal() << endl;
// 	//coutOS << "keywords: " << livro.getKeywords() << endl;

// 	return coutOS;
// }