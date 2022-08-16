#include <iostream>
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

//Verificar escopo adequado para essa função
void lerBaseDeDados(vector<Livro> *livros);

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
	
	/**
	 * Colecao unica de livros
	 * 		- Contem os livros fornecidos pelos arquivos .txt
	 */
	vector<Livro> livros;
	lerBaseDeDados(&livros);
	return 0;
}

//Verificar escopo adequado para essa função
void lerBaseDeDados(vector<Livro> *livros)
{
	for (int i = 0; i < QTD_LIVROS; ++i)
	{
		string nomeArquivo = to_string(i+1) + ".txt";
		ifstream arquivo(nomeArquivo);

		string tipoLivro = getline();
	}
}

void split(const string& str, vector<string>& cont, char delim = ' ') 
{ 
	stringstream ss(str); 
	string token;
	while (getline(ss, token, delim)) 
	cont.push_back(token);
}