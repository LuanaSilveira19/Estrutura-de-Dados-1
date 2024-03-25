#include <iostream>
using namespace std;

#include "pilha_L3_E6.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p1;
    int num, v=0;

    cout<<"Informe um número decimal para descobrir o binário:";
    cin>>num;

     inicializaP(&p1, 64);

    while(num>0)
     {
          empilhaP(&p1,(num%2));
            num= num/2;
     }
       mostraP(&p1);
}
