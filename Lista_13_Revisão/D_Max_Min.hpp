#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA

struct No
{
    int dado;
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
    int Min;
    int Max;
    float soma;
    int indiceMaior;
    int indiceMenor;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;;
        Min=999999999;
        Max=0;
        soma=0;
        indiceMaior=0;
        indiceMenor=0;
    }
};

void destroiL(Lista *lista)
{
    No *n = lista->inicio;
    while(n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    lista->Max=0;
    lista->Min=999999999;
    lista->soma=0;
    lista->indiceMaior=0;
    lista->indiceMenor=0;
}

bool vaziaL(Lista *lista)
{
    if(!(lista->inicio) )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;
    int cont=0;
    cout << "{";
    while(n)
    {
        cout << n->dado;
         if(n->dado==lista->Max)
            lista->indiceMaior=cont;
        if(n->dado==lista->Min)
            lista->indiceMenor=cont;

            cont++;

        n = n->prox;


        if(n)
            cout << ", ";

    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}

bool insereInicioL(Lista *lista, int valor)
{

    No *novo = new No();
    if (!novo)
        return false;
    novo->dado = valor;
    novo->ant = nullptr; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->prox = lista->inicio;
    lista->soma+= novo->dado;

    if(novo->dado > lista->Max )
    {
        lista->Max=novo->dado;
    }
     if(novo->dado< lista->Min)
    {
        lista->Min= novo->dado;
    }

    if (!lista->fim) //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}
int removeInicio(Lista *lista)
{
    No *aux;
    No *atual= lista->inicio;
    if(lista->inicio->dado== lista->Max)
    {
        lista->Max=0;
        while(atual)
        {
            if(atual->dado != lista->inicio->dado && atual->dado > lista->Max)
                lista->Max= atual->dado;
            atual= atual->prox;
        }
    }
     if(lista->inicio->dado== lista->Min)
    {
        lista->Min=999999999;
        while(atual)
        {
            if(atual->dado != lista->inicio->dado && atual->dado < lista->Min)
                lista->Min= atual->dado;
            atual= atual->prox;
        }
    }

    int dado=0;
    if(vaziaL(lista))
        return dado;
//ver onde que ele verifica se tem um elemento só
    aux = lista->inicio;
    if(aux->prox != nullptr)
        aux->prox->ant= nullptr;
    else
        lista->fim=nullptr;


    lista->inicio = aux->prox;
    lista->tamanho--;
    dado = aux->dado;
    lista->soma-=dado;
    delete aux;

    return dado;
}

bool insereFimL(Lista *lista, int valor)
{
//insere no final com o anterior
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    lista->soma+=novo->dado;

    if(novo->dado > lista->Max )
    {
        lista->Max=novo->dado;
    }
     if(novo->dado< lista->Min)
    {
        lista->Min= novo->dado;
    }
//!linha->fim faz a verificação opasta
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
int removeUltimo(Lista *lista)
{

    No  * atual  = lista->fim ;
    int dado=0;

    if(vaziaL(lista))
        return dado;

    No* aux = lista->inicio;

    if(lista->fim->dado== lista->Max)
    {
        lista->Max=0;
        while(aux)
        {
            if(aux->dado != lista->fim->dado && aux->dado > lista->Max)
                lista->Max= aux->dado;
            aux= aux->prox;
        }
    }
    if(lista->fim->dado== lista->Min)
    {
        lista->Min=999999999;
        while(aux)
        {
            if(aux->dado != lista->fim->dado && aux->dado < lista->Min)
                lista->Min= aux->dado;
            aux= aux->prox;
        }
    }

    if(lista->tamanho==1)
    {
        dado=atual->dado;
        lista->fim=nullptr;
        lista->inicio=nullptr;
        lista->tamanho=0;
        lista->soma=0;
        lista->Max=0;
        lista->Min=999999999;
    }
    else
    {
        dado=atual->dado;
        lista->fim= atual->ant ;
        lista->fim->prox =NULL ;
        lista->tamanho-- ;
        lista->soma-=dado;
    }


    delete atual;
    return dado;
}

No* buscaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool removerNoL(Lista *lista, No *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) /// se anterior é igual a NULL, o elemento a ser excluído está no início da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }
    else   /// elemento está no meio ou no fim
    {

        no->ant->prox = no->prox;
        if (!no->prox)/// se for retirado último da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    /// libera a memória do elemento
    lista->tamanho--;
    delete(no);
    return true;
}

bool removeL(Lista *lista, int valor)//remove o elemento informado
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    No* aux = lista->inicio;

    if(valor == lista->Max)
    {
        lista->Max=0;
        while(aux)
        {
            if(aux->dado != valor && aux->dado > lista->Max)
                lista->Max= aux->dado;
            aux= aux->prox;
        }
    }
    if(valor == lista->Min)
    {
        lista->Min=999999999;
        while(aux)
        {
            if(aux->dado != valor && aux->dado < lista->Min)
                lista->Min= aux->dado;
            aux= aux->prox;
        }
    }
    lista->soma-=valor;
    removerNoL(lista, no);

    return true;
}

bool insereMeio(Lista *lista, int pos, int valor)
{
    No* anterior = nullptr;
    No* atual = lista->inicio;
    No* novo = new No();
    int cont = 0;

     novo->dado = valor;

     lista->soma+=novo->dado;

    if(novo->dado > lista->Max )
    {
        lista->Max=novo->dado;
    }
    if(novo->dado< lista->Min)
    {
        lista->Min= novo->dado;
    }
    if(pos > lista->tamanho-1) // Inserção no fim
    {
        lista->fim->prox = novo;
        novo->ant =  lista->fim;
        novo->prox = NULL;
        lista->fim = novo;

    }
    else
    {
        while (cont != pos)
        {
            anterior = atual;
            atual = atual->prox;
            cont++;
           /* if (atual == nullptr && pos > cont || pos < 0)
                return false;*///aqui ele não deixa inserir no final
        }

        if (anterior == nullptr)
        {
            // Inserção no início
            novo->prox = lista->inicio;
            novo->ant = nullptr;
            if (lista->inicio != nullptr)
            {
                lista->inicio->ant = novo;
            }
            lista->inicio = novo;
        }
        else
        {
            // Inserção no meio
            novo->prox = atual;
            novo->ant = anterior;
            anterior->prox = novo;
            if (atual != nullptr)
            {
                atual->ant = novo;
            }
        }

    }


    lista->tamanho++;
    return true;
}
int removePorPosicao(Lista* lista, int posicao) {

    if (posicao < 1 || posicao > lista->tamanho) {
       // cout << "Posição inválida." <<endl;
        return 0;
    }

    No* atual = lista->inicio;

    // Encontrar o nó na posição desejada
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }

     No* aux = lista->inicio;
     if(atual->dado== lista->Max)
    {
        lista->Max=0;
        while(aux)
        {
            if(aux->dado != atual->dado && aux->dado > lista->Max)
                lista->Max= aux->dado;
            aux= aux->prox;
        }
    }
    if(atual->dado== lista->Min)
    {
        lista->Min=999999999;
        while(aux)
        {
            if(aux->dado != atual->dado && aux->dado < lista->Min)
                lista->Min= aux->dado;
            aux= aux->prox;
        }
    }



    // Remover o nó
    if (atual->ant) {
        atual->ant->prox = atual->prox;
    } else {
        lista->inicio = atual->prox;
        if (lista->inicio) {
            lista->inicio->ant = nullptr;
        }
    }

    if (atual->prox) {
        atual->prox->ant = atual->ant;
    } else {
        lista->fim = atual->ant;
        if (lista->fim) {
            lista->fim->prox = nullptr;
        }
    }

    int dado;
    dado=atual->dado;
    delete atual;
    lista->tamanho--;
    lista->soma-=dado;


      return dado;
}
void insereOrdenado(Lista *lista, int valor)
{
     No* novo = new No();
     novo->dado=valor;

    if (novo->dado > lista->Max)
        lista->Max = novo->dado;
    if (novo->dado < lista->Min)
        lista->Min = novo->dado;

    lista->soma += novo->dado;

    No* anterior = nullptr;
    No* atual = lista->inicio;

    while (atual != nullptr && atual->dado >= valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == nullptr) {
        // Inserção no início da lista
        novo->prox = lista->inicio;
        novo->ant = nullptr;

        if (lista->inicio != nullptr) {
            lista->inicio->ant = novo;
        } else {
            // Se a lista estava vazia, atualiza o fim
            lista->fim = novo;
        }

        lista->inicio = novo;
    } else {
        // Inserção no meio ou no final da lista
        novo->prox = anterior->prox;
        novo->ant = anterior;

        if (anterior->prox != nullptr) {
            anterior->prox->ant = novo;
        } else {
            // Se estamos inserindo no final da lista, atualiza o fim
            lista->fim = novo;
        }

        anterior->prox = novo;
    }

    lista->tamanho++;

}
void ordenarL(Lista *lista)
{

    if(!vaziaL(lista))
    {
        for(No *i=lista->inicio; i->prox !=NULL; i= i->prox)
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

    }
    else
    {
        cout<<"Lista vazia!"<<endl;
    }

}


#endif // _HPP_LISTA_DUPLA

