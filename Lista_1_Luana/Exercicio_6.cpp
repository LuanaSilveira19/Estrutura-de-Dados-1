#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;

void gerar(int **v, int n)
{
    int *i = new int(0);
     while(*i < n)
    {
         //aux= min + rand()% (max- min +1);
        (*v)[*i]=rand() % 100;
        (*i)++;
    }

    cout<<"Vetor gerado com sucesso!"<<endl;

}
void mostrar(int **v, int n)
{
    cout<<"Vetor: ";
    for(int j=0; j<n;j++)
    {
        cout << (*v)[j] << ", ";

    }
    cout<<endl;
}

main()
{
    setlocale(LC_ALL, "Portuguese");
    int op = -1, n;
    int *vet=NULL;
    srand(time(NULL));
    //aux= min + rand()% (max- min +1);
    do
    {
        system("cls");
        cout << "-------------MENU------------" << endl;
        cout << "------- 0 Sair.         -----" << endl;
        cout << "------- 1 Gerar vetor   -----" << endl;
        cout << "------- 2 Mostrar vetor -----" << endl;
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
            cout<<"Informe o tamanho do vetor: ";
            cin>>n;
            vet= new int[n];
            gerar(&vet,n);
           delete [] vet;//tem momentos que pega lixo de memoria por conta desse delet
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
                   mostrar(&vet,n);

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
