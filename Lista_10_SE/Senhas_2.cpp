#include <iostream>
using namespace std;
#include "Lista_A10_E2.hpp"

void naoSeguras(No **lista){

    No *n= *lista;
    No *aux;

    inicializaL(&aux);
    while(n){
        if(n->dado.size()<4 || buscaL(lista,n->dado)>3 ){
                if(!buscaL(&aux,n->dado))
                insereInicioL(&aux,n->dado);
        }

        n= n->prox;
    }
     No *n2= *lista;
     while(n2){
            if(buscaL(&aux,n2->dado))
            removeL(lista,n2->dado);
         n2= n2->prox;
     }

    cout<<"Seguras:";
    mostraL(lista);
    cout<<"Não seguras:";
    mostraL(&aux);
}
int main(void)
{

    //ver o pq se usa nó na lista normal e Lista nas com descritores
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);

    insereInicioL(&lista, "sol");
    insereInicioL(&lista, "lua");
    insereInicioL(&lista, "luana");//ok
    insereInicioL(&lista, "solange");
    insereInicioL(&lista, "solange");
    insereInicioL(&lista, "camila");//ok
    insereInicioL(&lista, "solange");
    insereInicioL(&lista, "lua");
    insereInicioL(&lista, "solange");
    insereInicioL(&lista, "solange");

    naoSeguras(&lista);
}

