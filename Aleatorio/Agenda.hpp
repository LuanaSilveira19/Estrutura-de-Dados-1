#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA


struct No
{
    Agenda dado;
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
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado.nome<<", "<<n->dado.telefone<<", "<<n->dado.data_nc;
        n = n->prox;

        if(n != NULL)
            cout << "| ";
    }
    cout << "}\n";
}

//insere no início da lista
bool insereInicioL(No **lista, Agenda valor)
{

    No *novo = new No(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
    /* *lista  referencia do primeiro nó*/
    return true;
}

//retorna o valor do primeiro elemento da lista SEM removê-lo
Agenda leInicioL(No **lista)
{
    Agenda dado;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
Agenda removeInicioL(No **lista)
{
    No* aux;
    Agenda dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado
        aux = *lista; //pega a referenccia do primeiro nó, o qual será removido

        *lista = (*lista)->prox; //atualiza o início da lista para o próximo elemento

        delete aux;
    }

    return dado;
}

///remover um nó da lista com um valor específico
bool removeL(No **lista, Agenda valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual!=NULL && atual->dado.nome != valor.nome)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endereço do elemento para excluir
    if(atual == NULL) /// se atual é NULL -> não encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a memória do elemento
    delete(atual);
    return true;
}


bool buscaL(No **lista, string valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if (n->dado.nome == valor)
            return true;

        n = n->prox;
    }

    return false;
}

int totalElementos(No **lista)
{
    No *n=*lista;
    int tot=0;
    while(n)
    {

        tot++;
        n=n->prox;
    }
    return tot;
}


void inserenoFinalL(No **lista, Agenda valor)
{

    No *novo = new No(); // aloca memória para o nó
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
    else
        cout<<"Erro ao alocar memória!"<<endl;
}

Agenda leFinalL(No **lista)
{

    No *n=*lista;
    Agenda dado;
    if(vaziaL(lista) == false)
    {
        while(n)
        {
            if(n->prox==NULL)
                dado = n->dado;
            n=n->prox;
        }
    }

    return dado;
}

Agenda removeFinalL(No **lista)
{
    No* aux;
    No* ant;
    Agenda dado;

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

void insereOrdenado(No **lista, Agenda valor)
{
     No *anterior = NULL;
     No *atual = *lista;
     No *novo = new No();

  novo->dado=valor;
  while(atual!=NULL && atual->dado.nome <= valor.nome)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL)
    {
        novo->prox=*lista;
        *lista=novo;

    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox= novo;

    }

}


#endif // _HPP_LISTA_DINAMICA

