/**------------------------------
 * Dynamic Queue
 * ------------------------------
 * @autor Alyson Maia <amsq@ecomp.poli.br>
 * @disciplina Estrutura de Dados
 */

#include <stdio.h>
#include <stdlib.h>

/* Definição de constantes */
#define TRUE 1
#define FALSE 0

/* Definição de tipos */
typedef int bool;
typedef int type;

typedef struct node_struct{
    type data;
    struct node_struct* next;
} Node;

typedef struct{
    Node* head;
    Node* tail;
} Queue;

/* Construtores de estruturas */
Node* newNode(type data){
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    newNode->data = data;
    return newNode;
}

Queue* newQueue(){
    Queue* newQueue = (Queue*)calloc(1, sizeof(Queue));
    return newQueue;
}

/* ------------------------------
 * Funções para a fila
 * ------------------------------
 */

/* Verifica se a fila está ou não vazia.
 */
bool isEmpty(Queue* queue){
    return (queue->head == NULL)?TRUE:FALSE;
}

/* Retorna a quantidade de elementos na fila.
 */
int size(Queue* queue){
    int size = 0;
    Node* temp_node = queue->head;
    while(temp_node != NULL){
        size++;
        temp_node = temp_node->next;
    }
    return size;
}

/* Retorna nulo para uma fila vazia ou o
 * primeiro elemento de uma pilha preenchida.
 */
type peek(Queue* queue){
    return (isEmpty(queue))?NULL:queue->head->data;
}

/* Adiciona um novo elemento ao final da lista.
 */
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

/* Se a fila estiver vazia, retorna 0.
 * Se não estiver, retorna o valor do
 * primeiro elemento, libera o espaço
 * de memória e coloca o segundo elemento
 * para ser o novo primeiro.
 */
type deQueue(Queue* queue){
    Node* temp_node;
    type deQueuedValue = 0;
    if(!isEmpty(queue)){
        // temp_node guarda o endereço de memória a ser liberado
        temp_node = queue->head;
        deQueuedValue = queue->head->data;
        queue->head = queue->head->next;
        free(temp_node);
    }
    return deQueuedValue;
}

/* Imprime no console os elementos da fila.
 */
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

/* ------------------------------
 * Funções para o trabalho
 * ------------------------------
 */

/* Inverte todos os elementos da fila passada como parâmetro.
 * Ex: [1, 2, 3] >> [3, 2, 1].
 */
void reverseQueue(Queue* queue){
    Queue* aux1 = newQueue();
    Queue* aux2 = newQueue();
    int i, j;
    //Passa todos os elementos de queue para aux1.
    for(i = size(queue); i > 0; i--){
        enQueue(aux1, deQueue(queue));
    }
    //A variável i, nesse caso, é a metade do tamanho arredondada para cima.
    for(i = (size(aux1)+1)/2; i > 0; i--){
        //Passa todos os elementos de aux1 para aux2, menos o último, que vai para queue.
        for(j = size(aux1); j>0; j--){
            if(j!=1)
                enQueue(aux2, deQueue(aux1));
            else
                enQueue(queue, deQueue(aux1));
        }
        //Passa todos os elementos de aux2 para aux1, menos o último, que vai para queue.
        for(j = size(aux2); j>0; j--){
            if(j!=1)
                enQueue(aux1, deQueue(aux2));
            else
                enQueue(queue, deQueue(aux2));
        }
    }
}

int main(){
    Queue* queue = newQueue();

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    printQueue(queue);

    printf("Invertendo a fila...\n");
    reverseQueue(queue);
    printQueue(queue);

    printf("deQueued: %d\n", deQueue(queue));
    printQueue(queue);

    printf("deQueued: %d\n", deQueue(queue));
    printQueue(queue);

    printf("deQueued: %d\n", deQueue(queue));
    printQueue(queue);

    return 0;
}
