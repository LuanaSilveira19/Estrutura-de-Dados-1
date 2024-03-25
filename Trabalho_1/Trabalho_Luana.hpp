#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA


struct NoFila
{
    Cadastro dado; //informacao do n�
    NoFila *prox; //proximo elemento da fila
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila(){ //Construtor. Usado para inicializar os dados das vari�veis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};


bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(Fila *f, Cadastro dado)
{
    NoFila *novo = new NoFila();//cria a "caixinha" com o dado e o n�
    if (novo == NULL) /// n�o conseguiu alocar mem�ria (novo == NULL)
        return false;

    novo->dado = dado;//recebe o endere�o onde o dado esta
    novo->prox = nullptr;
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

//Dequeue
Cadastro desenfileiraF(Fila *f)
{
    Cadastro dado;

    // se n�o estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila n�o est� vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro n�
        NoFila *apagar = f->inicio; //guarda o primeiro n�(endere�o) em uma vari�vel auxiliar;
        f->inicio = f->inicio->prox; // atualiza o in�cio da fila
        delete apagar;  // libera a mem�ria

        if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
Cadastro espiaF(Fila* f)
{
   Cadastro dado;

    if (vaziaF(f) == false) //verifica se a fila n�o est� vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado;
}

//show


void mostraF(Fila *f)
{

    if(vaziaF(f) == false)
    {


        cout << "{";
        NoFila *no = f->inicio;
        while (no != NULL)
        {
            cout << "["<<no->dado.nome<<", s=: "<<no->dado.sexo<<", t= "<<no->dado.tipo<<", q= "<<no->dado.quantidade;
            no = no->prox;

            if(no != NULL)
                cout << "],";
        }
        cout << "]}"<<endl;
    }
    else
        cout << "vazia!\n";
}
bool buscaF(Fila *f, Cadastro dado)
{

    NoFila *no = f->inicio;
    while (no != NULL) //fa�a enquanto (no != NULL)
    {
        if(no->dado.nome == dado.nome)
            return true;

        no = no->prox;
    }

    return false;
}

void destroiF(Fila *f)
{

    NoFila *no = f->inicio;
    while (no != NULL) //fa�a enquanto (no != NULL)
    {
        NoFila *apagar = no; //guarda o n� em uma vari�vel auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif // _HPP_FILA_DINAMICA

