#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h"
#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\operario.h"
#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\administrativo.h"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//6.5
void ReadFile (vector<Funcionario*> &VetorFuncionarios) {
	ifstream ficheiroFuncionarios;
	ficheiroFuncionarios.open("Funcionarios.txt");

	if (! ficheiroFuncionarios.is_open())	{
    cerr << "Erro ao abrir ficheiro" << endl;
		exit(1);
	}

  string linha;
  while (getline(ficheiroFuncionarios, linha)) {

    string tipoFuncionario = "\0";
    getline(ficheiroFuncionarios, tipoFuncionario, ':');

    if (tipoFuncionario == "O") {
      Operario *operario = new Operario();
      operario->ReadFileOperario(ficheiroFuncionarios);
      VetorFuncionarios.push_back(operario);

    } else if (tipoFuncionario == "A") {
      Administrativo *administrativo = new Administrativo();
      administrativo->ReadFileFuncionario(ficheiroFuncionarios);
      VetorFuncionarios.push_back(administrativo);  }
  
  } //ou do { } while (ficheiroFuncionarios.peek() != EOF);

	cout << VetorFuncionarios.size() << " funcionarios introduzidos no vetor"; 

	ficheiroFuncionarios.close();
}


int main() {
  vector<Funcionario*> VetorFuncionarios;

  int opcao;
  while (true) {
    cout << "Escolha uma opção: " << endl;
    cin >> opcao;
    switch (opcao) 
    {
    case 1:
      ReadFile(VetorFuncionarios);
      break;
    
    default:
      break;
    }

  }

  
  return 0;
} 


