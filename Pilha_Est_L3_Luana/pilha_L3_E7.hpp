#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha

struct Pilha
{
    int tam;
    int base;
    int topo;
    int *dados;

    Pilha()
    {
        tam=0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};



void inicializaP(Pilha *p, int tam)
{
    p->base = -1;
    p->topo = -1;
    p->tam  =  tam;
    p->dados = new int[tam];
}


bool verificaInicializacaoP(Pilha *p)
{
    if(p->dados != NULL)
        return true;
    else
        return false;
}

void destroiP(Pilha *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;

    if(p->dados != NULL)
    {
        delete[] (p->dados);
        p->dados = NULL;
    }
}

bool cheiaP(Pilha *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}

bool vaziaP(Pilha *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}

///push
bool empilhaP(Pilha *p, int valor) ///push
{

    if (verificaInicializacaoP(p)==false || cheiaP(p)==true)
        return false;
    else{
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}



///pop
int desempilhaP(Pilha *p) ///pop
{

    int valor = 0;
    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
        p->topo--;
    }

    return valor;
}



///peek
int espiaP(Pilha *p) ///peek
{
    int valor = 0; //inicializar a vari�vel valor, a qual ser� retornada

    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
    }

    return valor;
}





void mostraP(Pilha *p)
{

    cout << "P3: " << endl;
    if(vaziaP(p) == false)
    {
        cout << "   ------------" << endl;
        for(int i = p->topo; i > p->base; i--){

            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << p->dados[i] << "|" << endl;
            cout << "   ------------" << endl;
        }
    }
}


bool buscaP(Pilha *p, int valor)
{

   for(int i = p->topo ; i > p->base; i--)
   {
       if (valor == p->dados[i])
          return true;
   }
   return false;

}



#endif






