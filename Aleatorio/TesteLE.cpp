#include <iostream>
using namespace std;

#include "Teste.hpp"
void paresEimpares(No **lista)
{

    No *atual=*lista;
    No *aux;
    while(atual)
    {
        if(atual->dado%2==0)
        {
            inserenoFinalL(&aux,atual->dado);
            removeL(lista,atual->dado);
        }

        atual=atual->prox;
    }

    cout<<"Impares:";
    mostraL(lista);
    cout<<"Pares:";
    mostraL(&aux);
}
int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    No* lista;
    No* lista2;
    inicializaL(&lista);
    inicializaL(&lista2);

    insereInicioL(&lista, 60);
    insereInicioL(&lista,11);
    insereInicioL(&lista, 16);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 21);
    insereInicioL(&lista,10);

    mostraL(&lista);
    paresEimpares(&lista);

}
