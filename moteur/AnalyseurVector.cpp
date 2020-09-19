#include"AnalyseurVector.h"
#include<string>
#include<vector>

using namespace std;

vector<Occurence> AnalyseurVector::analyser (vector<string> contenu){
  vector<Occurence> v;
  //cette boucle va creer un vecteur dont les cases comportent le mots avec leurs nombre d'occurence
  for(size_t i=0;i<contenu.size();i++){
        // Est quel'occurence de cette mot est déja  calculé
    bool exist = false;
    for (size_t iv=0; iv<v.size(); iv++){
        if (v[iv].getMot()==contenu[i]) {
            exist = true;
            break;
        }
    }
  //Calculer l'occurence
    if (!exist) {
        int nb = 1;
        for(size_t j=i+1;j<contenu.size();j++){
            if(contenu[i]==contenu[j]){
                nb++;
            }
        }
        Occurence objet(contenu[i],nb);
        v.push_back(objet);
    }
  }
  return v;
}


AnalyseurVector::~AnalyseurVector()
{

}
