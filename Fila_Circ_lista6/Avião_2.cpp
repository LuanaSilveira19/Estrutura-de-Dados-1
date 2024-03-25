#include <iostream>
#include <cstring>
using namespace std;

struct Aviao
{

    int codigo;
    int passageiros;
    string empresa;

    Aviao()
    {
        codigo=0;
        passageiros=0;
        empresa=" ";
    }

    Aviao( int c, int p, string e)
    {

        codigo=c;
        passageiros=p;
        empresa=e;

    }

};

#include "fila_L6_E2.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Fila f1;
    int qtdA=10;
    int op=-1, cont=0;
    inicializaF(&f1, qtdA);
    do
    {
        system("cls");
        cout << "-------------------------Aeroporto-----------------------" << endl;
        cout << "------- 0 Sair.                                     -----" << endl;
        cout << "------- 1 Entrada de um novo avião                  -----" << endl;
        cout << "------- 2 Descolagem de um avião                    -----" << endl;
        cout << "------- 3 Lista de aviões para decolar              -----" << endl;
        cout << "------- 4 Lista de caracteristicas do proximo avião -----" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Sua escolha: ";
        cin >> op;
        fflush(stdin);
       if(op==0)
       {    system("cls");
            cout << "Programa finalizado!";
            getchar();
            break;
       }
       else if(op==1)
        {
            system("cls");
            Aviao A;
            cout<<"Informe o código do avião:";
            cin>>A.codigo;
            cout<<"Informe a quantidade dos passageiros do avião:";
            cin>>A.passageiros;
            cout<<"Informe o nome da empresa do avião:";
            cin>>A.empresa;
            cout<<endl;
            if(!cheiaF(&f1))
            {
                enfileiraF(&f1, A);
                cout<<"O avião "<<A.codigo<<" da compania "<< A.empresa <<" está pronto para decolar."<<endl;
            }
            else
            cout<<"O Fila cheia."<<endl;

            system("pause");
        }
        else if(op==2)
        {
            system("cls");

            Aviao X= desenfileiraF(&f1);
            cout<<"O avião "<<X.codigo<<" da compania "<< X.empresa <<" decolou."<<endl;
            system("pause");

        }

        else if(op==3)
        {
            system("cls");
            mostraF(&f1);
            system("pause");

        }

        else if(op==4)
        {
            system("cls");
              Aviao Y= espiaF(&f1);
           cout<<"O avião "<<Y.codigo<<" da compania "<< Y.empresa <<" será o proximo a decolar."<<endl;
            system("pause");

        }



    }
    while (op != 0);



}
