/*pautas para notas de alunos
Adicioanr alunos
Nome Idade Número -> Guardar em estrutura
Depois guardar em ficheiro todos os dados separados por ,
Poder apagar ou gerir alunos
*/
#include <iostream> 
#include <vector> // criar vetores
#include <fstream> //poder mexer com ficheiros
using namespace std;


struct Aluno{
    char nome[50];
    int idade;
    int numero;
};

void alunos_ficheiro(int n_alunos, Aluno *alunos);

void adicionar_aluno(int n_alunos, Aluno *alunos){
    
    for(int i {0}; i < n_alunos; i++){
        cout << "Introduza o nome do aluno:" << endl;
        cin >> alunos[i].nome;

        cout << "Introduza a idade do aluno:" << endl;
        cin >> alunos[i].idade;

        cout << "Introduza o numero do aluno:" << endl;
        cin >> alunos[i].numero;

        cout << "/Novo Aluno/" << endl;
 
    }

    alunos_ficheiro(n_alunos, alunos);
}

void alunos_ficheiro(int n_alunos, Aluno *alunos){
    ofstream Lista_Alunos("lista_alunos.txt");
    if (!Lista_Alunos.is_open()){
        cerr << "Erro ao abrir o ficheiro" << endl; //cerr usado para mostrar erros
    }

    for (int i {0}; i < n_alunos; i++)
    {
        Lista_Alunos << alunos[i].nome <<";"<<alunos[i].idade <<";"<<alunos[i].numero << endl;
    }
    
    Lista_Alunos.close();
}




void mostrar_alunos(void){
    ifstream Lista_Alunos("lista_alunos.txt");
    if( !Lista_Alunos ){
        cout << "ERRO: não é possível abrir o ficheiro lista_alunos.txt" << '\n';
        exit(1);
    }
    string linha;
    while (getline(Lista_Alunos, linha)) {
        cout << linha << endl;
    }
    Lista_Alunos.close();

}


void inserir_alunos(){
    int n_alunos {0};

    do{
        cout << "Quantos alunos pretende inserir?:";
        cin >> n_alunos;

        if (n_alunos < 0) {
            cout << "Introduza um numero > 0.\n";
        }

    }while(n_alunos < 0);
    Aluno alunos[n_alunos];
    adicionar_aluno(n_alunos, alunos);   
}

int menu(){
    int op {0};

    do {
        cout << "1-Inserir Alunos.\n";
        cout << "2-Vizualizar Alunos.\n";

        cout << "Escolha (1, 2, or 3): ";
        cin >> op;

        if (op < 1 || op > 3) {
            cout << "Escolha Inválida" << endl;
        }
    } while (op < 1 || op > 3);

    return op;
}

int main(){
    int op {0};
    op = menu();
    switch (op)
        
    {
    case 1:
        inserir_alunos();

    case 2:
        mostrar_alunos();     
    }

    system("pause");
    return 0;
}   