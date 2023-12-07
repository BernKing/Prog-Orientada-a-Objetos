#ifndef GERIRNUMEROS_H
#define GERIRNUMEROS_H

#include <list>

/*
Exercicio7
*/

using namespace std;

class GerirNumeros {
 private:
  list<int> listaInteiros;

 public:
  //Construtores
  GerirNumeros();
  GerirNumeros(list<int> Lista);
  //Destrutores

  inline list<int> GetLista() { return listaInteiros; }
  inline void SetLista(list<int> _listaInteiros) { listaInteiros = _listaInteiros; }

  //methods
  void inserirNumero(int numero);
  void removerNumero(int numero);
  void Show();
  void ObterPosicao(int numero);

};
#endif //GERIRNUMEROS_H
