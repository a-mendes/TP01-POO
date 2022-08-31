#include "headers/Impresso.h"
#include "headers/Utilitarios.h"

vector<string> Impresso::getLivrarias(){
    return this->livrarias;
}
void Impresso::setLivrarias(vector<string> livrarias){
	this->livrarias = livrarias;
}

int Impresso::getColunas(){
    return this->colunas;
}

void Impresso::setColunas(int colunas){
    this->colunas = colunas;
}

ostream& operator<<(ostream& cout,  Impresso& livro){
    
	cout<< left <<'|'<<livro.getTitulo().erase(30);
	cout<<right <<'|'<<livro.getEscritores().front();
	cout<< left <<'|'<<livro.getIdiomaOriginal();
	if(livro.getCapitulos().size()<=10)
		cout<<"|00"<<livro.getCapitulos().size();
	
	else if(livro.getCapitulos().size()>10&&livro.getCapitulos().size()<100)
		cout<<"|0"<<livro.getCapitulos().size();
	
	else
		cout<<"|" <<livro.getCapitulos().size();

	
	if(livro.getKeywords().size()<10){
		cout<<"|0"<<livro.getKeywords().size(); }
	else{
		cout<<"|"<<livro.getKeywords().size();
	}
	
    if (livro.getLivrarias().front()=="")
        cout<<"|Nenhuma";
    else 
        cout<<"|"<<livro.getLivrarias().front();
	
	return cout;
}