#ifndef ORDONNANCEUR_H_INCLUDED
#define ORDONNANCEUR_H_INCLUDED
#include<vector>
#include<map>
#include<string>
#include"Occurence.h"

class Ordonnanceur
{
public:
    Ordonnanceur()
    {
    }
    virtual std::map<std::string,int> trier(std::vector<Occurence>)=0;

};


#endif // ORDONNANCEUR_H_INCLUDED
