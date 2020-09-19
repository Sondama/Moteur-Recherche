#include"Bibliotheque.h"
#include<vector>
#include<fstream>
#include <iostream>


using namespace std;

Bibliotheque::Bibliotheque(Index* i,Analyseur* a)
{
    chemin="c:/bib/fichier";
    in=i;
    an=a;
    ifstream monFlux(chemin.c_str());

    if(monFlux)
    {
        string ligne;//pour stocker les lignes du fichier qui contient les noms des fichires déja indexé
        while(getline(monFlux, ligne))
        {
            if(ligne != "")
            {
                Fichier f(a,ligne);
                fichiers.push_back(f);
            }
        }
    }
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}



}


void Bibliotheque::ajouterFich(std::string ch)
{
    Fichier fich(an,ch);
    fichiers.push_back(fich);
    std::ofstream out;
    out.open(chemin.c_str(), std::ios::app);
    out << "\n"+ch;
    in->indexerFich(fich);

}

void Bibliotheque::supprimerFich(string ch)
{
    Fichier fich(an,ch);
    vector<Fichier> v;

    for(size_t i=0;i<fichiers.size();i++)
    {
        if(fichiers[i].getChemin()!=ch)
        {
            v.push_back(fichiers[i]);
        }
    }
    fichiers=v;
    ofstream monFlux(chemin.c_str());
    if(monFlux)
    {
        for(size_t i=0;i<fichiers.size();i++)
        {
                monFlux<<fichiers[i].getChemin()<<endl;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    in->suppIndex(ch);

}

void Bibliotheque::afficherBib()
{
    for(size_t i=0;i<fichiers.size();i++)
    {
        cout<<fichiers[i].getChemin()<<endl;
    }
}

bool Bibliotheque::existe(string ch)
{
    bool test=false;
    size_t i=0;
    while((i<fichiers.size())&&(test==false)){
        if(fichiers[i].getChemin()==ch){
            test=true;
        }
        i++;
    }
    return test;
}

void Bibliotheque ::reIndexer(string ch)
{
    Fichier fich(an,ch);
    in->suppIndex(ch);
    in->indexerFich(fich);
}

void Bibliotheque::afficherIndex()
{
    in->afficherIndex();
}

void Bibliotheque::getStatistique()
{
    int s=0;
    for(size_t i=0;i<fichiers.size();i++)
        {
            s+=fichiers[i].nbMots();
        }
    int nbdis=in->nbMotsDistincts();
    int nbdoc=fichiers.size();
    cout<<"on a "<<nbdoc<<" documents, "<<nbdis<<" mots distincts, "<<s<<" mots en totale"<<endl;
}

Bibliotheque::~Bibliotheque()
{

}
