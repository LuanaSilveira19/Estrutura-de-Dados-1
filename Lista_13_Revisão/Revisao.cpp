#include <unistd.h>
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;

#include "Lista_Revisao.hpp"

//fazer um ajuste na função insere ordenado ex5 lista 10, modificar para usar com descritor
int main(void)
{
    setlocale(LC_ALL, "portuguese");
    cout << fixed;
    cout.precision(2);
    stringstream strBuffer;
    string op, linha;
    Lista L1 = Lista();
    Lista L2 = Lista();

    ifstream arq ("entrada.txt");

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = "";
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "adiciona")
        {
            string nomeLista;
            int valor;
            strBuffer >> nomeLista;
            strBuffer >> valor;

            if(nomeLista=="L1")
            {
                insereFimL(&L1,valor);
                cout<<"O número "<<valor<<" foi adicionado na lista L1"<<endl;
            }
            else if(nomeLista=="L2")
            {
                insereFimL(&L2,valor);
                cout<<"O número "<<valor<<" foi adicionado na lista L2"<<endl;
            }


        }
        else if(op=="mostra")
        {
            string nomeLista;
            string valor;
            strBuffer >> nomeLista;
            strBuffer >> valor;

            if(nomeLista=="L1")
            {
                if(valor=="I")
                {
                    cout<<"L1(I):";
                    mostraL(&L1);
                }
                else if(valor=="C")
                {
                    cout<<"L1(C):";
                    ordemCresc_Decresc_Copia(&L1,valor);
                }
                else if(valor=="D")
                {
                    cout<<"L1(D):";
                    ordemCresc_Decresc_Copia(&L1,valor);
                }
            }
            else if(nomeLista=="L2")
            {
                if(valor=="I")
                {
                    cout<<"L2(I):";//IMPRIMIR O TEXTO DE VAZIA
                    mostraL(&L2);
                }
                else if(valor=="C")
                {
                    cout<<"L2(C):";
                    ordemCresc_Decresc_Copia(&L2,valor);
                }
                else if(valor=="D")
                {
                    cout<<"L2(D):";
                    ordemCresc_Decresc_Copia(&L2,valor);
                }
            }
        } else if(op=="mostraDif"){
            string nomeLista1;
            string nomeLista2;
            strBuffer >> nomeLista1;
            strBuffer >> nomeLista2;

            if(nomeLista1=="L1" && nomeLista2=="L2"){
                cout<<"L1-L2:";
                mostraDif(&L1,&L2);
            }else if(nomeLista1=="L2" && nomeLista2=="L1"){
                cout<<"L2-L1:";
                 mostraDif(&L2,&L1);
            }

        }else if(op=="removeTodos"){
             string nomeLista;
             strBuffer >> nomeLista;

             if(nomeLista=="L1"){
                removeTodos(&L1);
                cout<<"Todos os valores de L1 foram removidos"<<endl;
             }else if(nomeLista=="L2"){
                 removeTodos(&L2);
                cout<<"Todos os valores de L2 foram removidos"<<endl;
             }
        }else if(op=="mediana"){
             string nomeLista;
             strBuffer >> nomeLista;

             if(nomeLista=="L1"){
                    if(L1.tamanho==0)
                    cout<<"Erro ao calcular a mediana de L1: lista vazia!"<<endl;
                    else
                    cout<<"Mediana L1:"<<mediana(&L1)<<endl;
             }

             else if(nomeLista=="L2")
             {
                 if(L2.tamanho==0)
                     cout<<"Erro ao calcular a mediana de L2: lista vazia!"<<endl;
                    else
                    cout<<"Mediana L2:"<<mediana(&L2)<<endl;
             }

        }else if(op=="moda"){
             string nomeLista;
             strBuffer >> nomeLista;

             if(nomeLista=="L1"){
                cout<<"Moda L1:";
                moda(&L1);
             }

             else if(nomeLista=="L2"){
                cout<<"Moda L2:";
                moda(&L2);
             }

        }


        usleep(10000);

    }
    return 0;

}
