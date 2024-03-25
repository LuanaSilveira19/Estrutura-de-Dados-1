#include <iostream>
using namespace std;


#include "Lista_A9_E2.hpp"
void inverte(No **lista)
{
    No *aux;
    No *n = *lista;

    inicializaL(&aux);
    while(!vaziaL(&n))
    {
        insereFinalL(&aux,removeFinalL(&n));
    }
    cout<<"Invertida:";
    mostraL(&aux);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    string ler;
    No* L1;

    inicializaL(&L1);

   /* cout<<"Insira uuma sequência de letras:";
    getline(cin, ler);
    for(int i=0; i<ler.size(); i++)
    {
        insereInicioL(&L1,ler); //fazer inserir letra por letra
    }*/

    insereInicioL(&L1,"U");
    insereInicioL(&L1,"O");
    insereInicioL(&L1,"I");
    insereInicioL(&L1,"E");
    insereInicioL(&L1,"A");
    cout<<"Lista original:";
    mostraL(&L1);

   inverte(&L1);


}
