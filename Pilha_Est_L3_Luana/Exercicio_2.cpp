#include <iostream>
#include <string>
using namespace std;

#include "pilha_L3_E2.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    Pilha p1;
bool balanciada= true;
    string str;
    cout << "Informe uma palavra: ";
    //cin>> str;
    getline(cin, str);


    inicializaP(&p1, str.size());

    for (int i=0; i<str.size(); i++)
    {
        if(str[i] == '(')
            empilhaP(&p1, str[i]);
        if(str[i] == ')')
            if(vaziaP(&p1))
        {
            balanciada = false;
            break;
        }
        else
            desempilhaP(&p1);
    }
    if(vaziaP(&p1) && balanciada==true)
        cout<<"A expressão ESTÁ balanciada!";
        else
                cout<<"A expressão NÃO ESTÁ balanciada!";



    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main


