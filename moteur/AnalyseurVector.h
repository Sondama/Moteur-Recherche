#ifndef ANALYSEURVECTOR_H_INCLUDED
#define ANALYSEURVECTOR_H_INCLUDED
#include<string>
#include<vector>
#include"Analyseur.h"

class AnalyseurVector: public Analyseur
{
public:
    std::vector<Occurence> analyser (std::vector<std::string> contenu);//fontion pour calculer le nbr d'occurence de chaque mot
    virtual ~AnalyseurVector();
};


#endif // ANALYSEURVECTOR_H_INCLUDED
