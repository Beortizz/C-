#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    max = tam;
    x = new int[tam];
    ultimo = -1;
}

ListaCont::~ListaCont()
{
    delete [] x;
}

void ListaCont::insereOrd(int val)
{
    if(ultimo == (max-1))
    {
        cout << "Vetor cheio!" << endl;
        exit(1);
    }
    else
    {
        if(ultimo == -1)
        {
            x[0] = val;
            ultimo = ultimo + 1;
        }
        else
        {
            int k = buscaBinariaInsere(val);
            if(x[k] != val)
            {
                for(int i = ultimo; i >= k; i--)
                    x[i+1] = x[i];
                    x[k] = val;
                    ultimo++;
            }
        }
    }
}

// ----------------------------------------------------------------------------
//Q1
int ListaCont::buscaBinariaInsere(int val)
{
    if(ultimo == -1)
        return 0;
    else if(x[ultimo] < val)
        return ultimo+1;
    else
    {
        int esq = 0;
        int dir = ultimo;
        while(esq <= dir)
        {
            int meio = (esq + dir) / 2;
            if(val > x[meio])
                esq = meio+1;
            else if(val < x[meio])
                dir = meio-1;
            else
                return meio;
        }
        return esq;
    }
}
//-Q1
// ----------------------------------------------------------------------------

void ListaCont::imprime()
{
    cout << "LISTA CONTIGUA: ";
    if(ultimo == -1) cout << "Vazia!" << endl;
    for(int i = 0; i <= ultimo; i++)
        cout << x[i] << " ";
    cout << endl;
}
