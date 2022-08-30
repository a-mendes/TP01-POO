/**
 * Demais imports sao feitos por "headers/Utilitarios.h"
 */
#include "headers/Utilitarios.h"

#include <typeinfo>

bool hasAudioBook(vector<Livro*> &livros, string escritor);

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

	/* print teste*/
	for (int i = 0; i < livros.size(); ++i)
	{
		Livro *livro = livros[i];
		cout << "Livro " << i + 1 << ") " << typeid(*livro).name() << endl;
		cout << "\t" << livros[i]->getTitulo() << endl;
		cout << "\t" << livros[i]->getAnoPublicacao() << endl;

		for (int j = 0; j < livros[i]->getEscritores().size(); ++j)
			cout << "\t" << livros[i]->getEscritores()[j] << endl;

		cout << endl;
	}

	//Criar um menu de acesso as funcoes - novo arquivo?

	char op;
	cout << "Escolha a opcao" << endl; //Melhorar
	cin >> op;

	switch(op)
	{
		case 'd':
		{

		} break;

		case 'e':
		{
			cout << "Informe o nome do escritor: ";
			string escritor;
			/**
			 * cin >> ws, artificio usado para contornar problema de buffer
			 * Disponivel em: https://www.geeksforgeeks.org/problem-with-getline-after-cin/.
			 */ 
			getline(cin >> ws, escritor); 
			
			string nao = (hasAudioBook(livros, escritor)) ? (" ") : (" nao ");

			cout << "O escritor '" << escritor << "'" << nao << "possui AudioBooks" << endl; 
		} break;

		case 'f':
		{

		} break;

	}

	return 0;
}

//Verificar escopo adequado
vector<Impresso> qtdLivrarias(vector<Livro*> &livros, int qtd)
{
	/**
	 * Dado um número de livrarias, criar uma função que retorne uma coleção com os 
	 * livros impressos com um número maior ou igual de livros em livrarias. No main
	 * deve ser mostrado uma mensagem de “não encontrado” se nenhum livro impresso
	 */ 
	//Quantidade de livros em livrarias ou a quantidade de livrarias que possuem o livro?
	
	for (int i = 0; i < livros.size(); ++i)
	{
		/* code */
	}
}

//Verificar escopo adequado
bool hasAudioBook(vector<Livro*> &livros, string escritor)
{
	for (int i = 0; i < livros.size(); ++i)
	{
		Livro *livro = livros[i];

		/**
		 * Variavel auxiliar para identificar instancia do objeto
		 */
		Livro *audiobook = new AudioBook();

		/**
		 * Verifica se o objeto atual pertence a Classe AudioBook
		 */
		if(typeid(*livro).name() == typeid(*audiobook).name())
		{ 
			/**
			 * Compara todos os escritores do AudioBook com o escritor buscado
			 */ 
			vector<string> escritores = livro->getEscritores();
			for (int i = 0; i < escritores.size(); ++i)
			{
				if(escritores[i] == escritor)
					return true;
			}
		}
	}

	return false;
}