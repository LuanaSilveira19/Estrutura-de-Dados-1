#include <iostream>
#include<cstring>
using namespace std;

#include "pilha_L2_E8.hpp"
//não consegui armazenar dados do tipo char

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    string texto, copia;

    cout<<"Insira uma palavra para verificar se é um palindromo:";
    getline(cin, texto);

    inicializaP(&p1,texto.size());
    for(int i=0; i<texto.size(); i++)
    {
        empilhaP(&p1, texto);
    }
    // mostraP(&p1);
    for(int i=0; i<texto.size(); i++)
    {
        copia+=desempilhaP(&p1);
    }
    if(copia==texto)
        cout<<"Essa palavra É um palindromo!"<<endl;
    else
        cout<<"Essa palavra NÃO É um palindromo!"<<endl;



}
