#include <iostream>
using namespace std;

#include "Questao_1.hpp"//arquivo de cabeçalho

void removeMaiorMenor(Pilha *p)
{

Pilha aux;
inicializaP(&aux,10);
    int maior=0;
    int menor=99999999999;
    int cont_1=0, cont_2=0;

    if(!vaziaP(p))
    {
          for(int i = p->topo; i > p->base; i--){
              if(maior<p->dados[i])
                maior=p->dados[i];
              if(menor>p->dados[i])
                 menor=p->dados[i];
          }

    }
    while(!vaziaP(p))
    {
          int x= desempilhaP(p);
          if(x!=maior && x!=menor)
          {
              empilhaP(&aux,x);

          }
          if(x==maior)
          {
              cont_1++;
              if(cont_1>1)
                 empilhaP(&aux,x);
          }
           if(x==menor)
          {
              cont_2++;
              if(cont_2>1)
                 empilhaP(&aux,x);
          }



    }
    while(!vaziaP(&aux))
    {

        empilhaP(p,desempilhaP(&aux));
    }
  cout<<"Maior:"<<maior<<endl;
  cout<<"Menor:"<<menor<<endl;
  cout<<"Pilha depois"<<endl;
  mostraP(p);

}
int main(void)
{
   Pilha P;
    int valor,i=0;

   inicializaP(&P,10);
/*while(i<5)
{
    cout<<"Informe um valor:";
   cin>>valor;

   if(valor>-1)
    empilhaP(&P, valor);
   else
     cout<<"Informe somente valores positivos!";

    i++;
}*/


   empilhaP(&P, 8);
   empilhaP(&P, 9);
   empilhaP(&P, 7);
   empilhaP(&P, 9);
   empilhaP(&P, 3);
   empilhaP(&P, 6);
   empilhaP(&P, 3);

   cout<<"Pilha antes:"<<endl;
   mostraP(&P);
   removeMaiorMenor(&P);


}
