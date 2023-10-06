#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;
int main(){
    cout<<"ENSAIO do setw() .............. " <<endl;
    cout<< setw(10) <<11<< endl;  //tamanho minimo de caracteres do output
    cout<< setw(10) <<2222<< endl;
    cout<< setw(10) <<4<< endl;
    cout<< setfill('-')<< setw(10) <<11<< endl; //preenche espaços nos caracteres vazios


    cout<<"Precisao global ....................... " << endl;
    cout<<"5 digitos, parte inteira e decimal "<< setprecision(5) <<1234.537<< endl;
    cout<<"6 digitos parte inteira e decimal "<<setprecision(6)<<1234.537<<endl<< endl;
    cout<<"Precisao da parte decimal ....................... " << endl;
    cout.setf(ios::floatfield,ios::fixed);
    cout<< "2 digitos na parte decimal "<< setprecision(2)<<1234.537<< endl;
    cout<< "5 digitos na parte decimal "<< setprecision(5)<<1234.537<< endl;

    system("pause");
    return 0;
}