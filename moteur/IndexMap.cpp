#include"IndexMap.h"
#include<vector>
#include<fstream>
#include <iostream>
#include<map>
#include<utility>


using namespace std;

IndexMap::IndexMap():Index()
{
}

void IndexMap::indexerFich(Fichier fich)
{
    map<vector<Occurence>, string> stat;
    stat.insert(std::make_pair (fich.getOcc(),fich.getChemin()) );

    for(map< vector<Occurence>,string>::iterator it=stat.begin(); it!=stat.end(); ++it)
        {
            for(size_t j=0;j<fich.getOcc().size();j++)
                {
                    Occurence objet((it->first)[j].getMot(),(it->first)[j].getNbocc(),it->second);
                    occ.push_back(objet);
                }
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

IndexMap::~IndexMap()
{

}
