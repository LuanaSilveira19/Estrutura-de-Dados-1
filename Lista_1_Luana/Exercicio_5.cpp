#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int l, c;
    cout<<"Informe o número de linhas: ";
    cin>> l;
    cout<<"Informe o número de colunas: ";
    cin>> c;

    int **mat_1= new int*[l];
    int **mat_2= new int*[l];
    int **soma= new int*[l];
    for(int i=0; i<l; i++)
    {
        mat_1[i]= new int[c];
    }
    cout<<"M1:"<<endl;
    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat_1[i][j]= 10+rand()%89;
            cout<< mat_1[i][j]<<"\t";
        }
        cout<<endl;
    }/////
    for(int i=0; i<l; i++)
    {
        mat_2[i]= new int[c];
    }
    cout<<endl;
    cout<<"M2:"<<endl;
    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat_2[i][j]= 10+rand()%50;
            cout<< mat_2[i][j]<<"\t";
        }
        cout<<endl;
    }
cout<<endl;

    for(int i=0; i<l; i++)
    {
        soma [i]= new int[c];
    }

     cout<<"Soma das matrizes:"<<endl;
    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
        {
            soma[i][j]= mat_1[i][j]+ mat_2[i][j];
              cout<< soma[i][j]<<"\t";
        }
        cout<<endl;
    }


    for(int i=0; i<l; i++)
    {
        delete[] mat_1[i];
        delete[] mat_2[i];
        delete[] soma[i];
    }
    delete[]mat_1;
    delete[] mat_2;
    delete[] soma;

}
