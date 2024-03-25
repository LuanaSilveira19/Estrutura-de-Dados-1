#include <iostream>
using namespace std;

#include "pilha_D_L4_E5.hpp"

void copia(Pilha *p1, Pilha *p2)
{
    Pilha aux;
    int x;

    for(int i=0; i<3; i++)
    {
        empilhaP(&aux,desempilhaP(p1));
    }
    for(int i=0; i<3; i++)
    {
        x=desempilhaP(&aux);
        empilhaP(p1,x);
        empilhaP(p2,x);
    }
    destroiP(&aux);

    cout << "PILHA P1: " << endl;
    mostraP(p1);
    cout<<endl;
    cout << "PILHA P2: " << endl;
    mostraP(p2);

}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1, p2;
    empilhaP(&p1, 2);
    empilhaP(&p1, 3);
    empilhaP(&p1, 4);


    copia(&p1,&p2);

    destroiP(&p1);
    destroiP(&p2);

}

