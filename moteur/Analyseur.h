#ifndef ANALYSEUR_H_INCLUDED
#define ANALYSEUR_H_INCLUDED
#include<string>
#include<vector>
#include"Occurence.h"

class Analyseur{

public:
    Analyseur(){
    }
    virtual std::vector<Occurence> analyser (std::vector<std::string> contenu)=0;//fontion pour calculer le nbr d'occurence de chaque mot
    virtual ~Analyseur();
};



#endif // ANALYSEUR_H_INCLUDED
