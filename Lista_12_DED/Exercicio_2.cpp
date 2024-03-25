#include <iostream>
using namespace std;
#include "Lista_Dupla_E2.hpp"

void removeTodos(Lista *L,int valor)
{
    if (L->inicio != NULL)
    {
        No *no = L->inicio, *aux = no->prox, *anterior = NULL;
        while (aux != NULL)
        {
            if (no == L->inicio)
            {
                if (no->dado == valor)
                {
                    L->inicio = aux;
                    free(no);
                    L->tamanho--;
                    no = L->inicio;
                    aux = aux->prox;
                }
                else
                {
                    anterior = no;
                    no = no->prox;
                    aux = aux->prox;
                }
            }
            else
            {
                if (no->dado == valor)
                {
                    anterior->prox = aux;
                    free(no);
                    L->tamanho--;
                    no = aux;
                    aux = aux->prox;
                }
                else
                {
                    anterior = no;
                    no = no->prox;
                    aux = aux->prox;
                }
            }
        }
        //condição para o último nó
        if (no->dado == valor)
        {
            if (L->tamanho > 1)
            {
                anterior->prox = NULL;
                L->tamanho--;
                free(no);
            }
            else
            {
                free(no);
                L->tamanho--;
                L->inicio = NULL;
            }
        }
    }
}

void Ordena(Lista *L)
{

    /* No *n=L->inicio;
     cout<<"L->inicio: "<<L->inicio<<endl;
     cout<<"L->fim: "<<L->fim<<endl;
     cout<<"n->prox: "<<n->prox<<endl;
     cout<<"n->dado: "<<n->dado<<endl;
     n=n->prox;
     cout<<"n=n->prox"<<endl;
     cout<<"n->prox: "<<n->prox<<endl;
     cout<<"n->dado: "<<n->dado<<endl;
     cout<<"n->ant: "<<n->ant<<endl;
     cout<<"n->ant->prox: "<<n->ant->prox<<endl;*/
    No *n = L->inicio;
    if(!vaziaL(L))
    {
        for(No *i= n; i->prox !=NULL; i= i->prox)
        {
            No *maior= i;
            for(No *j= i->prox; j!=NULL; j= j->prox)
            {
                if(j->dado>maior->dado)
                    maior=j;
            }
            int aux= i->dado;
            i->dado= maior->dado;
            maior->dado= aux;
        }
    }
    else
    {
        cout<<"Lista vazia!"<<endl;
    }

    //mostraL(L);
}

Lista leMaiores(Lista *L, int K)
{

    Lista valor;
    No  * no  = L->inicio;
    while(K>0)
    {
        insereFimL(&valor, no->dado);

        no=no->prox;
        K--;
    }


    return valor;
}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Lista lista = Lista();

    insereInicioL(&lista,1);
    insereInicioL(&lista,2);
    insereInicioL(&lista,10);
    insereInicioL(&lista,20);
    insereInicioL(&lista,10);
    insereInicioL(&lista,7);
    insereInicioL(&lista,10);

    mostraL(&lista);


    cout<<"Nova lista elemento 10 removido: ";
    removeTodos(&lista,10);
    mostraL(&lista);
    cout<<endl;
    cout<<"Lista ordenada: ";
    Ordena(&lista);
    mostraL(&lista);

    cout<<"Retorna os maiores elementos da lista: "<<leMaiores(&lista, 2)<<endl;

}
