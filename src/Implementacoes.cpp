#include "headers/Implementacoes.h"

#include<vector>
#include <algorithm>
#include <typeinfo>
#include <map>

//------------------------ A
//Sobrecarga nas classes e print no main

//------------------------ B
vector<Livro*> livrosByID(string idioma,vector<Livro*>&livros){
	vector<Livro*> livrosIdioma;
	int tam = (int)livros.size();
	//Separa Livros com determinado idioma dos demais 
	for (int i = 0; i < tam; ++i)
	{
		Livro *livro = livros[i];
		if (livro->getIdiomaOriginal() == idioma)
			livrosIdioma.push_back(livro);
		
	}

	return livrosIdioma;
}

//------------------------ C
vector<Eletronico*> livrosEByFormato(string formato,vector<Livro*>&livros){
	vector<Eletronico*> livrosEletronicos;
	Eletronico *aux1;
	int tam = (int)livros.size();
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


	int tam2 = (int)livrosEletronicos.size();
	//Ordena Livros Eletronicos com base no ano de publicação


	std::sort(livrosEletronicos.begin(), livrosEletronicos.end(), comparePtrToEletronico);

	return livrosEletronicos;
}
bool comparePtrToEletronico(Eletronico* a, Eletronico* b) {
	Livro livro1 = *a;
	Livro livro2 = *b; 
	return (livro1.getAnoPublicacao() < livro2.getAnoPublicacao()); 
}

//------------------------ D
vector<Impresso*> qtdLivrosEmLivrarias(vector<Livro*> &livros, int qtd)
{ 
	//Quantidade de livros em livrarias ou a quantidade de livrarias que possuem o livro?
	vector<Impresso*> livrosEmLivrarias;
	int tam = (int)livros.size();
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

			if((int)livrarias.size() >= qtd)
				livrosEmLivrarias.push_back(livroImpresso);
		}
	}

	return livrosEmLivrarias;
}

//------------------------ E
bool hasAudioBook(vector<Livro*> &livros, string escritor)
{
	int tam = (int)livros.size();
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
			for (int i = 0; i < (int)escritores.size(); ++i)
			{
				if(escritores[i] == escritor)
					return true;
			}
		}
	}

	return false;
}

//------------------------ F
vector<Livro*> livrosByTitulo(vector<Livro*> &livros, string titulo)
{
	vector<Livro*> livrosTitulo;
	int tam = (int)livros.size();
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

//------------------------ G
vector <string> printKeywords(vector<Livro*> &livros){
	vector<string> keywords; // vector auxiliar que ira armazenar as keywords sem repeticao
	for(int i = 0; i < QTD_LIVROS; i++){
		for(int j = 0; j < (int)livros[i]->getKeywords().size(); j++){// percorre todas as keywords de cada livro
			if(count(keywords.begin(), keywords.end(), livros[i]->getKeywords()[j]) == 0){// verifica se a keyword analisada ja se encontra no vetor
				keywords.push_back(livros[i]->getKeywords()[j]);// add a nova keyword ao vetor
			}
		}
	}
	return keywords;
}

//------------------------ H
vector <string> filtraPorCapitulo(vector<Livro*> &livros, int capitulos){
	vector<string> livrosFiltrados;// vetor de titulos de livros filtrados por quantidade de capitulos
	vector<Livro*> aux = livros;// vetor auxiliar que sera ordenado
	sort(aux.begin(), aux.end(), comparaEscritores);// ordena o vetor auxiliar em ordem do primeiro escritor
	for(int i = 0; i < QTD_LIVROS; i++){
		// a cada livro do vetor de livros, verifica se a quantidade de capitulos é a quantidade buscada
		if(aux[i]->getCapitulos().size() <= capitulos){
			livrosFiltrados.push_back(aux[i]->getTitulo());// se for, add o livro ao vetor de livros filtrados por capitulo
		}
	}
	return livrosFiltrados;//retorna o vetor de livros filtrados, ja ordenado em relacao aos escritores
}
bool comparaEscritores(Livro* a, Livro* b){
	return (a->getEscritores()[0] < b->getEscritores()[0]);
}

//------------------------ I
vector<vector<Livro*>::iterator> retornaIterador (string titulo, vector<Livro*> &livros){
	vector<vector<Livro*>::iterator> retorno;//vetor de iteradores
	for (auto itr = livros.begin(); itr != livros.end(); itr++) {
		if ((*itr)->getTitulo() == titulo){//percorre o vetor de livros buscando os titulos passados como entrada
			retorno.push_back(itr);// add o iterador do vector de livros ao vector de iteradores
		}
	}
	return retorno;//retorna o vector de iteradores para todos os titulos encontrados
}

//------------------------ J
void mostrarOuSalvarColecaoLivro(vector<Livro*> &livros, int arquivoConsole){
	fstream arquivo;
	if(arquivoConsole == 2)
			arquivo.open("data/saida.txt", ios::out);

	//https://stackoverflow.com/questions/70671667/why-my-overloaded-operator-is-not-working-for-derived-class
	for (int i = 0; i < (int)livros.size(); i++){
		if(typeid(*livros[i]).name() == typeid(Impresso).name()){
			Impresso *livroImpresso = dynamic_cast<Impresso*>(livros[i]);

			if(arquivoConsole == 1)
				cout << *livroImpresso;
			
			else if(arquivoConsole == 2)
				arquivo << *livroImpresso;
		}
		else if(typeid(*livros[i]).name() == typeid(Eletronico).name()){
			Eletronico *livroEletronico = dynamic_cast<Eletronico*>(livros[i]);
			if(arquivoConsole == 1)
				cout << *livroEletronico;
			
			else if(arquivoConsole == 2)
				arquivo << *livroEletronico;
		}
		else if(typeid(*livros[i]).name() == typeid(AudioBook).name()){
			AudioBook *livroAudioBook = dynamic_cast<AudioBook*>(livros[i]);
			if(arquivoConsole == 1)
				cout << *livroAudioBook;
			
			else if(arquivoConsole == 2)
				arquivo << *livroAudioBook;
		}
	}
}

//------------------------ K
int quantidadeKeywordColecaoLivro(vector<Livro*> &livros, string keyword){
	int countVar = 0;
	vector<string> vetorKeywords;
	int tam = (int)livros.size();
	for (int i = 0; i < tam; i++){
		vetorKeywords = livros[i]->getKeywords(); 
		if(count(vetorKeywords.begin(), vetorKeywords.end(), keyword) > 0)
			countVar += 1;
	}
	
	return countVar;

}

//------------------------ L
multimap<string, Livro> mapeamentoColecaoLivro(vector<Livro*> &livros){
	multimap<string, Livro> mapaLivro;
	
	for (int i = 0; i < (int)livros.size(); i++){
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


