#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED
#include<string>
#include<vector>
#include"Occurence.h"
#include"Fichier.h"

class Index{
protected:
    std::string chemin;
    std::vector<Occurence> occ;
public:
    Index();
    std::vector<Occurence> getIndex();
    std::vector<Occurence> getOcc() const;
    virtual void indexerFich(Fichier fich)=0;
    void suppIndex(std::string chemin);
    void afficherIndex();
    int nbMotsDistincts();
    std::vector<Occurence> getstat(std::string mot);//on va afficher les triplets dont le mot est celui donner en paramétre
    virtual ~Index();
};

#endif // INDEX_H_INCLUDED
