#include <iostream>
#include "headers/AudioBook.h"
#include "headers/Livro.h"
#include "headers/Eletronico.h"
#include "headers/Impresso.h"

using namespace std;

/*
g++ -o code src/*.cpp -Wall
./code
*/

int main(int argc, char const *argv[]){
	cout << "TP01 - POO" << endl;

	Impresso livroImpresso;
	AudioBook livroAudioBook;
	Eletronico livroEletronico;

	livroImpresso.setTitulo("TesteImpresso");
	cout << "livroImpresso: " << livroImpresso.getTitulo() << endl;

	livroAudioBook.setTitulo("TesteAudioBook");
	cout << "livroAudioBook: " << livroAudioBook.getTitulo() << endl;

	livroEletronico.setTitulo("TesteEletronico");
	cout << "livroEletronico: " << livroEletronico.getTitulo() << endl;

	return 0;
}