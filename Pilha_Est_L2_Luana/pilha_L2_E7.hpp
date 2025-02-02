#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha

struct Pilha
{
    int tam;
    int base;
    int topo;
    string *dados; //Vetor que ser� alocado para armazenar os elementos da pilha

    Pilha() //Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        tam=0;
        base = -1;
        topo = -1;
        dados = NULL;
    }
};



///inicializa��o dos dados da pilha
void inicializaP(Pilha *p, int tam)
{
    p->base = -1; ///  (*p).base = -1;  /// p->base  p.topo
    p->topo = -1;
    p->tam  =  tam;
    p->dados = new string[tam];///aloca mem�ria dinamicamente
}


//retorna true se a pilha foi inicializada
//retorna false se a pilha n�o foi inicializada
bool verificaInicializacaoP(Pilha *p) //verifica de a pilha foi inicializada
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
bool empilhaP(Pilha *p, string valor) ///push
{
    /// retorna false se a pilha n�o foi inicializada ou se ela est� cheia
    if (verificaInicializacaoP(p)==false || cheiaP(p)==true)//verificaInicializacaoP verifica se foi inicializada
        return false;
    else{
        p->topo++;
        p->dados[p->topo] = valor[p->topo];
        return true;
    }
}



string desempilhaP(Pilha *p) ///pop
{

    string valor = 0; //inicializar a vari�vel valor, a qual ser� retornada


    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
        p->topo--;
    }

    return valor;
}



///peek
string espiaP(Pilha *p) ///peek
{
    string valor; //inicializar a vari�vel valor, a qual ser� retornada

    if (vaziaP(p)==false)
    {
        valor = p->dados[p->topo];
    }

    return valor;
}





void mostraP(Pilha *p)
{

    cout << "PILHA: " << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO: " << p->topo << endl;
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


bool buscaP(Pilha *p, string valor)
{

   for(int i = p->topo ; i > p->base; i--)
   {
       if (valor == p->dados[i])
          return true;
   }
   return false;

}



#endif // _HPP_PILHA

