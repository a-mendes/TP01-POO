/**
 * Demais imports sao feitos por "headers/Utilitarios.h"
 */
#include "headers/Utilitarios.h"
#include<vector>
#include <algorithm>
#include <typeinfo>
#include <map>

char menu();

bool hasAudioBook(vector<Livro*> &livros, string escritor);
vector<Livro*> livrosByTitulo(vector<Livro*> &livros, string titulo);
vector<Impresso*> qtdLivrosEmLivrarias(vector<Livro*> &livros, int qtd);
vector <string> printKeywords(vector<Livro*> &livros);

vector<Livro*> livrosByID(string idioma,vector<Livro*>&livros);

vector<Eletronico*> livrosEByFormato(string idioma,vector<Livro*>&livros);

void mostrarOuSalvarColecaoLivro(vector<Livro*> &livros, int arquivoConsole);
int quantidadeKeywordColecaoLivro(vector<Livro*> &livros, string keyword);
multimap<string, Livro> mapeamentoColecaoLivro(vector<Livro*> &livros);

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
	cout << "Guilherme Salim Monteiro de Castro Paes - 21.1.4109" << endl;
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
			case 'a': case 'A': //Imprime todos os livros 
			{
				for (int i = 0; i < livros.size(); ++i)
				{
					cout << *livros[i];
					cout<<"\n";
				}

				system("pause");
			} break;

			case 'b': case 'B': //Imprime livros de determinado idioma 
			{
				cout << "Informe o Idioma: \n";
				string idioma;
				cin>> idioma; //Capta o idioma requerido 

				vector<Livro*>recebelivros = livrosByID(idioma,livros); // Chama a função
				
				cout << "O idoma " << idioma << " " << "esta presente nos seguintes livros:"  << endl; 
				for (int i = 0; i < recebelivros.size(); i++)
				{
					cout <<*recebelivros[i];
					cout<<"\n";
				}
				system("pause");
			} break;

			case 'c': case 'C'://Imprime Livros eletronicos de determinado formato em ordem Crescente com base no ano de Publicação 
			{
				cout << "Informe o formato: \n";
				string formato;
				cin>> formato; // Capta formato
				
				vector<Eletronico*>recebelivros = livrosEByFormato(formato,livros);//Chama função 
				
				cout << "O formato " << formato << " " << "esta presente nos seguintes livros:"  << endl; 
				for (int i = 0; i < recebelivros.size(); i++)
				{
					cout <<*recebelivros[i];
					cout<<"\n";
				}
				system("pause");
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
					system("pause");
					break;
				}

				for (int i = 0; i < livrosEmLivrarias.size(); ++i)
				{
					cout << *livrosEmLivrarias[i] << "\n";
				}
				system("pause");
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
				system("pause");
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
					system("pause");
					break;
				}

				for (int i = 0; i < livrosTitulo.size(); ++i)
				{
					cout<<*livrosTitulo[i];
					cout << *livrosTitulo[i] << "\n";
				}
				system("pause");
			} break;

			case 'g': case 'G':
			{
                vector<string> keywords = printKeywords(livros);
				for(int i = 0; i < keywords.size();i++){
					cout << keywords[i] << "; ";
				}
				cout << endl;
				system("pause");
			} break;

			case 'h': case 'H':
			{
				system("pause");
			} break;

			case 'i': case 'I':
			{
				system("pause");
			} break;

			case 'j': case 'J':
			{
				int mostrarSalvar;
				cout << "1: Mostrar Dados Console. 2: Escrever no Arquivo: ";
				cin >> mostrarSalvar;
				mostrarOuSalvarColecaoLivro(livros, mostrarSalvar);
				system("pause");
			} break;

			case 'k': case 'K':
			{
				string keyword;
				cin.ignore();

				cout << "Keyword: "; getline(cin, keyword);
				cout << "Quantidade de livros com Keyword " << keyword << ": " << quantidadeKeywordColecaoLivro(livros, keyword) << endl;
				system("pause");
			} break;

			case 'l': case 'L':
			{
				multimap<string, Livro> mapaLivro;
				mapaLivro = mapeamentoColecaoLivro(livros);		

				for (auto &elm: mapaLivro)
					cout << elm.second << "\n";
				system("pause");
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

multimap<string, Livro> mapeamentoColecaoLivro(vector<Livro*> &livros){
	multimap<string, Livro> mapaLivro;
	
	for (int i = 0; i < livros.size(); i++){
		if(livros[i]->getIdiomaOriginal() == "Ingles")
			mapaLivro.insert(pair<string, Livro>("ING", *livros[i]));
		else if(livros[i]->getIdiomaOriginal() == "Espanhol")
			mapaLivro.insert(pair<string, Livro>("ESP", *livros[i]));
		else if(livros[i]->getIdiomaOriginal() == "Frances")
			mapaLivro.insert(pair<string, Livro>("FRS", *livros[i]));
		else if(livros[i]->getIdiomaOriginal() == "Portugues")
			mapaLivro.insert(pair<string, Livro>("POT", *livros[i]));
	}

	return mapaLivro;
	
}

void mostrarOuSalvarColecaoLivro(vector<Livro*> &livros, int arquivoConsole){
	fstream arquivo;
	if(arquivoConsole == 2)
			arquivo.open("data/saida.txt", ios::out);

	for (int i = 0; i < livros.size(); i++){
		if(typeid(*livros[i]).name() == typeid(Impresso).name()){
			Impresso *livroImpresso = dynamic_cast<Impresso*>(livros[i]);
			if(arquivoConsole == 1)
				cout << *livroImpresso << "\n";
			
			else if(arquivoConsole == 2)
				arquivo << *livroImpresso << "\n";
		}
		else if(typeid(*livros[i]).name() == typeid(Eletronico).name()){
			Eletronico *livroEletronico = dynamic_cast<Eletronico*>(livros[i]);
			if(arquivoConsole == 1)
				cout << *livroEletronico << "\n";
			
			else if(arquivoConsole == 2)
				arquivo << *livroEletronico << "\n";
		}
		else if(typeid(*livros[i]).name() == typeid(AudioBook).name()){
			AudioBook *livroAudioBook = dynamic_cast<AudioBook*>(livros[i]);
			if(arquivoConsole == 1)
				cout << *livroAudioBook << "\n";
			
			else if(arquivoConsole == 2)
				arquivo << *livroAudioBook << "\n";
		}
	}
}

int quantidadeKeywordColecaoLivro(vector<Livro*> &livros, string keyword){
	int countVar = 0;
	vector<string> vetorKeywords;
	int tam = livros.size();
	for (int i = 0; i < tam; i++){
		vetorKeywords = livros[i]->getKeywords(); 
		if(count(vetorKeywords.begin(), vetorKeywords.end(), keyword) > 0)
			countVar += 1;
	}
	
	return countVar;

}

//Verificar escopo adequado
vector<Impresso*> qtdLivrosEmLivrarias(vector<Livro*> &livros, int qtd)
{ 
	//Quantidade de livros em livrarias ou a quantidade de livrarias que possuem o livro?
	vector<Impresso*> livrosEmLivrarias;
	int tam = livros.size();
	for (int i = 0; i < tam; ++i)
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
	int tam = livros.size();
	for (int i = 0; i < tam; ++i)
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
	int tam = livros.size();
	for (int i = 0; i < tam; ++i)
	{
		Livro *livro = livros[i];

		if (livro->getTitulo() == titulo)
		{
			livrosTitulo.push_back(livro);
		}
	}

	return livrosTitulo;
}

vector <string> printKeywords(vector<Livro*> &livros){
	vector<string> keywords;
	vector <string> :: iterator it;
	int k = 0;
	for(int i = 0; i < QTD_LIVROS; i++){
		for(int j = 0; j < livros[i]->getKeywords().size(); j++){
			if(count(keywords.begin(), keywords.end(), livros[i]->getKeywords()[j]) == 0){
				it = keywords.begin() + k;
				keywords.insert(it, livros[i]->getKeywords()[j]);
				k+=1;
			}
		}
	}
	return keywords;
}

//Retrona vector com Livros de idioma requerido 
vector<Livro*> livrosByID(string idioma,vector<Livro*>&livros){
	vector<Livro*> livrosIdioma;
	int tam = livros.size();
	//Separa Livros com determinado idioma dos demais 
	for (int i = 0; i < tam; ++i)
	{
		Livro *livro = livros[i];
		if (livro->getIdiomaOriginal() == idioma)
			livrosIdioma.push_back(livro);
		
	}

	return livrosIdioma;
}

//Função que retorna vector de Livros eletronicos com um determinado formato 
vector<Eletronico*> livrosEByFormato(string formato,vector<Livro*>&livros){
	vector<Eletronico*> livrosEletronicos;
	Eletronico *aux1;
	int tam = livros.size();
//Separa os livros eletronicos dos demais 
	for (int i = 0; i < tam; ++i)
	{
		Livro *livro = livros[i];
		Livro *aux = new Eletronico();
		
		if(typeid(*livro).name() == typeid(*aux).name()){
			Eletronico *eletronico = dynamic_cast<Eletronico *>(livro);
//Separa os livros eletronicos com o formato desejado 
			if (eletronico->getFormatoArquivo() == formato)
				livrosEletronicos.push_back(eletronico);
		}
	}


	int tam2 = livrosEletronicos.size();
//Ordena Livros Eletronicos com base no ano de publicação
	for (int  i = 0; i < tam2; i++)
	{
		for (int  j = 0; j < tam2; j++)
		{
			if (livrosEletronicos[i]->getAnoPublicacao()<livrosEletronicos[j]->getAnoPublicacao())
			{
				aux1 = livrosEletronicos[i];
				livrosEletronicos[i] = livrosEletronicos[j];
				livrosEletronicos[j]=aux1;
			}
			
		}
	}
	return livrosEletronicos;
}






