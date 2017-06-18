#ifndef BTREE_H
#define BTREE_H

#include "Page.h"

class Btree
{
    public:
        Btree();
        int getOrder();
        Page * getRoot();
        void print();
        void insertKey(int key);
        int height();
    private:
        int heightAux(Page * root);
        int searchKey(int key);
        void printOnlyPage(Page * page, int h);
        void setRoot(Page * newRoot);
        Page * insertBtree(Page * root, int key, bool * boolean, int *return_key);
        void insertToPage(int key, Page * ptk, Page * page);

        int order;
        Page * root;
};

#endif
