#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h"


class Administrativo : public Funcionario {
public:
  Administrativo();
  Administrativo(string v_nome, Data v_data, string v_morada, string v_setor, 
    int v_num, float v_ord_base, int v_h_extra, float v_p_hora_extra);

 private:

};
#endif //ADMINISTRATIVO_H