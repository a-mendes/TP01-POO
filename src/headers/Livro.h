#ifndef LIVRO_H_
#define LIVRO_H_

#include <string>
#include <list>

//Verificar boa prática
using namespace std;

/**
 * Classe abstrata
 */ 
class Livro
{	
	private:
		list<string> escritores;
		string titulo;
		list<string> capitulos;
		int anoPublicacao;
		string idiomaOriginal;
		list<string> keywords;

	public:
		Livro();
		//Confirmar questão de classe abstrata e função virtual pura
		virtual ~Livro();

		list<string> getEscritores();
		void setEscritores(list<string> escritores);

		string getTitulo();
		void setTitulo(string titulo);

		list<string> getCapitulos();
		void setCapitulos(list<string> capitulos);

		int getAnoPublicacao();
		void setAnoPublicacao(int anoPublicacao);

		string getIdiomaOriginal();
		void setIdiomaOriginal(string idiomaOriginal);

		list<string> getKeywords();
		void setKeywords(list<string> keywords);
};

#endif 