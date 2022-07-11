#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class NoPilha
{
    public:
        NoPilha() {}
        ~NoPilha() {}

        char getInfo() { return info; }
        NoPilha* getProx() { return prox; }
        void setInfo(char c) { info = c; }
        void setProx(NoPilha *p) { prox = p; }

    private:
        char info;
        NoPilha *prox;
};

#endif // NO_H_INCLUDED
