#include <iostream>
#include "Btree.h"
using namespace std;

/* INICIANDO ARVORE */
Btree::Btree(){
    Page * root = new Page();
    this->root = root;
    this->order = ORDER;
}
/* OBTENDO A ORDEM*/
Btree::getOrder(){
    return this->order;
}
/* DEFININDO UMA NOVA RAIZ */
void Btree::setRoot(Page * newRoot){
    this->root = newRoot;
}
/* OBTENDO RAIZ */
Page * Btree::getRoot(){
    return this->root;
}
/* FUN��O PARA INSERIR EM UMA PAGINA*/
void Btree::insertToPage(int key, Page * ptk, Page * page){
    int pos = 0;
    while ( key > page->tuples[pos].key && pos < page->num_keys) pos++;
    /* PREPARANDO AS TUPLAS */
    for ( int i = page->num_keys; i > pos; i--){
        page->tuples[i].key = page->tuples[i-1].key;
        page->tuples[i].ptk = page->tuples[i-1].ptk;
    }
    /* INSERINDO NA POSI��O CORRETA */
    //cout << "ANTES "<< page->num_keys << endl;
    page->tuples[pos].key = key;
    page->tuples[pos].ptk = ptk;
    page->up();
    //cout << "DEPOIS "<< page->num_keys << endl;

}
Page * Btree::insertBtree(Page * root, int key, bool * boolean, int *return_key){
    /* RIGHTSON: PONTEIRO PARA O FILHO A DIREITA DA CHAVE NA TUPLA */
    /* BROTHER: PAGINA QUE VAI SER USADA NA CIS�O SE PRECISAR */
    Page * rightSon, *brother;
    brother = new Page();

    /* SE O N� E FOLHA, MELHOR LOCAL PARA INSERIR */
    if ( root == NULL){
        *boolean = true;
        *return_key = key;
        return NULL;
    }

    /* ACHANDO O MELHOR LOCAL PARA INSERIR O ELEMENTO */
    int pos = 0;
    while(key > root->tuples[pos].key && pos < root->num_keys) pos++;

    /* CONDI��ES PARA VERIFICAR SE A CHAVE J� EST� NA �RVORE */
    if ( root->num_keys > pos && root->tuples[pos].key == key){
        cout << "Ja existe a key." << endl;
        *boolean = false;
        delete brother;
    }else{
        /* CHAMANDO RECURSIVAMENTE AT� ALGUM N� FOLHA */
        if ( pos == 0 )
            rightSon = insertBtree(root->pt,key,boolean,return_key);
        else
            rightSon = insertBtree(root->tuples[pos-1].ptk,key,boolean,return_key);

        /* SE O BOOLEAN FOR VERDADEIRO, SINAL QUE TEMOS QUE INSERIR */
        if (*boolean){
            if (root->num_keys < MAX_KEYS){// QUANDO AINDA TEM ESPA�O NA P�GINA
                insertToPage(*return_key,rightSon,root);
                *boolean = false;
            }else{
                cout << "OVERFLOW" << endl;
                // OVERFLOW CASE

                //MUITO IMPORTANTE INSERIR ANTES PARA TER O ELEMENTO CENTRAL DISPON�VEL
                insertToPage(*return_key,rightSon,root);
                //ELEMENTO QUE VAI SUBIR
                int center = root->tuples[MIN_KEYS].key;
                //ADICIONANDO KEYS NO IRM�O NOVO DECORRENTE DA CIS�O
                brother->pt = root->tuples[MIN_KEYS].ptk;
                for ( int i = MIN_KEYS+1; i < MAX_KEYS + 1 ;i++ )
                    insertToPage(root->tuples[i].key,root->tuples[i].ptk,brother);
                //ZERANDO OS ELEMENTOS QUE N�O FAZEM PARTE DA P�GINA DE OVERFLOW
                for ( int i = MIN_KEYS ; i < MAX_KEYS + 1; i++){
                    root->tuples[i].key = 0;
                    root->tuples[i].ptk = NULL;
                }
                //ATUALIZANDO N�MERO DE ELEMENTOS PRO N�MERO M�NIMO
                root->num_keys = MIN_KEYS;
                //CHAVE CENTRAL QUE VAI SERVIR PARA INCLUIR EM OUTRA PAGINA RECURSIVAMENTE
                *return_key = center;
                return brother;
            }
        }
    }
    return root;
}
/* FUN��O P�BLICA PARA INSER��O */
void Btree::insertKey(int key){
    bool boolean = false;
    int return_key;
    Page * rightSon, *newRoot;
    /* CHAMADA INTERNA RECURSIVA PARA CAPTURAR O IRM�O DA DIREITA */
    rightSon = insertBtree(this->root,key,&boolean,&return_key);

    /* SE AQUI O BOOLEAN FOR TRUE, TEREMOS QUE CRIAR UMA NOVA RAIZ */
    if (boolean){
        cout << "OVERFLOW2" << endl;
        /* CRIANDO NOVA RAIZ E SETANDO OS VALORES */
        newRoot = new Page();
        newRoot->num_keys = 1;
        newRoot->tuples[0].key = return_key;
        newRoot->pt = root;
        newRoot->tuples[0].ptk = rightSon;
        setRoot(newRoot);
    }else {
        setRoot(this->root);
    }

}
void Btree::printOnlyPage(Page * page, int h){
    if (page == NULL) return;
    /* DIF: DIFEREN�A DA ALTURA DA ARVORE COM A PAGINA ATUAL */
    int dif = h - heightAux(page);
    /* DEFININDO A MARGEM PARA CADA NIVEL*/
    for ( int i = 0; i < dif; i++ ){
        cout << "  ";
    }
    /* IMPRIMINDO TODA PAGINA */
    cout << "[";
    for ( int i = 0; i < page->num_keys ; i++){
        if (i == page->num_keys-1) cout << page->tuples[i].key;
        else cout << page->tuples[i].key << ",";
    }
    cout << "]" << endl;
    /* CHAMANDO AS OUTRAS RECURSIVAMENTE */
    printOnlyPage(page->pt, h);
    for ( int i = 0; i < page->num_keys ; i++) printOnlyPage(page->tuples[i].ptk, h);

}
/* FUN��O P�BLICA PARA IMPRIMIR */
void Btree::print(){
    printOnlyPage(this->root, height()); // UTILIZANDO FUN��O PRIVADA
}
/* RETORNA O TAMANHO DA �RVORE, FUN��O AUXILIAR E PRIVADA */
int Btree::heightAux(Page * root){
    int alt;
    if (root == NULL) return 0;
    alt = heightAux(root->pt);
    return alt+1;
}
/* RETORNA O TAMANHO DA �RVORE, FUN��O PUBLICA */
int Btree::height(){
    return heightAux(this->root);
}
bool Btree::isLeaf(Page * page){
    if (page->pt == NULL) return true;
    return false;
}
