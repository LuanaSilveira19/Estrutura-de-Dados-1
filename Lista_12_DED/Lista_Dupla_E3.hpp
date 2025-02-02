#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA


struct No
{
    Pet dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};


/// quando cout receber uma struct No
/*ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n
    return os << n->dado;
}*/

/// quanto cout receber uma struct Lista
/*ostream& operator << (ostream& os, const Lista &l)
{
    No *n = l.inicio;
    os << "L[" << l.tamanho << "]:{";
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    os << "}";
    return os;
}*/

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;
    cout << "{";
    while(n)
    {
        cout <<"[C�digo: "<< n->dado.codigo<<", Nome: "<<n->dado.nome<<", Idade: "<<n->dado.idade<<", Peso:"<<n->dado.peso;
        n = n->prox;
        if(n)
            cout << "] ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


///insere no in�cio da lista
bool insereInicioL(Lista *lista, Pet valor)
{

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo n� ser� adicionado no in�cio da lista, o ponteiro *ant do primeiro n� sempre � nulo
    novo->prox = lista->inicio;

    if (!lista->fim) //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}

No* buscaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.codigo ==valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}
bool busca2L(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.codigo ==valor)
            return true;

        n = n->prox;
    }

    return false;
}

bool removerNoL(Lista *lista, No *no)
{
    //essa fun��o atualiiza os ponteiros e remove o n� da mem�ria
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) /// se anterior � igual a NULL, o elemento a ser exclu�do est� no in�cio da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }else{ /// elemento est� no meio ou no fim

        no->ant->prox = no->prox;
        if (!no->prox)/// se for retirado �ltimo da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    /// libera a mem�ria do elemento
    lista->tamanho--;
    delete(no);
    return true;
}

/*bool removeL(Lista *lista, Pet valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}*/

bool insereFimL(Lista *lista, Pet valor)
{
//insere no final com o anterior
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
//!linha->fim faz a verifica��o opasta
    if (!vaziaL(lista)) //lista vazia?
    {
        lista->fim->prox = novo;
        novo->ant =  lista->fim;
        novo->prox = NULL;
        lista->fim = novo;
    }
    else
    {

        novo->ant = nullptr;
        novo->prox = NULL;
        lista->fim = novo;
        lista->inicio = novo;
    }


    lista->tamanho++;

    return true;
}


#endif // _HPP_LISTA_DUPLA

