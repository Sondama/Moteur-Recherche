#ifndef INDEXVECTOR_H_INCLUDED
#define INDEXVECTOR_H_INCLUDED
#include"Index.h"

class IndexVector: public Index
{
public:
    IndexVector();
    void indexerFich(Fichier fich);
    virtual ~IndexVector();
};


#endif // INDEXVECTOR_H_INCLUDED
