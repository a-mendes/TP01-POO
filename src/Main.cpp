/**
 * Demais imports sao feitos por "headers/Utilitarios.h"
 */
#include "headers/Utilitarios.h"

#include<vector>
#include <algorithm>
#include <typeinfo>
#include <map>

char menu();

//g++ -o ColecaoLivros.exe src/*.cpp -Wall
//https://stackoverflow.com/questions/3660901/a-warning-comparison-between-signed-and-unsigned-integer-expressions


int main(int argc, char const *argv[])
{                                        
	cout << "  _____ ____   ___  _           ____   ___   ___  " << endl;
	cout << " |_   _|  _ \\ / _ \\/ |         |  _ \\ / _ \\ / _ \\ " << endl;
	cout << "   | | | |_) | | | | |  _____  | |_) | | | | | | |" << endl;
	cout << "   | | |  __/| |_| | | |_____| |  __/| |_| | |_| |" << endl;
	cout << "   |_| |_|    \\___/|_|         |_|    \\___/ \\___/ " << endl;
	cout << endl;
	cout << "Ana Laura Siqueira Mendes - 20.2.4091" << endl;
	cout << "Guilherme Salim Monteiro de Castro Paes - 21.1.4109" << endl;
	cout << "Mateus Filipe Moreira Silva - 21.1.4156" << endl;
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
				for (int i = 0; i < (int)livros.size(); ++i)
				{
					cout << *livros[i];
					
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
				for (int i = 0; i < (int)recebelivros.size(); i++)
				{
					cout <<*recebelivros[i];
					
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
				for (int i = 0; i < (int)recebelivros.size(); i++)
				{
					cout <<*recebelivros[i];
					
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

				if ((int)livrosEmLivrarias.size() == 0)
				{
					cout << "Nenhum livro foi encontrado" << endl;
					system("pause");
					break;
				}

				for (int i = 0; i < (int)livrosEmLivrarias.size(); ++i)
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

				if ((int)livrosTitulo.size() == 0)
				{
					cout << "Nenhum livro foi encontrado" << endl;
					system("pause");
					break;
				}

				for (int i = 0; i < (int)livrosTitulo.size(); ++i)
				{
					cout<<*livrosTitulo[i];
				}
				system("pause");
			} break;

			case 'g': case 'G':
			{
                vector<string> keywords = printKeywords(livros);
				for(int i = 0; i < (int)keywords.size();i++){
					cout << keywords[i] << "; ";
				}
				cout << endl;
				system("pause");
			} break;

			case 'h': case 'H':
			{
				int capitulos;
				cout << "Numero minimo de capitulos:"; cin >> capitulos;
				vector<string> listaDeLivros = filtraPorCapitulo(livros, capitulos);
				for(int i = 0; i < listaDeLivros.size(); i++){
					cout << listaDeLivros[i] << "; ";
				}
				cout << endl;
				system("pause");
			} break;

			case 'i': case 'I':
			{	
				string titulo;
				cout << "Digite o título do livro:" << endl;
				getline(cin >> ws, titulo);
				vector<vector<Livro*>::iterator> itrs = retornaIterador(titulo, livros);
				for(int i = 0; i < itrs.size(); i++){
					Impresso *livroImpresso = dynamic_cast<Impresso*>(*itrs[i]);
					if(livroImpresso != nullptr){
						cout << *livroImpresso << endl; 
					}
					Eletronico *livroEletronico = dynamic_cast<Eletronico*>(*itrs[i]);
					if(livroEletronico != nullptr){
						cout << *livroEletronico << endl; 
					}
					AudioBook *livroAudioBook = dynamic_cast<AudioBook*>(*itrs[i]);
					if(livroAudioBook != nullptr){
						cout << *livroAudioBook << endl; 
					}
				}
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








