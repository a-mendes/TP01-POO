#ifndef UTILITARIOS_H_
#define UTILITARIOS_H_

#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 
#include <algorithm> 
#include <iterator>
#include <vector>

#include "Livro.h"
#include "AudioBook.h"
#include "Eletronico.h"
#include "Impresso.h"

#define QTD_LIVROS 16

using namespace std;

void lerBaseDeDados(vector<Livro*> &livros);
void lerLivro(ifstream &arquivo, Livro *livro);
void lerEletronico(ifstream &arquivo, Eletronico *eletronico);
void lerImpresso(ifstream &arquivo, Impresso *impresso);
void lerAudioBook(ifstream &arquivo, AudioBook *audioBook);

void split(const string &str, vector<string> &cont, char delim); 

#endif 