#ifndef AUDIO_BOOK
#define AUDIO_BOOK

#include <string>
#include <vector>
#include "Livro.h"

//Verificar boa prática
using namespace std;

class AudioBook : public Livro{
    
	private:
		float duracao;
		string formatoArquivo;

	public:
		float getDuracao();
		void setDuracao(float duracao);
		
		string getFormatoArquivo();
		void setFormatoArquivo(string formatoArquivo);	

};

#endif 