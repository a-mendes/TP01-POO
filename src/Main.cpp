/**
 * Demais imports sao feitos por "headers/Utilitarios.h"
 */
#include "headers/Utilitarios.h"

#include <typeinfo>

char menu();

bool hasAudioBook(vector<Livro*> &livros, string escritor);
vector<Livro*> livrosByTitulo(vector<Livro*> &livros, string titulo);
vector<Impresso*> qtdLivrosEmLivrarias(vector<Livro*> &livros, int qtd);


//Deletar isso depois
void printTeste(Livro *livro)
{
	cout << "======================================" << endl;

	cout << "Tipo livro: " << endl;
	cout << "\t" << typeid(*livro).name() << endl;
	
	cout << "Titulo: " << endl;
	cout << "\t" << livro->getTitulo() << endl;

	cout << "Ano publicacao: " << endl;
	cout << "\t" << livro->getAnoPublicacao() << endl;
	
	cout << "Idioma: " << endl;
	cout << "\t" << livro->getIdiomaOriginal() << endl;

	cout << "Escritores: " << endl;
	for (int j = 0; j < livro->getEscritores().size(); ++j)
		cout << "\t" << livro->getEscritores()[j] << endl;

	cout << "Keywords: " << endl;	
	for (int j = 0; j < livro->getKeywords().size(); ++j)
		cout << "\t" << livro->getKeywords()[j] << endl;

	cout << "Capitulos: " << endl;
	for (int j = 0; j < livro->getCapitulos().size(); ++j)
		cout << "\t" << livro->getCapitulos()[j] << endl;

	cout << endl;
}

void mostrarOuSalvarColecaoLivro();
int quantidadeKeywordColecaoLivro(vector<Livro*> &livros, string keyword);
void mapeamentoColecaoLivro();

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

	char op = '*';
	do 
	{
		op = menu();

		switch(op)
		{
			case 'a': case 'A':
			{
				//trocar por implementacao do romulo
				for (int i = 0; i < livros.size(); ++i)
				{
					printTeste(livros[i]);
				}	
			} break;

			case 'b': case 'B': 
			{

			} break;

			case 'c': case 'C': 
			{

			} break;

			case 'd': case 'D': 
			{
				//Melhorar UI
				cout << "Informe a quantidade de Livros: ";
				int qtdLivros;
				cin >> qtdLivros;

				vector<Impresso*> livrosEmLivrarias = qtdLivrosEmLivrarias(livros, qtdLivros);

				if (livrosEmLivrarias.size() == 0)
				{
					cout << "Nenhum livro foi encontrado" << endl;
					break;
				}

				for (int i = 0; i < livrosEmLivrarias.size(); ++i)
				{
					//Substituir por implementacao do Romulo
					printTeste(livrosEmLivrarias[i]);
				}

			} break;

			case 'e': case 'E':
			{
				//Melhorar UI
				cout << "Informe o nome do escritor: ";
				string escritor;
				/**
				 * cin >> ws, artificio tecnico usado para contornar problema de buffer
				 * Disponivel em: https://www.geeksforgeeks.org/problem-with-getline-after-cin/.
				 */ 
				getline(cin >> ws, escritor); 
				
				string nao = (hasAudioBook(livros, escritor)) ? (" ") : (" nao ");

				cout << "O escritor '" << escritor << "'" << nao << "possui AudioBooks" << endl; 
			} break;

			case 'f': case 'F':
			{
				//Melhorar UI
				cout << "Informe o Titulo: ";
				string titulo;
				/**
				 * cin >> ws, artificio usado para contornar problema de buffer
				 * Disponivel em: https://www.geeksforgeeks.org/problem-with-getline-after-cin/.
				 */ 
				getline(cin >> ws, titulo); 

				vector<Livro*> livrosTitulo = livrosByTitulo(livros, titulo);

				if (livrosTitulo.size() == 0)
				{
					cout << "Nenhum livro foi encontrado" << endl;
					break;
				}

				for (int i = 0; i < livrosTitulo.size(); ++i)
				{
					//Substituir por implementacao do Romulo
					printTeste(livrosTitulo[i]);
				}

			} break;

			case 'g': case 'G':
			{
					
			} break;

			case 'h': case 'H':
			{
					
			} break;

			case 'i': case 'I':
			{
					
			} break;

			case 'j': case 'J':
			{
				mostrarOuSalvarColecaoLivro();		
			} break;

			case 'k': case 'K':
			{
				string keyword;
				cin.ignore();

				cout << "Keyword: "; getline(cin, keyword);
				cout << "Quantidade de livros com Keyword " << keyword << ": " << quantidadeKeywordColecaoLivro(livros, keyword) << endl;
			} break;

			case 'l': case 'L':
			{
				mapeamentoColecaoLivro();		
			} break;

			case '0': break;

			default:
				cout << "Opcao Invalida" << endl;
				menu();
				break;
		}
	} while(op != '0');

	return 0;
}

char menu()
{
	cout << endl;
	cout << ".---------------------------." << endl;
	cout << "|          FUNCOES          |" << endl;
	cout << "`---------------------------`" << endl;
	cout << endl;
	cout << "a) Exibir Livros" << endl;
	cout << "b) Filtrar Livros por Idioma" << endl;
	cout << "c) Filtrar Livros Eletronicos por Formato" << endl;
	cout << "d) Filtrar Livros Impressos por quantidade em livrarias" << endl;
	cout << "e) Verificar se escritor possui AudioBook" << endl;
	cout << "f) Filtrar Livros por Titulo" << endl;
	cout << "g) Exibir todos os Keywords" << endl;
	cout << "h) Filtrar Livros por quantidade de Capitulos" << endl;
	cout << "i) kkkkkk n entendi esse item" << endl;
	cout << "j) Exibir todos os tipos de Livros" << endl;
	cout << "k) Exibir a quantidade de Livros que contem uma keyword" << endl;
	cout << "l) tbm n entendi esse item" << endl;
	cout << "0) SAIR" << endl;

	char op;
	cout << endl;
	cout << " * Escolha a opcao informando a letra correspondente: " << endl; //Melhorar
	cin >> op;

	return op;
}

void mostrarOuSalvarColecaoLivro(){
	// Criar uma função que recebe uma unica coleção de livros de todos os tipos e que                             
	// mostre no terminal ou salve em um arquivo (saida.txt) todos os tipos de livros.                      
	// Mostrar os dados comuns e específicos do livro conforme o item a). Um argumento                         
	// passado para a função define qual será a saída. Nesse caso é necessário                         
	// downcasting.
}

int quantidadeKeywordColecaoLivro(vector<Livro*> &livros, string keyword){
	int countVar = 0;
	vector<string> vetorKeywords;

	for (int i = 0; i < 16; i++){
		vetorKeywords = livros[i]->getKeywords(); 
		if(count(vetorKeywords.begin(), vetorKeywords.end(), keyword) > 0)
			countVar += 1;
	}
	
	return countVar;

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
vector<Impresso*> qtdLivrosEmLivrarias(vector<Livro*> &livros, int qtd)
{ 
	//Quantidade de livros em livrarias ou a quantidade de livrarias que possuem o livro?
	vector<Impresso*> livrosEmLivrarias;

	for (int i = 0; i < livros.size(); ++i)
	{
		Livro *livro = livros[i];

		/**
		 * Variavel auxiliar para identificar instancia do objeto
		 */
		Livro *impresso = new Impresso();

		/**
		 * Verifica se o objeto atual pertence a Classe Impresso
		 */
		if(typeid(*livro).name() == typeid(*impresso).name())
		{ 
			Impresso *livroImpresso = dynamic_cast<Impresso *>(livro);
			vector<string> livrarias = livroImpresso->getLivrarias();

			if(livrarias.size() >= qtd)
				livrosEmLivrarias.push_back(livroImpresso);
		}
	}

	return livrosEmLivrarias;
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

vector<Livro*> livrosByTitulo(vector<Livro*> &livros, string titulo)
{
	vector<Livro*> livrosTitulo;

	for (int i = 0; i < livros.size(); ++i)
	{
		Livro *livro = livros[i];

		if (livro->getTitulo() == titulo)
		{
			livrosTitulo.push_back(livro);
		}
	}

	return livrosTitulo;
}