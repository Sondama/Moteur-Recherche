#include"IndexVector.h"
#include<vector>
#include<fstream>
#include <iostream>

using namespace std;

IndexVector::IndexVector():Index()
{
}

void IndexVector::indexerFich(Fichier fich)
{
    for(size_t i=0;i<fich.getOcc().size();i++)
    {
        Occurence objet((fich.getOcc())[i].getMot(),(fich.getOcc())[i].getNbocc(),fich.getChemin());
        occ.push_back(objet);
    }

    ofstream monFlux(chemin.c_str());

    if(monFlux)
    {
        for(size_t i=0;i<occ.size();i++)
            {
                monFlux<<occ[i].getMot()<<" "<<occ[i].getNbocc()<<" "<<occ[i].getChemin()<<endl;
            }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

IndexVector::~IndexVector()
{

}

