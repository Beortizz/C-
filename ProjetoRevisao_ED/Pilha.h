#ifndef PILHA_H
#define PILHA_H
#include "NoPilha.h"

class Pilha
{
    public:
        Pilha();
        ~Pilha();

        char getTopo();
        void empilha(char c);
        char desempilha();
        bool vazia();
        void imprime();

    private:
        NoPilha *topo;
};

#endif // PILHA_H
