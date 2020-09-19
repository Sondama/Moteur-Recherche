#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include<string>
#include<vector>
#include"Occurence.h"
#include"Analyseur.h"

class Fichier{
std::string chemin;
std::vector<std::string> contenu;
std::vector<Occurence> occ;
public:
    Fichier(Analyseur* a, std::string ch );
    void setChemin(std::string s);
    void setContenu(std::vector<std::string> v);
    void setOcc(std::vector<Occurence> ve);
    std::string getChemin()const;
    std::vector<std::string> getContenu()const;
    std::vector<Occurence> getOcc ()const;
    void extraireMot();
    int nbMots();

};

#endif // FICHIER_H_INCLUDED
