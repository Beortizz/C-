#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include "ListaCont.h"
#include "ListaSimples.h"
#include "ListaDupla.h"
#include "Pilha.h"

using namespace std;

// ############################################################################
// TVC 2 -- ESTRUTURA DE DADOS e LABORATORIO DE PROGRAMACAO II
// DATA: 30/10/2017
// PREENCHER ESTE CABECALHO COM SUAS INFORMACOES
// ALUNO(A):
// MATRICULA:
// ############################################################################

// ----------------------------------------------------------------------------
//Q4
bool satisfazPadro(char str[], int n)
{
    Pilha p1,p2;
    int i=0;

    while(i<n && str[i] != 'z')//percorre a cadeia at� achar o 1o 'z'
    {
        p1.empilha(str[i]); //empilha todos os chars
        i++;
    }

    i++; //salta o 1o 'z'

    while(i<n && str[i] != 'z')//percorre a cadeia at� achar o 2o 'z'
    {
        if(p1.vazia() || p1.desempilha() != str[i])
            return false;  //caso p1 se torne vazia, � porque a 2a parte tem mais char que a 1a
        p2.empilha(str[i]); //empilha todos os chars
        i++;
    }

    i++; //salta o 2o 'z'

    while(i<n)//percorre a 3a parte da cadeia str
    {
        if(p2.vazia() || p2.desempilha() != str[i])
            return false; //caso p2 se torne vazia, � porque a 3a parte tem mais char que a 2a
        i++;
    }

    return p1.vazia() && p2.vazia();
}
//-Q4
// ----------------------------------------------------------------------------

int main()
{
    cout << "TVC 2 -- ESTRUTURA DE DADOS e LAB. DE PROG. II" << endl;
    cout << "FAVOR PREENCHER OS SEUS DADOS" << endl;

    // TESTE DA QUESTAO 1 -----------------------------------------------------
    srand(time(0));
    cout << endl << "TESTE DA QUESTAO 1" << endl;
    ListaCont lista(20);
    for(int i = 0; i < 20; i++)
    {
        int val = rand() % 100;
        lista.insereOrd( val );
    }
    lista.imprime();
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 2 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 2" << endl;
    ListaSimples l2;
    l2.insere(10);
    l2.insere(20);
    l2.insere(30);
    l2.insere(40);
    l2.insere(50);
    l2.imprime();
    cout << endl;

    ListaSimples *lc = l2.criaListaCumulativa(200);
    lc->imprime();
    delete lc;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 3 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 3" << endl;
    ListaDupla l3;
    l3.insereInicio(7);
    l3.insereInicio(2.1);
    l3.insereInicio(-0.2);
    l3.insereInicio(7);
    l3.insereInicio(12.3);
    l3.insereInicio(-5.4);
    l3.insereInicio(7);
    cout << "ANTES DE INSERIR:" << endl;
    l3.imprime();
    cout << "DEPOIS DE INSERIR:" << endl;
    l3.insereDepois(8.7, 12.3);
    l3.imprime();
    cout << "DEPOIS DE INSERIR:" << endl;
    l3.insereDepois(7, 7);
    l3.imprime();
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 4 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 4" << endl;
    char strs[8][50] = {"abbzbbazabb",
                        "abbzabbzabb",
                        "aazaazaa",
                        "abbabbabb",
                        "zz",
                        "abzbzab",
                        "aabbzbbaazaa",
                        "ababzbabazabab"};

    for(int i = 0; i < 8; i++)
    {
        if(satisfazPadro(strs[i], strlen(strs[i])))
            cout << strs[i]<<"\t"<< ": SATISFAZ O PADRAO!" << endl;
        else
            cout << strs[i]<<"\t" << ": NAO SATISFAZ O PADRAO!" << endl;
    }
    cout << endl;
    // ------------------------------------------------------------------------

    return 0;
}
