#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

#include "pilha_D_L5_E2.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1;
    string op;
    int X;

    ifstream ler("entrada.txt", ios::in);
    if(!ler.is_open())
    {
        cout << "Erro: nao foi possivel ler o arquivo\n";
        return 0;
    }

    while(!ler.eof())
    {
        //le a operacao
        if (!(ler >> op))
            break;

        //cout << op << endl;

        if(op=="MOSTRAR")
        {
            if(vaziaP(&p1))
                cout<<"PILHA VAZIA"<<endl;
            else
                mostraP(&p1);
        }
        else if(op=="REMOVER")
        {
            if(vaziaP(&p1))
                cout<<"PILHA VAZIA"<<endl;
            else
            {
                X = desempilhaP(&p1);
                cout << "O elemento "<< X <<" foi removido da pilha\n";
            }
        }
        else if(op=="CONSULTAR")
        {
            ler >> X;
            if(buscaP(&p1, X))
                cout<<"O valor "<<X<<" está armazenado na pilha."<<endl;
            else
                cout<<"O valor "<<X<<" não está armazenado na pilha."<<endl;
        }
        else if(op=="INSERIR")
        {
            ler >> X;
            empilhaP(&p1,X );
            cout<<"O valor "<<X<<" foi inserido na pilha."<<endl;

        }
         else if(op=="REMOVERTODOS")
        {
           while(!vaziaP(&p1))
           {
               desempilhaP(&p1);
           }
            cout<<"Todos os elementos removidos."<<endl;

        }
        else{
            //operação desconhecida, não faz nada (assumimos que o arquivo texto está correto)
        }

    }//fim while

    ler.close();
}

