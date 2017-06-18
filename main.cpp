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
                    cout << "INSIRA UMA CHAVE: ";
                    cin >> key;
                    if (key > 0){
                        tree.insertKey(key);
                        system("cls");
                        cout << "0 - VOLTAR\n" << endl;
                        cout << "-----ARVORE-----" << endl;
                        tree.print();
                        cout << endl;
                    }
                }
                system("cls");
                break;
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                tree.print();
                break;
        }

    } while ( op != 0 );

    /*
    DEFINE A QUANTIDADE DE ELEMENTOS A INSERIR

    int n = 30;
    for ( int i = 0; i < n; i++){
        cout << "INSERINDO CHAVE #" << i << endl;
        tree.insertKey(i);
        cout << "-----ARVORE-----" << endl;
        tree.print();
    }
    */
    /*
    int chave;
    do{
        cout << "INSIRA UMA CHAVE OU 0 PARA SAIR: ";
        cin >> chave;
        cin.ignore();
        cout << "INSERINDO #" << chave << endl;
        tree.insertKey(chave);
        cout << "-----ARVORE-----" << endl;
        tree.print();

    }while(chave != 0);
    */

    return 0;
}

