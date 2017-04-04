#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int bool;
typedef int type;

typedef struct node_t{
    type data;
    struct node_t* next;
} Node;

typedef struct{
    Node* head;
    Node* tail;
} Queue;

Node* newNode(type data){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    newNode->data = data;
    return newNode;
}

Queue* newQueue(){
    Queue* newQueue = (Queue*)calloc(1, sizeof(Queue));
    return newQueue;
}

bool isEmpty(Queue* queue){
    return (queue->head == NULL)?TRUE:FALSE;
}

void enQueue(Queue* queue, type data){
    Node* node = newNode(data);
    if(isEmpty(queue)){
        queue->head = node;
        queue->tail = node;
    }
    else{
        queue->tail->next = node;
        queue->tail = node;
    }
}

type deQueue(Queue* queue){
    type temp_return = NULL;
    if(!isEmpty(queue)){
        Node* temp_node = queue->head;
        queue->head = queue->head->next;
        temp_return = temp_node->data;
        free(temp_node);
    }
    return temp_return;
}

void printQueue(Queue* queue){
    printf("Queue Data:\n");
    if (isEmpty(queue)){
        printf("--The queue is empty--\n");
    }
    else{
        Node* temp_node = queue->head;
        do {
            printf("%d\n", temp_node->data);
            temp_node = temp_node->next;
        }while(temp_node != NULL);
    }
    putchar('\n');
}

int main(){
    Queue* queue = newQueue();

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    printQueue(queue);

    printf("deQueued: %d\n", deQueue(queue));
    printQueue(queue);

    printf("deQueued: %d\n", deQueue(queue));
    printQueue(queue);

    printf("deQueued: %d\n", deQueue(queue));
    printQueue(queue);

    return 0;
}
