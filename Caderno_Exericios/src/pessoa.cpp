#include <C:\Users\ASUS\Documents\GitHub\Prog.-Orientada-a-Objetos\Caderno_Exericios\include\pessoa.h>

#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Pessoa::Show(){
    cout << "Nome: " << nome << endl;
    cout << "Data: " << dataP.GetDia() << "/" << dataP.GetMes() << "/" << dataP.GetAno() << endl;
    cout << "Morada: " << morada << endl;
}

void Pessoa::ReadK(){
    string nome;
    cout << "Introduza o nome da pessoa:" << endl;
    getline(cin, nome);
    SetNome(nome);

    string data;
    cout << "Introduza a data de nascimento da pessoa (dia/mes/ano): " << endl;
    getline(cin, data);

    istringstream iss(data);
    vector<int> data_completa;
    string data_string;
    while (getline(iss, data_string, '/')) {
        //stoi -> string to integer conversor
        int data_inteiro = stoi(data_string);
        data_completa.push_back(data_inteiro); //insere novos int no final do vetor
    }
    
    Data data_temp = Data(data_completa[0], data_completa[1], data_completa[2]);
    SetDataN(data_temp);

    string morada;
    cout << "Introduza a morada da pessoa: " << endl;
    getline(cin, morada);
    SetMorada(morada);
}

ostream& operator<<(ostream& out, const Pessoa& pessoa_temp){
    out << "Nome: " << pessoa_temp.nome << endl;
    out << "Data: " << pessoa_temp.dataP.GetDia() << "/" << pessoa_temp.dataP.GetMes() << "/" << pessoa_temp.dataP.GetAno() << endl;
    out << "Morada: " << pessoa_temp.morada << endl;
    return out;
};

istream& operator>>(istream& in, Pessoa& pessoa_temp){
    cout << "Nome: ";
    in >> pessoa_temp.nome;
    cout << "Data (separada por espaços): ";
    in >> pessoa_temp.dataP;
    cout << "Morada: ";
    in >> pessoa_temp.morada;
    return in;
}

bool Pessoa::operator==(const Pessoa& pessoa_comparar) const {
    if ( nome == pessoa_comparar.nome && dataP == pessoa_comparar.dataP) { 

        return true; 
    } else {

        return false; 
    }
}

bool Pessoa::operator!=(const Pessoa& pessoa_comparar) const {
    if ( nome != pessoa_comparar.nome && dataP != pessoa_comparar.dataP) { 

        return true; 
    } else { 

        return false;   
    }
}

void Pessoa::MaisNovo(const Pessoa& pessoa1, const Pessoa& pessoa2) {
        int pessoa1_data = pessoa1.dataP.GetDia() + pessoa1.dataP.GetMes() + pessoa1.dataP.GetAno(); 
        int pessoa2_data = pessoa2.dataP.GetDia() + pessoa2.dataP.GetMes() + pessoa2.dataP.GetAno(); 

        if (pessoa1_data < pessoa2_data) {
            
            cout << "Pessoa mais nova:" << endl;
            cout << pessoa1;
        } else if (pessoa2_data < pessoa1_data) {
            
            cout << "Pessoa mais nova:" << endl;
            cout << pessoa2;
        } else {

            cout << "Mesma Idade." << endl;
        }    
}

void Pessoa::SaveFilePessoa(ofstream &os){
os << nome << ";" << morada << ";"  << dataP << ";";
}

void Pessoa::ReadFilePessoa(ifstream &is){
	char aux[100];

	is.getline(aux, 100, ';');
	nome = aux;
	is.getline(aux, 100, ';');
	morada = aux;

  dataP.ReadFile(is);
}