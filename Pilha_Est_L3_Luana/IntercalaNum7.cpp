#include <iostream>
using namespace std;

#include "pilha_L3_E7.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1, p2, p3;

    int cont=0, i=0;

    inicializaP(&p1,10);
    inicializaP(&p2,10);
    inicializaP(&p3,20);

    empilhaP(&p1,5);
    empilhaP(&p1,4);
    empilhaP(&p1,3);
    empilhaP(&p1,2);
    empilhaP(&p1,1);
    empilhaP(&p1,0);

    empilhaP(&p2,50);
    empilhaP(&p2,40);
    empilhaP(&p2,30);
    empilhaP(&p2,20);

    while(!vaziaP(&p1)&& !vaziaP(&p2))//enquanto as 2 tiverem elementos
    {
        empilhaP(&p3,desempilhaP(&p1));
        empilhaP(&p3,desempilhaP(&p2));
    }
    while(!vaziaP(&p1))//se ainda tiver elementos aqui empilha
    {
        empilhaP(&p3,desempilhaP(&p1));
    }
     while(!vaziaP(&p2))
    {
        empilhaP(&p3,desempilhaP(&p2));
    }


    mostraP(&p3);

}
