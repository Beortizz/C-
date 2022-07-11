#include <iostream>
#include <cstdlib>
#include "Pilha.h"

using namespace std;

Pilha::Pilha()
{
    topo = NULL;
}

Pilha::~Pilha()
{
    NoPilha *p = topo;
    while(p != NULL)
    {
        NoPilha *t = p->getProx();
        delete p;
        p = t;
    }
}

void Pilha::empilha(char c)
{
    NoPilha *novo = new NoPilha();
    novo->setInfo(c);
    novo->setProx(topo);
    topo = novo;
}

char Pilha::desempilha()
{
    if(!vazia())
    {
        NoPilha *p = topo->getProx();
        char c = topo->getInfo();
        delete topo;
        topo = p;
        return c;
    }
    else
    {
        cerr << "Pilha vazia!" << endl;
        exit(1);
    }
}

char Pilha::getTopo()
{
    if(!vazia())
        return topo->getInfo();
    else
    {
        cerr << "Pilha vazia!" << endl;
        exit(1);
    }
}

bool Pilha::vazia()
{
    return (topo == NULL);
}

void Pilha::imprime()
{
    NoPilha *p = topo;
    cout << "PILHA: ";
    if(topo == NULL) cout << "Vazia!" << endl;
    while(p != NULL)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
    cout << endl;
}
