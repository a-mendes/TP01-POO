#ifndef AUDIO_BOOK
#define AUDIO_BOOK

#include <string>
#include <vector>
#include "Livro.h"

using namespace std;

class AudioBook : public Livro {
    
	private:
		float duracao;
		string formatoArquivo;

	public:
		float getDuracao();
		void setDuracao(float duracao);
		
		string getFormatoArquivo();
		void setFormatoArquivo(string formatoArquivo);	
		void saida(ostream& os)const;
		
		friend ostream& operator<<(ostream&, const AudioBook&);
};

#endif 