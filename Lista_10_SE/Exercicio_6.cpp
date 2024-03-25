#include <iostream>
using namespace std;

#include "Lista_A10_E6.hpp"
/* No *novo = new No();
   No *atual = new No();
 No *anterior = NULL;

  int cont=0;
    if (novo == NULL)
        return false;
     novo->dado= valor;
     if(*lista==NULL)
     {
         novo->prox=NULL;
         *lista=novo;
     }
     else{
        atual= *lista;
        while(cont!=pos)
        {
            anterior = atual;
           atual = atual->prox;
            cont++;
        }

     }*/
bool inserePosicao(No** lista, int pos, int valor){

     No *anterior = NULL;
     No *atual = *lista;
     No *novo = new No();

    int cont=0;

novo->dado=valor;
  while(cont!=pos)
    {
        anterior = atual;
        atual = atual->prox;
        cont++;
        if(atual->prox==NULL && pos>cont || pos<0)
            return false;
    }
    if (anterior == NULL)
    {
        novo->prox=*lista;
        *lista=novo;

    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox= novo;

    }

 return true;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 6);
    insereInicioL(&lista, 7);
    insereInicioL(&lista, 8);
    insereInicioL(&lista, 9);
    insereInicioL(&lista, 9);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 5);
    insereInicioL(&lista, 2);

    inserePosicao(&lista, 0, 100);
    inserePosicao(&lista, 3, 200);
    inserePosicao(&lista, 11, 300);
    inserePosicao(&lista, 13, 1000);
    inserePosicao(&lista, -1, 1000);
    mostraL(&lista);
}
