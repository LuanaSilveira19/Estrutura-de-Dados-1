#include <iostream>
using namespace std;

#include "pilha_D_L5_E3.hpp"

void remove_impar(Pilha *p)
{
    Pilha aux;
    int v=0;
    while(! vaziaP (p))
    {
        v=desempilhaP(p);
        if(v%2==0)
            empilhaP(&aux, v);

    }
    while(! vaziaP (&aux))
    {
        v=desempilhaP(&aux);
        empilhaP(p, v);

    }


    destroiP(&aux);
}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1;
    int valor;

    empilhaP(&p1, 4);
    empilhaP(&p1, 3);
    empilhaP(&p1, 8);
    empilhaP(&p1, 2);
    empilhaP(&p1, 1);
    empilhaP(&p1, 10);


    remove_impar(&p1);
    mostraP(&p1);

}
