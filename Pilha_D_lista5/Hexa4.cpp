#include <iostream>

using namespace std;

#include "pilha_D_L5_E4.hpp"

void mostraH(Pilha *p)
{
    cout << "Hexadecimal: " << endl;

    if(vaziaP(p) == false)
    {
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            if(no->dado==10)
                cout << setfill(' ') << std::setw(4) << "A";
            else if(no->dado==11)
                cout << setfill(' ') << std::setw(4) << "B";
            else if(no->dado==12)
                cout << setfill(' ') << std::setw(4) << "C";
            else if(no->dado==13)
                cout << setfill(' ') << std::setw(4) << "D";
            else if(no->dado==14)
                cout << setfill(' ') << std::setw(4) << "E";
            else if(no->dado==15)
                cout << setfill(' ') << std::setw(4) << "F";
            else
                cout << setfill(' ') << std::setw(4) << no->dado;

            no = no->prox;
        }

    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Pilha p1;
    int num, v;

    cout<<"Informe um número decimal para descobrir o hexadecimal:";
    cin>>num;

    while(num>=16)
    {
        empilhaP(&p1,(num%16));
        num= num/16;

    }
    empilhaP(&p1,num);


    mostraH(&p1);


}
