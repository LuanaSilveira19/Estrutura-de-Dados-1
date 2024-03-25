#include <iostream>
#include <cstring>
using namespace std;

#include "fila_L6_E3.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Pilha p1;
    string texto, P, F;
    cout<<"Insir uma palavra para para verificar se ela é um palindromo:";
    getline(cin,texto);

    inicializaF(&f1, texto.size());
    inicializaP(&p1, texto.size());
    enfileiraF(&f1, texto);

    for(int i=0; i<texto.size(); i++)
    {
        empilhaP(&p1,texto);
    }
    // mostraF(&f1);
    //mostraP(&p1);
    for(int i=0; i<texto.size(); i++)
    {
        F+=desenfileiraF(&f1);
        P+=desempilhaP(&p1);
    }

    if(P==F)
        cout<<"Essa palavra É um palindromo!"<<endl;
    else
        cout<<"Essa palavra NÃO É um palindromo!"<<endl;


}
