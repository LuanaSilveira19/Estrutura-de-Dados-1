#include <iostream>
using namespace std;

#include "Lista_A10_E1.hpp"
/*void inverteXelementos(No **lista, int valor){

    //No *n=*lista;
    No *aux;
    int cont=0;
    while(cont!=valor){
            inserenoFinalL(lista,removeInicioL(lista));
            cont++;
    }
    cout<<"Lista invertida:";
    mostraL(lista);
 }*/

 void inverteXelementos(No **lista, int valor){
    No *aux;
    No *n=*lista;
    int cont=0;
    while(n){
        inserenoFinalL(&aux,n->dado);
        n=n->prox;
    }
    while(cont!=valor){
            inserenoFinalL(&aux,removeInicioL(&aux));
            cont++;
    }

    cout<<"Lista originalF:";
    mostraL(lista);


    cout<<"Lista invertida:";
    mostraL(&aux);
 }


int main(void)
{
 setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 7);
    insereInicioL(&lista, 11);
    insereInicioL(&lista, 12);
    insereInicioL(&lista, 9);
    insereInicioL(&lista, 8);
    insereInicioL(&lista, 5);
    insereInicioL(&lista, 3);
    cout<<"Lista original:";
    mostraL(&lista);
    inverteXelementos(&lista,4);//da pra ser sem/com aux

}

