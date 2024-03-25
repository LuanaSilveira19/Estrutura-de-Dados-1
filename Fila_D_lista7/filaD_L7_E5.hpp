#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA
#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip>
#include <cstring>


struct NoFila
{
    Ficha dado; //informacao do n�
    NoFila *prox; //proximo elemento da fila
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
struct NoPilha
{
    Ficha dado; //informa��o do n�
    NoPilha *prox; //pr�ximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha()  //Construtor. Inicializa��o da pilha
    {
        topo = nullptr;//obrigat�ria
    }
};

bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
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
bool empilhaP(Pilha *p, Ficha dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo n�
    if (novo == NULL) /// sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado; //armazena a informa��o no n�
    novo->prox = p->topo; //o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o n� criado.

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

//peek
/*int espiaF(Fila* f)
{
    int dado = 0;

    if (vaziaF(f) == false)
    {
        dado = f->inicio->dado;
    }

    return dado;
}
*/
//show
/*void mostraF(Fila *f)
{
    cout << "Fila: ";

    if(vaziaF(f) == false)
    {



        NoFila *no = f->inicio;
        while (no != NULL)
        {
            cout << "[Nome: "<<no->dado.nome<<", Idade: "<<no->dado.idade<<", Tipo: "<<no->dado.tipo<<", Quadro: "<<no->dado.quadro;
            no = no->prox;

            if(no != NULL)
                cout << "]" << endl;
        }
        cout << "," << endl;
    }
    else
        cout << "vazia!\n";
}*/
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


/*bool buscaF(Fila *f, Ficha dado)
{

    NoFila *no = f->inicio;
    while (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;
}
bool buscaP(Pilha *p, Ficha dado)
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == dado.codigo)
            return true;

        no = no->prox;
    }

    return false;
}*/

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

#endif // _HPP_FILA_DINAMICA
#endif

