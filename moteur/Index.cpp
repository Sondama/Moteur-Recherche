#include <iostream>
#include"Index.h"
#include<string>
#include<vector>
#include<fstream>
#include<utility>
#include<sstream>

using namespace std;

Index::Index()
{
    chemin="c:/mp/fichier.txt";
    occ = getIndex();
}

vector<Occurence> Index::getIndex()
{
    vector<Occurence> fich;
    ifstream fichier(chemin.c_str());
    if(fichier)
    {
        string ligne; //Une variable pour stocker les lignes lues
        while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {   //on va decouper chaque ligne en mots ey on ja stocker les triplets de chaque ligne dans strs
            if(ligne != "")//on verifie que le fichier est vide ou pas
            {
                vector<string> strs;
                size_t pos = ligne.find( ' ' );
                size_t initialPos = 0;
                strs.clear();

                // ajouter les premier mots
                while( pos != std::string::npos )
                    {
                        strs.push_back( ligne.substr( initialPos, pos - initialPos ) );
                        initialPos = pos + 1;
                        pos = ligne.find( ' ', initialPos );
                    }

                // ajouter la derniére
                strs.push_back( ligne.substr( initialPos, std::min( pos, ligne.size() ) - initialPos + 1 ) );
                //dans le vecteur strs le champs nbOcc est de type syring pour cela le bout de code dessous convertit le string en entier
                //pour pouvoir constituer l'objet de type occurence de chaque ligne du fichier et stocker le tout dans le vecteur fich
                string s=strs[1];
                int j;
                std::istringstream(s)>>j;
                Occurence objet(strs[0],j,strs[2]);
                fich.push_back(objet);
            }

      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   return fich;

}

void Index::suppIndex(string ch)
{
    vector<Occurence> v;
    for(size_t i=0;i<occ.size();i++)
    {
        if(occ[i].getChemin()!=ch)
            {
                v.push_back(occ[i]);
            }
    }

    occ = v;
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


void Index::afficherIndex()
{
    //le vecteur occ contient les données déja existant dans le fichier index et le resultat d'une nouvelle indexation d'un fichier
    for(size_t i=0;i<occ.size();i++)
        {
            cout<<occ[i].getMot()<<" "<<occ[i].getNbocc()<<" "<<occ[i].getChemin()<<endl;
        }
}
// on va parcourir tout le fichier de l'index contenant toutes les données à l'aide du vecteur occ qui représente deja tout le fichier aprés
//on va extraire tous les tripltes dont leurs mot est celui donner en paramétre
vector<Occurence> Index:: getstat(string mot)
{
    vector<Occurence> stat;
    for(size_t i=0;i<occ.size();i++)
        {
            if(occ[i].getMot()==mot)
            {
                stat.push_back(occ[i]);
            }
        }

    return stat;
}
vector<Occurence> Index:: getOcc() const
{
    return occ;
}

int Index::nbMotsDistincts()
{
    return occ.size();
}

Index::~Index()
{

}
