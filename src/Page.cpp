#include <iostream>
#include "Page.h"
using namespace std;

/* M�TODOS DA PAGINA */
Page::Page(){
    this->num_keys = 0;
    this->pt = NULL;
    this->tuples = new Tuple[MAX_KEYS];
}
int Page::getNumKeys(){
    return this->num_keys;
}
void Page::up(){
    this->num_keys = this->num_keys + 1;
}
