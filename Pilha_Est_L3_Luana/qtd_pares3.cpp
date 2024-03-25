#include <iostream>
using namespace std;

#include "pilha_L3_E3.hpp"//arquivo de cabeçalho

int contP (Pilha *p, int tamPilha)
{
    Pilha aux;
    int cont=0;
    int v=0;
    inicializaP(&aux, tamPilha);

    while(! vaziaP (p))
    {
        empilhaP(&aux, desempilhaP(p));
        cont++;
    }
    while(! vaziaP (&aux))
    {
        empilhaP(p, desempilhaP(&aux));
    }

    destroiP(&aux);
    return cont;

}

bool iguaisP(Pilha *p1, Pilha *p2, int tam_p1, int tam_p2 )
{
    int contP1= contP(p1,tam_p1);
    int contP2=contP(p2,tam_p2);
    int v1, v2;
    Pilha aux1;
    inicializaP(&aux1, tam_p1);
    Pilha aux2;
    inicializaP(&aux2, tam_p2);

    bool iguais=true;
    if(contP1!= contP2)
        return false;

    while(! vaziaP (p1))
    {
        v1=desempilhaP(p1);
        empilhaP(&aux1, v1);
        v2=desempilhaP(p2);
        empilhaP(&aux2, v2);
        if(v1!=v2)
        {
            iguais=false;
            break;
        }
    }
    while(! vaziaP (&aux1))
    {
        v1=desempilhaP(&aux1);
        empilhaP(p1, v1);
        v2=desempilhaP(&aux2);
        empilhaP(p2, v2);
    }

    return iguais;
}

int pares(Pilha *p, int tam_pilha)
{
     Pilha aux;
    int cont=0;
    int v=0;
    inicializaP(&aux, tam_pilha);

    while(! vaziaP (p))
    {
        v=desempilhaP(p);
        if(v%2==0)
        cont++;
        empilhaP(&aux, v);

    }
    while(! vaziaP (&aux))
    {
        empilhaP(p, desempilhaP(&aux));
    }

    destroiP(&aux);
    return cont;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1, p2;
    inicializaP(&p1, 10);
    inicializaP(&p2, 5);

    empilhaP(&p1, 2);
    empilhaP(&p1, 22);
    empilhaP(&p1, 3);

    empilhaP(&p2, 2);
    empilhaP(&p2, 22);
    empilhaP(&p2, 3);

    if(iguaisP(&p1, &p2, 10, 5))
    {
                cout<<"As pilhas são iguais"<<endl;
        cout<<"Quantidade de números pares: "<<pares(&p1,20);
    }
    else
        cout<<"As pilhas são diferentes";





  /*  cout<<"P1: "<<endl;
    mostraP(&p1);
    cout<<"P2: "<<endl;
    mostraP(&p2);
*/







}
