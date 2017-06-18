#include <iostream>
#include "Tupla.h"
/* DEFINE A ORDEM */
#define ORDEM 2
#define MAX_KEYS ORDEM*2
#define MIN_KEYS ORDEM
using namespace std;

Tupla::Tupla()
{
    //ctor
}

Tupla::~Tupla()
{
    //dtor
}

void Tupla::imprimir(){
    cout << ORDEM << endl;
}
