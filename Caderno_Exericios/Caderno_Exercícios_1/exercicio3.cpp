//Exercicio 3

#include <iostream>
#include "C:\Users\ASUS\Desktop\projetos\helloworld\exercicio3.h"
#include <fstream>
using namespace std;

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
bool Data::Igual(Data &data1, Data &data2){
    if (data1.dia == data2.dia && data1.mes == data2.mes && data1.ano == data2.ano){
        cout << "Iguais" << endl;
        return true;
    }
    else{
        cout << "Diferentes" << endl;
        return false;
    }
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
ostream& operator <<(ostream& out, const Data& data_temp){
    out << "Data: " << data_temp.dia << "/" << data_temp.mes << "/" << data_temp.ano << endl;
    return out;
}
istream& operator >>(istream& in, Data& data_temp){
    in >> data_temp.dia;
    in >> data_temp.mes;
    in >> data_temp.ano;

    return in;
}

void Data::escrever_ficheiro(){
    ofstream ficheiroData("Datas.txt");
    if (!ficheiroData.is_open()){
        cerr << "Erro ao abrir o ficheiro" << endl; //cerr usado para mostrar erros
    }
    ficheiroData << "Data: " << dia << "/" << mes << "/" << ano << endl;

    ficheiroData.close();
}

void Data::leitura_ficheiro(){
    ifstream ficheiroData("Datas.txt");
    if (!ficheiroData.is_open()){
        cerr << "Erro ao abrir o ficheiro" << endl; //cerr usado para mostrar erros
        exit(1);
    }
    string linha_ficheiro;

    while (getline(ficheiroData, linha_ficheiro)) {
        cout << linha_ficheiro << endl;
    }
    ficheiroData.close();
}

int main(){
    //e)
    Data data2;
    /*
    data2.GetDia();
    data2.GetMes();
    data2.GetAno();   
    */
    data2.SetDia(2); data2.SetMes(4); data2.SetAno(1997);   

    data2.Show();

    Data data1{28,12,2004};
    //data1.Update();
    data1.Show();
    
    // f)
    data1.Igual(data1,data2);

    //sobrecarga operador ==  g)
    cout << "Data1 == Data2: " << ((data1 == data2) ? "true" : "false") << endl;  
    //sobrecarga operador !=  e)
    cout << "Data1 != Data2: " << ((data1 != data2) ? "true" : "false") << endl;  

    //sobrecarga operador << e >> alinea e) i) na leitura

    Data data3;
    cout << "Introduza uma Data:" << endl;
    cin >> data3;
    cout << data3 << endl;

    //alinea j
    cout << data1 << endl;
    cout << data2<< endl;
    cout << data3 << endl;

    //alinea k)
    data3.escrever_ficheiro();
    data3.leitura_ficheiro();
    


    system("pause");
    return 0;
}

