/*
Binária de Pesquisa{
    Sem repetição
    esq: valor maior q raiz local
    dir: valor maior q raiz local
};
Heap;
Fila de Prioridade (máxima e mínima);
Arvore AVL;
Treap;
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/*
● localiza (k,T) : retorna uma referência para o nó da
árvore T que contém a chave igual a k; caso não
exista nenhum item com esta chave, retorna (NULL);
● elimina(k,T) : elimina da árvore T, o item cuja chave
é igual a k.
max(T) : busca última folha à direita;
● min(T) : busca última folha à esquerda;
● imprime(T) : 
*/
struct NODE{
    int elem;
    NODE* r; //right (endereço)
    NODE* l; //left (endereço)
};

NODE* criaArvore(int elem){
    NODE* first = new NODE;
    first->elem = elem;
    first->r=NULL;
    first->l=NULL;
    return(first);
}

int estaVazia(NODE* root){
    if(root == NULL)
        return 1; // 1 para sim
    else 
        return 0; // 0 para não 
}

NODE* busca(NODE* root, int elem){
    if(!estaVazia(root)){
        if(elem < root->elem)
            busca(root->l,elem);
        else if(elem > root->elem)
            busca(root->r,elem);
        return(root);
    }else
    return(NULL);
}

NODE* insere(NODE* root, int elem){

    if(estaVazia(root)){ // encontrou uma ramificação do nó folha
        NODE* node = new NODE;
        node = NULL;

        node = criaArvore(elem);
        
        return(node);
    }else{
        if(elem < (root->elem))
            if(root->l != NULL)                
                insere(root->l,elem); //recursão para encontrar um folha
            else{
                root->l = insere(root->l,elem); //recursão para atribuir um novo nó à esquerda
            }
        else if(elem > (root->elem))
            if(root->r != NULL)                
                insere(root->r,elem);//recursão para encontrar um folha
            else{
                root->r = insere(root->r,elem);//recursão para atribuir um novo nó à direita
            }
        else 
            printf("\nerror\n");
    }
    return(root);
}

int main(){
    struct NODE* root = new NODE;
    int cont, n; // cont vai de 0 a n-1 para delimitar o while

    root = NULL;
    cont = 0;
    n = 0;

    // entrada do parâmetro: n
    printf("numero de entradas (n)\n");
    scanf("%d",&n);

    while(cont < n){
        int elem;
        printf("it\n");
        scanf("%d",&elem);
        root = insere(root,elem);
        cont++;
    }
    //exemplo de busca pelo emento inteiro = 3

    root = busca(root,3);

    if(root!=NULL)
        printf("\n ok \n");
    else
        printf("\n error \n");
    

    return 0;
}