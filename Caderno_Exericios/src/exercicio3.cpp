//Exercicio 3

#include "C:\Users\ASUS\Desktop\projetos\CPP\Exercicios\include\data.h"

#include <iostream>
#include <fstream>

int Exercicio3(){
    //e)
    Data data2;
    /*
    data2.GetDia();
    data2.GetMes();
    data2.GetAno();   
    */
    data2.SetDia(2); data2.SetMes(4); data2.SetAno(1997);   

    data2.Show();

    data2.GetDia();

    Data data1{28,12,2004};
    //data1.Update();
    data1.Show();
    
    // f)
    data1.Igual(data2);

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

