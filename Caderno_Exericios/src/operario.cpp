#include "C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\operario.h"

using namespace std;

Operario::Operario() {
	SetP_Hora_Extra(8);

};

Operario::Operario(string v_nome, Data v_data, string v_morada, string v_setor, 
  int v_num, float v_ord_base, int v_h_extra, float v_p_hora_extra, bool v_f_turno)
  : Funcionario(v_nome, v_data, v_morada, v_setor, v_num, v_ord_base, v_h_extra, 8), f_turno(v_f_turno) {};


double Operario::Calcula_ordenado() {
	if (f_turno) {
		return GetH_Extra() * GetP_Hora_Extra() + GetOrd_Base() + GetOrd_Base()* 25;
	} else {
		return GetH_Extra() * GetP_Hora_Extra() + GetOrd_Base();
	}
}
void Operario::SaveFileOperario(ofstream &ficheiroFuncionarios) {
	Funcionario::SaveFileFuncionario(ficheiroFuncionarios);

	if (f_turno){
		ficheiroFuncionarios << "sim;";
	} else{
		ficheiroFuncionarios << "não;";
	}
}

void Operario::ReadFileOperario(ifstream &ficheiroFuncionarios) {
	Funcionario::ReadFileFuncionario(ficheiroFuncionarios);
	string turno;
	
	getline(ficheiroFuncionarios, turno, ';');

	if (turno == "sim")	{
		f_turno = true;			 
	}	else	{
		f_turno = false;
	}


}
