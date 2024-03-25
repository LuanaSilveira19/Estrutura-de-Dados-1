#include <iostream>
#include <cstring>
using namespace std;


struct Pet
{

    int codigo;
    string nome;
    int idade;
    float peso;

    Pet()
    {
        codigo=0;
        nome=" ";
        idade=0;
        peso=0;
    }
    Pet(int c, string n, int i, float p)
    {
        codigo=c;
        nome=n;
        idade=i;
        peso=p;
    }

};
#include "Lista_Dupla_E3.hpp"

void descritor(Lista *L)
{
    //ver se a quest�o do decritor era isso mesmo
    cout<<"Ponteiro para o primeiro n� da lista: "<<L->inicio<<endl;
    cout<<"Ponteiro para o dado do primeiro n� da lista: "<<L->inicio->dado.nome<<endl;
    cout<<endl;
    cout<<"Ponteiro para o ultimo n� da lista: "<<L->fim<<endl;
    cout<<"Ponteiro para o dado do ultimo n� da lista: "<<L->fim->dado.nome<<endl;
    cout<<endl;
    cout<<"Quantidade de n�s: "<<L->tamanho<<endl;
}

void insereAnimal(Lista *L)
{
    int cont;
    int valor;
    Pet p;

    while(valor!=0){
        cont++;
        p.codigo=cont;

        cout<<"Informe o nome do animal:";
        cin>>p.nome;
        cout<<"Informe a idade do animal:";
        cin>>p.idade;
        cout<<"Informe o peso do animal:";
        cin>>p.peso;

        insereFimL(L,p);
        cout<<"Se quiser inserir mais um animal digite 1 se n�o digite 0:";
        cin>>valor;

    }
}

bool removeCodL(Lista *lista, int valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}
void tresUltimos(Lista *lista)
{

    No *n= lista->fim;

    cout<<n->dado.codigo<<"+"<<n->dado.nome<<", ";
    if(n->ant!= NULL)
        cout<<n->ant->dado.codigo<<"+"<<n->ant->dado.nome<<", ";
    if(n->ant->ant != NULL)
        cout<<n->ant->ant->dado.codigo<<"+"<<n->ant->ant->dado.nome;
}

void novasListas(Lista *lista)
{
    Lista L2 = Lista();
    Lista L3 = Lista();
    No *n= lista->inicio;

    Pet inf;

    while(n)//copia os elementos sem alterar a lista original
    {

        if(n->dado.peso<=50){
            inf=n->dado;
            insereFimL(&L2,inf);
        }else{
            inf=n->dado;
            insereFimL(&L3,inf);
        }

        n = n->prox;
    }

    cout<<"Original:";
    mostraL(lista);
    cout<<endl;
    cout<<"C�pia L2, peso <=50:";
    mostraL(&L2);
    cout<<endl;
    cout<<"C�pia L3, peso >50:";
    mostraL(&L3);

}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Lista lista = Lista();
    Pet p;
    int valor;
    insereAnimal(&lista);
    cout<<endl;
    mostraL(&lista);
    cout<<endl;
    descritor(&lista);
    cout<<endl;
    cout<<"Ultimos 3 elementos:";
    tresUltimos(&lista);
    cout<<endl;
    cout<<endl;
    novasListas(&lista);
    cout<<"Removendo valor pelo cod:"<<endl;
    cout<<"Insira um valor para remover o codigo:";
    cin>>valor;

    if(busca2L(&lista,valor))
    removeCodL(&lista,valor);
    else
    cout<<"Esse c�digo n�o existe!!"<<endl;

    mostraL(&lista);
}

