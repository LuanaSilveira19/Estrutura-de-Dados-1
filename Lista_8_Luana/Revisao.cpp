#include <unistd.h>
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;//não esquecer, pode ocorrer erro no arquivo

struct Cadastro
{
    string nome;
    int codigo;
    int idade;
    float saldo;

    Cadastro()
    {
        nome=" ";
        codigo=0;
        idade=0;
        saldo=0;
    }

    Cadastro( string n,int c, int i, float s)
    {
        nome=n;
        codigo=c;
        idade=i;
        saldo=s;

    }
};

#include "pilha_filaD_revisao.hpp"
void insere_ordenado(Pilha *p, Cadastro f)
{
    Pilha aux;
    while(!vaziaP(p) && p->topo->dado.nome < f.nome)
    {
       Cadastro x= desempilhaP(p);
       empilhaP(&aux, x);
    }
    empilhaP(p,f);
    while(!vaziaP(&aux))
    {
       Cadastro x= desempilhaP(&aux);
       empilhaP(p, x);
    }
}
void insere_fila(Pilha *p1, Fila *P,Fila *N, Fila *D, Cadastro dado, int cod)
{
    NoPilha *no = p1->topo;
    while (no != NULL)
    {
        if(!vaziaP(p1) && no->dado.codigo==cod)
        {
            if(no->dado.idade>60)
            {
                if(!buscaF(P,cod))
                {
                    enfileiraF(P,cod);
                    cout<<no->dado.nome<< "(cod "<<no->dado.codigo<<") foi adicionado na fila P."<<endl;
                }
                else
                    cout<<"ERRO: "<<no->dado.nome <<" já está na fila aguardando atendimento."<<endl;
            }
            else if(no->dado.idade<60 && no->dado.saldo>0)
            {
                if(!buscaF(N,cod))
                {
                    enfileiraF(N,cod);
                    cout<<no->dado.nome<< "(cod "<<no->dado.codigo<<") foi adicionado na fila N."<<endl;
                }
                else
                    cout<<"ERRO: "<<no->dado.nome <<" já está na fila aguardando atendimento."<<endl;
            }
            else if(no->dado.idade<60 && no->dado.saldo<=0)
            {
                if(!buscaF(D,cod))
                {
                    enfileiraF(D,cod);
                    cout<<no->dado.nome<< "(cod "<<no->dado.codigo<<") foi adicionado na fila D."<<endl;
                }
                else
                    cout<<"ERRO: "<<no->dado.nome <<" já está na fila aguardando atendimento."<<endl;
            }
        }

        no = no->prox;
    }

}

void dados_cliente(Pilha *p)
{
      NoPilha *no = p->topo;
     int tam=0, sN=0;
     float soma=0, saldoM=0;
    while (no != NULL)
    {
        if(no->dado.saldo<0)
            sN++;
        if(no->dado.saldo)
            soma+=no->dado.saldo;
        tam++;
        no = no->prox;
    }
saldoM=soma/tam;
cout<<"Total de clientes: "<<tam<<"; Clientes com saldo negativo:"<<sN<<";\n";
cout<<"Saldo médio:"<<saldoM<<"; Soma dos saldos="<<soma<<endl;
}

void deposito(Pilha *p, int cod, float valor){
    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo==cod)
        {
            no->dado.saldo+= valor;
              cout<<no->dado.nome <<" depositou R$ "<<valor<<endl;
        }

        no = no->prox;
    }

}
void saque(Pilha *p, int cod, float valor){
    NoPilha *no = p->topo;
    while (no != NULL)
    {
        if(no->dado.codigo==cod)
        {
            no->dado.saldo-= valor;
            cout<<no->dado.nome <<" sacou R$ "<<valor<<endl;
        }

        no = no->prox;
    }

}


int main()
{
    cout << fixed;
   cout.precision(2);
    setlocale(LC_ALL, "portuguese");
    Pilha p1;
    Fila P, N, D;
    Cadastro reg;
    int cod, id;
    float valor;
    string nome, tipo;


    stringstream strBuffer;
    string op, linha;
    ifstream arq ("entrada.txt");

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }


    while(!arq.eof())
    {
        float limite=0;
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

         if(vaziaF(&P)&& vaziaF(&N)&& vaziaF(&D))
                cout<<"ERRO: não há clientes nas filas"<<endl;
        if(op == "ATENDENDERCLIENTE")
        {
            int x;
            float a;
            strBuffer >> tipo;
            strBuffer >> valor;
            a=saldoTotal(&p1);
            limite=(a*0.8);
            if(!vaziaF(&P))
            {
                x=desenfileiraF(&P);
                if(tipo=="D")
                    deposito(&p1,x,valor);
                if(tipo=="S")
                {
                    if(valor<=limite)
                        saque(&p1,x,valor);
                    else{
                         cout<<"Erro: Não foi possível realizar o saque do valor informado."<<endl;
                        cout<<"O limite atual de saque é de R$ "<<limite<<endl;
                    }

                }

            }else if(!vaziaF(&N))
            {
                 x=desenfileiraF(&N);
                if(tipo=="D")
                    deposito(&p1,x,valor);
                if(tipo=="S")
                {

                    if(valor<=limite)
                        saque(&p1,x,valor);
                    else{
                         cout<<"Erro: Não foi possível realizar o saque do valor informado."<<endl;
                        cout<<"O limite atual de saque é de R$ "<<limite<<endl;
                    }
                }

            }else  if(!vaziaF(&D)){
                 x=desenfileiraF(&D);
                if(tipo=="D")
                    deposito(&p1,x,valor);
                if(tipo=="S")
                {

                    if(valor<=limite)
                        saque(&p1,x,valor);
                    else{
                         cout<<"Erro: Não foi possível realizar o saque do valor informado."<<endl;
                        cout<<"O limite atual de saque é de R$ "<<limite<<endl;
                    }


                }
            }



        }
        else if(op == "CADASTRAR")
        {

            bool igual=false;

            strBuffer >>cod;
            reg.codigo=cod;

            if(buscaP(&p1,reg))
            {
                cout<<"Erro: já existe um cliente com o código "<<cod<<" cadastrado"<<endl;
                igual=true;

            }
            else if(igual==false)
            {
                strBuffer >>nome;
                strBuffer >>id;
                strBuffer >>valor;
                reg.idade=id, reg.nome=nome, reg.saldo=valor;
                insere_ordenado(&p1,reg);

                cout<<nome<<" (cod "<<cod<<") foi empilhado"<<endl;

            }
        }
        else if(op == "ADDFILA")
        {
            strBuffer >>cod;
            reg.codigo=cod;
            if(!buscaP(&p1,reg))
                cout<<"Erro: Cliente inexistente"<<endl;
            else
            insere_fila(&p1, &P,&N,&D, reg,cod);
        }
        else if(op == "MOSTRAR")
        {
            strBuffer >> tipo;
            if(tipo=="P")
                mostraP(&p1);
            if(tipo=="F")
            {
                cout<<"Fila P: ";
                mostraF(&P);
                cout<<"Fila N: ";
                mostraF(&N);
                cout<<"Fila D: ";
                mostraF(&D);
            }


        }
         else if(op == "DADOSBANCO")
        {
            dados_cliente(&p1);
        }

        usleep(10000);

    }


    return 0;
}











