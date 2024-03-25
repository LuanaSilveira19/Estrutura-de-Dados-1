#include <iostream>
#include<cstring>
#include <cctype>

using namespace std;

#include "pilha_L3_E1.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1, p2;
    string texto;

    cout<<"Insira um texto:";
    getline(cin, texto);

    inicializaP(&p1,texto.size());
    inicializaP(&p2,texto.size());

    for(int i=0; i<texto.size(); i++)
    {
        if(isalpha(texto[i]))
            empilhaP(&p1, texto[i]);
        if(isdigit(texto[i]))
            empilhaP(&p2, texto[i]);
    }

    cout<<"Pilha das letras: "<<endl;
    mostraP(&p1);
    cout<<"Pilha dos numeros: "<<endl;
    mostraP(&p2);
    cout<<endl;

    cout<<"P1 desempilhada: ";
    for(int i=0; i<texto.size(); i++)
    {
        cout<<desempilhaP(&p1);
    }
      cout<<endl;
     cout<<"P2 desempilhada: ";
    for(int i=0; i<texto.size(); i++)
    {
        cout<<desempilhaP(&p2);
    }
      cout<<endl;


}
