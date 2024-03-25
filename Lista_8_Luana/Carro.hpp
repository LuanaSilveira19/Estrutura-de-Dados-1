#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA
#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip>
#include <cstring>


struct NoFila
{
    Ficha dado; //informacao do nó
    NoFila *prox; //proximo elemento da fila
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila(){ //Construtor. Usado para inicializar os dados das variáveis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};
struct NoPilha
{
    Ficha dado; //informação do nó
    NoPilha *prox; //próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha()  //Construtor. Inicialização da pilha
    {
        topo = nullptr;//obrigatória
    }
};

bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}

bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}

//Enqueue
bool enfileiraF(Fila *f, Ficha dado)
{
    NoFila *novo = new NoFila();//cria a "caixinha" com o dado e o nó
    if (novo == NULL) /// não conseguiu alocar memória (novo == NULL)
        return false;

    novo->dado = dado;//recebe o endereço onde o dado esta
    novo->prox = nullptr;
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}
bool empilhaP(Pilha *p, Ficha dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo nó
    if (novo == NULL) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.

    return true;
}

//Dequeue
Ficha desenfileiraF(Fila *f)
{
    Ficha dado;


    if (vaziaF(f) == false)
    {
        dado = f->inicio->dado;
        NoFila *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;
        if (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}
Ficha desempilhaP(Pilha *p)
{
    Ficha dado;


    if (vaziaP(p) == false)
    {
        dado = p->topo->dado;
        NoPilha *apagar = p->topo;
        p->topo = p->topo->prox;

        delete apagar;
    }

    return dado;
}

void mostraP(Pilha *p)
{



    if(vaziaP(p) == false)
    {

        NoPilha *no = p->topo;

        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(0) <<"|Nome: "<< no->dado.nome << ", Idade:" <<no->dado.idade<< ", Sexo: ";
            cout << setfill(' ') << std::setw(0) << no->dado.sexo << ", Cidade:" <<no->dado.cidade<< ", Placa:" <<no->dado.placa<<"|"<<endl;
            cout << "----------------------------------------------------------------------" << endl;

            no = no->prox;

        }
    }
}



void destroiF(Fila *f)
{

    NoFila *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        NoFila *apagar = no; //guarda o nó em uma variável auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif // _HPP_FILA_DINAMICA
#endif

