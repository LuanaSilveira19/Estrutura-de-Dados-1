#ifndef _HPP_FILA
#define _HPP_FILA
#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <cstring>
#include <iomanip> //biblioteca usada para formatar a impressão da fila

struct Fila
{
    int tam; //tamanho do vetor de dados
    int total; //total de elementos armazenados na fila
    int inicio; //ponteiro para o elemento armazenado no inicio da fila
    int fim; //ponteiro para o fim da fila (posição do vetor onde será armazenado o próximo elemento)
   string *dados;//ponteiro para o vetor que será alocado para armazenar os dados
    Fila() //Construtor. Usado para inicializar os dados das variáveis da struct
    {
        tam =0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};
struct Pilha
{
    int tam;
    int base;
    int topo;
    string *palavra;

    Pilha()
    {
        tam=0;
        base = -1;
        topo = -1;
        palavra = NULL;
    }
};

void inicializaF(Fila *f, int tam) /// inicialização da fila
{
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new string[tam];/// aloca memória para vetor
}
void inicializaP(Pilha *p, int tam)
{
    p->base = -1;
    p->topo = -1;
    p->tam  =  tam;
    p->palavra = new string [tam];
}

bool verificaInicializacaoF(Fila *f) //verifica de a fila foi inicializada
{
    if(f->dados != NULL)
        return true;
    else
        return false;
}
bool verificaInicializacaoP(Pilha *p)
{
    if(p->palavra != NULL)
        return true;
    else
        return false;
}

void destroiF(Fila *f)
{
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(verificaInicializacaoF(f) == true)
    {
        delete[] (f->dados);
        f->dados = nullptr;
    }
}


bool vaziaF(Fila *f)// fila vazia
{
    if (f->total == 0)
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

bool cheiaF(Fila *f)// fila cheia
{
    if (f->total == f->tam)
        return true;
    else
        return false;
}

//Enqueue
bool enfileiraF(Fila *f, string valor) /// incluir valor na fila
{

    if (verificaInicializacaoF(f)==false || cheiaF(f) == true) // retorna false se a fila não foi inicializada ou se cheia
        return false;
for(int i=0; i<valor.size(); i++)
{
     //inserir no final da fila
    f->dados[f->fim] = valor[i];


    //incrementa a quantidade de elementos armazenados na fila
    f->total++;

    //avança o ponteiro fim
    f->fim++;

    if(f->fim>=f->tam)
       f->fim = 0; //circular
}


    return true;
}
bool empilhaP(Pilha *p,string text)
{

    if (verificaInicializacaoP(p)==false)
        return false;
    else{
        p->topo++;
        p->palavra[p->topo] = text[p->topo];
        return true;
    }
}

//Dequeue
string desenfileiraF(Fila *f)  //retirar da fila
{
    string valor;

    if (vaziaF(f) == true) // retorna 0 se fila vazia
        return valor;

    //remover do inicio da fila
    valor = f->dados[f->inicio];

    //diminui a quantidade de elementos armazenados na fila
    f->total--;

    //avança o ponteiro início
    f->inicio++;

    if(f->inicio>=f->tam)
       f->inicio = 0; //circular

    return valor;
}
string desempilhaP(Pilha *p) ///pop
{

    string valor ;
    if (vaziaP(p)==false)
    {
        valor = p->palavra[p->topo];
        p->topo--;
    }

    return valor;
}

//Peek
string espiaF(Fila *f) ///peek
{
    string valor;

    if(vaziaF(f)==true)// retorna 0 se fila vazia
        return valor;

    valor = f->dados[f->inicio];
    return valor;
}

void mostraF(Fila *f)
{
   // cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total << "} -> ";

cout<<"Fila:";
    if (vaziaF(f) == false)
    {
        int idx = f->inicio;
        cout << "[";
        for(int i = 0; i < f->total; i++)
        {
            cout << f->dados[idx]; //imprime o dado armazenado na fila

            if(i < f->total-1)
                cout << ", ";

            idx++;
            if(idx >= f->tam)
                idx=0; //circular
        }
        cout << "]\n";
    }else
        cout << "Fila vazia!\n";
}
void mostraP(Pilha *p)
{
    cout<<"Pilha:"<<endl;
        cout << "   ------------" << endl;
        for(int i = p->topo; i > p->base; i--){

            cout << setfill(' ') << std::setw(3) << i << "|";
            cout << setfill(' ') << std::setw(10) << p->palavra[i] << "|" << endl;
            cout << "   ------------" << endl;
        }
    }

#endif // _HPP_FILA
#endif
