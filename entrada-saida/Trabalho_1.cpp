#include <unistd.h>
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;
struct Cadastro
{
    string nome;
    string sexo;
    string tipo;
    int quantidade;

    Cadastro()
    {
        nome=" ";
        sexo=" ";
        tipo=" ";
        quantidade=0;
    }

    Cadastro( string n,string s, string t, int q)
    {
        nome=n;
        sexo=s;
        tipo=t;
        quantidade=q;

    }
};
#include "Trabalho_Luana.hpp"
int tamanho(Fila *f)
{
    int cont=0;
    NoFila *no = f->inicio;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }

    return cont;
}
int livros(Fila *f)
{
    int cont=0;
    if(vaziaF(f) == false)
    {

        NoFila *no = f->inicio;
        while (no != NULL)
        {
            if(no->dado.tipo=="L")
            {
                cont+=no->dado.quantidade;
            }
            no = no->prox;

        }

    }

    return cont;
}
int roupas(Fila *f)
{
    int cont=0;
    if(vaziaF(f) == false)
    {

        NoFila *no = f->inicio;
        while (no != NULL)
        {
            if(no->dado.tipo=="R")
            {
                cont+=no->dado.quantidade;
            }
            no = no->prox;

        }

    }

    return cont;
}
int masculino(Fila *f)
{
    int cont=0;
    if(vaziaF(f) == false)
    {

        NoFila *no = f->inicio;
        while (no != NULL)
        {
            if(no->dado.sexo=="M")
            {
                cont++;
            }
            no = no->prox;

        }

    }

    return cont;
}
/*void mostrar_ord(Fila *f){

Fila aux, aux2;
//Cadastro A;
bool add=false;

  NoFila *no = f->inicio;
while(no != NULL)){


     no = no->prox;

}


}*/
void ordenaF(Fila *f, Cadastro dado)
{

    Fila aux, aux2, aux3;
    Cadastro B;

   if(vaziaF(f) == false)
    {
        NoFila *no = f->inicio;
        while (no != NULL)
        {
            B=no->dado;
            //cout <<no->dado.nome<<", s=: "<<no->dado.sexo<<", t= "<<no->dado.tipo<<", q=: "<<no->dado.quantidade;
            no = no->prox;
            enfileiraF(&aux3,B);
        }

    }

    while(!vaziaF(f))
    {
        NoFila *no = f->inicio;
        Cadastro menor = f->inicio->dado;
        while (no != NULL)
        {
            // mostraF(f);
            if(menor.quantidade > no->dado.quantidade)
            {
                menor.quantidade=no->dado.quantidade;
                menor.nome=no->dado.nome;
                  menor.sexo=no->dado.sexo;
                   menor.tipo=no->dado.tipo;
            }
            no = no->prox;
        }
        enfileiraF(&aux, menor);

        while(!vaziaF(f))
        {
            Cadastro x= desenfileiraF(f);
            if(x.quantidade!=menor.quantidade)
                enfileiraF(&aux2, x);//pega a lista sem o menor
        }

        while(!vaziaF(&aux2))
        {
            Cadastro x= desenfileiraF(&aux2);
            enfileiraF(f, x);
        }


    }

    mostraF(&aux);//voltar ao normal

 while(!vaziaF(&aux3))
    {
        enfileiraF(f,desenfileiraF(&aux3));

    }
}
void menor(Fila *f1, Fila *f2, Cadastro dado)
{

    int menor=10000000000;
    string nome;
    string sexo;

    if(!vaziaF(f1))
    {
        NoFila *no = f1->inicio;
        while (no != NULL)
        {
            if(no->dado.sexo == dado.sexo)
            {
                if(menor>no->dado.quantidade)
                {
                    nome=no->dado.nome;
                    sexo=no->dado.sexo;
                    menor=no->dado.quantidade;
                }

            }
            no = no->prox;
        }

    }
    if(!vaziaF(f2))
    {
        NoFila *no = f2->inicio;
        while (no != NULL)
        {
            if(no->dado.sexo == dado.sexo)
            {
                if(menor>no->dado.quantidade)
                {
                    nome=no->dado.nome;
                    sexo=no->dado.sexo;
                    menor=no->dado.quantidade;
                }

            }
            no = no->prox;
        }

    }
    if(vaziaF(f1) && vaziaF(f2))
    {
        cout<<"As filas estão vazias!"<<endl;
    }
    else
        cout<<nome<<" sexo("<<sexo<<") possui a menor quantidade de itens ("<<menor<<")"<<endl;

}
int main()
{
    setlocale(LC_ALL, "portuguese");
    //  cout << fixed;
    // cout.precision(2);

    Fila f1, f2;
    Cadastro cad;
    stringstream strBuffer;
    string op, linha;
    string nome, sexo, tipo;
    int quant;
  string R="F1";
    ifstream arq ("entrada2.txt");

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

        if(op == "ADDFILA")
        {
            bool igual=false;
            int dif_1= (tamanho(&f1)- tamanho(&f2));
            int dif_2= (tamanho(&f2)- tamanho(&f1));
            strBuffer >> nome;
            cad.nome=nome;

            if(buscaF(&f1,cad))
            {
                cout<<"Erro: já existe uma pessoa com esse nome!!"<<endl;
                igual=true;

            }
            else if(igual==false)
            {
                strBuffer >> sexo;
                strBuffer >> tipo;
                strBuffer >> quant;

                cad.sexo=sexo;
                cad.tipo=tipo;
                cad.quantidade=quant;

                if(cad.quantidade>10 && dif_1<3 )//ajustar
                {
                    enfileiraF(&f1,cad);
                    cout<<cad.nome<<" (qtd="<<cad.quantidade<<") foi adicionado na fila F1."<<endl;
                }
                else if(dif_2>=3)
                {
                    enfileiraF(&f1,cad);
                    cout<<cad.nome<<" (qtd="<<cad.quantidade<<") foi adicionado na fila F1."<<endl;
                }
                else if(cad.quantidade>0)
                {
                    enfileiraF(&f2,cad);
                    cout<<cad.nome<<" (qtd="<<cad.quantidade<<") foi adicionado na fila F2."<<endl;
                }
                else
                 {
                     cout<<"Quantidade de itens inferior a 1 unidade!"<<endl;
                 }
            }

        }
        else if(op == "MOSTRAFILAS")
        {
            cout<<"Fila F1: ";
            mostraF(&f1);
            cout<<endl;
            cout<<"Fila F2: ";
            mostraF(&f2);
            cout<<endl;

        }
        else if(op == "MOSTRADADOSFILAS")
        {
            float  tam= tamanho(&f1)+ tamanho(&f2);
            int livr= livros(&f1)+ livros(&f2);
            int roup= roupas(&f1)+ roupas(&f2);
            float masc= masculino(&f1) + masculino(&f2);
            //(grav/tot)*100
            cout<<"Quantidade de pessoas: "<< tam<<"; Percentual do sexo M: "<<(masc/tam)*100 <<"%; ";
            cout<<"Quantidade de livros: "<< livr<<"; Quantidade de roupas: "<<roup<<endl;

        }
        else if(op == "MOSTRAMENORQTD")
        {
            strBuffer >> sexo;
            cad.sexo=sexo;
            menor(&f1,&f2, cad);
        }
        else if(op == "MOSTRAFILAORD")
        {
              string tip;
             strBuffer >> tip;

             if(tip=="F1")
             {
                  cout<<"Fila F1 ordenado:";
                 ordenaF(&f1,cad);
             }
             if(tip=="F2")
             {
                 cout<<"Fila F2 ordenado:";
                 ordenaF(&f2,cad);
             }

        }
        else if(op == "REMOVEFILA")
        {
            Cadastro A;


            if(R=="F1")
            {
                if(!vaziaF(&f1))
                {
                A=desenfileiraF(&f1);
                cout<<A.nome<<" foi atendido na fila F1"<<endl;
                R="F2";

                }else
                {
                   R="F2";
                }

            }
            else if(R=="F2")
            {
                if(!vaziaF(&f2))
                {
                    A=desenfileiraF(&f2);
                    cout<<A.nome<<" foi atendido na fila F2"<<endl;
                    R="F1";
                }else{
                    R="F1";
                }

            }
            else if(vaziaF(&f1)&& vaziaF(&f2))
            {
                cout<<"As filas estão vazias!"<<endl;
            }
        }

        usleep(10000);

    }

    return 0;
}

