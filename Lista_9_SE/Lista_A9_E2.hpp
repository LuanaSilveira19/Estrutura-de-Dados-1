#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA


struct No
{
    string dado;
    struct No *prox;
};


void inicializaL(No **lista)
{
    *lista = NULL;
}

bool vaziaL(No **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n != NULL)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(No **lista)
{
    No *n = *lista;

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

void insereFinalL(No **lista, string  valor)
{
    No *novo = new No();
    No *aux = new No();

    if(novo)
    {
        novo->dado = valor;
        novo->prox = NULL;

        if(*lista==NULL)
            *lista = novo;
        else
        {
            aux=*lista;
            while(aux->prox)
                aux=aux->prox;

            aux->prox=novo;
        }

    }
    /*else
        cout<<"Erro ao alocar mem�ria!"<<endl;*/

}
//insere no in�cio da lista
bool insereInicioL(No **lista, string  valor)
{

    No *novo = new No(); // aloca mem�ria para o n�
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//retorna o valor do primeiro elemento da lista SEM remov�-lo
string leInicioL(No **lista)
{
    string  dado;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado

    return dado;
}

string leFinalL(No **lista)
{
    string  dado;
    No *aux = new No();
    if(vaziaL(lista) == false)
    {
        aux=*lista;
        while(aux->prox)
            aux=aux->prox;
        dado = aux->dado;

    }


    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
string  removeInicioL(No **lista)
{
    No* aux;
    string dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado
        aux = *lista; //pega a referenccia do primeiro n�, o qual ser� removido

        *lista = (*lista)->prox; //atualiza o in�cio da lista para o pr�ximo elemento

        delete aux;
    }

    return dado;
}

string removeFinalL(No **lista)
{
    No* aux;
    No* ant;
    string  dado;

    aux = *lista;
    ant = NULL;
    if(vaziaL(lista) == false)
    {
        while(aux->prox)
        {
            ant=aux;
            aux=aux->prox;
        }

       dado= aux->dado;
       if(ant)
           ant->prox = NULL;
       else
           *lista = NULL;


       delete aux;
    }
    return dado;

}

///remover um n� da lista com um valor espec�fico
bool removeL(No **lista, string valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endere�o do elemento para excluir
    if(atual == NULL) /// se atual � NULL -> n�o encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        *lista = atual->prox;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a mem�ria do elemento
    delete(atual);
    return true;
}


No* buscaL(No **lista, string valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return NULL;
}
string lePosicao(No **lista, int posicao)
{
    string  dado;
    int cont=0;
     No *n = *lista;
    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
    {
        if(cont==posicao)
        dado= n->dado;
        n = n->prox;
        cont++;

    }
    return dado;
}



#endif // _HPP_LISTA_DINAMICA
