#include <iostream>
#include <cstring>
using namespace std;

#include "pilha_L2_E7.hpp"//arquivo de cabe�alho


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
     Pilha p1;
    string texto, valor;

    cout<<"Insira uma palavra para verificar se � um palindromo:";
    getline(cin, texto);

    inicializaP(&p1,texto.size());
    for(int i=0; i<texto.size(); i++)
    {
        empilhaP(&p1, texto);
    }
     mostraP(&p1);

    if(vaziaP(&p1) == false)
    {

        cout << "A letra no topo da pilha �: " << espiaP(&p1) << endl;
    }
    else
        cout << "N�o foi possivel consultar letra no topo da pilha, a pilha est� vazia!\n";

}
