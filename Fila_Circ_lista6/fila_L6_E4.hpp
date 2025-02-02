#ifndef _HPP_FILA
#define _HPP_FILA

#include <iomanip> //biblioteca usada para formatar a impress�o da fila

struct Fila
{
    int tam; //tamanho do vetor de dados
    int total; //total de elementos armazenados na fila
    int inicio; //ponteiro para o elemento armazenado no inicio da fila
    int fim; //ponteiro para o fim da fila (posi��o do vetor onde ser� armazenado o pr�ximo elemento)
    Impressao *dados;//ponteiro para o vetor que ser� alocado para armazenar os dados

    Fila() //Construtor. Usado para inicializar os dados das vari�veis da struct
    {
        tam =0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};

void inicializaF(Fila *f, int tam) /// inicializa��o da fila
{
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new Impressao[tam];/// aloca mem�ria para vetor
}

bool verificaInicializacaoF(Fila *f) //verifica de a fila foi inicializada
{
    if(f->dados != NULL)
        return true;
    else
        return false;
}

void destroiF(Fila *f)
{
    f->fim = 0;
    f->inicio = 0;
    f->total = 0;
    f->tam = 0;

    if(verificaInicializacaoF(f) == true)
    {
        delete[] (f->dados);
        f->dados = nullptr;
    }
}


bool vaziaF(Fila *f)// fila vazia
{
    if (f->total == 0)
        return true;
    else
        return false;
}

bool cheiaF(Fila *f)// fila cheia
{
    if (f->total == f->tam)
        return true;
    else
        return false;
}

//Enqueue
bool enfileiraF(Fila *f, Impressao valor) /// incluir valor na fila
{
    if (verificaInicializacaoF(f)==false || cheiaF(f) == true) // retorna false se a fila n�o foi inicializada ou se cheia
        return false;

    //inserir no final da fila
    f->dados[f->fim] = valor;

    //incrementa a quantidade de elementos armazenados na fila
    f->total++;

    //avan�a o ponteiro fim
    f->fim++;

    if(f->fim>=f->tam)
        f->fim = 0; //circular

    return true;
}
/*bool buscaF(Fila *f, Impressao valor)
{
    while (f->dados!= NULL)
    {
        if(f->dados[f->inicio].nome == valor.nome)
            return true;
    f->inicio++;
     if(f->inicio>=f->tam)
       f->inicio = 0;
    }
        return false;
}*/


Impressao desenfileiraF(Fila *f)  //retirar da fila
{
    Impressao valor;

    if (vaziaF(f) == true) // retorna 0 se fila vazia
        return valor;

    //remover do inicio da fila
    valor = f->dados[f->inicio];

    //diminui a quantidade de elementos armazenados na fila
    f->total--;

    //avan�a o ponteiro in�cio
    f->inicio++;

    if(f->inicio>=f->tam)
        f->inicio = 0; //circular

    return valor;
}
bool buscaF(Fila *f, string nome, int tam)
{
    Fila aux;
    inicializaF(&aux,tam);
    Impressao doc;
    bool encontrou=false;
    if(vaziaF(f)==true)//retorna 0 se fila vazia
        return false;
    while(vaziaF(f)==false)
    {
        //desenfilera F para a vari�vel doc
        doc=desenfileiraF(f);

        if(doc.nome==nome)
            encontrou=true;
        enfileiraF(&aux,doc);
        //e enfilera o doc em aux
    }
    while(vaziaF(&aux)==false)
    {
        doc=desenfileiraF(&aux);
        enfileiraF(f,doc);
    }


    return encontrou;

}
//Peek
Impressao espiaF(Fila *f) ///peek
{
    Impressao  valor;

    if(vaziaF(f)==true)// retorna 0 se fila vazia
        return valor;

    valor = f->dados[f->inicio];
    return valor;
}

void mostraF(Fila *f)
{
    // cout << "\nFila{TAM = " << f->tam << ", TOTAL = " <<  f->total << "} -> ";

    if (vaziaF(f) == false)
    {
        int idx = f->inicio;

        for(int i = 0; i < f->total; i++)
        {
            cout<<f->dados[idx].nome;

            if(i < f->total-1)
                cout << ", ";

            idx++;
            if(idx >= f->tam)
                idx=0; //circular
        }
        cout << "\n";
    }
    else
        cout << "Fila vazia\n";
}

#endif // _HPP_FILA
