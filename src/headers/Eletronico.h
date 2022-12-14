#ifndef ELETRONICO
#define ELETRONICO

#include <string>
#include <vector>
#include "Livro.h"

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
		void saida(ostream& os)const;
		friend ostream& operator<<(ostream&, const Eletronico&);
};

#endif 