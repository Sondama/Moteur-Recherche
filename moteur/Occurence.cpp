#include"Occurence.h"
#include<string>

using namespace std;

    Occurence::Occurence(string m, int nb, string ch)
    {
        mot=m;
        nbocc=nb;
        chemin=ch;
    }

    void Occurence::setMot(string s)
    {
        mot=s;
    }

    void Occurence::setNbocc(int a)
    {
       nbocc=a;
    }

    string Occurence::getMot()const
    {
        return mot;
    }

    int Occurence::getNbocc()const
    {
        return nbocc;
    }

    void Occurence::setChemin(string ch)
    {
        chemin=ch;
    }

    string Occurence::getChemin()const
    {
        return chemin;
    }

    /*std::ostream& operator<<(std::ostream& flux, Occurence occ)
    {
        flux<<occ.mot<<":"<<occ.nbocc<<":"<<occ.chemin<<endl;
        return flux;
    }*/

    bool Occurence::operator< (const Occurence &v) const
    {
         return (this->nbocc<v.nbocc);
    }
