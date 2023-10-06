#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data{
    private:
        int dia;
        int mes;
        int ano;
    public:
        
        void SetDia(int dia_temp) { dia = dia_temp;};
        void SetMes(int mes_temp) { mes = mes_temp;};
        void SetAno(int ano_temp) { ano = ano_temp;};

        /*  
         const
         -Qualificador que indica que o metodo não modifica o estado do objeto;
         -Melhora a segurança e leitura do código;
         -Evita modificações acidentais;              
        */
        int GetDia() const{ return dia; };
        int GetMes() const{ return mes; };
        int GetAno() const{ return ano; };


        void Show();
        void Update();

        //f)
        bool Igual(Data &data1, Data &data2);

        //sobrecarga de operador g)
        bool operator ==(const Data& data_comparar) const;

        //sobrecarga de operadores h)

        bool operator !=(const Data& data_comparar) const;

        //friend permite a func acessar membros privados da classe
        friend ostream& operator<<(ostream& os, const Data& data_temp);
        //não pode ser constante pois o intuito é mudar os valores da Data
        friend istream& operator>>(istream& in, Data& data_temp);

        //alinea k)
        void escrever_ficheiro();

        void leitura_ficheiro();

        //construtores
        Data(): dia {28}, mes{12}, ano{2004} {}
        //b)
        Data(int dia_construtor, int mes_construtor, int ano_construtor)
            : dia(dia_construtor), mes(mes_construtor), ano(ano_construtor) {}    
};
#endif