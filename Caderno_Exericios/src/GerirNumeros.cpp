#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\GerirNumeros.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

GerirNumeros::GerirNumeros() {

  if (!listaInteiros.empty()) {
    listaInteiros.clear();
  }
};
GerirNumeros::GerirNumeros(list<int> Lista) { 
  if (!listaInteiros.empty()) {
    listaInteiros.clear();
  } 
  listaInteiros = Lista;


};
  //Destrutores


//methods
void GerirNumeros::inserirNumero(int numero) {
  listaInteiros.push_back(numero);
};
void GerirNumeros::removerNumero(int numero) {
  /*
  list<int>::iterator numeroRemover = find(listaInteiros.begin(), listaInteiros.end(), numero);

  if (numeroRemover == listaInteiros.end()) {
    cout << "Numero nao encontrado";
  }

  listaInteiros.erase(numeroRemover);
  */
  //ou
  listaInteiros.remove(numero);


};
void GerirNumeros::Show() {
  
  for (int numero : listaInteiros) {
      cout << numero << " ";
  }
   
  /* 
  list<int>::iterator iterator = listaInteiros.begin();
  while(iterator != listaInteiros.end()){
    cout << *iterator << " " ;
    iterator++;
  }
  */
  
};

void GerirNumeros::ObterPosicao(int numero) {
  list<int>::iterator numeroEncontrar = find(listaInteiros.begin(), listaInteiros.end(), numero);

  if (numeroEncontrar == listaInteiros.end()) {
    cout << "Numero nao encontrado";
  }

  int posicao = distance(listaInteiros.begin(), numeroEncontrar) + 1;

  cout << "Posicao absoluta: " << posicao;

  /*
  ou
  i = -1
  while ( p != lista.end()) {
    i++;
    if (p* == numeroEncontrar) {
      return i;
    }
    p++;
  }
  
  
  */
};