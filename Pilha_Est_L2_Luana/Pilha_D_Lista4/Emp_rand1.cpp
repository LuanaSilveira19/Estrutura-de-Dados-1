#include <iostream>
#include <ctime>
using namespace std;

#include "pilha_D_L4_E1.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1;
    int valor;
    bool resultado;
    for(int i=0; i<4; i++)
    {
        empilhaP(&p1, rand()%10);
    }

    mostraP(&p1);
    media(&p1);


    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main


