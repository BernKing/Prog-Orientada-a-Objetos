#include <C:\Users\ASUS\Desktop\projetos\CPP\Exercicios\include\funcionario.h>

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

void Funcionario::SaveFileFuncionario() {
  Pessoa::SaveFilePessoa();
  
  string ficheiro;
  cout << "Introduza o nome do ficheiro: " << endl;
  cin >> ficheiro;

  string nome_ficheiro = ficheiro + ".txt";

  ofstream ficheiroFuncionario(nome_ficheiro, std::ios::app);
  if (!ficheiroFuncionario.is_open()) {
    cerr << "Erro ao abrir ficheiro" << endl;  
    exit(1);
  }
  ficheiroFuncionario << setor << ";" << num << endl; 

  ficheiroFuncionario.close();
}

void Funcionario::ReadFileFuncionario() {
  string ficheiro;
  cout << "Introduza o nome do ficheiro: " << endl;
  cin >> ficheiro;

  string nome_ficheiro = ficheiro + ".txt";

  ifstream ficheiroFuncionario(nome_ficheiro);
  if (!ficheiroFuncionario.is_open()) {
    cerr << "Erro ao abrir o ficheiro" << endl; //cerr usado para mostrar erros
    exit(1);
  }
  string linha_ficheiro;

  while (getline(ficheiroFuncionario, linha_ficheiro)) {
    cout << linha_ficheiro << endl;
  }
  ficheiroFuncionario.close();

}