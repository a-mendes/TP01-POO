/**
 * Demais imports sao feitos por "headers/Utilitarios.h"
 */
#include "headers/Utilitarios.h"

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
		cout << "Livro " << i + 1 << ") " << endl;
		cout << "\t" << livros[i]->getTitulo() << endl;
		cout << "\t" << livros[i]->getAnoPublicacao() << endl;

		for (int j = 0; j < livros[i]->getEscritores().size(); ++j)
			cout << "\t" << livros[i]->getEscritores()[j] << endl;

		cout << endl;
	}

	//Criar um menu de acesso as funcoes - novo arquivo?

	char op;
	cout << "Escolha a opcao" << endl;
	cin >> op;

	switch(op)
	{
		case 'd':
		{

		} break;

		case 'e':
		{

		} break;

		case 'f':
		{

		} break;

	}

	return 0;
}

