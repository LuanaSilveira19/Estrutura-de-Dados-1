#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA


struct No
{
    int dado;
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
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";

}
int totalL(No **lista)
{
    No *n = *lista;
    int t;

    while(n != NULL )
    {
        t++;
        n = n->prox;

    }
    return t;

}
bool igualL(No **lista1, No **lista2)
{
    No *n1= *lista1;
    No *n2 = *lista2;
    int tot=0;
    while(n1 != NULL && n1 != NULL)
    {
        if(n1->dado != n2->dado)
        {
           return false;
        }
        n1 = n1->prox;
        n2 = n2->prox;
    }
   /* if(totalL(lista1)!=totalL(lista2))  //só funciona se as listas sao do mesmo tamanho
        return false;
    else*/
        return n1 == NULL && n1 == NULL;


}

void insereFinalL(No **lista, int valor)
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
    else
        cout<<"Erro ao alocar memória!"<<endl;
    // cout<<"ok"<<endl;
}
//insere no início da lista
bool insereInicioL(No **lista, int valor)
{

    No *novo = new No(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//retorna o valor do primeiro elemento da lista SEM removê-lo
int leInicioL(No **lista)
{
    int dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

int leFinalL(No **lista)
{
    int dado =0;
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
int removeInicioL(No **lista)
{
    No* aux;
    int dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado
        aux = *lista; //pega a referenccia do primeiro nó, o qual será removido

        *lista = (*lista)->prox; //atualiza o início da lista para o próximo elemento

        delete aux;
    }

    return dado;
}

int removeFinalL(No **lista)
{
    No* aux;
    No* ant;
    int dado=0;

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

///remover um nó da lista com um valor específico
bool removeL(No **lista, int valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
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


No* buscaL(No **lista, int valor)
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
int lePosicao(No **lista, int posicao)
{
    int dado;
    int cont=0;
     No *n = *lista;
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        if(cont==posicao)
        dado= n->dado;
        n = n->prox;
        cont++;

    }
    return dado;
}
void uniao(No **lista1, No **lista2, No **listaSaida)
{
    int valor;
    No *n = *lista1;
    No *n2 = *lista2;
    while(n!=NULL)
    {
        valor= n->dado;
        insereInicioL(listaSaida,valor);
        n=n->prox;
    }
    while(n2!=NULL)
    {
        valor= n2->dado;
        insereInicioL(listaSaida,valor);
        n2=n2->prox;
    }
    cout<<"União das listas:";
    mostraL(listaSaida);
}


#endif // _HPP_LISTA_DINAMICA
