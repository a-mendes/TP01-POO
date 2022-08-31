#include "headers/Utilitarios.h"

#include <typeinfo>

bool hasAudioBook(vector<Livro*> &livros, string escritor);

void mostrarOuSalvarColecaoLivro();
int quantidadeKeywordColecaoLivro(vector<Livro*> &livros, string keyword);
void mapeamentoColecaoLivro();

int testeSobrecarga();

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

	// print teste
	// for (int i = 0; i < livros.size(); ++i)
	// {
	// 	Livro *livro = livros[i];
	// 	cout << "Livro " << i + 1 << ") " << typeid(*livro).name() << endl;
	// 	cout << "\t" << livros[i]->getTitulo() << endl;
	// 	cout << "\t" << livros[i]->getAnoPublicacao() << endl;

	// 	for (int j = 0; j < livros[i]->getEscritores().size(); ++j)
	// 		cout << "\t" << livros[i]->getEscritores()[j] << endl;

	// 	cout << endl;
	// }

	//Criar um menu de acesso as funcoes - novo arquivo?

	testeSobrecarga();

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

		case 'j':{
			mostrarOuSalvarColecaoLivro();		
		}

		case 'k':{
			string keyword;
			cin >> keyword;
			//validar Keyword digitada? 

			cout << "Quantidade de livros com Keyword " << keyword << ": " << quantidadeKeywordColecaoLivro(livros, keyword) << endl;		
		}

		case 'l':{
			mapeamentoColecaoLivro();		
		}

	}

	return 0;
}

void mostrarOuSalvarColecaoLivro(){
	// Criar uma função que recebe uma unica coleção de livros de todos os tipos e que                             
	// mostre no terminal ou salve em um arquivo (saida.txt) todos os tipos de livros.                      
	// Mostrar os dados comuns e específicos do livro conforme o item a). Um argumento                         
	// passado para a função define qual será a saída. Nesse caso é necessário                         
	// downcasting.
}

int quantidadeKeywordColecaoLivro(vector<Livro*> &livros, string keyword){
	// Dado uma keyword, criar uma função que retorne a quantidade de livros que                       
	// possuam aquela keyword dentro uma coleção, seja ela qual for (livro, impresso,                     
	// eletrônico ou audiobook). No main deve ser mostrado a quantidade encontrada.

	//Buscas pela Keyword por todas os compos do livro	

	//verificar qual o tipo do livro
	//fazer o dawncasting
	//buscar pela Keyword e incrementar no retorno

	return 1;

}

void mapeamentoColecaoLivro(){
	// Criar uma função que recebe uma única coleção de livros de todos os tipos, além                           
	// de uma estrutura capaz de realizar o mapeamento a seguir (No main mostrar o                         
	// resultado):

	// i. Inglês = ING;
	// ii. Espanhol = ESP;
	// iii. Francês = FRS;
	// iv. Português  = POT.
}

//Verificar escopo adequado
vector<Impresso> qtdLivrarias(vector<Livro*> &livros, int qtd)
{ 
	//Quantidade de livros em livrarias ou a quantidade de livrarias que possuem o livro?
	
	for (int i = 0; i < livros.size(); ++i)
	{
		/* code */
	}

	//so pro compilador para de reclamar. mateus
	vector<Impresso> tmp;
	return tmp;
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



//Verificar escopo adequado
