#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\pessoa.h"

//Vai herdas tudo da class pessoa
//Herança Simples
//Funcionario é uma pessoa mais o setor num. 

/*
  Funcionario é uma classe abstrata com um metodo virtual que sera programado nas classes que herdarem dela;
  https://en.cppreference.com/w/cpp/language/abstract_class
Abstract classes are used to represent general concepts (for example, Shape, Animal), which can be used as base classes for concrete classes (for example, Circle, Dog).
No objects of an abstract class can be created (except for base subobjects of a class derived from it) and no non-static data members whose type is an abstract class can be declared.
*/

class Funcionario : public Pessoa {
 public:
  //Construtores
  Funcionario();

  Funcionario(string v_nome, Data v_data, string v_morada, string v_setor, int v_num, 
    float v_ord_base, int v_h_extra, float v_p_hora_extra);
  
  void ShowFuncionario();

  inline string GetSetor() { return setor; }
  inline int GetNum() { return num; }

  inline float GetOrd_Base() { return ord_base; }
  inline int GetH_Extra() { return h_extra; }
  inline float GetP_Hora_Extra() { return p_hora_extra; }

  inline void SetSetor(string v_setor) { setor = v_setor; }
  inline void SetNum(int v_num) { num = num;}

  inline void setOrd_Base(float v_ord_base) { ord_base = v_ord_base; }
  inline void SetH_Extra(int v_h_extra) { h_extra = v_h_extra; }
  inline void SetP_Hora_Extra(float v_p_hora_extra) { p_hora_extra = v_p_hora_extra; }

  friend istream& operator>>(istream& in, Funcionario& funcionario_temp);

  void SaveFileFuncionario(ofstream &of);

  void ReadFileFuncionario(ifstream &is);

  void ReadFuncionario();

  virtual double Calcula_ordenado() = 0;

 private:
  string setor;
  int num;  

  float ord_base;
  int h_extra;
  float p_hora_extra;
};


#endif //FUNCIONARIO_H