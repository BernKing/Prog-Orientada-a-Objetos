#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data{

 public:
        
  inline void SetDia(int dia_temp) { dia = dia_temp;};
  inline void SetMes(int mes_temp) { mes = mes_temp;};
  inline void SetAno(int ano_temp) { ano = ano_temp;};

  inline int GetDia() const{ return dia; };
  inline int GetMes() const{ return mes; };
  inline int GetAno() const{ return ano; };


  void Show();
  void Update();

  bool Igual(Data &data2);

  bool operator==(const Data& data_comparar) const;
  bool operator!=(const Data& data_comparar) const;

  bool operator<(const Data& data_comparar) const;
        

  //friend permite a func acessar membros privados da classe
  friend ostream& operator<<(ostream& out, const Data& data_temp);

  friend istream& operator >>(istream& in, Data& data_temp);

  void SaveFile(ofstream &os);

  void ReadFile(ifstream &is);

  //construtores
  Data();
  Data(int dia_construtor, int mes_construtor, int ano_construtor); 

 private:
  int dia;
  int mes;
  int ano;
};
#endif