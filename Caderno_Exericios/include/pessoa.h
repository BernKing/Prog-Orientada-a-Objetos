#ifndef PESSOA_H
#define PESSOA_H

#include <C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\data.h>

#include <iostream>
#include <string>
#include <sstream>

class Pessoa {

 public:
  //Construtores
  Pessoa() : 
    nome {"Bernardo"}, dataP {28, 12, 2004}, morada {"Rua 2, Casa 1"} {}

  Pessoa(string nome_construtor, const Data& data_construtor, string morada_construtor) :
    nome {nome_construtor}, dataP {data_construtor}, morada {morada_construtor} {}

  //Metodos de acesso
  inline void SetNome(string nome_temp) { nome = nome_temp; };
  inline void SetDataN(Data data_temp) { dataP = data_temp; };
  inline void SetMorada(string morada_temp) { morada = morada_temp; };
  inline string GetNome() const{ return nome; };
  inline Data getDataN()  const{ return dataP; };

  inline string GetMorada() const{ return morada; };

  inline int GetAno() const {
    return dataP.GetAno();
  }

  //c) 
  void Show();

  //f)
  void ReadK();

  //g) sobrecarga de << e >>

  friend ostream& operator<<(ostream& out, const Pessoa& pessoa_temp);
  friend istream& operator>>(istream& in, Pessoa& pessoa_temp);

  //h= sobrecarga de == e !=
  bool operator==(const Pessoa& pessoa_comparar) const;
  bool operator!=(const Pessoa& pessoa_comparar) const;

  //i)
  void MaisNovo(const Pessoa& pessoa1, const Pessoa& pessoa2);

  //j)
  void SaveFilePessoa(ofstream &os);

  //k) e i)
  void ReadFilePessoa(ifstream &is);

 private:
  string nome;
  Data dataP;
  string morada;
};






#endif //PESSOA_H