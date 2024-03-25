#include <iostream>
using namespace std;

#include "Lista_A9_E3.hpp"

/*void imprime_rec (No **lista)//mostra a lista de forma recursiva
{
    if (vaziaL(lista))
         return;

    cout<<(*lista)->dado<<",";

   *lista = (*lista)->prox;
    imprime_rec(lista);
}*/

void imprime_rec (No **lista)
{
    if (vaziaL(lista))
         return;
    cout<< removeFinalL(lista)<<",";

   //*lista = (*lista)->prox;

    imprime_rec(lista);

}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);

    insereInicioL(&lista, 100);
    insereInicioL(&lista, 200);
    insereInicioL(&lista, 300);
    insereInicioL(&lista, 400);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 40);


    cout<<"Lista original:";
    mostraL(&lista);
    cout<<"Lista invertida:{";
    imprime_rec(&lista);
    cout<<"}\n";
}
