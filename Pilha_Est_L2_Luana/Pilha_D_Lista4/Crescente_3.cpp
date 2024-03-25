#include <iostream>
using namespace std;

#include "pilha_D_L4_E3.hpp"

void insereOrdenadoP(Pilha* p, int dado)
{
    Pilha aux;
    int x;

    while(!vaziaP(p) && p->topo->dado < dado)
    {
        x = desempilhaP(p);
        empilhaP(&aux, x);
    }
    empilhaP(p, dado);

     while(!vaziaP(&aux))
    {
        x = desempilhaP(&aux);
        empilhaP(p, x);
    }


}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha ORD;
    int valor, i=0;

   do
      {
         cout<<"Insira um valor(digite -1 pra parar): ";
         cin>>valor;
        if(valor>-1)
        // ordena(&ORD, valor);
        insereOrdenadoP(&ORD, valor);

      }while(valor>-1);

    mostraP(&ORD);

    return EXIT_SUCCESS;

}//final do main

