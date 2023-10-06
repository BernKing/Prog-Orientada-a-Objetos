/*

Composição de Objetos ( object composition )

Na vida real objetos complexos são compostor por objetos mais pequenos e mais simples. Por exemplo um carro é composto pelo chasis, motor, transmissão etc...
O processo de construir objetos complexos através de outros mais pequenos é chamado de object composition (composição de objetos)

O objeto complexo normalmente é chamado de parent (pai) e o mais simples de child (filho)

Object composition é importante em c++ pois permite-nos criar objetos mais complexos através de outros mais simples.
Isto reduz a complexidade, e permite-nos escrever código mais rapidamente e com menos erros pois podemos re usar código que já foi escrito, estado e implementado.

Há dois tipos de object composition ->
    - Object Composition
    - Object Aggregation


Exemplo:
    -Muitos jogos têm criaturas ou objetos que estão posicionados num mapa. Uma coisa que todos estes obejtos têm em comum é o facto de terem uma localização.
    -Neste exemplo iremos criar a classe criatura que usa a classe ponto para guardar a sua localizaçãoo
    -A nossa criatura vive num mundo 2D então o nosso ponto possui apenas 2 dimensões


Deveria definir as classes em ficheiros .h mas para o exemplo não o farei
*/

#include <iostream>
#include <string>
using namespace std;



class Ponto2D
{
private:
    int x;
    int y;
public:
    //Construtor 
    Ponto2D() : x {0}, y {0} {}
    //Construtor Parameterizado
    Ponto2D(int x, int y) : x {x}, y {y}{}
    //Sobrecarga de operador >>
    friend ostream& operator<<(ostream& out, const Ponto2D& ponto_temp){
        out << '(' << ponto_temp.x << ", " << ponto_temp.y << ')';
        return out;
    }
    //Metodos de acesso
    void setPonto (int x_temp, int y_temp){
        x = x_temp;
        y = y_temp;
    }
};

class Criatura
{
    private:
        string nome;
        Ponto2D localizacao;

    public:
        //construtor parameterizado
        Criatura(string nome_temp, const Ponto2D& localizacao_temp) :
            nome { nome_temp }, localizacao { localizacao_temp } {}

        friend ostream& operator<<(ostream& out, const Criatura& criatura_temp){

            out << criatura_temp.nome << " esta no ponto" << criatura_temp.localizacao;
            return out;    
        }

        void moverPara(int x, int y){
            localizacao.setPonto(x, y);
        }
};

int main(){
    string nome;
    cout << "Introduza o nome da criatura: ";
    cin >> nome;
    Criatura criatura{ nome, {4, 7}};

    while(true){
        int x { 0 };
        cout << criatura << endl;
        cout << "Nova localizacaoo de X (-1 para sair): ";
        cin >> x;
        if (x == -1)
            break;

        int y { 0 };
        cout << criatura << endl;
        cout << "Nova localizacao de Y (-1 para sair): ";
        cin >> y;
        if (y == -1)
            break;
        
        criatura.moverPara(x, y);
    }

    return 0;

}






