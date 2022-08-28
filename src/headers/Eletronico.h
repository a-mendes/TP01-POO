#ifndef ELETRONICO
#define ELETRONICO

#include <string>
#include <vector>
#include "Livro.h"

//Verificar boa prática
using namespace std;

class Eletronico : public Livro {
    
	private:
		string url;
		string formatoArquivo;

	public:
		string getUrl();
		void setUrl(string url);
		
		string getFormatoArquivo();
		void setFormatoArquivo(string formatoArquivo);	

};

#endif 