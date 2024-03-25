#include <iostream>
using namespace std;

#include "Max_minD.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    cout << fixed;
    cout.precision(2);
    Lista lista = Lista();
    Lista lista2 = Lista();

    insereFimL(&lista, 10);
    insereFimL(&lista, 20);
    insereFimL(&lista, 4);
    insereFimL(&lista, 30);
    insereFimL(&lista, 40);
    insereFimL(&lista, 1);
    insereInicioL(&lista, 200);
    insereFimL(&lista, 500);
    insereFimL(&lista, 45);
    cout<<"Lista 1 normal:";
    mostraL(&lista);
    cout<<"Lista 1 INVERTIDA:";
    mostrarInversoL(&lista);

    cout<<"Valor MAX da lista: "<< lista.Max<<endl;
    cout<<"Valor MIN da lista: "<< lista.Min<<endl;
    cout<<"Insere 100 na posição 2:";
    inserePosicao(&lista,2,100);
    inserePosicao(&lista,10,600);
    mostraL(&lista);
    cout<<"Soma dos elementos da lista: "<< lista.soma<<endl;


    removeL(&lista,500);
    removeL(&lista,1);
    cout<<endl;

    cout<<"Lista 2:";
    mostraL(&lista);

    cout<<"Lista 2 INVERTIDA depois de remover o 500 e 1:";
   // imprime_rec(&lista); da pra usar essa tb, mas tem que atualizar os descritores
    mostrarInversoL(&lista);

    cout<<"Valor MAX da lista: "<< lista.Max<<endl;
    cout<<"Valor MIN da lista: "<< lista.Min<<endl;
    cout<<"Soma dos elementos da lista: "<< lista.soma<<endl;
    cout<<"Dado do inicio:"<<leInicio(&lista)<<endl;
    cout<<"Dado do fim:"<<leFim(&lista)<<endl;
    cout<<"Media dos elementos COM OS DESCRITORES:"<< lista.soma/lista.tamanho<<endl;
    cout<<"Remove inicio:"<<removeInicio(&lista)<<endl;
    cout<<"Remove final:"<<removeFim(&lista)<<endl;


    cout<<endl;
    cout<<"Lista 3:";
    mostraL(&lista);
    cout<<"Remove inicio:"<<removeInicio(&lista)<<endl;
    cout<<"Remove final:"<<removeFim(&lista)<<endl;
    cout<<"Lista 3 ordenada:";
    ordenarL(&lista);
    mostraL(&lista);
    cout<<endl;
     cout<<"Remove valor da posição 2:"<<removePorPosicao(&lista,2)<<endl;
     mostraL(&lista);

     cout<<endl;
    cout<<"Valor MAX da lista: "<< lista.Max<<endl;



    cout<<"Lista 3 INVERTIDA:";
    mostrarInversoL(&lista);

    cout<<endl;
    insereOrdenado(&lista2,12);
    insereOrdenado(&lista2,0);
    insereOrdenado(&lista2,15);
    insereOrdenado(&lista2,200);
    insereOrdenado(&lista2,1);

    cout<<endl;
    cout<<"Lista nova ordenada:";
    mostraL(&lista2);
    cout<<"Soma dos elementos da lista NOVA: "<< lista2.soma<<endl;
    cout<<"Tamanho da lista NOVA: "<< lista2.tamanho<<endl;
    cout<<"Valor MAX da lista NOVA: "<< lista2.Max<<endl;
    cout<<"Valor MIN da lista NOVA: "<< lista2.Min<<endl;




}
