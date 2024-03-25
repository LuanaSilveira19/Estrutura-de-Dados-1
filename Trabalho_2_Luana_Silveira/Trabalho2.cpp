#include <unistd.h>
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;

#include "Ld_trabalho2.hpp"

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    cout << fixed;
    cout.precision(2);
    stringstream strBuffer;
    string op, linha;
    Lista L1 = Lista();
    Lista L2 = Lista();
    Lista L3 = Lista();

    ifstream arq ("entrada1.txt");

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

        if(op == "inserir")
        {
            string nomeLista;
            int n;
            char c;
            strBuffer >> nomeLista;
            strBuffer >> n;

            if(nomeLista=="L1")
            {
                cout<<"O caracteres <";
                for(int i=0; i<n; i++)
                {
                    strBuffer >> c;
                    insereFimL(&L1,c);
                    cout<<c;
                }
                 cout<<"> foram adicionados na lista L1"<<endl;

            }
            else if(nomeLista=="L2")
            {
                 cout<<"O caracteres <";
                for(int i=0; i<n; i++)
                {
                    strBuffer >> c;
                    insereFimL(&L2,c);
                    cout<<c;
                }
                 cout<<"> foram adicionados na lista L2"<<endl;


            }
            else if(nomeLista=="L3")
            {
                cout<<"O caracteres <";
                for(int i=0; i<n; i++)
                {
                    strBuffer >> c;
                    insereFimL(&L3,c);
                    cout<<c;
                }
                 cout<<"> foram adicionados na lista L3"<<endl;

            }


        }
        else if(op == "mostrar")
        {
            string nomeLista;
            char tipo;
            strBuffer >> nomeLista;
            strBuffer >> tipo;

            if(nomeLista=="L1")
            {
                if(tipo=='N')
                {
                    cout<<"L1-N";
                    mostraL(&L1);
                }else if(tipo=='I'){
                    cout<<"L1-I";
                    mostrarInversoL(&L1);
                }
            }
            if(nomeLista=="L2")
            {
                if(tipo=='N')
                {
                    cout<<"L2-N";
                    mostraL(&L2);
                }else if(tipo=='I'){
                    cout<<"L2-I";
                    mostrarInversoL(&L2);
                }
            }
            if(nomeLista=="L3")
            {
                if(tipo=='N')
                {
                    cout<<"L3-N";
                    mostraL(&L3);
                }else if(tipo=='I'){
                    cout<<"L3-I";
                    mostrarInversoL(&L3);
                }
            }

        }else if(op == "substituir"){
            string nomeLista;
            int n;
            char c;
            strBuffer >> nomeLista;
            strBuffer >> n;
             if(nomeLista=="L1")
            {
                destroiL(&L1);
                cout<<"Substituição de L1 pelos caracteres <";
                for(int i=0; i<n; i++)
                {
                    strBuffer >> c;
                    insereFimL(&L1,c);
                    cout<<c;
                }
                 cout<<">"<<endl;

            }
            else if(nomeLista=="L2")
            {
                destroiL(&L2);
                 cout<<"Substituição de L2 pelos caracteres <";
                for(int i=0; i<n; i++)
                {
                    strBuffer >> c;
                    insereFimL(&L2,c);
                    cout<<c;
                }
                 cout<<">"<<endl;


            }
            else if(nomeLista=="L3")
            {
                destroiL(&L3);
                cout<<"Substituição de L3 pelos caracteres <";
                for(int i=0; i<n; i++)
                {
                    strBuffer >> c;
                    insereFimL(&L3,c);
                    cout<<c;
                }
                 cout<<">"<<endl;

            }

        }else if(op == "inserirCaractereApos"){
            string nomeLista;
            char c1;
            char c2;
            strBuffer >> nomeLista;
            strBuffer >> c1;
            strBuffer >> c2;
            if(nomeLista=="L1")
            {
                cout<<"Foram inseridos "<< qtdInsere(&L1, c1,c2)<< " caracteres<"<<c1<<">apos o caracter<"<<c2<<">na lista L1"<<endl;
                insereClone(&L1, c1,c2);

            }else if(nomeLista=="L2")
            {
                cout<<"Foram inseridos "<< qtdInsere(&L1, c1,c2)<< " caracteres<"<<c1<<">apos o caracter<"<<c2<<">na lista L2"<<endl;
                insereClone(&L2, c1,c2);

            }else if(nomeLista=="L3")
            {
                cout<<"Foram inseridos "<< qtdInsere(&L1, c1,c2)<< " caracteres<"<<c1<<">apos o caracter<"<<c2<<">na lista L3"<<endl;
                insereClone(&L3, c1,c2);

            }


        }else if(op == "contarOcorrencia"){

            //contarOcorrencia(&L1,&L2);
        }

        usleep(10000);

    }
    return 0;

}
