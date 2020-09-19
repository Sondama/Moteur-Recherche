#ifndef ANALYSEURMAP_H_INCLUDED
#define ANALYSEURMAP_H_INCLUDED
#include<string>
#include<vector>
#include"Analyseur.h"

class AnalyseurMap:public Analyseur{
public:
    std::vector<Occurence> analyser (std::vector<std::string> contenu);//fontion pour calculer le nbr d'occurence de chaque mot
    virtual ~AnalyseurMap();
};


#endif // ANALYSEURMAP_H_INCLUDED
