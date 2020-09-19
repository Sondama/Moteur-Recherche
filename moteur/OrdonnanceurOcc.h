#ifndef ORDONNANCEUROCC_H_INCLUDED
#define ORDONNANCEUROCC_H_INCLUDED
#include"Ordonnanceur.h"
#include"Occurence.h"
#include<vector>
#include<map>
#include<string>

class OrdonnanceurOcc: public Ordonnanceur {
public:
    std::map<std::string,int> trier(std::vector<Occurence>);
};


#endif // ORDONNANCEUROCC_H_INCLUDED
