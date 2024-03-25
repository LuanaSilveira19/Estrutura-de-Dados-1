#include <iostream>
using namespace std;

#include "Lista_A10_E5.hpp"


void insereOrdenado(No **lista, int valor)
{
     No *anterior = NULL;
     No *atual = *lista;
     No *novo = new No();

  novo->dado=valor;
  while(atual!=NULL && atual->dado >= valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL)
    {
        novo->prox=*lista;
        *lista=novo;

    }
    else
    {
        //mandar mostrar o que vai dentro dos ponteiros para não se perder
        //ir mostrando dentro dos ifs
        novo->prox = anterior->prox;
        anterior->prox= novo;

    }

}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    No* lista;
    int a;
    inicializaL(&lista);



    insereOrdenado(&lista,4);
    insereOrdenado(&lista,0);
    insereOrdenado(&lista,5);
    insereOrdenado(&lista,2);
    insereOrdenado(&lista,1);


   mostraL(&lista);


}
