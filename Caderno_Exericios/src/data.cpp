#include <C:\Users\ASUS\Documents\GitHub\Prog-Orientada-a-Objetos\Caderno_Exericios\include\data.h>
#include <fstream>
#include <string>

using namespace std;

Data::Data(): dia {28}, mes{12}, ano{2004} {}

Data::Data(int dia_construtor, int mes_construtor, int ano_construtor)
  : dia(dia_construtor), mes(mes_construtor), ano(ano_construtor) {} 

void Data::Show(){
    cout << "Dia:" << dia << endl;
    cout << "Mes:" << mes << endl;
    cout << "Ano:" << ano << endl << endl;  

}
void Data::Update(){
    dia = 0;mes = 0;ano = 0;
    cout << "Insira o dia, mes e o ano separados por um Enter" << endl;
    cin >> dia;
    cin >> mes;
    cin >> ano;
}
bool Data::Igual(Data &data2){
    if (dia== data2.dia && mes == data2.mes && ano == data2.ano){
        cout << "Iguais" << endl;
        return true;
    }
    else{
        cout << "Diferentes" << endl;
        return false;
    }
}
void Data::SaveFile(ofstream &os){
	os << GetDia() << "/" << GetMes() << "/" << GetAno() << ";";
}

void Data::ReadFile(ifstream &is){
	char aux[10];

	is.getline(aux, 10, '/');
	dia = atoi(aux);
	is.getline(aux, 10, '/');
	mes = atoi(aux);
	is.getline(aux, 10, ';');
	ano = atoi(aux);
}

bool Data::operator ==(const Data& data_comparar) const{
    if (dia == data_comparar.dia && mes == data_comparar.mes && ano == data_comparar.ano){
        return true;
    }
    else{
        return false;

    }
}

bool Data::operator !=(const Data& data_comparar) const{
    if (dia != data_comparar.dia && mes != data_comparar.mes && ano != data_comparar.ano){
        return true;
    }
    else{
        return false;

    }
}

bool Data::operator <(const Data& data) const{
    int data_original = dia + mes + ano;
    int data_comparar = data.GetDia() + data.GetMes() + data.GetAno();

    if (data_original < data_comparar) {
        return true;
    } else {
        return false;
    }   
}


ostream& operator <<(ostream& out, const Data& data_temp){
  out << "Data: " << data_temp.dia << "/" << data_temp.mes << "/" << data_temp.ano << endl;
  return out;
}
istream& operator >>(istream& in, Data& data_temp){
  int v_dia, v_mes, v_ano;

  cout << "Dia: ";
  in >> v_dia;      
  data_temp.SetDia(v_dia);

  cout << "Mes: ";
  in >> v_mes;
  data_temp.SetMes(v_mes);

  cout << "Ano: ";
  in >> v_ano;
  data_temp.SetAno(v_ano);

  return in;
}

