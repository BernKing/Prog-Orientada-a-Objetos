/*Um construtor é um tipo especial de metodo que é chamado
logo que um objeto é criado
*/
#include <iostream>
using namespace std;

class Parede{
    public:
    //cria um construtor sem paramatetros
    Parede(){
        //código ou não
    };

};

//Aqui Parede() é um construtor da classe Parede
/* O construtor:
    - Tem o mesmo nome da classe;
    - Não tem o tipo de função;
    - é pública;
*/

/* CONSTRUTOR Padrão
   Um construtor sem parametros é considerado um construtor padrão

   No exemplo acima, o Parede() é um construtor Padrão

   Exemplo:
*/ 

class Muro {
    private:
        double comprimento;

    public:
        /*
        Muro(){
            comprimento = 5.5;
            cout << "A criar um muro." << endl;
            cout << "Comprimento = " << comprimento << endl;
        }
        Metodo abaixo recomendado para inicializar variaveis em construtores.
        */
        Muro() : comprimento(5.5){
            cout << "A criar um muro." << endl;
            cout << "Comprimento = " << comprimento << endl;
        }
};

/*
    Construtor Parameterizado
*/

class Circulo{
    private:
        double raio;

    public:
        //Construtor Parameterizado para iniciar variaveis
        /*
        Circulo(double raio){
            raio = raio;
        }
        */
       //forma recomendada de inicialização de construtores
        Circulo(double raio) : raio(raio){};

        double calcularArea(){
            return 3.14 * raio * raio;
        }
};



int main(){
    Muro muro1;

    Circulo circulo1{4};
    cout << "Area do Circulo 1 : " <<circulo1.calcularArea() << endl;

    return 0;
}
