//nome, idade, sexo, cidade e placa do veículo
#include <iostream>
#include <cstring>
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
#include "filaD_L7_E5.hpp"

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
    int num_M=0, num_F=0, id=0,cont=0;
    float media=0;
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
    media=id/cont;
    cout<<"Numero de mulheres: "<<num_F<<", Numero de homens: "<<num_M<<", Média idades: "<<media<<"%"<<endl;
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
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha PILHAPF, PILHAGERAL;
    Fila P, N;
    Ficha ficha;
    string nome;
    int op=-1;
    do
    {
        system("cls");
        cout << "-------------------------VEICULOS----------------------------" << endl;
        cout << "------- 0 Sair.                                         -----" << endl;
        cout << "------- 1 Criar ficha de atendimento                    -----" << endl;
        cout << "------- 2 Mostrar os dados das fichas                   -----" << endl;
        cout << "------- 3 Listar as fichas da pilha PILHAPF na ordem    -----" << endl;
        cout << "------- 4 Mostrar informações da pilha PILHAGERAL       -----" << endl;
        cout << "------- 5 Mostrar informações pessoa mais velha         -----" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Sua escolha: ";
        cin >> op;
        fflush(stdin);
        switch(op)
        {
        case 0:
            system("cls");
            cout << "Programa finalizado!";
            getchar();
            break;

        case 1:
            system("cls");
            cout<<"Informe o nome do cliente:";
            cin>>ficha.nome;
            fflush(stdin);

            cout<<"Informe a idade do cliente:";
            cin>>ficha.idade;

            cout<<"Informe o sexo(M ou F) do cliente:";
            cin>>ficha.sexo;
            fflush(stdin);

            cout<<"Informe a cidade do cliente:";
            getline(cin,ficha.cidade);
            fflush(stdin);

            cout<<"Informe a placa do veiculo do cliente:";
            cin>>ficha.placa;
            fflush(stdin);

            if(ficha.cidade=="Passo Fundo")
            {
                empilhaP(&PILHAPF,ficha);
                cout<<"Cliente colocado na pilha PASSO FUNDO!"<<endl;
            }

            else
            {
                empilhaP(&PILHAGERAL,ficha);
                cout<<"Cliente colocado na pilha GERAL!"<<endl;
            }
            system("pause");
            break;
        case 2:
            system("cls");

            cout<<"Pilha PF:"<<endl;
            mostraP(&PILHAPF);

            cout<<"Pilha GR:"<<endl;
            mostraP(&PILHAGERAL);

            system("pause");
            break;
         case 3:
            system("cls");

            cout<<"Pilha PF invertida:"<<endl;
            inverte(&PILHAPF);

            system("pause");
            break;
        case 4:
            system("cls");
                inf_geral(&PILHAGERAL,ficha);
            system("pause");
            break;
         case 5:
            system("cls");
            cout<<"Pessoa mais vela da PILHAGERAL: ";
                velho(&PILHAGERAL,ficha);
              cout<<"Pessoa mais vela da PILHAPF: ";
                velho(&PILHAPF,ficha);
            system("pause");
            break;
        default:
            cout << "Opção inválida!" << endl;
            system("pause");
            break;

        }

    }
    while (op != 0);


}

