#include <C:\Users\ASUS\Desktop\projetos\CPP\Exercicios\include\funcionario.h>

#include <iostream>
#include <string>

Funcionario::Funcionario() {};

Funcionario::Funcionario(string v_nome, Data v_data, string v_morada, string v_setor, int v_num) :
  Pessoa(v_nome, v_data, v_morada), setor ( v_setor ), num ( v_num ) {}; 

void Funcionario::ShowFuncionario() {
  Pessoa::Show();
  cout << "Setor: " << setor << endl;
  cout << "Num: " << num << endl;
}