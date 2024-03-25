#include <iostream>
using namespace std;
#include "D_Max_Min.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    cout << fixed;
    cout.precision(2);
    Lista lista = Lista();
    Lista lista2 = Lista();
    Lista lista3 = Lista();

    insereInicioL(&lista,32);
    insereInicioL(&lista,2);
    insereFimL(&lista,40);
    insereFimL(&lista,19);
    insereInicioL(&lista,53);
    insereInicioL(&lista,28);
    insereFimL(&lista,7);
    insereFimL(&lista,18);
    cout<<"Elementos da lista 1: ";
    mostraL(&lista);
    cout<<"Valor MAX da lista 1: "<<lista.Max<<endl;
    cout<<"Indice do maior elemento da lista 1: "<<lista.indiceMaior<<endl;
    cout<<"Valor MIN da lista 1: "<<lista.Min<<endl;
    cout<<"Indice do maior elemento da lista 1: "<<lista.indiceMenor<<endl;
    cout<<"Soma lista 1: "<<lista.soma<<endl;
    cout<<"Tamanho da lista 1: "<<lista.tamanho<<endl;
    cout<<"Remove fim lista 1: "<<removeUltimo(&lista)<<endl;
    cout<<"Remove inicio lista 1: "<<removeInicio(&lista)<<endl;
    cout<<"Remove fim lista 1: "<<removeUltimo(&lista)<<endl;
    cout<<"Remove inicio lista 1: "<<removeInicio(&lista)<<endl;
    cout<<endl;
    cout<<"Elementos da lista 1: ";
    mostraL(&lista);
    cout<<"Valor MAX da lista 1: "<<lista.Max<<endl;
    cout<<"Valor MIN da lista 1: "<<lista.Min<<endl;
    cout<<endl;

    cout<<"Insere 100 na pos 0: "<<endl;
    cout<<"Insere 200 na pos 2: "<<endl;
    cout<<"Insere 300 na pos 4: "<<endl;
    cout<<"Insere 1 na pos 7: "<<endl;
    insereMeio(&lista, 0, 100);
    insereMeio(&lista, 2, 200);
    insereMeio(&lista, 4, 300);
    insereMeio(&lista, 7, 1);
    cout<<"Elementos da lista 1: ";
    mostraL(&lista);
    cout<<endl;
    cout<<"Elementos da lista 1 INVERTIDO: ";
    mostrarInversoL(&lista);
    cout<<"Remove elemento da posição 4: "<< removePorPosicao(&lista,4)<<endl;
    cout<<"Remove elemento da posição 3: "<< removePorPosicao(&lista,3)<<endl;
    cout<<endl;
    cout<<"Elementos da lista 1: ";
    mostraL(&lista);
    cout<<"Valor MAX da lista 1 ATUALIZADO: "<<lista.Max<<endl;
    cout<<"Indice do maior elemento da lista 1 ATUALIZADO: "<<lista.indiceMaior<<endl;
    cout<<"Valor MIN da lista 1 ATUALIZADO: "<<lista.Min<<endl;
     cout<<"Indice do maior elemento da lista 1 ATUALIZADO: "<<lista.indiceMenor<<endl;
    cout<<"Elementos da lista 1 INVERTIDO: ";
    mostrarInversoL(&lista);

    cout<<"Lista 1 ordenada:";
    ordenarL(&lista);
    mostraL(&lista);
    cout<<"Remove elemento da posição 4: "<< removePorPosicao(&lista,4)<<endl;
    mostraL(&lista);


    cout<<endl;
    cout<<"Insere ordenado lista 2: "<<endl;
    insereOrdenado(&lista2,40);
    insereOrdenado(&lista2,25);
    insereOrdenado(&lista2,60);
    insereOrdenado(&lista2,4);
    insereOrdenado(&lista2,2);
    cout<<"Elementos da lista 2: ";
    mostraL(&lista2);


    cout<<endl;
    cout<<"Lista 3, 1 elemento: "<<endl;
    insereInicioL(&lista3,100);
    cout<<"Elementos da lista 3: ";
    mostraL(&lista3);
    cout<<"Valor MAX da lista 3: "<<lista3.Max<<endl;
    cout<<"Valor MIN da lista 3: "<<lista3.Min<<endl;
    cout<<"Soma lista 3: "<<lista3.soma<<endl;
    cout<<"Tamanho da lista 3: "<<lista3.tamanho<<endl;
    cout<<"Remove lista 3: "<<removeUltimo(&lista3)<<endl;
     mostraL(&lista3);

}
