#include"OrdonnanceurOcc.h"
#include<string>
#include<vector>
#include<map>
#include<utility>

using namespace std;

map<string,int> OrdonnanceurOcc:: trier(vector<Occurence> v){
    map<string,int> m;
    for(size_t i=0;i<v.size();i++)
        {
            if(m.find(v[i].getChemin())==m.end() )
            {
                m.insert(pair<string,int>(v[i].getChemin(),v[i].getNbocc()));
            }
            else
            {
                m[v[i].getChemin()]+=v[i].getNbocc();
            }
        }

    return m;
}
