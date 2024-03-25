#include <iostream>
#include <cstring>
using namespace std;

#include "pilha_D_L4_E2.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1;
    string texto, resultado;
    cout<<"Insira um texto:";
    getline(cin,texto);

    for(int i=0; i<texto.size(); i++)
    {
        if(!isspace(texto[i]) )
           {
               empilhaP(&p1,texto[i]);
           }
        if(isspace(texto[i])|| i==texto.size()-1)
        {
            while(!vaziaP(&p1))
            {
                cout<< desempilhaP(&p1);
            }
            cout<<" ";
        }


    }



//mostraP(&p1);






    return EXIT_SUCCESS;

}//final do main
