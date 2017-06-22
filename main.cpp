#include <iostream>
#include <stdlib.h>
#include "btree.h"
using namespace std;

/*
    TRABALHO DE ESTRUTURA DE DADOS - UFF - 2017
    PROF. ANSELMO MONTENEGRO
    IMPLEMENTAÇÃO DE UMA ÁRVORE B

    DESENVOLVIDO POR JOSE MAURICIO.

    A ORDEM ESTÁ SENDO DEFINIDA NO ARQUIVO PAGE.H
*/

void menu(){

}

int main()
{
    Btree tree; // INICIANDO ARVORE

    /* MENU PRINCIPAL
    int op;
    do{
        cout << "1 - INSERIR 2 - REMOVER 3 - IMPRIMIR 0 - SAIR\n" << endl;
        cin >> op;
        int key = 1;
        switch (op){
            case 1:
                system("cls");
                cout << "0 - VOLTAR\n" << endl;
                key = 1;
                while ( key > 0){
                    cout << "-----ARVORE-----" << endl;
                    tree.print();
                    cout << endl << "INSIRA UMA CHAVE: ";
                    cin >> key;
                    if (key > 0){
                        tree.insertKey(key);
                        system("cls");
                        cout << "0 - VOLTAR\n" << endl;
                    }
                }
                system("cls");
                break;
            case 2:
                system("cls");
                break;
            case 3:
                key = 1;
                while (key != 0){
                    system("cls");
                    cout << "0 - VOLTAR\n" << endl;
                    cout << "-----ARVORE-----" << endl;
                    tree.print();
                    cin >> key;
                }
                system("cls");
                break;
        }

    } while ( op != 0 );
    */


    /*
    DEFINE A QUANTIDADE DE ELEMENTOS A INSERIR
    */

    int n = 20;
    for ( int i = 0; i < n; i++){
        cout << "INSERINDO CHAVE #" << i << endl;
        tree.insertKey(i);
        cout << "-----ARVORE-----" << endl;
        tree.print();
    }

    return 0;
}

