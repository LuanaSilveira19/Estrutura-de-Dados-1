#include <iostream>
using namespace std;

#include "AV2.hpp"

void mesclar(No **L1, No **L2, No **L3, int k)
{
    int cont=0;
    No *n1= *L1;
    No *n2= *L2;
    if(k>=0 && k<=totalElementos(L1))
    {
        while(cont!=k)
        {

            inserenoFinalL(L3,n1->dado);
            n1=n1->prox;
            cont++;
        }
        if(cont==k)
        {
            while(n2)
            {

                inserenoFinalL(L3,n2->dado);
                n2=n2->prox;
            }
        }
        if(n1!=NULL)
        {
            while(n1)
            {

                inserenoFinalL(L3,n1->dado);
                n1=n1->prox;
            }
        }

    }


}
int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    No *l1, *l2, *l3;
    inicializaL(&l1);
    inicializaL(&l2);
    inicializaL(&l3);

    insereInicioL(&l1, 40);
    insereInicioL(&l1,30);
    insereInicioL(&l1, 20);
    insereInicioL(&l1, 10);
    insereInicioL(&l1, 20);
    insereInicioL(&l1, 7);

    insereInicioL(&l2, 500);
    insereInicioL(&l2,400);
    insereInicioL(&l2, 300);
    insereInicioL(&l2, 200);
    insereInicioL(&l2, 100);
    insereInicioL(&l2, 6);

    mesclar(&l1,&l2,&l3,5);
    cout<<"L1: ";
    mostraL(&l1);
    cout<<"L2: ";
    mostraL(&l2);
    cout<<"L3: ";
    mostraL(&l3);

    destroiL(&l1);
    destroiL(&l2);
    cout<<endl;
    cout<<"L3: ";
    mostraL(&l3);

     destroiL(&l3);

}

