//pilha e fila com struct
#include <unistd.h>
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;
struct Ficha
{
    string nome;
    int idade;
    string tipo;
    string quadro;

    Ficha()
    {
        nome=" ";
        idade=0;
        tipo=" ";
        quadro=" ";
    }

    Ficha( string n,int i, string t, string q)
    {
        nome=n;
        idade=i;
        tipo=t;
        quadro=q;

    }
};
#include "Vet.hpp"

void idade_quadro(Pilha *p)
{
    int id=1000;
    string nome;

    if(vaziaP(p) == false)
    {

        NoPilha *no = p->topo;

        while (no != NULL)
        {
            if(no->dado.idade <id){
            id=no->dado.idade;
            nome=no->dado.nome;
        }
            no = no->prox;

        }
    }

 cout<<nome<<" com a idade de "<<id<< "ano(s) possui a menor idade com o quadro clínico grave."<<endl;

}
void concatenaF(Fila *f1, Fila *f2)
{

    Fila concat;
    Fila aux;

    Ficha valor;//altera pro tipo da struct
    while(!vaziaF(f1))
    {
        valor=desenfileiraF(f1);
        enfileiraF(&concat,valor);
        enfileiraF(&aux,valor);
    }
    while(!vaziaF(&aux))
    {
        enfileiraF(f1,desenfileiraF(&aux));
    }
    while(!vaziaF(f2))
    {
        valor=desenfileiraF(f2);
        enfileiraF(&concat,valor);
        enfileiraF(&aux,valor);
    }
    while(!vaziaF(&aux))
    {
        enfileiraF(f2,desenfileiraF(&aux));
    }
    mostraF(&concat);

}
int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha;
    Pilha ANIMALS, ANIMALD;
    Fila P, N;
    Ficha ficha,  aux;
    string nome, tipo, quadro;
    int cont=0, dom=0, id;
    float tot=0, grav=0;


    ifstream arq ("clinica.txt");

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "CADASTRO")
        {
            strBuffer >> nome;
            strBuffer >> id;
            strBuffer >> tipo;
            strBuffer >> quadro;
            ficha.nome=nome;
            ficha.idade=id;
            ficha.tipo=tipo;
            ficha.quadro=quadro;
             if(ficha.quadro=="G")
            {
                tot++;
                grav++;
                enfileiraF(&P,ficha);
                cout<<"Animal add a fila P!"<<endl;
            }

            else if(ficha.quadro=="E")
            {
                tot++;
                enfileiraF(&N,ficha);
                cout<<"Animal add a fila N!"<<endl;
            }
            if(ficha.tipo=="D")
                dom++;



        }
        else if(op == "ATENDER")
        {
            if(!vaziaF(&P) && cont<3)
            {
                cont++;
                aux=desenfileiraF(&P);
                if(aux.tipo=="S")
                {
                    empilhaP(&ANIMALS, aux);
                }
                else if(aux.tipo=="D")
                {
                    empilhaP(&ANIMALD, aux);
                }

            }else if(cont==3 && !vaziaF(&N))
            {
                cont=0;
                aux=desenfileiraF(&N);
                if(aux.tipo=="S"|| aux.tipo=="s")
                {
                    empilhaP(&ANIMALS, aux);
                }
                else if(aux.tipo=="D"||aux.tipo=="d")
                {
                    empilhaP(&ANIMALD, aux);
                }
            }
            else if(vaziaF(&N))
            {
                aux=desenfileiraF(&P);
                if(aux.tipo=="S"|| aux.tipo=="s")
                {
                    empilhaP(&ANIMALS, aux);
                }
                else if(aux.tipo=="D"||aux.tipo=="d")
                {
                    empilhaP(&ANIMALD, aux);
                }
            }
            cout<<"Animal atendido!"<<endl;
            cout<<endl;
        }
        else if(op == "MOSTRAR")
        {
             cout<<"Fila P:"<<endl;
            mostraF(&P);
            cout<<endl;
            cout<<"Fila N:"<<endl;
            mostraF(&N);
            cout<<endl;


        }else if(op == "INFORMACAO")
        {


            cout<<"Total de fichas: "<<tot<<", Porcentagem de animais com quadro grave: "<< (grav/tot)*100 <<"%, ";
            cout<<"Total de animais domesticos: "<<dom<<endl;
            cout<<endl;

        }
        else if(op == "ATENDIDA")
        {
            cout<<"Pilha ANIMALS:"<<endl;
            mostraP(&ANIMALS);
            cout<<endl;
            cout<<"Pilha ANIMALD:"<<endl;
            mostraP(&ANIMALD);
            cout<<endl;
        }else if(op == "REMOVER")
        {
             strBuffer >> nome;
              if(nome=="ANIMALS")
            {
                desempilhaP(&ANIMALS);
                cout<<"Paciente removido da pilha SELVAGEM!"<<endl;
            }
            else if(nome=="ANIMALD")
            {
                desempilhaP(&ANIMALD);
                cout<<"Paciente removido da pilha DOMESTICO!"<<endl;
            }
        }
        else if(op == "ANIMAL")
        {
                cout<<"Domestico:";
                idade_quadro(&ANIMALD);
                cout<<endl;
                cout<<"Selvagem:";
                idade_quadro(&ANIMALS);
                                cout<<endl;
        }
         else if(op == "CONCATENA")
        {
            cout<<"Concatenação:";
             concatenaF(&P,&N);
                cout<<endl;
        }


        usleep(10000);

    }

    return 0;
}

