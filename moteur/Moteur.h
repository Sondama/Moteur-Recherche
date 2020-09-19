#ifndef MOTEUR_H_INCLUDED
#define MOTEUR_H_INCLUDED
#include"Bibliotheque.h"
#include"Ordonnanceur.h"
#include<map>
#include<string>

class Moteur
{
    Analyseur* an;
    Index* in;
    Ordonnanceur* ord;
    Bibliotheque* bib;
public:
    Moteur(Analyseur* a,Index* i,Ordonnanceur* o);
    void ajouterFich(std::string ch);
    void ajouterPlusFich(std::vector<std::string> chs);
    void supprimerFich(std::string ch);
    void afficherBib();
    void afficherIndex();
    void reIndexer(std::string ch);
    void getstat();
    std::map<std::string,int> rechercher(std::vector<std::string> req);

};


#endif // MOTEUR_H_INCLUDED
