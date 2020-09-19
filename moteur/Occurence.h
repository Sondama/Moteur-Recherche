#ifndef OCCURENCE_H_INCLUDED
#define OCCURENCE_H_INCLUDED
#include<string>
class Occurence{
std::string mot;
int nbocc;
std::string chemin;
public:
    Occurence(std::string m, int nb=1, std::string ch="");
    void setMot(std::string s);
    void setNbocc(int a);
    std::string getMot()const;
    int getNbocc()const;
    void setChemin(std::string ch);
    std::string getChemin()const;
    friend std::ostream& operator<<(std::ostream& flux, Occurence occ);
    bool operator< (const Occurence &v) const;

};



#endif // OCCURENCE_H_INCLUDED
