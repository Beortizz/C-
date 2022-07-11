#ifndef LISTASIMPLESORD_H
#define LISTASIMPLESORD_H

#include "No.h"

class ListaSimples
{
 public:
  ListaSimples();
  ~ListaSimples();

  void insere(int val);
  void imprime();

  ListaSimples * criaListaCumulativa(int vmax);

 private:
  No *primeiro;
};

#endif // LISTASIMPLESORD_H
