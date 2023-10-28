//Exercicio 4

#include <iostream>
#include <string>
//tokenization em c++

#include <sstream>
#include <vector>
#include <fstream>


#include "C:\Users\ASUS\Desktop\projetos\CPP\Exercicios\include\pessoa.h"
using namespace std;

//i)

void LerPessoaVetor(vector<Pessoa>& VetorPessoas){
    string ficheiro;
    cout << "Introduza o nome do ficheiro: ";
    cin >> ficheiro; 
    string nome_ficheiro = ficheiro + ".txt";

    ifstream ficheiroPessoa(nome_ficheiro);

    if (!ficheiroPessoa.is_open()) {
        cerr << "Erro ao abrir o ficheiro" << endl; //cerr usado para mostrar erros
        exit(1);
    }
    string linha_ficheiro;
    vector<string> pessoa_completa;
    while (getline(ficheiroPessoa, linha_ficheiro)) {

        istringstream iss(linha_ficheiro);
        
        string pessoa_string;
        while (getline(iss, pessoa_string, ';')) {
            //Cada parte da string irá ser inserida num vetor
            pessoa_completa.push_back(pessoa_string); 
        }
        
        //stoi -> string to integer conversor
        int dia_ficheiro = stoi(pessoa_completa[1]);
        int mes_ficheiro = stoi(pessoa_completa[2]);
        int ano_ficheiro = stoi(pessoa_completa[3]);
        //Escolhemos cada parte do vetor consoante o seu conteudo. [0] -> Nome, [4] -> Morada
        Data DataParaVetor(dia_ficheiro, mes_ficheiro, ano_ficheiro);
        Pessoa PessoaParaVetor(pessoa_completa[0], DataParaVetor, pessoa_completa[4]);

        VetorPessoas.push_back(PessoaParaVetor);
        pessoa_completa.clear();

    }
    ficheiroPessoa.close();

}

//m
void Nascimento1990(vector<Pessoa>& VetorPessoas){
    for (auto& pessoa : VetorPessoas) {
        if (pessoa.GetAno() < 1990) {
            pessoa.Show();
        }
    }
}

int Exercicio4(){
    //i)
    vector<Pessoa> pessoas;

    LerPessoaVetor(pessoas);   

    Nascimento1990(pessoas);

    //alinea b)
    Pessoa jonas("Jonas Culatra", {20, 9, 1987}, "Rua da direita n 2");

    Pessoa joni("Joni Rato", {4, 2, 1990}, "Rua da esquerda n 3");
 
    //alinea c)
    jonas.Show();

    //alinea d
    string morada_d;
    cout << "Introduza a nova morada do Joni Rato: " << endl;
    getline(cin, morada_d);
    joni.SetMorada(morada_d);

    //alinea e)

    /*
    int dia = 0; int mes = 0; int ano = 0;
    cout << "Insira o dia, mes e o ano separados por um Enter" << endl;
    cin >> dia; cin >> mes; cin >> ano;
    joni.SetDataN(dia, mes, ano);
    */

    joni.Show();
    //alinea f)
    Pessoa alineaF;

    alineaF.ReadK();
    cout << alineaF << endl;
    cout << "Show" << endl;
    alineaF.Show();
    
    //alinea g)
    Pessoa alineaG;
    cout << "Introduza uma Pessoa: " << endl;
    cin >> alineaG;
    cout << alineaG << endl;
    
    //alinea h)
    cout << "Jonas == Joni: " << ((jonas == joni) ? "true" : "false") << endl;  
    cout << "Jonas != Joni: " << ((jonas != joni) ? "true" : "false") << endl;  

    
    //i)
    jonas.MaisNovo(jonas, joni);

    //j)
    jonas.SaveFile();

    system("pause");    
    return 0;
}