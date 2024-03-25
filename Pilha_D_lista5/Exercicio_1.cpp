#include <iostream>
#include <cstring>
using namespace std;
struct Cadastro
{
    string nome;
    int codigo;
    int idade;
    float saldo;

    Cadastro()
    {//é um construtor para atributos dados
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
//struct tem que ser antes ou dentro do hpp

#include "pilha_D_L5_E1.hpp"

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

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    Cadastro cad;
    int op=-1, cont=0;
    do
    {
        system("cls");
        cout << "------------------BAN PASSO-----------------" << endl;
        cout << "------- 0 Sair.                       -----" << endl;
        cout << "------- 1 Cadastrar clientes          -----" << endl;
        cout << "------- 2 Mostrar clientes            -----" << endl;
        cout << "-------------------------------------------" << endl;
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
            do
            {
                cout<<"Informe o código do cliente:";
                cin>>cad.codigo;

                if(buscaP(&p1,Cadastro (cad.nome, cad.codigo, cad.idade, cad.saldo)))
                    cout<<"Ja existe cliente cadastrado com esse código!"<<endl;;

            }while(buscaP(&p1,Cadastro (cad.nome, cad.codigo, cad.idade, cad.saldo)));

            cout<<"Informe o nome do cliente:";
            cin>>cad.nome;
            fflush(stdin);

            cout<<"Informe a idade do cliente:";
            cin>>cad.idade;

            cout<<"Informe o saldo do cliente:";
            cin>>cad.saldo;
             insere_ordenado(&p1,Cadastro (cad.nome, cad.codigo, cad.idade, cad.saldo));

           // empilhaP(&p1, Cadastro(cad.nome, cad.codigo, cad.idade, cad.saldo));

            cont++;

            system("pause");
            break;
        case 2:
            system("cls");
            mostraP(&p1);

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
