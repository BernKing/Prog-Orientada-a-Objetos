#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h"

#include <iostream>

int Exercicio5() {

  Funcionario BernardoAlmeida;
  Data Data_VascoMaisCedo;
  Funcionario VascoMaisCedo("Vasco", Data_VascoMaisCedo, "Rua do Vasco", "LEI", 78798);

  VascoMaisCedo.ShowFuncionario();

  VascoMaisCedo.SetMorada("Rua do meio n 4");
  VascoMaisCedo.SetSetor("Ferragem");

  Data data_temp;
  //Alinea 5.6
  data_temp = BernardoAlmeida.getDataN();
  data_temp.SetDia(23);
  BernardoAlmeida.SetDataN(data_temp);
  system("pause");
  return 0;
}

