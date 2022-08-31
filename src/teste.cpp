
#include "headers/Utilitarios.h"

#include <typeinfo>
int main(){
  Livro a;
  
  string titulo = "asd";
  a.setTitulo(titulo);
  
//   vector<string>cap;
//   cap[0]="AU",cap[1]="AU",cap[2]="AU",cap[3]="AU",cap[4]="AU";
//   a.setCapitulos(cap);
  
//   vector<string>escri;
//   escri[0]="Alver",escri[1]="AU",escri[2]="AU",escri[3]="AU",escri[4]="AU";
//   a.setEscritores(escri);
  
//   string Nome = "sapequinha";
//   a.setTitulo(Nome);
  
//   string Idi = "Russo";
//   a.setIdiomaOriginal(Idi);
  
//   vector<string>keys;
//   keys[0]="paper",keys[1]="aaaa",keys[2]="AU",keys[3]="AU",keys[4]="AU",keys[7]="paper";
//   keys[8]="AU",keys[9]="AU",keys[10]="AU",keys[11]="AU",keys[12]="AU",keys[13]="AU",keys[14]="AU";
//   a.setKeywords(keys);

  cout<<a;
  
  return 0;
}