#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

//fazer o mesmo para a duplamente encadeada

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

    No *inicio;
    No *fim;
    int tamanho;
    int Min;
    int Max;
    float soma;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
        Min=999999999;
        Max=0;
        soma=0;
    }
};
void mostraL(Lista *lista)
{
    No *n = lista->inicio;

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
    lista->Max=0;
    lista->Min=999999999;
    lista->soma=0;
}

bool vaziaL(Lista *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

bool insereInicioL(Lista *lista, int valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    lista->soma+=novo->dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;

    if(novo->dado > lista->Max )
    {
        lista->Max=novo->dado;
    }
     if(novo->dado< lista->Min)
    {
        lista->Min= novo->dado;
    }


    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}
bool insereFimL(Lista *lista, int valor)
{

    No *novo = new No();//aloca memória (cria a caixinha com o ponteiro)
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    lista->soma+=novo->dado;
    novo->prox = NULL;

    if(novo->dado > lista->Max )
    {
        lista->Max=novo->dado;
    }
   if(novo->dado< lista->Min)
    {
        lista->Min= novo->dado;
    }

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

    lista->soma-=valor;

    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(!atual)
        return false;
    if (!anterior)
    {

        lista->inicio = atual->prox;
        if (!lista->inicio)
            lista->fim = lista->inicio;
    }
    else
    {
        anterior->prox = atual->prox;
        if (!atual->prox)
            lista->fim = anterior;
    }

    No *aux = lista->inicio;

    if(valor == lista->Max)
    {
        lista->Max=0;
        while(aux)
        {
            if(aux->dado != valor && aux->dado > lista->Max)
                lista->Max=aux->dado;

            aux= aux->prox;
        }
    }
    else if(valor == lista->Min)
    {
        lista->Min=999999999;
        while(aux)
        {
            if(aux->dado != valor && aux->dado < lista->Min)
                lista->Min =aux->dado;

            aux= aux->prox;
        }
    }
    lista->tamanho--;

    delete(atual);
    return true;

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
int leInicio(Lista *lista)
{

    int dado=0;
    if(vaziaL(lista)==false)
        dado= lista->inicio->dado;
    return dado;
}

int leFim(Lista *lista)
{

    int dado=0;
    if(vaziaL(lista)==false)
        dado= lista->fim->dado;

    return dado;
}

int removeInicio(Lista *lista)
{

    int dado=0;
    No* aux;
    No *atual = lista->inicio;

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
    if(vaziaL(lista)==false)
    {
        dado = lista->inicio->dado;
        aux = lista->inicio;

        lista->inicio = lista->inicio->prox;
        lista->tamanho--;
        lista->soma-=dado;
        delete aux;
    }
    else if(lista->inicio->prox ==NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
        lista->soma=0;
        lista->Min=999999999;
        lista->Max=0;
    }

    return dado;
}

int removeFim(Lista *lista)
{
       int valor=0;
  if (lista->inicio == nullptr)
        return valor;

    No* atual = lista->inicio;
    No* anterior = nullptr;
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

    // Percorre a lista até o penúltimo nó
    while (atual->prox) {
        anterior = atual;
        atual = atual->prox;
    }
    valor= atual->dado;
    // Libera a memória do último nó
    delete atual;

    // Atualiza os ponteiros
    if (anterior) {
        anterior->prox = nullptr;
        lista->tamanho--;// Atualiza o tamanho da lista
        lista->soma-=valor;
    } else {
        // Se não há penúltimo nó, a lista tinha apenas um nó
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho=0;
        lista->soma=0;
        lista->Min=999999999;
        lista->Max=0;

    }
    return valor;

}

bool inserePosicao(Lista *lista, int pos, int valor){

     No *anterior = NULL;
     No *atual = lista->inicio;
     No *novo = new No();
     int cont=0;

    novo->dado=valor;

    if(novo->dado > lista->Max)
        lista->Max= novo->dado;
    if(novo->dado < lista->Min)
         lista->Min= novo->dado;

    lista->soma+= novo->dado;

    if(pos > lista->tamanho-1) // Inserção no fim
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }else{
         while(cont!=pos)
    {
        anterior = atual;
        atual = atual->prox;
        cont++;
      /*  if(atual->prox==NULL && pos>cont || pos<0)
            return false;*///assim ele não deixa inseir no final
    }
    if (anterior == NULL)
    {
        novo->prox= lista->inicio;
        lista->inicio=novo;

    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox= novo;

    }
    }

    lista->tamanho++;

 return true;
}

void insereOrdenado(Lista *lista, int valor)
{
     No *anterior = NULL;
     No *atual =lista->inicio;
     No *novo = new No();

  novo->dado=valor;

    if(novo->dado > lista->Max)
        lista->Max= novo->dado;
    if(novo->dado < lista->Min)
         lista->Min= novo->dado;

  lista->soma+=novo->dado;

  while(atual!=NULL && atual->dado <= valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL)
    {
        novo->prox=lista->inicio;
        lista->inicio=novo;

    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox= novo;

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
                if(j->dado< menor->dado)
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

void imprimirInversoRecursivo(No* no) {
     if (no) {
        // Chamada recursiva para o próximo nó

        imprimirInversoRecursivo(no->prox);
        cout << no->dado<<",";//tentar tirar a virgula do ultimo elemeno

        if (no->prox) {
            cout << "";
        }
    }

}
void mostrarInversoL(Lista *lista)
{
    cout << "{";
    imprimirInversoRecursivo(lista->inicio);
    cout << "}" <<endl;
}

/*void imprime_rec (Lista *lista)
{
    if (vaziaL(lista))
         return;
    cout<< removeFim(lista)<<",";

   //*lista = (*lista)->prox;

    imprime_rec(lista);

}*/
int removePorPosicao(Lista* lista, int posicao) {

    if (posicao < 0 || posicao > lista->tamanho) {
       // cout << "Posição inválida." <<endl;
        return 0;
    }
    No* atual = lista->inicio;
    No* anterior = nullptr;

    // Encontrar o nó na posição desejada
    for (int i = 0; i < posicao; i++) {
        anterior = atual;
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
    if (anterior != nullptr) {
        anterior->prox = atual->prox;
    } else {
        lista->inicio = atual->prox;
    }

    int dado;
    dado=atual->dado;


    delete atual;
    lista->tamanho--;
    lista->soma-=dado;


      return dado;
}

#endif // _HPP_LISTA_DESCRITOR
