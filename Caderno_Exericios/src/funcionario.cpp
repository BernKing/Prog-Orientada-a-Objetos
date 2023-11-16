#include <C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h>

#include <iostream>
#include <string>
#include <fstream>

Funcionario::Funcionario() {};

Funcionario::Funcionario(string v_nome, Data v_data, string v_morada, string v_setor, 
    int v_num, float v_ord_base, int v_h_extra, float v_p_hora_extra) : 
    Pessoa(v_nome, v_data, v_morada), setor ( v_setor ), num ( v_num ), 
     ord_base ( v_ord_base ), h_extra ( v_h_extra ), p_hora_extra ( v_p_hora_extra ) {}; 

void Funcionario::ShowFuncionario() {
  Pessoa::Show();
  cout << "Setor: " << setor << endl;
  cout << "Num: " << num << endl;
}

istream& operator>>(istream& in, Funcionario& funcionario_temp) {
  // Chama o >> sobrecarregado de Pessoa, static_cast converte de forma segura a pessoa para funcioario
  //in >> (Pessoa&)funcionario_temp;
  in >> static_cast<Pessoa&>(funcionario_temp);

  // Read data specific to Funcionario
  cout << "Setor: ";
  in >> funcionario_temp.setor;

  cout << "Numero: ";
  in >> funcionario_temp.num;
  return in; 
}

void Funcionario::ReadFuncionario() {
  Pessoa::ReadK();
	cout << "Setor:";
	getline(cin, setor);

  cout << "Num:";
	cin >> num;

	//extra 
	cout << "Ord Base:";
	cin >> ord_base;

	cout << "Horas Extras";
	cin >> h_extra;
}


void Funcionario::SaveFileFuncionario(ofstream &of) {
	Pessoa::SaveFilePessoa(of);
	of << num << ";" << setor <<  ";"<< ord_base << ";" << h_extra << ";";
}

void Funcionario::ReadFileFuncionario(ifstream &is) {
	char aux[100];

	Pessoa::ReadFilePessoa(is);
  is.getline(aux, 100, ';');
	num = atoi(aux);
	is.getline(aux, 100, ';');
	setor = aux;
  
	float ord; 
	is >> ord;
	ord_base = ord;  //corrigir erro
	is.ignore(INT16_MAX, ';');

	int h;
	is >> h;
	h_extra = h;
	is.ignore(INT16_MAX, ';');
}


