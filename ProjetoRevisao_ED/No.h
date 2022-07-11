#ifndef NO_H
#define NO_H

class No
{
    public:
        No() {}
        ~No() {}

        int getInfo() { return info; }
        No* getProx() { return prox; }
        void setInfo(int val) { info = val; }
        void setProx(No *p) { prox = p; }

    private:
        int info;
        No *prox;
};

#endif // NOPONTO_H
