

#include <iostream>
using namespace std;

class Sala {

   private: //dados privados so podem ser acessados apartir do interior da propria classe
    double comprimento;
    double largura;
    double altura;

   public: //podem ser acessadas apartir de qualquer lado

    // função para inicializar variaveis
    void inicializarData(double comp, double larg, double alt) 
    {
        comprimento = comp;
        largura = larg;
        altura = alt;
    }

    double calcularArea() {
        return comprimento * comprimento;
    }

    double calcularVolume() {
        return comprimento * largura * altura;
    }
};

int main() {

    // cria objeto sala1 da classe Sala
    Sala sala1;

    //acessar diretamente variaveis impossivel pois são dadas como privadas
    // passar variaveis privadas como argumento para função
    sala1.inicializarData(42.5, 30.8, 19.2);

    cout << "Area da Sala =  " << sala1.calcularArea() << endl;
    cout << "Volume da Sala =  " << sala1.calcularVolume() << endl;

    return 0;
}