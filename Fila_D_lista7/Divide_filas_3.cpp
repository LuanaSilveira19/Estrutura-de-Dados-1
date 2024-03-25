#include <iostream>
using namespace std;

#include "filaD_L7_E3.hpp"

void separaF(int n, Fila *f1, Fila *f2)
{
    Fila aux;
    int dado;
    int i=0;
    while(!vaziaF(f1)&& i<n ){
            dado=desenfileiraF(f1);
        enfileiraF(&aux,dado);
    i++;
    }
    while(!vaziaF(f1))
    {
       dado= desenfileiraF(f1);
         enfileiraF(f2,dado);
    }
    while(!vaziaF(&aux))
    {
        dado=desenfileiraF(&aux);
        enfileiraF(f1,dado);
    }
    cout<<"Fila 1: ";
    mostraF(f1);
    cout<<endl;
    cout<<"Fila 2: ";
    mostraF(f2);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1, f2;

    enfileiraF(&f1, 1);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 3);
    enfileiraF(&f1, 4);
    enfileiraF(&f1, 5);
    enfileiraF(&f1, 6);
    enfileiraF(&f1, 7);
    enfileiraF(&f1, 8);
    enfileiraF(&f1, 9);

    separaF(2,&f1,&f2);

}
