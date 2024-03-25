
#ifndef _HPP_PILHA
#define _HPP_PILHA
#include <iomanip>
#include <cstring>

struct Pilha
{
    int tam;
    int base;
    int topo;
    char *palavra;

    Pilha()
    {
        tam=0;
        base = -1;
        topo = -1;
        palavra = NULL;
    }
};

void inicializaP(Pilha *p, int tam)
{
    p->base = -1;
    p->topo = -1;
    p->tam  =  tam;
    p->palavra = new char [tam];
}
bool verificaInicializacaoP(Pilha *p)
{
    if(p->palavra != NULL)
        return true;
    else
        return false;
}


bool empilhaP(Pilha *p, char text)
{

    if (verificaInicializacaoP(p)==false)
        return false;
    else{
        p->topo++;
        p->palavra[p->topo] = text;
        return true;
    }
}
bool vaziaP(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}
char desempilhaP(Pilha *p) ///pop
{

    char valor= ' ' ;
    if (vaziaP(p)==false)
    {
        valor = p->palavra[p->topo];
        p->topo--;
    }

    return valor;
}
void mostraP(Pilha *p)
{
        cout << "   ------------" << endl;
        for(int i = p->topo; i > p->base; i--){

            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << p->palavra[i] << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
#endif
