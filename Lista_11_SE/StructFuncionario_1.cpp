#include <cstring>
#include <string>
#include <iostream>

using namespace std;

struct Funcionario
{
    int codigo;
    string nome;
    float salario;
    int idade;

    Funcionario()
    {
        codigo=0;
        nome=" ";
        salario=0;
        idade=0;
    }
    Funcionario(int c, string n, float s, int id)
    {
        codigo=c;
        nome=n;
        salario=s;
        idade=id;
    }
    bool operator!=(const Funcionario& f)
    {
        if(codigo != f.codigo)
            return true;
        if(nome != f.nome)
            return true;
        if(idade != f.idade)
            return true;
        if(salario != f.salario)
            return true;

        return false;
    }

    bool operator==(const Funcionario& f)
    {
        if(codigo != f.codigo)
            return false;
        if(nome != f.nome)
            return false;
        if(idade != f.idade)
            return false;
        if(salario != f.salario)
            return false;

        return true;
    }

    //operador usado na ordenação
    bool operator > (const Funcionario& f)
    {
        if(strcmpi(nome.c_str(), f.nome.c_str()) > 0 )
            return true;
        else
            return false;
    }

};

#include "Lista_descritor_L11_E1.hpp"

Funcionario leInicio(Lista *lista)
{

    Funcionario dado;
    if(vaziaL(lista)==false)
        dado= lista->inicio->dado;
    return dado;
}

Funcionario leFim(Lista *lista)
{

    Funcionario dado;
    if(vaziaL(lista)==false)
        dado= lista->fim->dado;

    return dado;
}
Funcionario removeInicio(Lista *lista)
{

    Funcionario dado;
    No* aux;
    if(vaziaL(lista)==false)
    {
        dado = lista->inicio->dado;
        aux = lista->inicio;

        lista->inicio = lista->inicio->prox;
        lista->tamanho--;
        delete aux;
    }
    else if(lista->inicio->prox ==NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return dado;
}
float mediaSalario(Lista *lista)
{

    int valor;

    No *n = lista->inicio;
    while (n)
    {
        valor+=n->dado.salario;
        n = n->prox;
    }

    return valor/lista->tamanho;
}
void nomeMenor(Lista *lista)
{

    cout<<"Funcionários com salário menor que a média:";
    No *n = lista->inicio;
    if(vaziaL(lista)==false)
    {
        while (n)
        {
            if(n->dado.salario< mediaSalario(lista))
                cout<<n->dado.nome<<", ";

            n = n->prox;
        }
    }

}
void ordenaFunc(Lista *lista)
{

    Funcionario aux;
    bool trocou=true;
    while(trocou)
    {
        trocou=false;
        No *n= lista->inicio;
        while(n!=NULL)
        {
            if(n && n->prox)
            {
                if(n->dado.nome > n->prox->dado.nome)
                {
                    aux= n->dado;
                    n->dado= n->prox->dado;
                    n->prox->dado= aux;
                    trocou=true;
                }
            }
            n=n->prox;
        }
    }

}
void inverterLista(Lista *lista){
    Lista aux = Lista();

    while(!vaziaL(lista))
    {
        insereInicioL(&aux,removeInicio(lista));
    }

    mostraL(&aux);

    while(!vaziaL(&aux))
    {
        insereInicioL(lista,removeInicio(&aux));
    }
}
void uniao(Lista *lista1, Lista *lista2){
    Lista aux = Lista();
    int cont1=0, cont2=0;

    while(!vaziaL(lista1))
    {
        insereInicioL(&aux,removeInicio(lista1));
        cont1++;
    }
     while(!vaziaL(lista2))
    {
        insereInicioL(&aux,removeInicio(lista2));
        cont2++;
    }

    mostraL(&aux);

    while(cont2!=0)//deu certo pra essa cituação, mas cuidar na prova
    {
        insereInicioL(lista2,removeInicio(&aux));
        cont2--;
    }
     while(!vaziaL(&aux))
    {
        insereInicioL(lista1,removeInicio(&aux));
    }
}

void ordenaIdade(Lista *lista)
{

    Funcionario aux;
    bool trocou=true;
    while(trocou)
    {
        trocou=false;
        No *n= lista->inicio;
        while(n!=NULL)
        {
            if(n && n->prox)
            {
                if(n->dado.idade > n->prox->dado.idade)
                {
                    aux= n->dado;
                    n->dado= n->prox->dado;
                    n->prox->dado= aux;
                    trocou=true;
                }
            }
            n=n->prox;
        }
    }
}


void interseccao(Lista *L1, Lista *L2)
{
    No *n1= L1->inicio;

    Lista n3 = Lista();
    Funcionario a;

    while(n1!=NULL)
    {
        if(buscaL(L2, n1->dado)==true)
            {
                if(buscaL(&n3, n1->dado)==false)
                {
                    a=n1->dado;
                insereInicioL(&n3,a);
                }
            }
         n1 = n1->prox;
    }
   /* cout<<"L1:";
    mostraL(L1);
    cout<<"L2:";
    mostraL(L2);*/
    cout<<"L3:";
    mostraL(&n3);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista lista = Lista();
    Lista lista2 = Lista();
    Funcionario f;

    //cout<<"Dado do inicio:"<<leInicio(&lista)<<endl;
    insereInicioL(&lista, Funcionario(1,"Luana", 100.00f, 19));
    insereInicioL(&lista, Funcionario(2,"Julia", 500.00f, 20));
    insereInicioL(&lista, Funcionario(3,"Ana", 1500.00f, 25));

    cout << lista << endl;

    cout<<"Dado do inicio:"<<leInicio(&lista)<<endl;
    cout<<endl;
    cout<<"Remove inicio:"<<removeInicio(&lista)<<endl;
    cout<<"Remove inicio:"<<removeInicio(&lista)<<endl;
    cout<<"Remove inicio:"<<removeInicio(&lista)<<endl;
    cout<<"Lista vazia depois de remover todos:";
    cout << lista << endl;
    cout<<endl;

    insereFimL(&lista, Funcionario(4,"Carol", 2000.00f, 50));
    insereFimL(&lista, Funcionario(5,"Laura", 4000.00f, 22));
    insereInicioL(&lista, Funcionario(1,"Luana", 100.00f, 19));
    insereInicioL(&lista, Funcionario(2,"Julia", 500.00f, 20));
    cout<<"Insere no fim:";
    cout << lista << endl;

    cout<<"Dado do final:"<<leFim(&lista)<<endl;
    cout<<endl;
    cout<<"Média dos salarios:"<< mediaSalario(&lista)<<endl;
    nomeMenor(&lista);
    cout<<endl;


    cout<<"Lista ordenada:";
    ordenaFunc(&lista);
    cout << lista << endl;
      cout<<endl;
    cout<<"Lista ordem normal:";
    cout << lista << endl;

     cout<<"Lista invertida:";
      inverterLista(&lista);
    cout<<endl;
    insereInicioL(&lista2, Funcionario(1,"Luana", 100.00f, 19));
    insereInicioL(&lista2, Funcionario(2,"Julia", 500.00f, 20));
    cout<<"Segunda lista:";
    cout << lista2 << endl;

    cout<<"União das duas listas:";
    uniao(&lista,&lista2);
    cout<<endl;

    cout<<"Ordena por idade:";
    ordenaIdade(&lista);
    cout << lista << endl;
    cout<<endl;

    cout<<"Mostra intersecção:";
    interseccao(&lista,&lista2);


}
