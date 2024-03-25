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
    string sexo;
    string cidade;
    string placa;

    Ficha()
    {
        nome=" ";
        idade=0;
        sexo=" ";
        cidade=" ";
        placa=" ";
    }

    Ficha( string n,int i, string s, string c, string p)
    {
        nome=n;
        idade=i;
        sexo=s;
        cidade=c;
        placa=p;

    }
};
#include "Carro.hpp"
using namespace std;
void inverte(Pilha *p){

    Pilha aux;
    Ficha dado;
    while(!vaziaP(p))
    {
        dado=desempilhaP(p);
        empilhaP(&aux,dado);
    }
    mostraP(&aux);

    while(!vaziaP(&aux))
    {
        dado=desempilhaP(&aux);
        empilhaP(p,dado);
    }
    //destroiP(&aux);
}
void inf_geral(Pilha *p, Ficha f){
    int num_M=0, num_F=0;
    float id=0,cont=0;

    Pilha aux;
      while(!vaziaP(p))
    {
         f=desempilhaP(p);
       if(f.sexo=="M")
        num_M++;
       if(f.sexo=="F")
        num_F++;
       id+=f.idade;
       cont++;
      empilhaP(&aux,f);
    }

    cout<<"Numero de mulheres: "<<num_F<<", Numero de homens: "<<num_M<<", Média idades: "<<id/cont<<"%"<<endl;
  while(!vaziaP(&aux))
    {
         f=desempilhaP(&aux);

      empilhaP(p,f);
    }
}
void velho(Pilha *p, Ficha f){
    int id=0;
    string nome, placa;
    Pilha aux;
      while(!vaziaP(p))
    {
         f=desempilhaP(p);
       if(f.idade>id){
         id=f.idade;
         nome=f.nome;
         placa=f.placa;
       }

      empilhaP(&aux,f);
    }
    cout<<"Nome: "<<nome<<", Idade: "<<id<<", Placa: "<<placa<<endl;
  while(!vaziaP(&aux))
    {
         f=desempilhaP(&aux);

      empilhaP(p,f);
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    cout << fixed;
   cout.precision(2);
    Pilha PILHAPF, PILHAGERAL;
    Ficha ficha;
    stringstream strBuffer;
    string op, linha;
    string nome, sexo, cidade, placa;
    int id;


    ifstream arq ("veiculo.txt");

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

        if(op == "INFORMAR")
        {

            strBuffer >> nome;
            strBuffer >> id;
            strBuffer >> sexo;
            strBuffer >> cidade;
            strBuffer >> placa;
            ficha.nome=nome;
            ficha.idade=id;
            ficha.sexo=sexo;
            ficha.cidade=cidade;
            ficha.placa=placa;
            if(ficha.cidade=="PassoFundo")
            {
                empilhaP(&PILHAPF,ficha);
                cout<<"Cliente colocado na pilha PASSO FUNDO!"<<endl;
            }

            else
            {
                empilhaP(&PILHAGERAL,ficha);
                cout<<"Cliente colocado na pilha GERAL!"<<endl;
            }


        }else if(op == "MOSTRAR")
        {
            cout<<"Pilha PF:"<<endl;
            mostraP(&PILHAPF);
            cout<<endl;
            cout<<"Pilha GR:"<<endl;
            mostraP(&PILHAGERAL);
            cout<<endl;
        }else if(op == "PILHAPF"){
             cout<<"Pilha PF invertida:"<<endl;
            inverte(&PILHAPF);
            cout<<endl;
        }else if(op == "PILHAGERAL"){
                cout<<"Dados da pilha geral:"<<endl;
                inf_geral(&PILHAGERAL,ficha);
                cout<<endl;
        }else if(op == "PLACA"){
                 cout<<"Pessoa mais vela da PILHAGERAL: ";
                velho(&PILHAGERAL,ficha);
              cout<<"Pessoa mais vela da PILHAPF: ";
                velho(&PILHAPF,ficha);
        }



        usleep(10000);

    }

    return 0;
}
