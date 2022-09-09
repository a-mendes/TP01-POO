#ifndef LIVRO_H_
#define LIVRO_H_

#include <string>
#include <vector>

//Verificar boa prática
using namespace std;

/**
 * Classe abstrata
 */ 
class Livro
{	
	private:
		vector<string> escritores;
		string titulo;
		vector<string> capitulos;
		int anoPublicacao;
		string idiomaOriginal;
		vector<string> keywords;

	public:
		Livro();
		//Confirmar questão de classe abstrata e função virtual pura
		virtual ~Livro();

		vector<string> getEscritores();
		void setEscritores(vector<string> escritores);

		string getTitulo();
		void setTitulo(string titulo);

		vector<string> getCapitulos();
		void setCapitulos(vector<string> capitulos);

		int getAnoPublicacao();
		void setAnoPublicacao(int anoPublicacao);

		string getIdiomaOriginal();
		void setIdiomaOriginal(string idiomaOriginal);

		vector<string> getKeywords();
		void setKeywords(vector<string> keywords);

		friend ostream& operator<<(ostream&, Livro&);
		
};

#endif 