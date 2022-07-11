#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = NULL;
    n = 0;
    ultimo = NULL;
}

ListaDupla::~ListaDupla()
{
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaDupla::insereInicio(float val)
{
    NoDuplo *novo = new NoDuplo();
    novo->setInfo(val);
    novo->setAnt(NULL);
    novo->setProx(primeiro);

    if(primeiro != NULL)
        primeiro->setAnt(novo);
    else
        ultimo = novo;

    primeiro = novo;
    n++;
}

void ListaDupla::imprime()
{
    cout << "LISTA DUPLA: ";
    if(n == 0) cout << "Vazia!" << endl;
    for(NoDuplo *p = primeiro; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}

// ----------------------------------------------------------------------------
//Q3
void ListaDupla::insereAntes(float val, float x)
{
    for(NoDuplo *p = primeiro; p != NULL; p = p->getProx())
    {
        if(p->getInfo() == x)
        {
            NoDuplo *novo = new NoDuplo();
            novo->setInfo(val);
            novo->setProx(p);
            novo->setAnt(p->getAnt());
            if(p->getAnt() == NULL)
                primeiro = novo;
            else
                p->getAnt()->setProx(novo);
            p->setAnt(novo);
            n++;
        }
    }
}

void ListaDupla::insereDepois(float val, float x)
{
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        if(p->getInfo() == x)
        {
            NoDuplo *aux = p->getProx();
            NoDuplo *novo = new NoDuplo();
            novo->setInfo(val);
            novo->setAnt(p);
            novo->setProx(p->getProx());
            if(p->getProx() == NULL)
                ultimo = novo;
            else
                p->getProx()->setAnt(novo);
            p->setProx(novo);
            n++;
            p = aux;
        }
        else
            p = p->getProx();
    }
}
//-Q3
// ----------------------------------------------------------------------------
