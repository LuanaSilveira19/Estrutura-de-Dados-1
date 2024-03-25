#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impressão da pilha
#include <cstring>

struct NoPilha
{
    Cadastro dado; //informação do nó
    NoPilha *prox; //próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha()  //Construtor. Inicialização da pilha
    {
        topo = nullptr;//obrigatória
    }
};


bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
bool empilhaP(Pilha *p, Cadastro dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo nó
    if (novo == NULL) /// sistema não conseguiu alocar a memória
        return false;

    novo->dado = dado; //armazena a informação no nó
    novo->prox = p->topo; //o próximo elemento do nó criado será o último elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o nó criado.

    return true;
}

Cadastro desempilhaP(Pilha *p)
{
    Cadastro dado;

    // se não estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no nó do topo
        NoPilha *apagar = p->topo; //guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o próximo elemento;

        delete apagar;  /// libera a memória
    }

    return dado;
}


void mostraP(Pilha *p)
{


    cout << "Clientes: " << endl;
    if(vaziaP(p) == false)
    {

        NoPilha *no = p->topo;

        while (no != NULL)
        {

            cout << setfill(' ') << std::setw(0) <<"|"<< no->dado.nome << ", código " <<no->dado.codigo<< ", idade ";//ver se os dados estao certos
            cout << setfill(' ') << std::setw(0) << no->dado.idade << ", saldo " <<no->dado.saldo<<"|"<<endl;
            cout << "--------------------------------------------" << endl;

            no = no->prox;

        }
    }
}

bool buscaP(Pilha *p, Cadastro dado)//vai ser
{

    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo == dado.codigo)
            return true;

        no = no->prox;
    }

    return false;
}

void destroiP(Pilha *p)
{
    Cadastro dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}

#endif // _HPP_PILHA_DINAMICA






