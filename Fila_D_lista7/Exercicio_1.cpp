#include <iostream>
using namespace std;

#include "filaD_L7_E1.hpp"

void inverter(Fila *f)
{
    //2 laços, um pra vver enquanto a fila não estiver vazia passa pra pilha, e o inverso também
    Pilha p1;
    int dado;

    while(vaziaF(f)==false)
    {
        dado=desenfileiraF(f);
        empilhaP(&p1,dado);
    }
    while(vaziaP(&p1)==false)
    {
        dado=desempilhaP(&p1);
        enfileiraF(f,dado);
    }
      mostraF(f);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Fila f1;

    int valor, i=0;
    int op=-1;
    do
    {
        system("cls");
        cout << "-------------------------------------------" << endl;;
        cout << "------- 0 Sair.                       -----" << endl;
        cout << "------- 1 Incluir na fila             -----" << endl;
        cout << "------- 2 Remover da fila             -----" << endl;
        cout << "------- 3 Mostrar fila                -----" << endl;
        cout << "------- 4 Inverter fila               -----" << endl;
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
            while(i<5)
            {
                cout<<"Informe o "<<i+1<<"º valor da fila: ";
                cin>>valor;
                enfileiraF(&f1, valor);
                i++;
            }


            system("pause");
            break;
        case 2:
            system("cls");
            valor=desenfileiraF(&f1);
            cout<<"O valor "<< valor <<" foi removido da fila!"<<endl;

            system("pause");
            break;
        case 3:
            system("cls");

            mostraF(&f1);
            system("pause");
            break;
        case 4:
            system("cls");
            inverter(&f1);

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

