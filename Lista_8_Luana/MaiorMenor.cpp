#include <iostream>
using namespace std;

#include "PFmaiorMenor.hpp"

int maior(Pilha *p)
{

    int maior=0;

    if(!vaziaP(p))
    {
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            if(maior<no->dado)
                maior=no->dado;

            no = no->prox;
        }

    }
    return maior;

}

int menor(Fila *f)
{

    int menor=10000000000;

    if(!vaziaF(f))
    {
        NoFila *no = f->inicio;
        while (no != NULL)
        {
            if(menor>no->dado)
                menor=no->dado;

            no = no->prox;
        }

    }
    return menor;

}

void ordenaF(Fila *f)
{

    int tam=0;
    Fila aux, aux2;
    while(!vaziaF(f))
    {
        NoFila *no = f->inicio;
        int menor = f->inicio->dado;
        while (no != NULL)
        {
            // mostraF(f);
            if(menor > no->dado)
            {
                menor=no->dado;
            }
            no = no->prox;
        }
        enfileiraF(&aux, menor);

        while(!vaziaF(f))
        {
            int x= desenfileiraF(f);
            if(x!=menor)
                enfileiraF(&aux2, x);
        }

        while(!vaziaF(&aux2))
        {
            int x= desenfileiraF(&aux2);
            enfileiraF(f, x);
        }

        tam++;
    }

    mostraF(&aux);

}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1;
    Fila f1;
    empilhaP(&p1,10);
    empilhaP(&p1,1);
    empilhaP(&p1,23);
    empilhaP(&p1,2);

    enfileiraF(&f1, 7);
    enfileiraF(&f1, 17);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 27);
     enfileiraF(&f1, 217);
    enfileiraF(&f1, 267);
    enfileiraF(&f1, 72);

    cout<<"Maior PILHA:"<<maior(&p1)<<endl;
    cout<<"Menor Fila:"<<menor(&f1)<<endl;
    cout<<"Ordenado:";
    ordenaF(&f1);












    return EXIT_SUCCESS;

}


