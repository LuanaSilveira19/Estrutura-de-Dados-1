#include <unistd.h>
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;

struct Veiculo
{
    string placa;
    int ano;
    string marca;
    string modelo;

    Veiculo()
    {
        placa=" ";
        ano=0;
        marca=" ";
        modelo=" ";

    }
    Veiculo(string p, int a, string ma, string mo)
    {
         placa=p;
        ano=a;
        marca=ma;
        modelo=mo;
    }

};

#include "Lista_descritor_L11_E3.hpp"
void mostraPlaca(Lista *lista, string valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.marca == valor)
            cout<<n->dado.placa<<", ";

        n = n->prox;
    }



}

int main()
{
    setlocale(LC_ALL, "portuguese");

      Lista lista = Lista();
    stringstream strBuffer;
    string op, linha;


    ifstream arq ("entrada-exemplo3.txt");

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        if(linha.size()==0)
            break;

        strBuffer = stringstream(linha);
        int contPlavra=1;
        string palavra;
        Veiculo v;
        while(getline(strBuffer, palavra , '#')) //le cada palavra da linha separada pelo delimitador #
        {
            if(contPlavra==1) //primeira palavra da linha
                v.placa = palavra;
            else if(contPlavra==2) //segunda palavra da linha
                v.ano = stoi(palavra);
            else if(contPlavra==3) //segunda palavra da linha
                v.marca = palavra;
            else if(contPlavra==4) //segunda palavra da linha
                v.modelo = palavra;


            contPlavra++;
        }

        insereInicioL(&lista,v);

        usleep(10000);

    }
    int menu = -1;

    do
    {
        system("cls");
        cout << "----------------Carros PF------------------" << endl;
        cout << "------- 0 Sair                       -----" << endl;
        cout << "------- 1 Mostrar lista de veículos   -----" << endl;
        cout << "------- 2 Ordenar lista de veículos   -----" << endl;
        cout << "------- 3 Remover um veículo da lista -----" << endl;
        cout << "------- 4 Remover com base no fab e ano ---" << endl;
        cout << "------- 5 Filtrar veículo             -----" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        if(menu==0){
            system("cls");
            cout << "Programa finalizado!";
            getchar();
            break;
        }

        else if(menu==1){
            system("cls");
            cout << lista << endl;
            system("pause");

        }else if(menu==2){
              system("cls");
             char ord;

            cout<<"Escolha se quer ordenar pelo ano (A) ou pelo modelo (M)";
            cin>>ord;

            if(ord=='M' || ord=='m'){
                ordemAlfabetica(&lista);
                cout<<"Lista ordenada em ordem alfabética!"<<endl;
                cout<<endl;
                cout << lista << endl;
            }else  if(ord=='A' || ord=='a'){
                ordemCresc(&lista);
                cout<<"Lista ordenada por ano!"<<endl;
                cout<<endl;
                cout << lista << endl;
            }
            system("pause");

        }else if(menu==3){
             system("cls");
            string p;

            cout<<"Digite a placa do veículo para ser removido!";
            cin>>p;

            if(buscaL(&lista, p)){
                   removeL(&lista,p);
                cout<<"Carro removido com sucesso! Veja a lista:"<<endl;
                cout << lista << endl;

            }else{
                  cout<<"A placa digitada não foi encontrada!"<<endl;
            }

            system("pause");

        }else if(menu==4){
            system("cls");
            string r;

            cout<<"Digite o nome do fabricante!";
            cin>>r;

            if(buscaLF(&lista, r)){
                   removeAno(&lista, r);
                      cout<<"Veiculos com fabricação superior a 20000 removidos! Nova lista:"<<endl;
                        cout << lista << endl;


            }else{
                  cout<<"O fabricante não foi encontrado!"<<endl;

            }

            system("pause");

        }else if(menu==5){
             system("cls");
             string f;

            cout<<"Digite o nome do fabricante!";
            cin>>f;

            if(buscaLF(&lista, f)){
                      cout<<"Placas dos veículos referentes ao fabricante "<<f<<":";
                mostraPlaca(&lista, f);

            }else{
                  cout<<"O fabricante não foi encontrado!"<<endl;

            }

            system("pause");

        }

    }while (menu != 0);



}

