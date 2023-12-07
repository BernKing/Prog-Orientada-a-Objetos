/*
Exercicio8
*/
#include <iostream>
#include <list>
#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\GestorFuncionarios.h"
#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\operario.h"
#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\administrativo.h"


#include <fstream>

using namespace std;

/*
  Operario(string v_nome, Data v_data, string v_morada, string v_setor, 
    int v_num, float v_ord_base, int v_h_extra, float v_p_hora_extra,
      bool v_f_turno);
*/


int main(void) {

  GestorFuncionarios GestorFunc;
  
  GestorFunc.ReadFile();
  
  Data dataZeca(1, 1, 1985);
  Operario *op = new Operario("Zeca Estacionâncio", dataZeca, "Rua A n9", "Pintura", 25050, 1100, 15, 8, "nao");
  GestorFunc.AddFuncionario(op);

  Data dataAdrusila(6, 6, 1996);
  Administrativo *adm = new Administrativo("Adrusila Lopes", dataAdrusila, "Rua E n6", "RecHumanos", 25051, 800, 0, 10);
  GestorFunc.AddFuncionario(adm);

  GestorFunc.ShowLista();

  GestorFunc.RemoveFunc(25050);

  GestorFunc.SaveFile();
  
  system("pause");
  return 0;
}