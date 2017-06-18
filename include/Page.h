#ifndef PAGE_H
#define PAGE_H

/* INCLUDES */
#include <iostream>
#include "Tuple.h"

/* DEFINE A ORDEM */
#define ORDER 2
#define MAX_KEYS ORDER*2
#define MIN_KEYS ORDER

class Page
{
    private:
        int num_keys;
        Page * pt;
        Tuple tuples[MAX_KEYS];
        Page();
        int getNumKeys();
        void up();
    public:
        /* DANDO PERMISSÃO A OUTRA CLASSE */
        friend class Btree;
};

#endif
