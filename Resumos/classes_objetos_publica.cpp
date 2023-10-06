
/*  Classe é um modelo para o objeto.
    Ela define a estrutura e o comportamento dos objetos que serão criados a partir dele. 
    Uma classe encapsula dados (atributos ou variáveis ​​de membro) e métodos (funções) que operam nesses dados.
    Podemos pensar em uma classe como um esboço (protótipo) de uma casa. 
    Contém todos os detalhes sobre pisos, portas, janelas, etc. 
    Com base nessas descrições construímos a casa. A casa é o objeto.

    Um objeto é uma instância de uma classe. 
    É uma entidade concreta criada com base no modelo fornecido por uma classe

*/
#include <iostream>
using namespace std;

class NomeDaClasse{
    // data
    //funções
};

class Sala {
    //public signica que membros podem ser acessadas em qualquer lado do programa
    public: //especifica a visibilidade dos membros



    //data members
    double comprimento;
    double largura;
    double altura;

    //member functions ou metodos
    double calcularArea(){
        return comprimento * largura;

    }
    double calcularVolume(){
        return comprimento * largura * altura;
    }

};
//quando uma classe é definidade, só as especificações para os objetos
//são definidas, não é alocada memória 
//Para usar a data e os metodos definidos nelas temos de criar objetos
//objetos podem ser criados em qualquer lugar do programa, até dentro da própria classe ou de outras  classes
//podemos também criar um numero infinito de objetos vindos apenas de uma unica classe
// vvvv syntax para definir objetos vvvv


int main(){
    Sala sala1;
    //podemos acessar data ou metodos atraves do ".":
    
    sala1.comprimento = 5.5; //acessar data, neste caso inicializa a variavel comprimento com 5.5
    sala1.altura = 5.2;
    sala1.largura = 7.9;
    
    //calcular area dentro da classe Sala para o objeto sala1
    cout << "Area da Sala = " << sala1.calcularArea() << endl;
    cout << "Volume da Sala =  " << sala1.calcularVolume() << endl;

    system("pause");
    return 0;
}
