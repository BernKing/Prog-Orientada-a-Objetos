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

void PesquisarFuncionario(vector<Funcionario*> &VetorFuncionarios) {
  if (VetorFuncionarios.size() == 0) {
    cout << "Selecione a primeira opcao antes de pesquisar por um funcionario." << endl;
    return;
  }
  //c) Pesquisar um funcionário pelo seu número.
  int numeroFuncionario = 0;
  cout << "Introduza um numero de funcionario: ";
  cin >> numeroFuncionario;
  for (int i = 0; i < VetorFuncionarios.size(); i++) {
    if (numeroFuncionario == VetorFuncionarios[i]->GetNum()) {
      VetorFuncionarios[i]->ShowFuncionario();  
      return;    
    } else {
      continue;
    }
  }
  cout << "Nenhum Funcionario encontrado com o numero " << numeroFuncionario << endl;
}

void AlterarOrdenadoBase(vector <Funcionario*> &VetorFuncionarios) {
  if (VetorFuncionarios.size() == 0) {
    cout << "Selecione a primeira opcao antes de pesquisar por um funcionario." << endl;
    return;
  }
  //d) Alterar o ordenado base de um funcionário, identificado pelo seu número.
  int numeroFuncionario = 0;
  cout << "Introduza um numero de funcionario: ";
  cin >> numeroFuncionario;
  for (int i = 0; i < VetorFuncionarios.size(); i++) {
    if (numeroFuncionario == VetorFuncionarios[i]->GetNum() ) {
      float novoOrdenado = 0;
      cout << "Introduza um novo ordenado: ";
      cin >> novoOrdenado;

      VetorFuncionarios[i]->setOrd_Base(novoOrdenado);
      cout << "Ordenado do funcionario n" << numeroFuncionario << " mudado com sucesso para " << VetorFuncionarios[i]->GetOrd_Base();
      return;
    } else {
      continue;

    }
  }
  cout << "Nenhum Funcionario encontrado com o numero " << numeroFuncionario << endl;
}

//6.5 e)
void AdicionarOpAdmin(vector <Funcionario*> &VetorFuncionarios) {
  string tipoFuncionario;
  cout << endl;
  cout << "Que tipo de funcionario pretende inserir O ou A: ";
  cin >> tipoFuncionario;

  if (tipoFuncionario == "O") {
    Operario* operario = new Operario();
    operario->ReadOperario();
    VetorFuncionarios.push_back(operario);

  } else if (tipoFuncionario == "A") {
    Administrativo* administrativo = new Administrativo();
    administrativo->ReadFuncionario();
    VetorFuncionarios.push_back(administrativo);
  }
  cout << endl;
}
//f) Apresentar o nome dos operários que trabalham por turnos. 

void ApresentarNomeOperarios(vector <Funcionario*> &VetorFuncionarios){
  int i = 0;
  for (i = 0; i < VetorFuncionarios.size(); i++) {

    if (Operario* operario = dynamic_cast<Operario*>(VetorFuncionarios[i])) { //converter para operario, se n for possivel sera um admin
      if ( operario->GetTurno() == true) {
          cout << "\nNome: " << operario->GetNome();
      }
    }
  }
}


//g) Eliminar do vetor um funcionário, identificado pelo número

void EliminarFuncionario(vector <Funcionario*> &VetorFuncionarios) {
  int i = 0;
  int numeroFuncionario = 0;
  cout << endl << "Numero do funcionario a apagar: ";
  cin >> numeroFuncionario;

  for ( i = 0; i < VetorFuncionarios.size(); i++) {
    if (numeroFuncionario == VetorFuncionarios[i]->GetNum()) {
      cout << "Eliminado Funcionario numero : " << numeroFuncionario;
      VetorFuncionarios.erase (VetorFuncionarios.begin() + i);
    }
  }
}

//h) Guardar, num ficheiro “Administrativos.txt”, os dados dos Administrativos. 
//i) Guardar, num ficheiro “Operarios.txt”, os dados dos Operários. 


void GuardarFicheiroAdminOperario(vector <Funcionario*> &VetorFuncionarios, ofstream& fileAdmin, ofstream& fileOperario) {
  int i = 0;
  for (i = 0; i < VetorFuncionarios.size(); i++) {
    if (Administrativo* admin = dynamic_cast<Administrativo*>(VetorFuncionarios[i])) {
      admin->SaveFileFuncionario(fileAdmin);
      fileAdmin << endl;
      printf("Escrito Admin.");
    } else if (Operario* operario = dynamic_cast<Operario*>(VetorFuncionarios[i])) {
      operario->SaveFileOperario(fileOperario);
      fileOperario << endl;
      printf("Escrito Operario.");
    }
  }
}


int main() {
  vector<Funcionario*> VetorFuncionarios;
  printf("MENU MENU MENU...");
  printf("Funcionar Organizacao\n\n");
  printf("1-LER FUNCIONARIOS DO FICHEIRO\n2-CALCULAR ORDENADOS\n3-Pesquisar Funcionario(numero)\n4-Alterar Ordenado(numero func)\n");
  printf("5-Adicionar Operario ou Administrativo\n6-Nomes Operarios turnos\n7-Eliminar numero Funcionario\n8-Guardar Administrativos e Operarios em ficheiros proprios.\n");
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
      PesquisarFuncionario(VetorFuncionarios);
      break;

    case 4:
      AlterarOrdenadoBase(VetorFuncionarios);
      break;
    
    case 5:
      AdicionarOpAdmin(VetorFuncionarios);
      break;
    case 6:
      ApresentarNomeOperarios(VetorFuncionarios);
      break;
    case 7:
      EliminarFuncionario(VetorFuncionarios);
      break;

    case 8: {
      ofstream ficheiroOperario, ficheiroAdmin;
      ficheiroOperario.open("Operarios.txt");
      ficheiroAdmin.open("Administrativos.txt");


      GuardarFicheiroAdminOperario(VetorFuncionarios, ficheiroAdmin, ficheiroOperario);

      ficheiroOperario.close();
      ficheiroAdmin.close();
      break;
    }
    case 9:
      return 0;
    default:
      break;
    }

  }

  cout << "Sair do programa";
  getchar();
  return 0;
} 


