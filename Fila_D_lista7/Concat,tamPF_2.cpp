#include <iostream>
using namespace std;

#include "filaD_L7_E2.hpp"

void concatenaF(Fila *f1, Fila *f2)
{

    Fila concat;
    Fila aux;

    int valor;
    while(!vaziaF(f1))
    {
        valor=desenfileiraF(f1);
        enfileiraF(&concat,valor);
        enfileiraF(&aux,valor);
    }
    while(!vaziaF(&aux))
    {
        enfileiraF(f1,desenfileiraF(&aux));
    }
    while(!vaziaF(f2))
    {
        valor=desenfileiraF(f2);
        enfileiraF(&concat,valor);
        enfileiraF(&aux,valor);
    }
    while(!vaziaF(&aux))
    {
        enfileiraF(f2,desenfileiraF(&aux));
    }
    mostraF(&concat);

}
void insereOrdenadoP(Pilha* p, int dado)
{
    Pilha aux;
    int x;

    while(!vaziaP(p) && p->topo->dado > dado)
    {
        x = desempilhaP(p);
        empilhaP(&aux, x);
    }
    empilhaP(p, dado);

     while(!vaziaP(&aux))
    {
        x = desempilhaP(&aux);
        empilhaP(p, x);
    }


}
void concatenaP(Pilha *p1, Pilha *p2)
{

    Pilha concat;
    Pilha aux;

    int valor;
    while(!vaziaP(p1))
    {
        valor=desempilhaP(p1);
        insereOrdenadoP(&concat,valor);
        empilhaP(&aux,valor);
    }
    while(!vaziaP(&aux))
    {
        empilhaP(p1,desempilhaP(&aux));
    }
    while(!vaziaP(p2))
    {
        valor=desempilhaP(p2);
        insereOrdenadoP(&concat,valor);
        empilhaP(&aux,valor);
    }
    while(!vaziaP(&aux))
    {
       empilhaP(p2,desempilhaP(&aux));
    }

    mostraP(&concat);

}

int tamanho(Fila *f){
    int cont=0;
  NoFila *no = f->inicio;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }

return cont;
}
/*int tamanho(Pilha *p)
{
 int cont=0;
  NoFila *no = p->topo;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }

return cont;
}*/

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Fila f2;
    Pilha p1;
    Pilha p2;

    enfileiraF(&f1, 1);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 3);
    enfileiraF(&f1, 4);

    enfileiraF(&f2, 5);
    enfileiraF(&f2, 6);
    enfileiraF(&f2, 7);

    empilhaP(&p1, 10);
    empilhaP(&p1, 20);
    empilhaP(&p1, 30);
    empilhaP(&p1, 40);

    empilhaP(&p2, 50);
    empilhaP(&p2, 60);
    empilhaP(&p2, 70);

    cout<<"Concatenação Filas:";
    concatenaF(&f1,&f2);
    cout<<endl;
    cout<<"F1:";
    mostraF(&f1);
    cout<<endl;
    cout<<"F2:";
    mostraF(&f2);


    cout<<"Concatenação Pilhas:"<<endl;
    concatenaP(&p1,&p2);
    cout<<endl;
    cout<<"P1:"<<endl;;
    mostraP(&p1);
    cout<<endl;
    cout<<"P2:"<<endl;
    mostraP(&p2);

}
