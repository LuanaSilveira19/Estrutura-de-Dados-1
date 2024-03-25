#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

#include "pilha_L2_E4.hpp"
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int op = -1;

    Pilha p1;
    int tamPilha, valor, cont=0;

    srand(time(NULL));

    do
    {
        system("cls");
        cout << "-------------MENU------------" << endl;
        cout << "------- 0 Sair.         -----" << endl;
        cout << "------- 1 Criar pilha   -----" << endl;
        cout << "------- 2 Inserir       -----" << endl;
        cout << "------- 3 Remover       -----" << endl;
        cout << "------- 4 Consultar     -----" << endl;
        cout << "------- 5 Mostrar       -----" << endl;
        cout << "-----------------------------" << endl;
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
            cout << "Informe o tamanho da pilha: ";
            cin >> tamPilha;
            if(verificaInicializacaoP(&p1))
                destroiP(&p1);

            inicializaP(&p1, tamPilha);
            cout<<"Pilha inicializada com sucesso!"<<endl;
            cont++;

            system("pause");
            break;
        case 2:
            system("cls");
            if(cont!=0)
            {
                if(cheiaP(&p1) == true)
                {

                    cout << "A pilha está cheia!\n";

                }
                else{
                cout << "Informe o valor para a pilha: ";
                cin >> valor;
                if(buscaP(&p1, valor) == true)
                {
                    cout<<"Esse valor ja existe na pilha"<<endl;
                }
                else
                empilhaP(&p1, valor);
                }
            }
            else
                cout<<"ERRO, PRIMEIRO CRIE A PILHA!"<<endl;

            system("pause");
            break;
        case 3:
            system("cls");
            if(cont!=0)
            {
                if(vaziaP(&p1) == false)
                {
                    valor = desempilhaP(&p1);
                    cout << "O valor desempilhado é " << valor << endl;
                }
                else
                    cout << "Não foi possivel desempilhar, a pilha está vazia!\n";
            }
            else
                cout<<"ERRO, PRIMEIRO CRIE A PILHA!"<<endl;
            system("pause");
            break;
        case 4:
            system("cls");
            if(cont!=0)
            {
                cout << "Informe um valor para buscar na pilha:";
                cin >> valor;

                if(buscaP(&p1, valor) == true)
                    cout << "O valor " << valor << " foi encontrado na pilha!\n";
                else
                    cout << "O valor " << valor << " NÃO foi encontrado na pilha!\n";
            }

            else
                cout<<"ERRO, PRIMEIRO CRIE A PILHA!"<<endl;


            system("pause");
            break;
        case 5:
            system("cls");
            if(cont!=0)
            {
                if(vaziaP(&p1) == true)
                    cout << "A pilha está vazia!\n";
                else
                    mostraP(&p1);
            }
            else
                cout<<"ERRO, PRIMEIRO CRIE A PILHA!"<<endl;

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
