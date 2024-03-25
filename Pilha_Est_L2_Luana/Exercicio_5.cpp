#include <iostream>
using namespace std;

#include "pilha_L2_E5.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha_1 p;
    Pilha_Par p2;
    Pilha_Impar p3;
    int num, tamPilha, op=-1, contP, contI;
    bool a=true;
    do
    {
        system("cls");
        cout << "--------------------MENU---------------" << endl;
        cout << "------- 0 Sair.                   -----" << endl;
        cout << "------- 1 Criar pilha             -----" << endl;
        cout << "------- 2 Mostrar pilha principal -----" << endl;
        cout << "------- 3 Remover                 -----" << endl;
        cout << "------- 4 Mostrar pares e impares -----" << endl;
        cout << "------- 5 ZERAR                   -----" << endl;//ver se o zerar é destruir
        cout << "---------------------------------------" << endl;
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
            cout<<"Informe o tamanho da pilha:";
            cin>>tamPilha;
            inicializaP(&p, tamPilha);

            if(tamPilha<7 && tamPilha >-1)
            {
                for(int i=0; i<tamPilha; i++)
                {
                    cout<<"Insira o "<<i+1<<"º número para a pilha:";
                    cin>>num;
                    if(num%2==0)
                        contP++;
                    else
                        contI++;
                    empilhaP(&p, num);
                }
            }
            else
                cout<<"6 É TAMANHO MAXIMO DA PILHA!";

            iniPar(&p2, contP);
            iniImpar(&p3, contI);
            system("pause");
            break;
        case 2:
            system("cls");
            mostraP(&p);
            system("pause");
            break;
        case 3:
            system("cls");
            if(vaziaP(&p) == false)
            {
                num = desempilhaP(&p);
                cout << "O valor desempilhado é " << num << endl;
                if(num%2==0)
                    empilhaPar(&p2, num);
                else
                     empilhaImpar(&p3, num);

            }
            else
                cout << "Não foi possivel desempilhar, a pilha está vazia!\n";

            system("pause");
            break;
        case 4:
            system("cls");
            mostra_Par(&p2);
            mostra_Impar(&p3);

            system("pause");
            break;
         case 5:
            system("cls");
            destroiP(&p);

            system("pause");
            break;

        default:
            cout << "Opção inválida!" << endl;
            system("pause");
            break;

        }

    }
    while (op != 0);














}//final do main
