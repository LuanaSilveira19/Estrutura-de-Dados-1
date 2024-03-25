#include <iostream>
using namespace std;

#include "Lista_A9_E1.hpp"

bool inserePosicao(No **lista, int valor, int pos)
{

    No *atual= *lista;
    No *anterior=NULL;
    No *novo = new No();
    int cont=0;

    novo->dado=valor;
    if(pos>totalElementos(lista) || pos<0)
        return false;
    else
    {
        while(cont!= pos)
        {
            anterior=atual;
            atual=atual->prox;
            cont++;
        }
        if(anterior==NULL){
             novo->prox= *lista;
            *lista= novo;
        }
        else{
            novo->prox = anterior->prox;
            anterior->prox= novo;
        }

    }

return true;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor;
    No* aux;
    No* lista;
    No* lista2;
    No* lista3;

    inicializaL(&lista);


    insereInicioL(&lista, 13);
    insereInicioL(&lista, 81);
    insereInicioL(&lista, 49);
    insereInicioL(&lista, 21);
    cout<<"Lista 1: ";
    mostraL(&lista);

    cout<<"Total de elementos:"<<totalElementos(&lista)<<endl;

    inicializaL(&lista2);


    inserenoFinalL(&lista2, 1123);
    inserenoFinalL(&lista2, 2211);
    inserenoFinalL(&lista2, 3229);
    inserenoFinalL(&lista2, 4211);

    cout<<"Lista 2: ";
    mostraL(&lista2);


    if(igualdadeL(&lista,&lista2))
        cout<<"Listas iguais"<<endl;
    else
        cout<<"Listas diferentes"<<endl;

    cout<<"Insere posição 4, valor 350:"<<endl;
    inserePosicao(&lista,350,4);

      mostraL(&lista);
    cout<<"Elemento final da lista 2: "<<leFinalL(&lista2)<<endl;
    cout<<"Elemento final da lista 1: "<<leFinalL(&lista)<<endl;
    cout<<endl;

    cout<<"Remove fim da lista 1: "<<removeFinalL(&lista)<<endl;
    cout<<"Lista 1: ";
    mostraL(&lista);

    cout<<"Le a posição 1 da lista 2: "<<lePosicao(&lista2,1)<<endl;
    inicializaL(&lista3);
    uniaoListas(&lista,&lista2,&lista3);


}
