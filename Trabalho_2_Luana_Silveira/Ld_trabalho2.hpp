#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA

struct No
{
    char dado;
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
        tamanho =0;;

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
    cout << "[" << lista->tamanho << "]:{";
    if(n == NULL)
        cout <<"VAZIA";
    else
    {
        while(n)
        {
            cout << n->dado;

            n = n->prox;


            if(n)
                cout << "";

        }
    }

    cout << "}\n";
}
void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "[" << lista->tamanho << "]:{";
    if(n == NULL)
        cout <<"VAZIA";
    else
    {
        while(n)
        {
            cout << n->dado;
            n = n->ant;

            if(n)
                cout << "";
        }
    }

    cout << "}" << endl;
}


bool insereFimL(Lista *lista, char valor)
{
//insere no final com o anterior
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;

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
char removeInicio(Lista *lista)
{
    No *aux;
    No *atual= lista->inicio;

    char dado;
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

    delete aux;

    return dado;
}

int qtdInsere(Lista *lista, char valor, char pos)
{
    int repete=0;
    No* aux = lista->inicio;

    while(aux)
    {
        if(aux->dado==pos)
            repete++;
        aux=aux->prox;
    }

    return repete;
}

bool insereClone(Lista *lista, char valor, char pos){


    Lista aux = Lista();
    No *n= lista->inicio;


    while(n)
    {
       // inf= n->dado;
        if(n->dado == pos){
            insereFimL(&aux,n->dado);
             insereFimL(&aux,valor);
        }else{
               insereFimL(&aux,n->dado);
        }
        n = n->prox;
    }

    destroiL(lista);

    No *n2= aux.inicio;
    while(n2){
         insereFimL(lista,n2->dado);
        n2=n2->prox;

    }


}

void contarOcorrencia(Lista *L1,Lista *L2){

    No *n1= L1->inicio;
    No *n2= L2->inicio;




}
#endif // _HPP_LISTA_DUPLA


