#include <iostream>
using namespace std;
struct Agenda
{

    string nome;
    unsigned long int telefone;
    string data_nc;
    Agenda()
    {
        nome=" ";
        telefone=0;
        data_nc=" ";
    }
    Agenda(string n, unsigned long int t, string d)
    {
        nome=n;
        telefone=t;
        data_nc=d;
    }

};
#include "Agenda.hpp"
void atualiza_contato(No **Lista, string valor)
{
    No *atual=*Lista;

    if(buscaL(Lista,valor)==true)
    {
        while(atual->dado.nome!=valor)
            atual=atual->prox;

        cout<<"Informe o novo telefone: ";
        cin>>atual->dado.telefone;
        cout<<"Informe a nova data: ";
        cin>>atual->dado.data_nc;

    }
    else
        cout<<"Nome não encontrado na agenda"<<endl;



}
int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    No* lista;
    Agenda A;
    inicializaL(&lista);

    insereOrdenado(&lista, Agenda("Luana",996183980,"20/01/2004"));
    insereOrdenado(&lista, Agenda("Denair",996244046,"08/02/1970"));
    insereOrdenado(&lista, Agenda("Odinei",996177674,"04/04/1974"));

    mostraL(&lista);
    atualiza_contato(&lista,"Luana");
    atualiza_contato(&lista,"Carol");
    mostraL(&lista);


}

