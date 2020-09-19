#include <iostream>
#include"Moteur.h"
#include"AnalyseurVector.h"
#include"AnalyseurMap.h"
#include"IndexVector.h"
#include"IndexMap.h"
#include"OrdonnanceurBinaire.h"
#include"OrdonnanceurOcc.h"
#include<cstdlib>
#include<cstdio>
#include<map>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
    int choix=0;
    int n;
    int i=0;
    int j=0;
    int cas1=0;
    int cas2=0;
    int cas3=0;
    std::clock_t start;
    double duration;
    map<string,int> result;
    bool test=true;
    int nbreq;
    bool repeat = true;
    string supp;
    string ch;
    string req;
    string reIn;
    vector<string> fichiers;
    vector<string> reqs;
    string fichier;
    Analyseur* an ;
    an = new AnalyseurVector();
    Index* in;
    in=new IndexMap();
    Ordonnanceur* ord;
    ord=new OrdonnanceurOcc();
    Moteur m(an,in,ord);
    cout<<"*******************BIENVENUE**********************"<<endl;
        while(1)
    {
    cout<<"Pour indexer tapez 1"<<endl;
    cout<<"Pour rechercher tapez 2"<<endl;
    cout<<"Pour changer la configuration tapez 3"<<endl;
    cout<<"pour quitter taper 0 \n";
    cin>>choix;
    switch(choix)
    {
    case 1:
        while(repeat)
        {
            cout<<"--------------------------------------------------"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Pour indexer un fichier tapez 1"<<endl;
            cout<<"Pour indexer plusieurs fichiers tapez 2"<<endl;
            cout<<"Pour afficher la bibliotheque tapez 3"<<endl;
            cout<<"Pour afficher l'index tapez 4"<<endl;
            cout<<"Pour supprimer l'index tapez 5"<<endl;
            cout<<"Pour reindexer un fichier tapez 6"<<endl;
            cout<<"Pour afficher les statistiques de l'index tapez 7"<<endl;
            cout<<"pour revenir au menu principal tapez 0 \n";
            cin>>i;
            switch(i){
                case 1:
                    cout<<"entrez le chemin de fichier"<<endl;
                    cin>>ch;
                    m.ajouterFich(ch);
                    break;
                case 2:
                    cout<<"donnez le nombre de fichiers pour indexer"<<endl;
                    cin>>n;
                    for(int i=1;i<(n+1);i++)
                    {
                        cout<<"entrez le chemin de fichier "<<i<<" :";
                        cin>>fichier;
                        cout<<endl;
                        fichiers.push_back(fichier);
                    }

                    m.ajouterPlusFich(fichiers);

                    break;
                case 3:
                    cout<<"--------------------------------------------------"<<endl;
                    cout<<"la bibliotheque contient ces fichiers: "<<endl;
                    m.afficherBib();
                    break;
                case 4:
                    cout<<"--------------------------------------------------"<<endl;
                    cout<<"le fichier de index contient l'ensemble de ces triplets: "<<endl;
                    m.afficherIndex();
                    break;
                case 5:
                    cout<<"entrer le chemin du fichier que vous voulez supprimer"<<endl;
                    cin>>supp;
                    m.supprimerFich(supp);
                    break;
                case 6:
                    cout<<"entrer le chemin du fichier que vous voulez reindexer avec la nouvelle configuration"<<endl;
                    cin>>reIn;
                    m.reIndexer(reIn);
                    break;
                case 7:
                    cout<<"les statistiques:"<<endl;
                    m.getstat();
                    break;
                case 0:
                    repeat = false;
                    break;
            }
        }

        break;
    case 2:
        cout<<"--------------------------------------------------"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"donner le nombre de mots cles de votre requete"<<endl;
        cin>>nbreq;
        for(int i=1;i<(nbreq+1);i++)
        {
            cout<<"mot cle "<<i<<" : ";
            cin>>req;
            cout<<endl;
            reqs.push_back(req);
        }
        start = std::clock();
        result=m.rechercher(reqs);
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        std::cout<<"printf: "<< duration <<'\n';
        cout<<"le resutat de votre recherche est"<<endl;
        for (map<string, int>::const_iterator itMap = result.begin() ; itMap != result.end() ; ++itMap )
        {
            cout<<itMap->first<<" "<<itMap->second<<endl;
        }

        break;
    case 3:
        while(test)
        {
            cout<<"--------------------------------------------------"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Si vous voulez changer d'analyseur tapez 1"<<endl;
            cout<<"Si vous voulez changer d'index tapez 2"<<endl;
            cout<<"Si vous voulez changer d'ordonanceur 3"<<endl;
            cout<<"pour revenir au menu principal 0 \n";
            cin>>j;
            switch(j){
            case 1:
                cout<<"--------------------------------------------------"<<endl;
                cout<<"Analyseur Vector tapez 1"<<endl;
                cout<<"Analyseur Map tapez 2"<<endl;
                cin>>cas1;
                switch(cas1){
                case 1:
                    an=new AnalyseurVector;
                    break;
                case 2:
                    an=new AnalyseurMap;
                    break;
                }
                break;
            case 2:
                cout<<"--------------------------------------------------"<<endl;
                cout<<"Index Vector tapez 1"<<endl;
                cout<<"Index Map tapez 2"<<endl;
                cin>>cas2;
                switch(cas2){
                case 1:
                    in=new IndexVector;
                    break;
                case 2:
                    in=new IndexMap;
                    break;
                }
                break;
            case 3:
                cout<<"--------------------------------------------------"<<endl;
                cout<<"Ordonnanceur Occurence tapez 1"<<endl;
                cout<<"Ordonnanceur Binaire tapez 2"<<endl;
                cin>>cas3;
                switch(cas3){
                case 1:
                    ord=new OrdonnanceurOcc;
                    break;
                case 2:
                    ord=new OrdonnanceurBinaire;
                    break;
                }
                break;
            case 0:
                test = false;
                break;
            }
        }
        break;
    case 0:
        exit(0);
    default:
        cout<<"Votre choix est incorrect"<<endl;
        break;

    }}
    ord=new OrdonnanceurBinaire;

    return 0;
}
