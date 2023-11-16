#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h"
#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\operario.h"
#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\administrativo.h"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//6.5 a
void ReadFile (vector<Funcionario*> &VetorFuncionarios) {
	ifstream ficheiroFuncionarios;
	ficheiroFuncionarios.open("C:/Users/ASUS/Documents/GitHub/Prog-Orientada-a-Objetos/Caderno_Exericios/src/Funcionarios.txt");

	if (! ficheiroFuncionarios.is_open())	{
    cerr << "Erro ao abrir ficheiro" << endl;
		exit(1);
	}

  string linha;
  do {

    string tipoFuncionario = "\0";
    getline(ficheiroFuncionarios, tipoFuncionario, ':');

    if (tipoFuncionario == "O") {
      Operario *operario = new Operario();
      operario->ReadFileOperario(ficheiroFuncionarios);
      VetorFuncionarios.push_back(operario);

    } else if (tipoFuncionario == "A") {
      Administrativo *administrativo = new Administrativo();
      administrativo->ReadFileFuncionario(ficheiroFuncionarios);
      VetorFuncionarios.push_back(administrativo);  
    }

    ficheiroFuncionarios.ignore(INT16_MAX, '\n');
  } while (ficheiroFuncionarios.peek() != EOF);

	cout << VetorFuncionarios.size() << " funcionarios introduzidos no vetor"; 

	ficheiroFuncionarios.close();
}

//6.5b)
void CalcularOrdenado(vector<Funcionario*> &VetorFuncionarios) {
	cout << endl << endl << "-----    Lista de Funcionarios    -----" << endl;
  int i = 0;
  for (i = 0; i < VetorFuncionarios.size(); i++) {
    cout << VetorFuncionarios[i]->GetNum()  << "\t "
         << VetorFuncionarios[i]->GetNome() << "\t "
         << VetorFuncionarios[i]->Calcula_ordenado() << endl;
  }
  cout << "----    ----" << endl;
}

int main() {
  vector<Funcionario*> VetorFuncionarios;
  printf("MENU MENU MENU...");
  printf("Funcionar Organizacao\n\n");
  printf("1-LER FUNCIONARIOS DO FICHEIRO\n2-CALCULAR ORDENADOS\n");
  int opcao;
  while (true) {
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;
    switch (opcao) 
    {
    case 1:
      ReadFile(VetorFuncionarios);
      break;
    
    case 2:
      CalcularOrdenado(VetorFuncionarios);
      break;

    case 3:
      return 0;
    default:
      break;
    }

  }

  cout << "Sair do programa";
  getchar();
  return 0;
} 


