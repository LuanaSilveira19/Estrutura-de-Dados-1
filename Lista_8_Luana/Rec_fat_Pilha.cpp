#include <iostream>
using namespace std;

#include "Recursiva.hpp"

int fatorial(int num)
{

     Pilha no;
     int aux;
    while(num>1)
    {
        empilhaP(&no, num);
        num--;
    }
    //mostraP(&no);
    while(!vaziaP(&no))
    {
        aux = desempilhaP(&no);
        num= num * aux;

    }
    return num;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor;
    cout<<"Digite um valor:";
    cin>>valor;
    cout<<"Fatorial:"<<fatorial(valor);

}//final do main
