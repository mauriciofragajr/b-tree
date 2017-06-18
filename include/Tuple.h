#ifndef TUPLE_H
#define TUPLE_H

/* INCLUDES */
#include <iostream>

class Page;

class Tuple{
    private:
        int key;
        Page * ptk;
        Tuple();
    public:
        /* DANDO PERMISSÃO A OUTRA CLASSE */
        friend class Page;
        friend class Btree;
};

#endif
