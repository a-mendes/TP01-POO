#include "headers/Utilitarios.h"

void lerBaseDeDados(vector<Livro*> &livros)
{
	for (int i = 0; i < QTD_LIVROS; ++i)
	{
		string nomeArquivo = "data/" + to_string(i+1) + ".txt";
		ifstream arquivo(nomeArquivo);

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
	livro->setCapitulos(capitulos);
}

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