#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR



struct No
{
    Veiculo dado;
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
std::ostream& operator<<(std::ostream& os, const Veiculo &v)
{
    /// cout << n
    return os << "[" << v.placa << ", " << v.ano << ", " <<  v.marca << ", " <<  v.modelo << "]";
}
ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n
    return os << n->dado;
}


/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, Lista &l)//sobrecarga de operador
{
    No *n = l.inicio;
    os << "Veiculos:{";
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

    cout << "L:{";
    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
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
bool insereInicioL(Lista *lista, Veiculo valor)
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
bool insereFimL(Lista *lista, Veiculo valor)
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



void removeAno(Lista *lista, string valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    while(atual)
    {
        if(atual->dado.marca == valor && atual->dado.ano >2000)
        {
            if(anterior)
                anterior->prox= atual->prox;
            else
                lista->inicio= atual->prox;
        }
        else
            anterior=atual;
        atual=atual->prox;
    }

}
bool removeL(Lista *lista, string valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual && atual->dado.placa != valor)
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

bool buscaL(Lista *lista, string valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.placa == valor)
            return true;

        n = n->prox;
    }

    return false;

}
bool buscaLF(Lista *lista, string valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.marca == valor)
            return true;

        n = n->prox;
    }

    return false;

}
void ordemAlfabetica(Lista *lista)
{

    Veiculo aux;
    bool trocou=true;
    while(trocou)
    {
        trocou=false;
        No *n= lista->inicio;
        while(n!=NULL)
        {
            if(n && n->prox)
            {
                if(n->dado.modelo > n->prox->dado.modelo)
                {
                    aux= n->dado;
                    n->dado= n->prox->dado;
                    n->prox->dado= aux;
                    trocou=true;
                }
            }
            n=n->prox;
        }
    }

}

void ordemCresc(Lista *lista)
{

    Veiculo aux;
    bool trocou=true;
    while(trocou)
    {
        trocou=false;
        No *n= lista->inicio;
        while(n!=NULL)
        {
            if(n && n->prox)
            {
                if(n->dado.ano > n->prox->dado.ano)
                {
                    aux= n->dado;
                    n->dado= n->prox->dado;
                    n->prox->dado= aux;
                    trocou=true;
                }
            }
            n=n->prox;
        }
    }

}

#endif // _HPP_LISTA_DESCRITOR


