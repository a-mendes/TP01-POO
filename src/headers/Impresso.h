#ifndef IMPRESSO
#define IMPRESSO

#include <string>
#include <list>
#include "Livro.h"

//Verificar boa prática
using namespace std;

class Impresso: public Livro {
    
	private:
		list<string> livrarias;
		int colunas;

	public:
		list<string> getLivrarias();
		void setLivrarias(list<string> livrarias);
		
		int getColunas();
		void setColunas(int colunas);	
};


#endif 