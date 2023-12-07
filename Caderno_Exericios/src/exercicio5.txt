#include "C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\funcionario.h"

#include <iostream>
#include <vector>
#include <fstream>

void LerParaVetor(vector<Funcionario>& vetor_funcionarios) {
  string ficheiro;
  cout << "Introduza o nome do ficheiro: ";
  cin >> ficheiro; 
  string nome_ficheiro = ficheiro + ".txt";

  ifstream ficheiroFuncionario(nome_ficheiro);

  if (!ficheiroFuncionario.is_open()) {
    cerr << "Erro ao abrir o ficheiro" << endl; //cerr usado para mostrar erros
    exit(1);
  }
  string linha_ficheiro;
  vector<string> funcionario_completo;
  while (getline(ficheiroFuncionario, linha_ficheiro)) {

    istringstream iss(linha_ficheiro);
        
    string pessoa_string;
    while (getline(iss, pessoa_string, ';')) {
      //Cada parte da string irá ser inserida num vetor
      funcionario_completo.push_back(pessoa_string); 
    }
        
        //stoi -> string to integer conversor
    int dia_ficheiro = stoi(funcionario_completo[1]);
    int mes_ficheiro = stoi(funcionario_completo[2]);
    int ano_ficheiro = stoi(funcionario_completo[3]);
      //Escolhemos cada parte do vetor consoante o seu conteudo. [0] -> Nome, [4] -> Morada
    Data DataParaVetor(dia_ficheiro, mes_ficheiro, ano_ficheiro);

    int num = stoi(funcionario_completo[6]);
    Funcionario FuncionarioParaVetor(funcionario_completo[0], DataParaVetor, funcionario_completo[4], funcionario_completo[5], num);

    vetor_funcionarios.push_back(FuncionarioParaVetor);
    funcionario_completo.clear();

  }
  ficheiroFuncionario.close(); 
}

void OrdenarDataNascimento(vector<Funcionario> vetor_funcionarios) {
  int vetor_size = size(vetor_funcionarios);
  for ( int i = 0; i < vetor_size ; i++) {
    for (int j = i +1; j < vetor_size; j++) {
      Data data_j = vetor_funcionarios[j].getDataN();
      Data data_i = vetor_funcionarios[i].getDataN();

      if (data_j < data_i) {
        swap(data_j, data_i);
      }
      
    }
  }
}
/*
int main() {

  Funcionario BernardoAlmeida;
  Data Data_VascoMaisCedo;
  Funcionario VascoMaisCedo("Vasco", Data_VascoMaisCedo, "Rua do Vasco", "LEI", 78798);

  VascoMaisCedo.ShowFuncionario();

  VascoMaisCedo.SetMorada("Rua do meio n 4");
  VascoMaisCedo.SetSetor("Ferragem");

  Data data_temp;
  //Alinea 5.7
  data_temp = BernardoAlmeida.getDataN();
  data_temp.SetDia(23);
  BernardoAlmeida.SetDataN(data_temp);

  //Alinea 5.8
  Funcionario Inacio;
  cin >> Inacio;
  Inacio.ShowFuncionario();

  vector<Funcionario> vetor_funcionarios;

  Funcionario c, d;

  ofstream ficheiro;
	string ficheiroTxt = "funcionarios.txt";
	ficheiro.open(ficheiroTxt);
	if (ficheiro)
	{
		c.SaveFileFuncionario(ficheiro);
		d.SaveFileFuncionario(ficheiro);
		ficheiro.close();
		cout << "Ficheiro " << ficheiroTxt << " criado com sucesso!" << endl;
	}	else {
		cout << "ERRO a Abrir ficheiro " << ficheiroTxt << '\n';
  }

  ifstream ifficheiro;
	Funcionario vector[4];

	ifficheiro.open(ficheiroTxt);
	if (ficheiro)	{

		int contador=0;
		while (ifficheiro.peek() != EOF){
			vector[contador].ReadFileFuncionario(ifficheiro);
			contador++;
		}

		ifficheiro.close();
		cout << "Ficheiro " << ficheiroTxt << " lido com sucesso!" << endl;
	}
	else
		cout << "ERRO: n�o � poss�vel abrir o ficheiro " << ficheiroTxt << '\n';


  system("pause");
  return 0;
}
*/
