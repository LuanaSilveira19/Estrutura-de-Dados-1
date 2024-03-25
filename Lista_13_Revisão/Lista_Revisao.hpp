#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR



struct No
{
    int dado;
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
    }
};

struct Lista
{
    //descrtores s�o informa��es da propria lista
    No *inicio;
    No *fim;
    int tamanho;
    //se ttrabalhar com minimos e max podem ser usads como descritor
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};


/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n
    return os << n->dado;
}

/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, Lista &l)//sobrecarga de operador
{
    No *n = l.inicio;
    os << "L:{";
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    os << "}";
    return os;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    if(n == NULL)
        cout <<"VAZIA"<<endl;
    else
    {
        cout << "{";
        while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
        {
            cout << n->dado;
            n = n->prox;

            if(n != NULL)
                cout << ", ";
        }
        cout << "}\n";
    }
}

void destroiL(Lista *lista)
{
    No *n = lista->inicio;
    while(n != nullptr)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}


bool vaziaL(Lista *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no in�cio da lista
bool insereInicioL(Lista *lista, int valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}
bool insereFimL(Lista *lista, int valor)
{

    No *novo = new No();//aloca mem�ria (cria a caixinha com o ponteiro)
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    if(vaziaL(lista))
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}

bool removeL(Lista *lista, int valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endere�o do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual � NULL >> n�o encontrou
        return false;
    if (!anterior) /// se anterior � igual a NULL
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado �ltimo da lista
            lista->fim = anterior;
    }
    /// libera a mem�ria do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

bool buscaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return true;

        n = n->prox;
    }

    return false;
}

void ordemCresc(Lista *lista)
{
    if(!vaziaL(lista))
    {
        for(No *i= lista->inicio; i->prox !=NULL; i= i->prox)
        {
            No *menor= i;
            for(No *j= i->prox; j!=NULL; j= j->prox)
            {
                if(j->dado< menor->dado)
                    menor=j;
            }
            int aux= i->dado;
            i->dado= menor->dado;
            menor->dado= aux;
        }
        //mostraL(lista);
    }
    else
    {
        cout<<"Lista vazia!"<<endl;
    }

}
void ordemDCresc(Lista *lista)
{
    if(!vaziaL(lista))
    {
        for(No *i= lista->inicio; i->prox !=NULL; i= i->prox)
        {
            No *menor= i;
            for(No *j= i->prox; j!=NULL; j= j->prox)
            {
                if(j->dado> menor->dado)
                    menor=j;
            }
            int aux= i->dado;
            i->dado= menor->dado;
            menor->dado= aux;
        }
        //  mostraL(lista);
    }
    else
    {
        cout<<"Lista vazia!"<<endl;
    }

}
void ordemCresc_Decresc_Copia(Lista *lista, string letra)//fazer cresc e desc juntos
{
    Lista aux = Lista();
    No *n= lista->inicio;
    while(n)
    {
        insereFimL(&aux,n->dado);
        n=n->prox;
    }

    if(letra=="C")
    {
        ordemCresc(&aux);
        mostraL(&aux);
    }
    else if(letra=="D")
    {
        ordemDCresc(&aux);
        mostraL(&aux);
    }

}
void mostraDif(Lista *L1, Lista *L2)
{
    Lista aux = Lista();
    No *n= L1->inicio;
    int inf;
    while(n)
    {
        if(!buscaL(L2,n->dado))  //fun��o tipo a intersec��o
        {
            inf=n->dado;
            insereFimL(&aux,inf);
        }

        n = n->prox;
    }

    ordemCresc(&aux);
    mostraL(&aux);


}

float mediana(Lista *lista)
{

    ordemCresc(lista);
    No *n=lista->inicio;

    if(lista->tamanho %2!=0)
    {
        int cont=0;
        while(cont!=(lista->tamanho)/2)
        {

            n=n->prox;
            cont++;
        }
        return n->dado;
    }
    else
    {
        int cont=0;
        float anterior;
        while(cont!=(lista->tamanho)/2)
        {

            anterior=n->dado;
            n=n->prox;
            cont++;
        }
        return (anterior+ n->dado)/2;
    }
}

int buscaModaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    int cont=0;
    while (n)
    {
        if (n->dado == valor)
            cont++;

        n = n->prox;
    }

    return cont;
}
void moda(Lista *lista){

     No *n = lista->inicio;
       Lista aux = Lista();
     while(n){
        if(buscaModaL(lista,n->dado)>1)
            if(!buscaL(&aux,n->dado))
            insereFimL(&aux,n->dado);
        n=n->prox;
     }
     mostraL(&aux);

}



#endif // _HPP_LISTA_DESCRITO


