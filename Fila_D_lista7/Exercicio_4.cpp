//pilha e fila com struct
#include <iostream>
#include <cstring>
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
#include "filaD_L7_E4.hpp"

int grave(Fila *f, Ficha dado)
{
 int grave=0;
  NoFila *no = f->inicio;
    while (no != NULL)
    {
         if(no->dado.quadro == "G" || no->dado.quadro == "g")
                grave++;
        no = no->prox;
    }

return grave;
}

int domestico(Fila *f, Ficha dado)
{
 int dom=0;
  NoFila *no = f->inicio;
    while (no != NULL)
    {
         if(no->dado.tipo == "D" || no->dado.tipo == "d")
                dom++;
        no = no->prox;
    }

return dom;
}

int total(Fila *f)
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
void idade_quadro(Fila *f)
{
    int id=1000;
    string nome;
  NoFila *no = f->inicio;
    while (no != NULL)
    {
        if(no->dado.idade <id){
            id=no->dado.idade;
            nome=no->dado.nome;
        }

        no = no->prox;
    }

 cout<<nome<<" com a idade de "<<id<< "ano(s) possui a menor idade com o quadro clínico grave."<<endl;

}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha ANIMALS, ANIMALD;
    Fila P, N;
    Ficha ficha,  aux;
    string nome;
    int op=-1, cont=0, tot=0, grav=0, dom=0;
    do
    {
        system("cls");
        cout << "------------------VETERENÁRIA-----------------" << endl;
        cout << "------- 0 Sair.                          -----" << endl;
        cout << "------- 1 Ficha de atendimento           -----" << endl;
        cout << "------- 2 Atender ficha da fila          -----" << endl;
        cout << "------- 3 Mostrar clientes               -----" << endl;
        cout << "------- 4 Listar as inf sobre as filas   -----" << endl;
        cout << "------- 5 Listar as fichas já atendidas  -----" << endl;
        cout << "------- 6 Remover uma ficha da pilha     -----" << endl;
        cout << "------- 7 Menor idade e quadro grave     -----" << endl;
        cout << "----------------------------------------------" << endl;
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
            cout<<"Informe o nome do animal:";
            cin>>ficha.nome;
            fflush(stdin);

            cout<<"Informe a idade do animal:";
            cin>>ficha.idade;

            cout<<"Informe o tipo do animal (S-selvagem, D-domestico):";
            cin>>ficha.tipo;
            fflush(stdin);

            cout<<"Informe o quadro do animal(E-estavel, G-grave):";
            cin>>ficha.quadro;
            fflush(stdin);

            if(ficha.quadro=="G" || ficha.quadro=="g")
            {
                enfileiraF(&P,ficha);
                cout<<"Animal add a fila P!"<<endl;
            }

            else if(ficha.quadro=="E" || ficha.quadro=="e")
            {
                enfileiraF(&N,ficha);
                cout<<"Animal add a fila N!"<<endl;
            }


            system("pause");
            break;
        case 2:
            system("cls");//não executou bem
            if(!vaziaF(&P) && !vaziaF(&N) && cont<4)
            {
                cont++;
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
            else if(cont==3 && !vaziaF(&N))
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
            else if(vaziaF(&N))  //ver se precisa mais de um else if na op 2
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


            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"Fila P:";
            mostraF(&P);
            cout<<"Fila N:";
            mostraF(&N);
            system("pause");
            break;
        case 4:
            {
            system("cls");
            float por=0;
            tot=total(&P)+ total(&N);//tava dando erro
            grav=grave(&P, ficha);
            dom= domestico(&P, ficha)+ domestico(&N, ficha);
            por=((grav /tot)*100);
            cout<<"Total de fichas: "<<tot<<", Porcentagem de animais com quadro grave: "<< por <<"%, ";
            cout<<"Total de animais domesticos: "<<dom<<endl;
            system("pause");
            break;
            }
        case 5:
            system("cls");
            cout<<"Pilha ANIMALS:";
            mostraP(&ANIMALS);
            cout<<"Pilha ANIMALD:";
            mostraP(&ANIMALD);

            system("pause");
            break;
        case 6:
            system("cls");
            cout<<"Informe o nome da pilha para remover (ANIMALS ou ANIMALD):";
            cin>>nome;
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

            system("pause");
            break;

 case 7:
            system("cls");

            idade_quadro(&P);

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

