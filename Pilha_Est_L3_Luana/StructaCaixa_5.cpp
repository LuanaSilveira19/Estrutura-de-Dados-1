#include <iostream>
using namespace std;
struct Caixa
{
    int codigo;
    float peso;

    Caixa()
    {
        codigo=0;
        peso=0;
    }

    Caixa(int c, float p)
    {
        codigo=c;
        peso=p;
    }
};

#include "pilha_L3_E5.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1, aux;
    Caixa cx;
    int qtd, op=-1, cont=0, a;
    do
    {
        system("cls");
        cout << "----------------------MENU-----------------" << endl;
        cout << "------- 0 Sair.                       -----" << endl;
        cout << "------- 1 Definir quantidade de caixa -----" << endl;
        cout << "------- 2 Carregar caixa              -----" << endl;
        cout << "------- 3 Descarregar caixa           -----" << endl;
        cout << "------- 4 Mostar carga                -----" << endl;
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
            cout<<"Informe a quantidade de caixas: ";
            cin>>qtd;
            inicializaP(&p1, qtd);
            cont++;
            break;
        case 2:
            system("cls");
            if(cont>0)
            {
                for(int i=0; i<qtd; i++)
                {
                    cout<<"Informe o código da caixa "<< i+1<<": ";//ver uma forma do código não repetir
                    cin>>cx.codigo;

                    cout<<"Informe o peso da caixa "<< i+1<<": ";
                    cin>>cx.peso;

                    empilhaP(&p1, Caixa(cx.codigo, cx.peso));

                }

            }
            else
                cout<<"Primeiro defina a quantidade das caixas!"<<endl;

            system("pause");
            break;
        case 3:
            system("cls");
            if(cont>0)
            {

                desempilhaP(&p1);

                cout<<"Caixa removida com sucesso!"<<endl;

            }
            else
                cout<<"Primeiro defina a quantidade das caixas!"<<endl;

            system("pause");
            break;
        case 4:
            system("cls");
            if(cont>0)
                mostraP(&p1);
            else
                cout<<"Primeiro defina a quantidade das caixas!"<<endl;
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
