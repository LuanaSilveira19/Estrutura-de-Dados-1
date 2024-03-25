#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iomanip>

struct Pilha_1
{
    int tam;
    int base;
    int topo;
    int *dados;

    Pilha_1()
    {
        tam=0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};
struct Pilha_Par
{
    int t;
    int b;
    int top;
    int *pares;

    Pilha_Par()
    {
        t=0;
        b = -1;
        top = -1;
        pares = NULL;
    }
};
struct Pilha_Impar
{
    int ta;
    int ba;
    int to;
    int *impar;

    Pilha_Impar()
    {
        ta=0;
        ba = -1;
        to = -1;
        impar = NULL;
    }
};
void inicializaP(Pilha_1 *p, int tam)
{
    p->base = -1; ///  (*p).base = -1;  /// p->base  p.topo
    p->topo = -1;
    p->tam  =  tam;
    p->dados = new int[tam];///aloca memória dinamicamente
}
void iniPar(Pilha_Par *p2, int t)
{
    p2->b = -1;
    p2->top = -1;
    p2->t  =  t;
    p2->pares = new int[t];
}
void iniImpar(Pilha_Impar *p3, int ta)
{
    p3->ba = -1;
    p3->to = -1;
    p3->ta  =  ta;
    p3->impar = new int[ta];
}
bool verificaInicializacaoP(Pilha_1 *p) //verifica de a pilha foi inicializada
{
    if(p->dados != NULL)
        return true;
    else
        return false;
}
bool verificaIni_Par(Pilha_Par *p2)
{
    if(p2->pares != NULL)
        return true;
    else
        return false;
}
bool verificaIni_Impar(Pilha_Impar *p3)
{
    if(p3->impar != NULL)
        return true;
    else
        return false;
}

bool cheiaP(Pilha_1 *p)
{
    if (p->topo == p->tam - 1)
        return true;
    else
        return false;
}
void destroiP(Pilha_1 *p)
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

bool vaziaP(Pilha_1 *p)
{
    if (p->topo == p->base)
        return true;
    else
        return false;
}
bool empilhaP(Pilha_1 *p, int valor) ///push
{

    if (verificaInicializacaoP(p)==false || cheiaP(p)==true)
        return false;
    else
    {
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}
bool empilhaPar(Pilha_Par *p2, int valor) ///push
{

    if (verificaIni_Par(p2)==false)
        return false;
    else
    {
        p2->top++;
        p2->pares[p2->top] = valor;
        return true;
    }
}
bool empilhaImpar(Pilha_Impar *p3, int valor) ///push
{

    if (verificaIni_Impar(p3)==false)
        return false;
    else
    {
        p3->to++;
        p3->impar[p3->to] = valor;
        return true;
    }
}
int desempilhaP(Pilha_1 *p) ///pop
{

    int valor = 0; //inicializar a variável valor, a qual será retornada

    ///se a pilha foi inicializada && se não estiver vazia, retira valor
    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
        p->topo--;
    }

    return valor;
}

void mostraP(Pilha_1 *p)
{

    cout << "PILHA CRIADA: " << endl;
    cout << "   ------------" << endl;
    for(int i = p->topo; i > p->base; i--)
    {

        cout << setfill(' ') << std::setw(3) << i << "|";
        cout << setfill(' ') << std::setw(10) << p->dados[i] << "|" << endl;
        cout << "   ------------" << endl;

    }
}
void mostra_Par(Pilha_Par *p2)
{

    cout << "PILHA DOS PARES: " << endl;
    cout << "   ------------" << endl;
    for(int i = p2->top; i > p2->b; i--)
    {

        cout << setfill(' ') << std::setw(3) << i << "|";
        cout << setfill(' ') << std::setw(10) << p2->pares[i] << "|" << endl;
        cout << "   ------------" << endl;

    }
}
void mostra_Impar(Pilha_Impar *p3)
{

    cout << "PILHA DOS IMPARES: " << endl;
    cout << "   ------------" << endl;
    for(int i = p3->to; i > p3->ba; i--)
    {

        cout << setfill(' ') << std::setw(3) << i << "|";
        cout << setfill(' ') << std::setw(10) << p3->impar[i] << "|" << endl;
        cout << "   ------------" << endl;

    }
}


#endif // _HPP_PILHA
