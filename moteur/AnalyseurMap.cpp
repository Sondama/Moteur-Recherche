#include"AnalyseurMap.h"
#include<string>
#include<vector>
#include<map>
#include<utility>
using namespace std;

vector<Occurence> AnalyseurMap::analyser (vector<string> contenu){
  map<string,int> v;

  //cette boucle va creer un vecteur dont les cases comportent le mots avec leurs nombre d'occurence
  for(size_t i=0;i<contenu.size();i++){
        if(v.find(contenu[i])==v.end() ){
            v.insert(pair<string,int>(contenu[i],1));
        }
        else{
            v[contenu[i]]+=1;
        }
  }
  //on va creer un vecteur d'occurence à partir de ce map
  vector<Occurence> vec;
  for(map< string,int>::iterator it=v.begin(); it!=v.end(); ++it){
    Occurence objet(it->first,it->second);
    vec.push_back(objet);
  }
  return vec;
}

AnalyseurMap::~AnalyseurMap()
{

}
