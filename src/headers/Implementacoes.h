#ifndef IMPLEMENTACOES_H
#define IMPLEMENTACOES_H

#include <string>
#include<vector>
#include <algorithm>
#include <typeinfo>
#include <map>

#include "Utilitarios.h"

using namespace std;

vector<Livro*> livrosByID(string idioma,vector<Livro*>&livros);
vector<Eletronico*> livrosEByFormato(string formato,vector<Livro*>&livros); bool comparePtrToEletronico(Eletronico* a, Eletronico* b);
vector<Impresso*> qtdLivrosEmLivrarias(vector<Livro*> &livros, int qtd);
bool hasAudioBook(vector<Livro*> &livros, string escritor);
vector<Livro*> livrosByTitulo(vector<Livro*> &livros, string titulo);
vector <string> printKeywords(vector<Livro*> &livros);
//H
//I
void mostrarOuSalvarColecaoLivro(vector<Livro*> &livros, int arquivoConsole);
int quantidadeKeywordColecaoLivro(vector<Livro*> &livros, string keyword);
multimap<string, Livro> mapeamentoColecaoLivro(vector<Livro*> &livros);

#endif 