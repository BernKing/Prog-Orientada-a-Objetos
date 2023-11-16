#include <C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h>

#include <iostream>
#include <string>
#include <fstream>

Funcionario::Funcionario() {};

Funcionario::Funcionario(string v_nome, Data v_data, string v_morada, string v_setor, int v_num) :
  Pessoa(v_nome, v_data, v_morada), setor ( v_setor ), num ( v_num ) {}; 

void Funcionario::ShowFuncionario() {
  Pessoa::Show();
  cout << "Setor: " << setor << endl;
  cout << "Num: " << num << endl;
}

istream& operator>>(istream& in, Funcionario& funcionario_temp) {
  // Chama o >> sobrecarregado de Pessoa, static_cast converte de forma segura a pessoa para funcioario
  in >> static_cast<Pessoa&>(funcionario_temp);

  // Read data specific to Funcionario
  cout << "Setor: ";
  in >> funcionario_temp.setor;

  cout << "Numero: ";
  in >> funcionario_temp.num;
  return in; 
}

void Funcionario::SaveFileFuncionario(ofstream &of) {
	Pessoa::SaveFilePessoa(of);
	of << num << ";" << setor << "\n";
}

void Funcionario::ReadFileFuncionario(ifstream &is) {
	char aux[100];

	Pessoa::ReadFilePessoa(is);
	is.getline(aux, 100, ';');
	num = atoi(aux);
	is.getline(aux, 100, '\n');
	setor = aux;
}
