
#include <iostream>
using namespace std;

#include "Lista_A10_E7.hpp"


void interseccao(No **L1, No **L2){

   No *aux;
   No *n1=*L1;
   while(n1){

        if(buscaL(L2,n1->dado))
            if(!buscaL(&aux,n1->dado))
            insereInicioL(&aux,n1->dado);

        n1=n1->prox;
   }

   cout<<"Intersecção:";
   mostraL(&aux);


}
int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    No* lista;
    No* lista2;
    inicializaL(&lista);
    inicializaL(&lista2);

    insereInicioL(&lista, 46);
    insereInicioL(&lista,12);
    insereInicioL(&lista, 21);
    insereInicioL(&lista, 372);
    insereInicioL(&lista, 212);
    insereInicioL(&lista,83);




    insereInicioL(&lista2, 16);
    insereInicioL(&lista2,2);
    insereInicioL(&lista2, 87);
    insereInicioL(&lista2,372);
    insereInicioL(&lista2, 12);
    insereInicioL(&lista2, 46);
    insereInicioL(&lista2,372);

     cout<<"L1:";
     mostraL(&lista);
      cout<<"L2:";
     mostraL(&lista2);


    interseccao(&lista, &lista2);
}
