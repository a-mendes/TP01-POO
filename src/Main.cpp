/**
 * Demais imports sao feitos por "headers/Utilitarios.h"
 */
#include "headers/Utilitarios.h"

#include<vector>
#include <algorithm>
#include <typeinfo>
#include <map>

char menu();

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
				for (unsigned long int i = 0; i < livros.size(); ++i)
				{
					cout << *livros[i];
					
				}

			} break;

			case 'b': case 'B': //Imprime livros de determinado idioma 
			{
				cout << "Informe o Idioma: \n";
				string idioma;
				cin>> idioma; //Capta o idioma requerido 

				vector<Livro*>recebelivros = livrosByID(idioma,livros); // Chama a função
				if(recebelivros.size() == 0){
					cout<<"Nao existem livros com esse idioma"<<endl;
					break;}
				cout << "O idoma " << idioma << " " << "esta presente nos seguintes livros:"  << endl; 
				for (unsigned long int i = 0; i < recebelivros.size(); i++)
					cout <<*recebelivros[i];	
				
			} break;

			case 'c': case 'C'://Imprime Livros eletronicos de determinado formato em ordem Crescente com base no ano de Publicação 
			{
				cout << "Informe o formato: \n";
				string formato;
				cin>> formato; // Capta formato
				
				vector<Eletronico*>recebelivros = livrosEByFormato(formato,livros);//Chama função 
				if(recebelivros.size() == 0){
					cout<<"Nao existem livros com esse formato"<<endl;
					break;}
				cout << "O formato " << formato << " " << "esta presente nos seguintes livros:"  << endl; 
				for (unsigned long int i = 0; i < recebelivros.size(); i++)
				{
					cout <<*recebelivros[i];
					
				}
			} break;

			case 'd': case 'D': 
			{
				//Melhorar UI
				cout << "Informe a quantidade de Livros: ";
				unsigned long int qtdLivros;
				cin >> qtdLivros;

				vector<Impresso*> livrosEmLivrarias = qtdLivrosEmLivrarias(livros, qtdLivros);

				if (livrosEmLivrarias.size() == 0)
				{
					cout << "Nenhum livro foi encontrado" << endl;
					break;
				}

				for (unsigned long int i = 0; i < livrosEmLivrarias.size(); ++i)
				{
					cout << *livrosEmLivrarias[i];
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

				for (unsigned long int i = 0; i < livrosTitulo.size(); ++i)
				{
					cout<<*livrosTitulo[i];
				}
			} break;

			case 'g': case 'G':
			{
                vector<string> keywords = printKeywords(livros);
				for(unsigned long int i = 0; i < keywords.size();i++){
					cout << keywords[i] << "; ";
				}
				cout << endl;
			} break;

			case 'h': case 'H':
			{
				unsigned long int capitulos;
				cout << "Numero minimo de capitulos:"; cin >> capitulos;
				vector<Livro*> listaDeLivros = filtraPorCapitulo(livros, capitulos);
				for(unsigned long int i = 0; i < listaDeLivros.size(); i++){
					cout << *listaDeLivros[i];
				}
				cout << endl;
			} break;

			case 'i': case 'I':
			{	
				string titulo;
				cout << "Digite o título do livro:" << endl;
				getline(cin >> ws, titulo);
				vector<vector<Livro*>::iterator> itrs = retornaIterador(titulo, livros);
				//percorre o vector de iteradores e faz um downcasting de cada iterador para cada sub-classe
				for(unsigned long int i = 0; i < itrs.size(); i++){
					// downcasting de iterador para livro impresso
					Impresso *livroImpresso = dynamic_cast<Impresso*>(*itrs[i]);
					if(livroImpresso != nullptr){// se o downcasting tiver sucesso. imprime o livro impresso
						cout << *livroImpresso << endl; 
					}
					// downcasting de iterador para livro eletronico
					Eletronico *livroEletronico = dynamic_cast<Eletronico*>(*itrs[i]);
					if(livroEletronico != nullptr){// se o downcasting tiver sucesso. imprime o livro eletronico
						cout << *livroEletronico << endl; 
					}
					// downcasting de iterador para audiobook
					AudioBook *livroAudioBook = dynamic_cast<AudioBook*>(*itrs[i]);// se o downcasting tiver sucesso. imprime o audiobook
					if(livroAudioBook != nullptr){
						cout << *livroAudioBook << endl; 
					}
				}
			} break;

			case 'j': case 'J':
			{
				int mostrarSalvar;
				cout << "1: Mostrar Dados Console. 2: Escrever no Arquivo: ";
				cin >> mostrarSalvar;
				mostrarOuSalvarColecaoLivro(livros, mostrarSalvar);
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
				multimap<string, Livro> mapaLivro;
				mapaLivro = mapeamentoColecaoLivro(livros);		

				typedef std::multimap<string, Livro>::iterator MMAPIterator;
				pair<MMAPIterator, MMAPIterator> result;

				result = mapaLivro.equal_range("ING");
				for (MMAPIterator it = result.first; it != result.second; it++)
					cout << it->second;
				
				result = mapaLivro.equal_range("ESP");
				for (MMAPIterator it = result.first; it != result.second; it++)
					cout << it->second;

				result = mapaLivro.equal_range("FRS");
				for (MMAPIterator it = result.first; it != result.second; it++)
					cout << it->second;

				result = mapaLivro.equal_range("POT");
				for (MMAPIterator it = result.first; it != result.second; it++)
					cout << it->second;

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
	cout << "i) Retorna um interador para cada tipo de livro" << endl;
	cout << "j) Exibir todos os tipos de Livros" << endl;
	cout << "k) Exibir a quantidade de Livros que contem uma keyword" << endl;
	cout << "l) Realiza mapeamento de livros" << endl;
	cout << "0) SAIR" << endl;

	char op;
	cout << endl;
	cout << " * Escolha a opcao informando a letra correspondente: " << endl; //Melhorar
	cin >> op;

	return op;
}








