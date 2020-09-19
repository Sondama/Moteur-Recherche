#ifndef BIBLIOTHEQUE_H_INCLUDED
#define BIBLIOTHEQUE_H_INCLUDED
#include<string>
#include"Fichier.h"
#include"Index.h"

class Bibliotheque
{
    std::string chemin;//le chemin ou on va stocker tous les chemin des fichiers entrer chaque fois par l'utilisateur
    std::vector<Fichier> fichiers;//ce vecteur est utiliser pour avoir la liste de tous les fichiers déja indexer avant la fermeture du programme
    Index* in;
    Analyseur* an;
public:
    Bibliotheque(Index* i, Analyseur* a);
    bool existe (std::string ch);
    void ajouterFich(std::string ch);//pour ajouter un fichier à la biblio
    void supprimerFich(std::string ch);//pour supprimer un fichier de la biblio
    void afficherBib();//pour afficher le contenu de la biblio
    void reIndexer(std::string ch);
    void afficherIndex();
    void getStatistique();
    ~Bibliotheque();
};



#endif // BIBLIOTHEQUE_H_INCLUDED
