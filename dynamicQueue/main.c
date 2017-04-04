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
    int size;
} Queue;

Node* newNode(type data){
    Node* newQueue = (Node*)calloc(1, sizeof(Node));
    newQueue->data = data;
    return newQueue;
}

Queue* newQueue(){
    Queue* newQueue = (Queue*)calloc(1, sizeof(Queue));
    return newQueue;
}

bool isEmpty(Queue* queue){
    return (queue->size > 0)?TRUE:FALSE;
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

}
