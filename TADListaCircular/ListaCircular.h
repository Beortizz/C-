#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "NoDuplo.h"

class ListaCircular
{
    public:
    ListaCircular();
    ~ListaCircular();
/*    bool busca(int val);
    bool buscaReversa(int val);*/
    void imprime();
//    void imprimeReverso();
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val);
    void removeFinal();
    bool vazia(){return n==0;}
private:
    NoDuplo *primeiro;
    int n;
    NoDuplo *ultimo;
    void removeNo(NoDuplo *p);
};

#endif // LISTACIRCULAR_H
