#ifndef IMPRESSO
#define IMPRESSO

#include <string>
#include <vector>
#include "Livro.h"

//Verificar boa prática
using namespace std;

class Impresso: public Livro{
    
	private:
		vector<string> livraria;
		int colunas;

	public:
		vector<string> getLivraria();
		void setLivraria(vector<string> livraria);
		
		int getColunas();
		void setColunas(int colunas);	

};


#endif 