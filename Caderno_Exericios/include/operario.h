#ifndef OPERARIO_H
#define OPERARIO_H  

#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h"


class Operario : public Funcionario {
public:
  Operario();
  Operario(string v_nome, Data v_data, string v_morada, string v_setor, 
    int v_num, float v_ord_base, int v_h_extra, float v_p_hora_extra,
      bool v_f_turno);

  double Calcula_ordenado() override;

  inline bool GetTurno() { return f_turno; }
  inline bool SetTurno(bool v_f_turno) { f_turno = v_f_turno; }

 private:
  bool f_turno;


};
#endif //OPERARIO_H
