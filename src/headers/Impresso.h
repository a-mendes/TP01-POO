#ifndef IMPRESSO
#define IMPRESSO

#include <string>
#include <vector>
#include "Livro.h"

//Verificar boa prática
using namespace std;

class Impresso: public Livro {
    
	private:
		vector<string> livrarias;
		int colunas;

	public:
		vector<string> getLivrarias();
		void setLivrarias(vector<string> livrarias);
		
		int getColunas();
		void setColunas(int colunas);	
};


#endif 