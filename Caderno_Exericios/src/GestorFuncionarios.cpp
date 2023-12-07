#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\GestorFuncionarios.h"
#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\operario.h"
#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\administrativo.h"



GestorFuncionarios::GestorFuncionarios() {

  if (!ListaFuncionarios.empty()) {
    ListaFuncionarios.clear();
  }
};
GestorFuncionarios::GestorFuncionarios(list<Funcionario*> _ListaFuncionarios) { 
  if (!ListaFuncionarios.empty()) {
    ListaFuncionarios.clear();
  } 
  ListaFuncionarios = _ListaFuncionarios;


};

void GestorFuncionarios::AddFuncionario(Funcionario* _funcionario)
{
	//para evitar duplicados
	for (Funcionario* f : ListaFuncionarios)	{
		if (f->GetNum() == _funcionario->GetNum()) //se for igual já existe
		{
			return;
		}
	}

	ListaFuncionarios.push_back(_funcionario);
}

void GestorFuncionarios::RemoveFunc(int numeroFuncionario) {
	cout << "Remover!" << endl;
  list<Funcionario*>::iterator iterator = ListaFuncionarios.begin();
  
  while(iterator != ListaFuncionarios.end()){
    if (numeroFuncionario == (*iterator)->GetNum()) {
      cout << "Eliminado Funcionario numero : " << numeroFuncionario;

      ListaFuncionarios.erase(iterator);
      break;
    }
		iterator++;
  }
	cout << "Nenhum funcionario.";
  return;
}

void GestorFuncionarios::ShowLista() {
	cout << "------------------------------- Lista de Funcionarios ------------------------------------" << endl;

  list<Funcionario*>::iterator iterator = ListaFuncionarios.begin();

  for(Funcionario* funcionario : ListaFuncionarios){
		if (Operario *op = dynamic_cast<Operario*>(funcionario))
		{
			op->Show();
		}
		else {
			funcionario->Show();
		}
		cout << endl << endl;
  }
	cout << "------------------------------------------------------------------------------------------" << endl;

}

void GestorFuncionarios::ReadFile() {
	ifstream ficheiro;
	ficheiro.open("C:/Users/ASUS/Documents/GitHub/Prog-Orientada-a-Objetos/Caderno_Exericios/src/Funcionarios.txt");
	if (!ficheiro.is_open())
	{
		return;
	}
  string linha;
  do {

    string tipoFuncionario = "";
    getline(ficheiro, tipoFuncionario, ':');

    if (tipoFuncionario == "O") {
      Operario *operario = new Operario();
      operario->ReadFileOperario(ficheiro);
      //this->AddFuncionario(operario);
      ListaFuncionarios.push_back(operario);

    } else if (tipoFuncionario == "A") {
      Administrativo *administrativo = new Administrativo();
      administrativo->ReadFileFuncionario(ficheiro);
      //this->AddFuncionario(administrativo);
      ListaFuncionarios.push_back(administrativo);  
    }

    ficheiro.ignore(INT16_MAX, '\n');
  } while (ficheiro.peek() != EOF);

	cout << ListaFuncionarios.size() << " funcionarios introduzidos no vetor"; 

	ficheiro.close();
}

void GestorFuncionarios::SaveFile() {
	ofstream ficheiro;
	ficheiro.open("C:/Users/ASUS/Documents/GitHub/Prog-Orientada-a-Objetos/Caderno_Exericios/src/Funcionarios.txt");
	if (!ficheiro.is_open())
	{
		return;
	}

  list<Funcionario*>::iterator iterator = ListaFuncionarios.begin();
  /*
  while(iterator != ListaFuncionarios.end()){
    if (Administrativo* admin = dynamic_cast<Administrativo*>(*iterator)) {
      ficheiro << "A:";
      admin->SaveFileFuncionario(ficheiro);
      ficheiro << endl;
      printf("Escrito Admin.");
      
    } else if (Operario* operario = dynamic_cast<Operario*>(*iterator)) {
      ficheiro << "O:";
      operario->SaveFileOperario(ficheiro);
      ficheiro << endl;
      printf("Escrito Operario.");
  }  
  }
  */
 
	for (Funcionario* f : ListaFuncionarios)
	{
		if (Operario* op = dynamic_cast<Operario*>(f))
		{
			ficheiro << "O:";
			op->SaveFileOperario(ficheiro);
		}

		if (Administrativo *adm = dynamic_cast<Administrativo*>(f))
		{
			ficheiro << "A:";
			adm->SaveFileFuncionario(ficheiro);
		}

		ficheiro << endl;
	}
  
}

ostream& operator<<(ostream& os, GestorFuncionarios& GestorTemp){
  GestorTemp.ShowLista();
  return os;
}
istream& operator>>(istream& is, GestorFuncionarios& GestorTemp){
	cout << "Deseja inserir:" << endl
		<< "O - Operário" << endl
		<< "A - Administrativo" << endl
		<< ">";
	string tipo;
	getline(is, tipo, '\n');

	if (tipo == "O")	{
		Operario *op = new Operario();
		op->ReadK();
		GestorTemp.AddFuncionario(op);
	}	else if(tipo == "A") {
		Administrativo *adm = new Administrativo();
		adm->ReadK();
		GestorTemp.AddFuncionario(adm);
	}

	is.ignore(INT16_MAX, '\n');//limpar o buffer

	cout << "Deseja Inserir Mais (S/N)" << endl;
	string op;
	getline(is, op, '\n');
	
	if (op == "S") {
		is >> GestorTemp; //voltamos a chamar o operador
	}
	return is;
}