#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA
#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA


#include <iomanip> //biblioteca usada para formatar a impress�o da pilha
#include <cstring>

struct NoPilha //pilha
{
    Cadastro dado; //informa��o do n�
    NoPilha *prox; //pr�ximo elemento
};
struct NoFila
{
    int dado; //informacao do n�
    NoFila *prox; //proximo elemento da fila
};

struct Pilha
{
    NoPilha *topo;

    Pilha()  //Construtor. Inicializa��o da pilha
    {
        topo = nullptr;//obrigat�ria
    }
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila(){ //Construtor. Usado para inicializar os dados das vari�veis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};


bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}

bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}

//push
bool empilhaP(Pilha *p, Cadastro dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo n�
    if (novo == NULL) /// sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado; //armazena a informa��o no n�
    novo->prox = p->topo; //o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o n� criado.

    return true;
}

bool enfileiraF(Fila *f, int dado)
{
    NoFila *novo = new NoFila();//cria a "caixinha" com o dado e o n�
    if (novo == NULL) /// n�o conseguiu alocar mem�ria (novo == NULL)
        return false;

    novo->dado = dado;//recebe o endere�o onde o dado esta
    novo->prox = nullptr;
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

Cadastro desempilhaP(Pilha *p)
{
    Cadastro dado;

    // se n�o estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no n� do topo
        NoPilha *apagar = p->topo; //guarda o n� do topo em uma vari�vel auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o pr�ximo elemento;

        delete apagar;  /// libera a mem�ria
    }

    return dado;
}
int desenfileiraF(Fila *f)
{
    int dado = 0;

    // se n�o estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila n�o est� vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro n�
        NoFila *apagar = f->inicio; //guarda o primeiro n�(endere�o) em uma vari�vel auxiliar;
        f->inicio = f->inicio->prox; // atualiza o in�cio da fila
        delete apagar;  // libera a mem�ria

        if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

void mostraP(Pilha *p)
{


    cout << "Pilha: ";
    if(vaziaP(p) == false)
    {

        NoPilha *no = p->topo;
        cout<<"{";
        while (no != NULL)
        {

            cout << setfill(' ') << std::setw(0) <<"["<< no->dado.nome << ", c= " <<no->dado.codigo<< ", i= ";//ver se os dados estao certos
            cout << setfill(' ') << std::setw(0) << no->dado.idade << ", s= " <<no->dado.saldo<<"],"<<endl;

            no = no->prox;

        }
        //cout<<"}";
    }
    else
        cout<<"vazia\n";
}
void mostraF(Fila *f)
{


    if(vaziaF(f) == false) //verifica se a fila n�o est� vazia
    {



        NoFila *no = f->inicio;
        while (no != NULL) //fa�a enquanto (no != NULL)
        {
            cout << no->dado;
            no = no->prox;

            if(no != NULL) //verifica se o pr�ximo n� n�o � nulo (no != NULL)
                cout << ", ";
        }
        cout << ";" << endl;
    }
    else
        cout << "vazia\n";
}

bool buscaP(Pilha *p, Cadastro dado)//vai ser
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == dado.codigo)
            return true;

        no = no->prox;
    }

    return false;
}

bool buscaF(Fila *f, int dado)
{

    NoFila *no = f->inicio;
    while (no != NULL) //fa�a enquanto (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;
}


void destroiP(Pilha *p)
{
    Cadastro dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}
void destroiF(Fila *f)
{

    NoFila *no = f->inicio;
    while (no != NULL) //fa�a enquanto (no != NULL)
    {
        NoFila *apagar = no; //guarda o n� em uma vari�vel auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}
float saldoTotal(Pilha *p){
     NoPilha *no = p->topo;
     float soma=0;
    while (no != NULL)
    { if(no->dado.saldo)
        soma+=no->dado.saldo;
        no = no->prox;
    }
    return soma;
}

#endif // _HPP_PILHA_DINAMICA
#endif
