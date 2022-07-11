#ifndef NODUPLO_H_INCLUDED
#define NODUPLO_H_INCLUDED

class NoDuplo
{
    public:
        NoDuplo() {}
        ~NoDuplo() {}
        float getInfo() { return info; }
        NoDuplo* getProx() { return prox; }
        NoDuplo* getAnt() { return ant; }
        void setInfo(float val) { info = val; }
        void setProx(NoDuplo *p) { prox = p; }
        void setAnt(NoDuplo *p) { ant = p; }

    private:
        float info;
        NoDuplo *prox;
        NoDuplo *ant;
};

#endif // NODUPLO_H_INCLUDED
