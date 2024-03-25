#include <iostream>
using namespace std;

#include "Lista_A10_E4.hpp"

void ordenarL(No** lista)
{
    if(!vaziaL(lista))
    {
        for(No *i= *lista; i->prox !=NULL; i= i->prox)
        {
            No *menor= i;
            for(No *j= i->prox; j!=NULL; j= j->prox)
            {
                if(j->dado< menor->dado)
                    menor=j;
            }
            int aux= i->dado;
            i->dado= menor->dado;
            menor->dado= aux;
        }
    }
    else
    {
        cout<<"Lista vazia!"<<endl;
    }

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    No* lista;

    inicializaL(&lista);


    insereInicioL(&lista, 10);
    insereInicioL(&lista, 270);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 420);
    insereInicioL(&lista, 45);
    insereInicioL(&lista, 82);

    cout<<"Antes: ";
    mostraL(&lista);

    ordenarL(&lista);
    cout<<"Depois: ";
    mostraL(&lista);

}
