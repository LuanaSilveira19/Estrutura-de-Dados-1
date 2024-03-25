#include <iostream>
using namespace std;

#include "Lista_A10_E3.hpp"


int verificaOrdem(No** lista)
{
    if (*lista == nullptr || (*lista)->prox == nullptr)
        return 0;  // Lista vazia ou com apenas um elemento, considerada ordenada

    No* atual = *lista;

    // Verifica se a lista está em ordem crescente
    while (atual->prox != nullptr)
    {
        if (atual->dado > atual->prox->dado)
        {
            break;//break encerra a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.
        }
        atual = atual->prox;
    }

    if (atual->prox == nullptr)
    {
        return 0;  // Lista em ordem crescente
    }

    atual = *lista;

    // Verifica se a lista está em ordem decrescente
    while (atual->prox != nullptr)
    {
        if (atual->dado < atual->prox->dado)
        {
            break;
        }
        atual = atual->prox;
    }

    if (atual->prox == nullptr)
    {
        return 1;  // Lista em ordem decrescente
    }

    return 2;  // Lista não está ordenada
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);

    insereInicioL(&lista, 5);
    insereInicioL(&lista, 4);
    insereInicioL(&lista, 3);
    insereInicioL(&lista, 2);
    //insereInicioL(&lista, 9);
    insereInicioL(&lista, 1);

    /* insereInicioL(&lista, 5);
     insereInicioL(&lista, 6);
     insereInicioL(&lista, 7);
     insereInicioL(&lista, 8);
     insereInicioL(&lista, 9);
     insereInicioL(&lista, 10);*/
    mostraL(&lista);

    if(verificaOrdem(&lista)==0)
    cout<<"Lista Crescente"<<endl;
    else if(verificaOrdem(&lista)==1)
    cout<<"Lista Derescente"<<endl;
    else
    cout<<"Lista Desordenada"<<endl;



}
