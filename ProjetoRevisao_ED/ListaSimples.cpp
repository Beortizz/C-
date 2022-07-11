#include <iostream>
#include <cstdlib>

#include "ListaSimples.h"

using namespace std;

ListaSimples::ListaSimples()
{
    primeiro = NULL;
}

ListaSimples::~ListaSimples()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaSimples::imprime()
{
    cout << "LISTA SIMPLES: ";
    if(primeiro == NULL)
    {
        cout << "Vazia!" << endl;
        return;
    }
    No *p = primeiro;
    while(p != NULL)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
    cout << endl;
}

void ListaSimples::insere(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(primeiro == NULL)
        primeiro = p;
    else
    {
        No *q = primeiro;
        while(q->getProx() != NULL)
            q = q->getProx();
        q->setProx(p);
    }
}

// ----------------------------------------------------------------------------
//Q2
ListaSimples* ListaSimples::criaListaCumulativa(int valMax)
{
    ListaSimples *lc = new ListaSimples();
    int soma = 0;
    for(No *p = primeiro; p != NULL; p = p->getProx())
    {
        soma += p->getInfo();
        if(soma <= valMax)
            lc->insere(soma);
        else
            break;
    }
    return lc;
}
//-Q2
// ----------------------------------------------------------------------------
