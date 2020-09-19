#ifndef INDEXMAP_H_INCLUDED
#define INDEXMAP_H_INCLUDED
#include"Index.h"

class IndexMap: public Index
{
public:
    IndexMap();
    void indexerFich(Fichier fich);
    virtual ~IndexMap();
};



#endif // INDEXMAP_H_INCLUDED
