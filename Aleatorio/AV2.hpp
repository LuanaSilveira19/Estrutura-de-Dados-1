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

//insere no início da lista
bool insereInicioL(No **lista, int valor)
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
int leInicioL(No **lista)
{
    int dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

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


bool buscaL(No **lista, int valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
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

    cout<<"União das listas: ";
    mostraL(L3);

 }
void inverte(No **lista)
{
    No *aux;
    No *n = *lista;

    inicializaL(&aux);
    while(!vaziaL(&n))
    {
        inserenoFinalL(&aux,removeFinalL(&n));
    }
    cout<<"Invertida:";
    mostraL(&aux);
}
bool trocaPosicao(int k, No **L, int v) //modifica o valor do k-ésimo elemento da lista para v.
{

    if(k<0 || k>totalElementos(L))
        return false;

    No *anterior=NULL;
    No *atual=*L;
    int cont=0;
    while(cont!=k)
    {
        anterior=atual;
        atual=atual->prox;
        cont++;
    }
    if(atual==NULL)
        return false;
    else
        atual->dado=v;

    return true;


}
void banir(No **L, int valor) //elimina todas as ocorrências do elemento v da lista L.
{
    No *atual=*L;
    while(atual)
    {
        if(atual->dado==valor)
            removeL(L,atual->dado);

        atual=atual->prox;
    }
    mostraL(L);
}


#endif // _HPP_LISTA_DINAMICA

