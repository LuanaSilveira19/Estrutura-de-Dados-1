#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;


main()
{
    setlocale(LC_ALL, "Portuguese");
    int op = -1;
    int *vet=NULL;
    srand(time(NULL));
    do
    {
        system("cls");
        cout << "-------------MENU------------" << endl;
        cout << "------- 1 Gerar vetor   -----" << endl;
        cout << "------- 2 Mostrar vetor -----" << endl;
        cout << "------- 0 Sair.         -----" << endl;
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
            if(vet!=NULL)//libera a memória
            {
                delete [] vet;
                cout<<"Vetor anterior Deletado!"<<endl;
            }
            vet= new int[10];
            for(int a=0; a<10; a++)
            {
                    vet[a]=21+rand()% 30;
            }
            cout<<"Vetor gerado!"<<endl;
            system("pause");
            break;

        case 2:
            system("cls");
            if(vet==NULL)
            {
                cout<<"O VETOR NAO PODE SER NULO"<<endl;
                cout<<"Gere um valor na opcao 1."<<endl;
            }
            else
            {
                cout<<"Vetor: ";
                for(int i=0; i<10; i++)
                {
                    cout<<vet[i]<<", ";
                }
                cout<<endl;
            }
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



