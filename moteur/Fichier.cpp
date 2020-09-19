#include <iostream>
#include"Fichier.h"
#include<string>
#include<vector>
#include<fstream>

using namespace std;

Fichier::Fichier(Analyseur* an, string ch)
{
    chemin=ch;
    extraireMot();
    occ=an->analyser(contenu);
}

void Fichier::setChemin(string s)
{
    chemin=s;
}

void Fichier::setContenu(vector<string> v)
{
    contenu=v;
}
void Fichier::setOcc(std::vector<Occurence> ve)
{
    occ=ve;
}
string Fichier::getChemin()const
{
    return chemin;
}
vector<std::string> Fichier::getContenu()const
{
    return contenu;
}
vector<Occurence> Fichier::getOcc ()const
{
    return occ;
}

void Fichier::extraireMot()
{
    ifstream monFlux(chemin.c_str());

    if(monFlux)
    {
        string mot; //pour stocker les mots du fichier
        while(monFlux>>mot)
        {
            contenu.push_back(mot);
        }
    }
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}


}
int Fichier::nbMots()
{
    return contenu.size();
}
