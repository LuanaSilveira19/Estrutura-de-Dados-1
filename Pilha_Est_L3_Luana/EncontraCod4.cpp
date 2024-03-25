#include <iostream>
using namespace std;

#include "pilha_L3_E4.hpp"
bool buscaValor(Pilha *p, int valor, int tamPilha)
{
    Pilha aux;
    inicializaP(&aux, tamPilha);
    int v;

    bool encontrou=false;
    while(! vaziaP(p))
    {
        v = desempilhaP(p);
        empilhaP(&aux, v);
        if(v== valor)
        {
            encontrou=true;
            break;
        }
    }

    while(! vaziaP(&aux))
    {
        v = desempilhaP(&aux);
        empilhaP(p, v);

    }

    destroiP(&aux);
    return encontrou;
}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p;
    int num, cod, enc;

    cout<<"Informe o número de cidades que deseja incluir: ";
    cin>>num;

    inicializaP(&p, num);


    for(int i=0; i<num; i++)
    {
        cout<<"Informe o código da cidade "<<i+1<<": ";
        cin>>cod;
        empilhaP(&p,cod);
    }

    cout<<"Informe o codigo que deseja encontar: ";
    cin>>enc;


    if(buscaValor(&p, enc, num) )
        cout<<"A cidade com o codigo "<<enc<<" foi encontrada";
    else
         cout<<"A cidade com o codigo "<<enc<<" NÃO FOI encontrada";




}
