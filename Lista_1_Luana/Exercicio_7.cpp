#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<fstream>
using namespace std;

main()
{


    char texto[50];
    int cont=0, soma_1=0, sub=0, m=0, mul=0;
    float a, b, div_1, div_2;
    float soma_2=0;
    ifstream ler("entrada.txt", ios::in);

    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso" << endl;
        while(ler.getline(texto,50,' '))
        {
            cont++;

            if(cont==2 || cont==3)
                soma_1+=atof(texto);
            if(cont==4)
                a=atof(texto);
            if(cont==5)
                div_1=a/atof(texto);
            if(cont==6)
                b=atof(texto);
            if(cont==7)
                div_2=b/atof(texto);
            if(cont==8)
                sub=atof(texto);
            if(cont==9)
                sub-=atof(texto);
            if(cont==10)
                m=atof(texto);
            if(cont==11)
                mul= m*atof(texto);
            if(cont==12 || cont==13)
                soma_2+=atof(texto);
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    ler.close();
    cout<<"Soma 1:"<< soma_1<<endl;
    cout<<"Divisao:"<< div_1<<endl;
    cout<<"Divisao:"<< div_2<<endl;
    cout<<"Subtracao:"<< sub<<endl;
    cout<<"Multiplicacao:"<< mul<<endl;
    cout<<"Soma 2:"<< soma_2<<endl;
}
