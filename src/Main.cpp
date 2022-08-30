#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 
#include <algorithm> 
#include <iterator>
#include <vector>

#include "headers/Livro.h"
#include "headers/AudioBook.h"
#include "headers/Eletronico.h"
#include "headers/Impresso.h"

#define QTD_LIVROS 16

using namespace std;

void lerBaseDeDados(vector<Livro*> &livros);
void lerLivro(ifstream &arquivo, Livro *livro);
void lerEletronico(ifstream &arquivo, Eletronico *eletronico);
void lerImpresso(ifstream &arquivo, Impresso *impresso);
void lerAudioBook(ifstream &arquivo, AudioBook *audioBook);
void split(const string &str, vector<string> &cont, char delim); 


int main(int argc, char const *argv[])
{                                         
	cout << "  _____ ____   ___  _           ____   ___   ___  " << endl;
	cout << " |_   _|  _ \\ / _ \\/ |         |  _ \\ / _ \\ / _ \\ " << endl;
	cout << "   | | | |_) | | | | |  _____  | |_) | | | | | | |" << endl;
	cout << "   | | |  __/| |_| | | |_____| |  __/| |_| | |_| |" << endl;
	cout << "   |_| |_|    \\___/|_|         |_|    \\___/ \\___/ " << endl;
	cout << endl;
	cout << "Ana Laura Siqueira Mendes - 20.2.4091" << endl;
	//Acertem os nomes e matricula de vcs amiguinhos
	cout << "Guilherme Salim Sapequinha" << endl;
	cout << "Mateus" << endl;
	cout << "Romulo Junio Vieira Rocha - 21.1.4022" << endl;
	cout << endl;
	
	/**
	 * Colecao unica de livros
	 * 		- Contem os livros fornecidos pelos arquivos .txt
	 */
	vector<Livro*> livros;
	lerBaseDeDados(livros);

	/* print teste
	for (int i = 0; i < livros.size(); ++i)
	{
		cout << "Livro " << i + 1 << ") " << endl;
		cout << "\t" << livros[i]->getTitulo() << endl;
		cout << "\t" << livros[i]->getAnoPublicacao() << endl;

		for (int j = 0; j < livros[i]->getEscritores().size(); ++j)
			cout << "\t" << livros[i]->getEscritores()[j] << endl;

		cout << endl;
	}*/

	return 0;
}

//Verificar escopo adequado para essa função
void lerBaseDeDados(vector<Livro*> &livros)
{
	//cout << "Lendo Base de Dados..." << endl;
	for (int i = 0; i < QTD_LIVROS; ++i)
	{
		string nomeArquivo = "data/" + to_string(i+1) + ".txt";
		ifstream arquivo(nomeArquivo);
		//cout << "\tArquivo: " << nomeArquivo << endl;

		/** 
		 * Faz verificação de tipo de livro e cria instancia adequada
		 */ 
		string tipoLivro;
		getline(arquivo, tipoLivro);

		switch(stoi(tipoLivro))
		{
			/**
			 * Impresso
			 */ 
			case 1:
			{
				Impresso *livro = new Impresso();
				lerImpresso(arquivo, livro);
				livros.push_back(livro);
			}
			break;

			/**
			 * Eletronico
			 */ 
			case 2:
			{
				Eletronico *livro = new Eletronico();
				lerEletronico(arquivo, livro);
				livros.push_back(livro);
			}
			break;

			/**
			 * AudioBook
			 */ 
			case 3:
			{
				AudioBook *livro = new AudioBook();
				lerAudioBook(arquivo, livro);
				livros.push_back(livro);
			}
			break;
		}
	}
}

//Verificar escopo adequado para essa função
void lerLivro(ifstream &arquivo, Livro *livro)
{
	/**
	 * Titulo
	 */ 
	string titulo;
	getline(arquivo, titulo);
	livro->setTitulo(titulo);

	/**
	 * Escritores
	 */ 
	string strEscritores;
	getline(arquivo, strEscritores);
	vector<string> escritores;
	split(strEscritores, escritores, ';');
	livro->setEscritores(escritores);

	/**
	 * Ano
	 */ 
	string ano;
	getline(arquivo, ano);
	livro->setAnoPublicacao(stoi(ano));

	/**
	 * Idioma
	 */ 
	string idioma;
	getline(arquivo, idioma);
	livro->setIdiomaOriginal(idioma);

	/**
	 * Keywords
	 */ 
	string strKeywords;
	getline(arquivo, strKeywords);
	vector<string> keywords;
	split(strKeywords, keywords, ';');
	livro->setKeywords(keywords);
	
	/**
	 * Capitulos
	 */ 
	string strCapitulos;
	getline(arquivo, strCapitulos);
	vector<string> capitulos;
	split(strCapitulos, capitulos, ';');
	livro->setKeywords(capitulos);
}

//Verificar escopo adequado para essa função
void lerAudioBook(ifstream &arquivo, AudioBook *audioBook)
{
	lerLivro(arquivo, audioBook);

	/**
	 * Duracao Audio
	 */ 
	string duracao;
	getline(arquivo, duracao);
	audioBook->setDuracao(stof(duracao));
	
	/**
	 * Formato Audio
	 */ 
	string formato;
	getline(arquivo, formato);
	audioBook->setFormatoArquivo(formato);
}

//Verificar escopo adequado para essa função
void lerEletronico(ifstream &arquivo, Eletronico *eletronico)
{
	lerLivro(arquivo, eletronico);

	/**
	 * Url
	 */ 
	string url;
	getline(arquivo, url);
	eletronico->setUrl(url);
	
	/**
	 * Formato Audio
	 */ 
	string formato;
	getline(arquivo, formato);
	eletronico->setFormatoArquivo(formato);
}

//Verificar escopo adequado para essa função
void lerImpresso(ifstream &arquivo, Impresso *impresso)
{
	lerLivro(arquivo, impresso);

	/**
	 * Livrarias
	 */ 
	string strLivrarias;
	getline(arquivo, strLivrarias);
	vector<string> livrarias;
	split(strLivrarias, livrarias, ';');
	impresso->setLivrarias(livrarias);
	
	/**
	 * Colunas
	 */ 
	string colunas;
	getline(arquivo, colunas);
	impresso->setColunas(stoi(colunas));
}

void split(const string &str, vector<string> &cont, char delim = ' ') 
{ 
	stringstream ss(str); 
	string token;
	while (getline(ss, token, delim)) 
	cont.push_back(token);
}