#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h"

#include <iostream>
#include <fstream>
#include <string>

void ReadFile(void) {
  ifstream ficheiroFuncionario("Funcionario.txt");
  if (!ficheiroFuncionario.is_open()) {
    cerr << "Erro ao abrir o Ficheiro" << endl;
    exit(1);
  }
  string linha_ficheiro;
  while (getline(ficheiroFuncionario, linha_ficheiro)) {

  }
  ficheiroFuncionario.close();

}

int main() {

  return 0;
} 


