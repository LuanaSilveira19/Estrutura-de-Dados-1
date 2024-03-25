#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int *vet= new int[10];

    for(int i=0; i<10; i++)
    {
        vet[i]=21+rand()% 30;
    }
    cout<<"Vetor: ";
    for(int i=0; i<10; i++)
    {
        cout<<*(vet+i)<<", ";
    }
    delete[] vet;

}
