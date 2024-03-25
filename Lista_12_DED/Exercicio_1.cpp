#include <iostream>
using namespace std;
#include "Lista_Dupla_E1.hpp"


bool insereFimL(Lista *lista, int valor)
{
//insere no final com o anterior
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
//!linha->fim faz a verificação opasta
    if (!vaziaL(lista)) //lista vazia?
    {
        lista->fim->prox = novo;
        novo->ant =  lista->fim;
        novo->prox = NULL;
        lista->fim = novo;
    }
    else
    {

        novo->ant = nullptr;
        novo->prox = NULL;
        lista->fim = novo;
        lista->inicio = novo;
    }


    lista->tamanho++;

    return true;
}

int removeInicio(Lista *lista)
{
    No *aux;
    int dado=0;
    if(vaziaL(lista))
        return dado;

    aux = lista->inicio;
    if(aux->prox != nullptr)
        aux->prox->ant= nullptr;
    else
        lista->fim=nullptr;


    lista->inicio = aux->prox;
    lista->tamanho--;
    dado = aux->dado;
    delete aux;

    return dado;
}

int removeUltimo(Lista *lista)
{

    No  * atual  = lista->fim ;
    int dado=0;

    if(vaziaL(lista))
        return dado;

    if(lista->tamanho==1)
    {
        dado=atual->dado;
        lista->fim=nullptr;
        lista->inicio=nullptr;
        lista->tamanho=0 ;
    }
    else
    {
        dado=atual->dado;
        lista->fim= atual->ant ;
        lista->fim->prox =NULL ;
        lista->tamanho-- ;
    }


    delete atual;
    return dado;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Lista lista = Lista();
    Lista lista2 = Lista();
    insereInicioL(&lista, 33);
    insereInicioL(&lista, 34);
    insereInicioL(&lista, 40);
    cout << lista  << endl;

    cout<<endl;
    cout<<"Lista 2, insere fim:"<<endl;
    insereFimL(&lista2, 33);
    insereFimL(&lista2, 34);
    insereFimL(&lista2, 40);
    insereFimL(&lista2, 50);
    insereFimL(&lista2, 60);
    cout << lista2  << endl;

    cout<<"Elemento removido:";
    cout<< removeInicio(&lista2)<<endl;
    cout << lista2  << endl;

    cout<<"Mostra inverso:";
    mostrarInversoL(&lista2);
    cout<<endl;
    cout<<"Remove o ultimo elemento da lista 1: ";
    cout<< removeUltimo(&lista)<<endl;
    cout << lista  << endl;

    cout<<"Mostra inverso 2:";
    mostrarInversoL(&lista);

}
