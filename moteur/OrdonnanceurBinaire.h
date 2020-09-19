#ifndef ORDONNANCEURBINAIRE_H_INCLUDED
#define ORDONNANCEURBINAIRE_H_INCLUDED
#include"Ordonnanceur.h"
#include"Occurence.h"
#include<vector>
#include<map>
#include<string>


class OrdonnanceurBinaire: public Ordonnanceur {
public:
    std::map<std::string,int> trier(std::vector<Occurence>);
};


#endif // ORDONNANCEURBINAIRE_H_INCLUDED
