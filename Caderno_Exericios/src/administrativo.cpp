#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\administrativo.h"

Administrativo::Administrativo() {}

Administrativo::Administrativo(string v_nome, Data v_data, string v_morada, string v_setor, 
  int v_num, float v_ord_base, int v_h_extra, float v_p_hora_extra)
  : Funcionario(v_nome, v_data, v_morada, v_setor, v_num, v_ord_base, v_h_extra, v_p_hora_extra){}


double Administrativo::Calcula_ordenado() {
	
	return GetOrd_Base() + GetH_Extra() * GetP_Hora_Extra();
}