#include <iostream>
#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaCircular::~ListaCircular()
{
    NoDuplo *p = primeiro; //NoDuplo *p = ultimo;
    int i = 0;
    while(i<n)
    {
        NoDuplo *t = p->getProx(); //NoDuplo *t = p->getAnt();
        delete p;
        p = t;
        i++;
    }
}

void ListaCircular::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);

    if(n == 0)
    {
        p->setProx(p);
        p->setAnt(p);
        ultimo = p;
    }
    else
    {
        p->setProx(primeiro);
        p->setAnt(ultimo);
        primeiro->setAnt(p);
        ultimo->setProx(p);
    }

    primeiro = p;
    n = n + 1;
}

void ListaCircular::insereFinal(int val)
{
    if(n == 0)
        insereInicio(val);
    else
    {
        NoDuplo *p = new NoDuplo();

        p->setInfo(val);

        ///configura os ponteiros que partem do novo nó p
        p->setAnt(ultimo);
        p->setProx(primeiro);

        ///ponteiros que apontam para o novo nó p
        ultimo->setProx(p);
        primeiro->setAnt(p);
        ultimo = p;
        n++;
    }
}
void ListaCircular::removeInicio()
{
    if(n>0)  ///lista não vazia
    {
        if(n == 1)
        {
            delete ultimo;
            primeiro=ultimo=NULL;
        }
        else ///lista tem mais de 1 nó
        {
            NoDuplo *p = primeiro;
            primeiro = primeiro->getProx();
            primeiro->setAnt(ultimo);
            ultimo->setProx(primeiro);
            delete p;
        }
        n--;
    }
}

void ListaCircular::removeFinal()
{
    if(n>0)
    {
        if(n == 1) //if(primeiro == ultimo)
            removeInicio();
        else
        {///lista tem mais de um nó
            NoDuplo *p = ultimo;
            ultimo = ultimo->getAnt();
            ultimo->setProx(primeiro);
            primeiro->setAnt(ultimo);
            delete p;
            n--;
        }
    }
    else
        std::cout<<"Lista vazia";
}

///remover o maior
///remover menor
///remover todas as ocorrencias de nós com valor x

void ListaCircular::removeNo(NoDuplo *p)
///remove nó apontado por p da lista circular (duplamente encadeada)
///p é válido
{
    if(p == primeiro)
        removeInicio();
    else if(p == ultimo)
        removeFinal();
    else
    {///remove nó no meio da lista. Lisa tem 3 ou mais nós (n>=3)
        NoDuplo *ant = p->getAnt();
        NoDuplo *pos = p->getProx();

        ant->setProx(pos);
        pos->setAnt(ant);
        delete p;
        n--;
    }
}

void ListaCircular::imprime()
{
    std::cout << "Lista: ";
    int i=0;
    NoDuplo *p = primeiro;
    while(i<n)
    {
        std::cout << p->getInfo() << " ";
        p = p->getProx();
        i++;
    }
    std::cout << std::endl;
}
