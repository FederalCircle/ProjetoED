/**
 * UPE/POLI - Estrutura de Dados - 2017.1
 * @autor Alyson Maia
 */

#include <stdio.h>
#include <stdlib.h>

/* Definição de tipos */
typedef int type;
typedef struct node_struct{
    type data;
    struct node_struct* left;
    struct node_struct* right;
} Node;
typedef Node* Root;

/* Construtores de estruturas */
Node* newNode(type data){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    newNode->data = data;
    return newNode;
}
Root* newRoot(){
    Root* newRoot = (Root*)calloc(1, sizeof(Root));
    return newRoot;
}

/* Verifica se o nó atual é nulo.
 * Se for nulo, retorna 0, se não for nulo...
 *
 * Verifica se o valor do nó atual é igual ao procurado
 * Se for igual retorna 1, se não for igual...
 *
 * Verifica se o nó atual é maior ou menor que o valor procurado
 * Se for maior, manda o nó da direita recursivamente
 * Se for menor, manda o nó da esquerda recursivamente
 */
int exists(Root* root, type data){
    return (*root == NULL)? 0:(
        ((*root)->data == data)? 1:(
            exists(
                (data > (*root)->data)?
                    &(*root)->right:
                    &(*root)->left,
                data
            )
        )
    );
}
void insert(Root* root, type data){
    if(*root == NULL){
        *root = newNode(data);
        return;
    }
    if((*root)->data == data) return;
    insert(
        (data > (*root)->data)?
            &(*root)->right:
            &(*root)->left,
        data
    );
}
/* Auxiliar para delete() */
Node* _remove_node(Node* node){
    Node *aux, *prev_aux;
    if(node->left == NULL){
        return node->right;
    }
    if(node->right == NULL){
        return node->left;
    }
    prev_aux = NULL;
    aux = node->left;
    while(aux->right != NULL){
        prev_aux = aux;
        aux = aux->right;
    }
    if(prev_aux != NULL) prev_aux->right = NULL;
    aux->right = node->right;
    aux->left = node->left;
    return aux;
}
void delete(Root* root, type data){
    Node* current = *root;
    /*Nó anterior ao procurado*/
    Node* prev = NULL;
    if(exists(root, data)){
        /*Procura o nó com o valor especificado*/
        while(current->data != data){
            prev = current;
            current = (data > current->data)?current->right:current->left;
        }
        /**/
        if(prev == NULL){
            current = _remove_node(current);
            return;
        }
        else if(prev->data < current->data)
            prev->right = _remove_node(current);
        else
            prev->left = _remove_node(current);
        /**/
    }
}
/* função para imprimir a árvore no console horizontalmente */
void print_tree(Root* root, int height){
    int i;
    if(*root == NULL) return;
    print_tree(&(*root)->right, height+1);
    for(i=height; i>0; i--) putchar('\t');
    printf("%d\n", (*root)->data);
    print_tree(&(*root)->left, height+1);
}
int main(){
    Root* root = newRoot();

    insert(root, 10);
    insert(root, 15);
    insert(root, 5);
    insert(root, 20);
    insert(root, 13);
    insert(root, 7);
    insert(root, 2);
    insert(root, 21);
    insert(root, 18);
    insert(root, 8);
    insert(root, 6);

    print_tree(root, 0);
    return 0;
}
