#include <iostream>
using namespace std;

#include "Questao_2.hpp"//arquivo de cabeçalho
int tamanho(Pilha *p)
{
    int cont=0;
    if(vaziaP(p)==false)
    {
        for(int i = p->topo; i > p->base; i--)
        {
            cont++;
        }
    }



    return cont;
}

void repetidos(Pilha *p, Pilha *r, Pilha *c, int tam)
{
    Pilha aux;
    int x;

    inicializaP(&aux,15);
    for(int i=0; i<tam; i++)
    {
        empilhaP(&aux,desempilhaP(p));
    }
    for(int j=0; j<tam; j++)
    {
        x=desempilhaP(&aux);
        empilhaP(p,x);
        empilhaP(c,x);
    }
    for(int i = c->topo ; i > p->base; i--)
    {
        if(buscaP(p,c->dados[i])>1)
        {
            if(buscaP(r,c->dados[i])==0)
            empilhaP(r,c->dados[i]);
        }
    }



    cout<<"Pilha P depois:"<<endl;
    mostraP(p);
    cout<<"Pilha R:"<<endl;
    mostraP(r);

}





int main(void)
{
    Pilha P, R, C;
    inicializaP(&P,15);
    inicializaP(&R,15);
    inicializaP(&C,15);

    empilhaP(&P, 8);
    empilhaP(&P, 9);
    empilhaP(&P, 7);
    empilhaP(&P, 5);
    empilhaP(&P, 7);
    empilhaP(&P, 6);
    empilhaP(&P, 7);
    empilhaP(&P, 0);
    empilhaP(&P, 4);
    empilhaP(&P, 8);
    empilhaP(&P, 3);
    empilhaP(&P, 4);
    empilhaP(&P, 1);

    cout<<"Pilha P antes:"<<endl;
    mostraP(&P);
    repetidos(&P,&R,&C, tamanho(&P));




}
