#ifndef GESTORFUNCIONARIOS_H
#define GESTORFUNCIONARIOS_H

#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h"

#include <list>
#include <fstream>
using namespace std;

class GestorFuncionarios {
 private:
  list <Funcionario*> ListaFuncionarios;


 public:
  GestorFuncionarios();
  GestorFuncionarios(list <Funcionario*> ListaFuncionarios);


  inline list<Funcionario*> GetListaFuncionarios() { return ListaFuncionarios; }
  inline void SetListaFuncionarios(list<Funcionario*> _ListaFuncionarios) { ListaFuncionarios = _ListaFuncionarios; }

  /*
a) Um método para adicionar um funcionário à lista (AddFunc);
b) Um método para remover um funcionário da lista (RemoveFunc);
c) Listar, no ecrã, a informação de todos os funcionários (ShowFunc);
d) Sobrecarga dos operadores >> e << ;
e) Ler os dados de N funcionários, para a lista, a partir de um ficheiro (ReadFile).
f) Gravar os dados dos funcionários para um ficheiro (SaveFile);  
  */
  void AddFuncionario(Funcionario* _funcionario);
  void RemoveFunc(int numeroFuncionario);
  void ShowLista();

  void ReadFile();
  void SaveFile();

  friend ostream& operator<<(ostream& out, const GestorFuncionarios& GestorTemp);
  friend istream& operator>>(istream& in, GestorFuncionarios& GestorTemp);  

};

#endif //GESTORFUNCIONARIOS_H