#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;
/*void ListaDupla::insereFinal(int val)
//implementa��o usando o insere.
{
    insere(val,ultimo);
}*/

void ListaDupla::insere(int val, NoDuplo *p)
//Opera��o para inserir um novo n� com valor val ap�s
//um n� v�lido apontado por p
{
    if(n != 0) //n�o precisa desse teste. O ponteiro p aponta para um n� v�lido,
               //portanto a lista tem mais de um n� (n>0)
    {
        NoDuplo *q = new NoDuplo();
        q->setInfo(val);
        if(p == ultimo) // p aponta para o �ltimo n� da LDE
        {
            q->setProx(NULL);
            p->setProx(q);
            ultimo = q;
            q->setAnt(p);
        }
        else  //p aponta para quaquer outro n�, exceto o �ltimo
        {
            NoDuplo *r = p->getProx();

            q->setProx(r);
            q->setAnt(p);

            p->setProx(q)
            r->setAnt(q);
        }

        n = n + 1;
    }
}

void ListaDupla::removeOcorrencias(int val)
//remover todas as ocorr�ncias dos n�s que possuem valor val
{
    if(n > 0)
    {
        NoDuplo *p = primeiro;
        while(p != NULL)
        {
            if(p->getInfo() == val)
            {
                NoDuplo *q = p;
                p = p->getProx();
                removeNo(q);
            }
            else
                p = p->getProx();
        }
    }
    else
        cout << "Lista vazia" << endl;
}

void ListaDupla::removeNo(NoDuplo *p)
//remove o n� apontado por p da LDE.
{
    if(p != NULL)
    {
        if(n == 0)
            cout << "Lista vazia" << endl;
        else if(p == primeiro)  //caso II
            removeInicio();
        else if(p == ultimo) //caso III
            removeFinal();
        else//p aponta para um n� no meio da LDE. Logo, n>=3
            //caso IV
        {
            NoDuplo *ant_p = p->getAnt();
            NoDuplo *prox_p = p->getProx();

            ant_p->setProx(prox_p);
            prox_p->setAnt(ant_p);
            n = n - 1;
            delete p;
        }
    }
}


ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

void ListaDupla::insereFinal(int val)
{
    insere(val, ultimo);
  /*  NoDuplo *p = new NoDuplo();

    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);

    if(n != 0)
        ultimo->setProx(p);
    else
        primeiro = p;

    ultimo = p;
    n = n + 1;*/
}

void ListaDupla::removeFinal()
{
    if(primeiro != NULL)
    {
        NoDuplo *p = ultimo;

        ultimo = ultimo->getAnt();

        if(primeiro == p) //lista com 1 unico n�
            primeiro = NULL;
        else //lista com mais de um n�
            ultimo->setProx(NULL);

        delete p;
        n = n - 1;
    }
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(primeiro);
    p->setAnt(NULL);

    if(n == 0)
        ultimo = p;
    else
        primeiro->setAnt(p);

    primeiro = p;
    n = n + 1;
}

void ListaDupla::removeInicio()
{
    NoDuplo *p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;
        n = n - 1;

        if(n == 0) 	ultimo = NULL;
        else primeiro->setAnt(NULL);
    }
    else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::imprime()
{
    NoDuplo *p = primeiro;
    cout<<endl;
    while(p != NULL)
    {
        cout<<p->getInfo()<<" ";
        p = p->getProx();

    }
    cout<<endl;
}
