/*
Sobrecarga de Operadores-

Em c++ podemos mudar a maneira como os operadores funcionam para tipos definidos pelo utilizador como objetos e estruturas;

Por exemplo, imaginando que c1 e c2 e resultado são 3 objetos, poderiamos executar um simples 
resultado = c1 + c2; ao inves de algo como resultado = c1.Soma(c2);
Sendo Soma um metodo da classe onde o objeto está criada;

Syntax:
Para dar sobrecarregar(overloading/overload) um operador usamos uma função especial: "operator"
Definimosa  função dentro da classe cujos objetos/variaveis queremos que o operador sobrecarregado funcione


class nomeClasse {
    ... .. ...
    public
       tipoReturn operator simbolo (argumentos) {
           ... .. ...
       } 
    ... .. ...
};
tipoReturn é o tipo de retorno da func
operator é uma palavra chave e simbolo é o operador como "+", "<", "-" etc
argumentos são os argumentos passados para a função

*/

//Sobrecarga em operadores binários como + e -
#include <iostream>
using namespace std;

class Vetor
{
    private:
        int x, y;
    public:
        //Construtor parameterizado;
        Vetor(int valor_x, int valor_y) : x(valor_x), y(valor_y) {}
        //construtor não parameterizado
        Vetor(){};

        //Sobrecarga do operador "+"
        //ao usar "&" código mais eficiente ao usar referenciação do vetor 2 ao invês de fazer um objeto duplicado
        //usar const é uma boa prática para prevenir modificação do vetor 2;
        Vetor operator +(const Vetor& vetor_a_somar) const{
            return Vetor(x + vetor_a_somar.x, y + vetor_a_somar.y);
        }
        //Sobrecarga do operador "=="
        bool operator ==(const Vetor& vetor_a_comparar) const{
            if (x == vetor_a_comparar.x && y == vetor_a_comparar.y){
                return true;
            }
            else{
                return false;

            }
        }

    //friend permite as func acessar membros privados da classe
    friend ostream& operator <<(ostream& out, const Vetor& vetor_temp){
        out << "Vetor: " << vetor_temp.x << "," << vetor_temp.y << endl;
        return out;
    }
    friend istream& operator >>(istream& in, Vetor& vetor_temp){
        in >> vetor_temp.x;
        in >> vetor_temp.y;
        return in;
    }


        int getX() const { return x; }
        int getY() const { return y; }
};
int main() {
    //inicialização com {} preferida a ()

    Vetor v1{2, 3};
    Vetor v2{1, 4};
    Vetor v3{2, 3};

    Vetor resultado = v1 + v2; //chama a sobrecarga do operador + automaticamente sem se ter que especificar nada em concreto

    cout << "Resultado: (" << resultado.getX() << ", " << resultado.getY() << endl;

    //? operador condicional , se for true retorna o "true" se não o false
    cout << "v1 == v2: " << ((v1 == v2) ? "true" : "false") << endl;  
    cout << "v1 == v3: " << ((v1 == v3) ? "true" : "false") << endl;



    //sobrecarga operador << e >>

    Vetor vetor4;
    cout << "Introduza um vetor( dois numeros separados por um espaço):" << endl;
    cin >> vetor4;
    cout << vetor4 << endl;

    system("pause");
    return 0;
}



