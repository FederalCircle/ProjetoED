#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

/**
 * --------------------
 * Doubly Linked List
 * --------------------
 * @author Alyson Maia
 */

/* Type */
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} Node;
typedef struct{
    Node* start;
    Node* end;
    int size;
} List;

/* Init Functions */
Node* newNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
List* newList(){
    List* newList = (List*) malloc(sizeof(List));
    newList->start = NULL;
    newList->end = NULL;
    return newList;
}

/* Other Functions */
int size(List* list){
    int size = 0;
    if(list->start != NULL){
        Node* temp = list->start;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
    }
    return size;
}

int insertData(List* list, int data){
    Node* node = newNode(data);
    if(list->start == NULL){
        list->start = node;
        list->end = node;
        return TRUE;
    }
    else{
        Node* temp = list->start;
        while(temp->data < node->data){
            if(temp->next == NULL){
                list->end->next = node;
                node->prev = list->end;
                list->end = node;
                return TRUE;
            }
            temp = temp->next;
        }
        if(temp->data != node->data){
            node->prev = temp->prev;
            node->next = temp;
            if(temp->prev!=NULL) temp->prev->next = node;
            temp->prev = node;
            if(temp == list->start) list->start = node;
            return TRUE;
        }
        else return FALSE;
    }
}

int removeData(List* list, int data){
    Node* temp = list->start;
    if(temp->data == data){
        list->start = temp->next;
    }
    else{
        while(temp!=NULL){
            if(temp->data == data){
                if(temp->prev!=NULL) temp->prev->next = temp->next;
                if(temp->next!=NULL) temp->next->prev = temp->prev;
                return TRUE;
            }
            temp = temp->next;
        }
    }
    return FALSE;
}

void printList(List* list){
    if(size(list) == 0){
        printf("--- Empty List ---\n");
    }
    else{
        Node* temp = list->start;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        putchar('\n');
    }
}

int main(){
    List* list = newList();

    insertData(list, 3);
    insertData(list, 2);
    insertData(list, 1);
    insertData(list, 5);
    insertData(list, 4);
    printList(list);

    printf("%d\n",size(list));

    removeData(list, 1);
    removeData(list, 3);
    removeData(list, 5);
    printList(list);
    return 0;
}
