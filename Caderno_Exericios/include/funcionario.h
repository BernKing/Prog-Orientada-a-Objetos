#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\pessoa.h"

//Vai herdas tudo da class pessoa
//Herança Simples
//Funcionario é uma pessoa mais o setor num. 
class Funcionario : public Pessoa {
 public:
  //Construtores
  Funcionario();

  Funcionario(string v_nome, Data v_data, string v_morada, string v_setor, int v_num);
  
  void ShowFuncionario();

  inline string GetSetor() { return setor; }
  inline int GetNum() { return num; }

  inline void SetSetor(string v_setor) { setor = v_setor; }
  inline void SetNum(int v_num) { num = num;}

  friend istream& operator>>(istream& in, Funcionario& funcionario_temp);

  void SaveFileFuncionario();

  void ReadFileFuncionario();

 private:
  string setor;
  int num;  
};


#endif //FUNCIONARIO_H