#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val); /// exercicio
    void removeFinal();        /// exercicio
    void removeOcorrencias(int val);
    void imprime();
private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;

    void removeNo(NoDuplo *p);  ///exercício
    void insere(int val, NoDuplo *p);
    int n;
};
#endif
