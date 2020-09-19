#include"OrdonnanceurBinaire.h"
#include<string>
#include<vector>
#include<map>
#include<utility>

using namespace std;

map<string,int> OrdonnanceurBinaire:: trier(vector<Occurence> v){
    map<string,int> m;
    for(size_t i=0;i<v.size();i++)
        {
            if(m.find(v[i].getChemin())==m.end() )
            {
                m.insert(pair<string,int>(v[i].getChemin(),1));
            }
            else
            {
                m[v[i].getChemin()]+=1;
            }
        }

    return m;
}
