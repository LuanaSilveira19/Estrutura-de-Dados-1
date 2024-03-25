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
    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

//insere no in�cio da lista
bool insereInicioL(No **lista, int valor)
{

    No *novo = new No(); // aloca mem�ria para o n�
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
    /* *lista  referencia do primeiro n�*/
    return true;
}

//retorna o valor do primeiro elemento da lista SEM remov�-lo
int leInicioL(No **lista)
{
    int dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado

    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
int removeInicioL(No **lista)
{
    No* aux;
    int dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado
        aux = *lista; //pega a referenccia do primeiro n�, o qual ser� removido

        *lista = (*lista)->prox; //atualiza o in�cio da lista para o pr�ximo elemento

        delete aux;
    }

    return dado;
}

///remover um n� da lista com um valor espec�fico
bool removeL(No **lista, int valor)
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

bool igualdadeL(No **L1, No **L2)
{

    No *n1=*L1;
    No *n2=*L2;
    int cont=0;

    if(totalElementos(L1)!= totalElementos(L2))
        return false;
    else
    {
        while(n1&&n2)
        {
            if(n1->dado==n2->dado)
                cont++;

            n1=n1->prox;
            n2=n2->prox;
        }
        if(cont==totalElementos(L1))
            return true;
        else
            return false;
    }
}
void inserenoFinalL(No **lista, int valor)
{

    No *novo = new No(); // aloca mem�ria para o n�
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
        cout<<"Erro ao alocar mem�ria!"<<endl;
}

int leFinalL(No **lista)
{

    No *n=*lista;
    int dado =0;
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

int lePosicao(No **lista, int pos)
{
    No *n=*lista;
    int valor=0;
    int cont=0;

    while(cont!=pos)
    {
        cont++;
        n=n->prox;
    }
    valor=n->dado;
    return valor;


}

 void uniaoListas(No **L1,No **L2,No **L3){
    No *n1=*L1;
    No *n2=*L2;


    while(!vaziaL(&n1)){
           inserenoFinalL(L3, removeInicioL(&n1));
    }
     while(!vaziaL(&n2)){
           inserenoFinalL(L3,removeInicioL(&n2));
    }

    cout<<"Uni�o das listas: ";
    mostraL(L3);

 }



#endif // _HPP_LISTA_DINAMICA
