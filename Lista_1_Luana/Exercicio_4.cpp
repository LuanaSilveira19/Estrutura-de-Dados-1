#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;

struct registro
{
    string cpf;
    string nome;
    int ano;
};

main()
{
    //entender a letra C
    setlocale(LC_ALL,"Portuguese");
    int n;
    cout<<"Informe a quantidade de clientes: ";
    cin>>n;
    registro *c= new registro [n];


    for(int i=0; i<n; i++)
    {
        cout<<"-----Dados do cliente "<<i+1<<"--------"<<endl;
        cout<<"CPF: ";
        cin>>c[i].cpf;
        fflush(stdin);
        cout<<"Nome: ";
        getline(cin, c[i].nome);
        fflush(stdin);
        cout<<"Ano de nascimento: ";
        cin>>c[i].ano;
        fflush(stdin);

    }
    for(int i=0; i<n; i++)
    {
        cout<<"-----Dados do cliente "<<i+1<<"--------"<<endl;
        cout<<"CPF: "<<c[i].cpf<<endl;
        cout<<"Nome: "<<c[i].nome<<endl;
        cout<<"Ano de nascimento: "<<c[i].ano<<endl;
    }
    delete []c;//confirmar se essa maneira esta certa

}
