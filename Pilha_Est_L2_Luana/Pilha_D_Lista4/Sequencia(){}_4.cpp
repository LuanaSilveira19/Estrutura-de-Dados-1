#include <iostream>
#include <cstring>
using namespace std;

#include "pilha_D_L4_E4.hpp"
int forma_par(char f, char d)
{
    switch(f)
    {
    case ')':
        if(d=='(')
            return 1;
        else
            return 0;
        break;
    case ']':
        if(d=='[')
            return 1;
        else
            return 0;
        break;
    case '}':
        if(d=='{')
            return 1;
        else
            return 0;
        break;
    }
}
int confere(string x, int tam)
{
  Pilha p1;

  char remover;
    int i=0, cont=0;
    while(x[i]!= '\0')
    {
        if(x[i]=='(' || x[i]=='[' || x[i]=='{')
            {
              empilhaP(&p1, x[i]);
            }
        else if(x[i]==')' || x[i]==']' || x[i]=='}')
        {
            remover = desempilhaP(&p1);
            if(forma_par(x[i],remover ))
                cont++;
        }
        i++;
    }
    if(cont!= tam/2)
    return 0;//mal formada
    else
        return 1;


}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p1;
    string str;
    cout << "Informe uma sequencia com (),{} ou []: ";
    getline(cin, str);


if( confere(str,str.size()))
    cout<<"A sequencia ESTÁ BALANCEADA";
else
  cout<<"A sequencia NÃO ESTÁ BALANCEADA";

}
