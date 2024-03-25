#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA
#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip>

struct NoFila
{
    int dado; //informacao do nó
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


bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(Fila *f, int dado)
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

//Dequeue
int desenfileiraF(Fila *f)
{
    int dado = 0;

    // se não estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro nó
        NoFila *apagar = f->inicio; //guarda o primeiro nó(endereço) em uma variável auxiliar;
        f->inicio = f->inicio->prox; // atualiza o início da fila
        delete apagar;  // libera a memória

        if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
int espiaF(Fila* f)
{
    int dado = 0;

    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado;
}

//show
void mostraF(Fila *f)
{
    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        cout << "[";

        NoFila *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << no->dado;
            no = no->prox;

            if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";
}

// retorna true se o valor existe na fila
// retorna false se o valor não existe na fila
bool buscaF(Fila *f, int dado)
{

    NoFila *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;
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
//PILHA
struct NoPilha
{
    int dado; //informação do nó
    NoPilha *prox; //próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha(){ //Construtor. Inicialização da pilha
        topo = nullptr;//obrigatória
    }
};


bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
bool empilhaP(Pilha *p, int dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo nó
    if (novo == NULL) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.
    return true;
}

//pop
int desempilhaP(Pilha *p)
{
    int dado = 0;

    // se não estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no nó do topo
        NoPilha *apagar = p->topo; //guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o próximo elemento;

        delete apagar;  /// libera a memória
    }

    return dado;
}

//peek
int espiaP(Pilha* p)
{
    int dado = 0;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}


void mostraP(Pilha *p)
{
    //cout << "PILHA: " << endl;

    if(vaziaP(p) == false)
    {
       /* cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "Nó" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;*/
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            //cout << setfill(' ') << std::setw(13) << no << " | ";
            //cout << setfill(' ') << std::setw(13) << no->prox << " | ";
            cout << setfill(' ') << std::setw(10)<<" | " << no->dado << " |" << endl;

            no = no->prox;
        }
        cout << "------------------" << endl;
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor não existe na pilha
bool buscaP(Pilha *p, int dado)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;

}

void destroiP(Pilha *p)
{
    int dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}
#endif // _HPP_FILA_DINAMICA
#endif


