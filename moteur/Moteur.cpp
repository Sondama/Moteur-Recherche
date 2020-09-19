#include"Ordonnanceur.h"
#include"Bibliotheque.h"
#include"Index.h"
#include"Analyseur.h"
#include"Moteur.h"
#include<string>
#include<vector>
#include <iostream>

using namespace std;

Moteur::Moteur(Analyseur* a,Index* i,Ordonnanceur* o)
{
    an=a;
    in=i;
    ord=o;
    bib = new Bibliotheque(i,a);
}
void Moteur::ajouterFich(string ch)
{
    if(bib->existe(ch))
    {
        cout<<"ce fichier existe deja"<<endl;
    }
    else
    {
       bib->ajouterFich(ch);
    }

}

void Moteur::ajouterPlusFich(vector<string> chs)
{
    for(size_t i=0;i<chs.size();i++)
        {
            if((bib->existe(chs[i])))
            {
                cout<<"le fichier "<<(i+1)<<" existe deja"<<endl;
            }
            else
            {
                bib->ajouterFich(chs[i]);
            }
        }
}

void Moteur::supprimerFich(std::string ch)
{
    bib->supprimerFich(ch);
}

void Moteur::afficherBib()
{
    bib->afficherBib();
}

void Moteur::afficherIndex()
{
    bib->afficherIndex();
}

map<string,int> Moteur::rechercher(vector<string> req)
{
    vector<Occurence> ve;
    for(size_t j=0;j<req.size();j++)
    {
        vector<Occurence> sta=in->getstat(req[j]);
        for(size_t i=0;i<sta.size();i++)
        {
            ve.push_back(sta[i]);
        }
    }
    map<string,int> resultat=ord->trier(ve);

    return resultat;

}

void Moteur::reIndexer(std::string ch)
{
    bib->reIndexer(ch);
}

void Moteur::getstat()
{
    bib->getStatistique();
}
