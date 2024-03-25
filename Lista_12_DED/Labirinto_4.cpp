#include <iostream>
#include <cstring>
using namespace std;
#include "Lista_Dupla_E4.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
     Lista lista = Lista();

    insereFimL(&lista, "direita");
    insereFimL(&lista, "baixo");
    insereFimL(&lista, "direita");
    insereFimL(&lista, "cima");
    insereFimL(&lista, "direita");
    insereFimL(&lista, "baixo");
    insereFimL(&lista, "direita");
    insereFimL(&lista, "direita");
    insereFimL(&lista, "direita");
    insereFimL(&lista, "cima");
    insereFimL(&lista, "direita");
    insereFimL(&lista, "direita");
    insereFimL(&lista, "cima");
    insereFimL(&lista, "cima");
    insereFimL(&lista, "cima");
    insereFimL(&lista, "cima");
    insereFimL(&lista, "esquerda");
    insereFimL(&lista, "cima");
    insereFimL(&lista, "direita");
    insereFimL(&lista, "direita");

    cout<<"IDA:";
    mostraL(&lista);
    cout<<endl;
    cout<<"VOLTA:";
    mostrarInversoL(&lista);
}
