#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct Impressao
{

    string nome;
    int qtd_pg;

    Impressao()
    {
        nome=" ";
        int qtd_pg=0;
    }
    Impressao( string n, int q)
    {

        nome=n;
        qtd_pg=q;
    }

};
#include "fila_L6_E4.hpp"

void total_pg(int dado)
{
    int total;
    total+=dado;
    cout<<total<<" página(s)"<<endl;

}
//deu erro no buscar, ver com o professor
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Fila P, N;
    Impressao A, D;
    string op, tipo, nome_doc;
    int n, pg_doc=0, t=0;

    ifstream ler("entrada.txt", ios::in);
    if(!ler.is_open())
    {
        cout << "Erro: nao foi possivel ler o arquivo\n";
        return 0;
    }

    while(!ler.eof())
    {
        //le a operacao
        if (!(ler >> op))
            break;

        if(op=="MOSTRAR")
        {
            ler >> tipo;
            if(tipo == "P" && verificaInicializacaoF(&P)== false )
                cout<<"ERRO: inicializar a fila P"<<endl;
            if(tipo == "N" && verificaInicializacaoF(&N)== false )
                cout<<"ERRO: inicializar a fila N"<<endl;

            if(tipo == "P"&&vaziaF(&P)&& verificaInicializacaoF(&P)== true )
                cout<<"Fila vazia"<<endl;
            if(tipo == "N"&&vaziaF(&N)&& verificaInicializacaoF(&N)== true)
                cout<<"Fila vazia"<<endl;

            if(tipo == "P"&& !vaziaF(&P)&& verificaInicializacaoF(&P)== true )
                mostraF(&P);
            if(tipo == "N"&& !vaziaF(&N)&& verificaInicializacaoF(&N)== true )
                mostraF(&N);

        }
        else if(op=="IMPRIMIRDOC")
        {
            if(verificaInicializacaoF(&P)== false || verificaInicializacaoF(&N)== false)
                cout<<"ERRO: inicializar as filas P e N"<<endl;
            else if(vaziaF(&P) && vaziaF(&N))
                cout<<"Não há documentos para imprimir"<<endl;
            if(!vaziaF(&P))
            {
                D =desenfileiraF(&P);
                t-=D.qtd_pg;
                cout<<"O documento "<<D.nome<<" foi impresso."<<endl;
            }
            else if(!vaziaF(&N))
            {
                D =desenfileiraF(&N);
                t-=D.qtd_pg;
                cout<<"O documento "<<D.nome<<" foi impresso."<<endl;
            }

        }
        if(op=="INICIALIZAR")
        {
            destroiF(&P);
            destroiF(&N);//ver a questão de liberar a memória
            ler >> n;
            inicializaF(&P, n);
            inicializaF(&N, n);
            cout<<"A fila P e N foram inicializadas com o tamanho "<<n<<endl;

        }
        else if(op=="TOTALPAG")
        {
            total_pg(t);
        }
        else if(op=="ENFILEIRARDOC")
        {
            ler >> nome_doc;
            ler >> pg_doc;
            ler >> tipo;

            A.nome=nome_doc;
            A.qtd_pg=pg_doc;
            t+=pg_doc;
            if(tipo == "P")
            {
                if(!cheiaF(&P))
                {
                    enfileiraF(&P, A);
                    cout<<"O documento "<<A.nome<<" ("<<A.qtd_pg<<" pag) foi adicionado na fila "<< tipo<<endl;
                }
                else
                    cout<<"Fila cheia"<<endl;
            }
            if(tipo == "N")
            {
                if(!cheiaF(&P))
                {
                    enfileiraF(&N, A);
                    cout<<"O documento "<<A.nome<<" ("<<A.qtd_pg<<" pag) foi adicionado na fila "<< tipo<<endl;
                }
                else
                    cout<<"Fila cheia"<<endl;
            }

        }
        else if(op=="CONSULTAR")
        {
            ler >> nome_doc;
            ler >> tipo;

             if(tipo == "P")
             {
                 if(buscaF(&P,nome_doc,n))
                      cout<<"O documento "<<nome_doc<<" encontra-se na fila "<< tipo<<endl;
                 else
                      cout<<"O documento "<<nome_doc<<" não está na fila "<< tipo<<endl;
             }
          if(tipo == "N")
             {
                 if(buscaF(&N,nome_doc,n))
                      cout<<"O documento "<<nome_doc<<" encontra-se na fila "<< tipo<<endl;
                 else
                      cout<<"O documento "<<nome_doc<<" não está na fila "<< tipo<<endl;
             }

        }
        else
        {
            //operação desconhecida, não faz nada (assumimos que o arquivo texto está correto)
        }
    }
    ler.close();

}
