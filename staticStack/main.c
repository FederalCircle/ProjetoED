#include <stdio.h>
#include <stdlib.h>

/* ------------------------------
 * Constantes e Tipos
 * ------------------------------
 */
// Define o tamanho de Stack->data.
#define MAX 20
// Define o tipo de Stack->data.
typedef int type;
// Estrutura Stack.
typedef struct {
    type data[MAX];
    int top;
} Stack;

/* ------------------------------
 * Funções para a pilha
 * ------------------------------
 */
/* Aloca um espaço de memórica com o tamanho
 * da estrutura pilha e preenche todos os
 * bits com 0.
 */
Stack* newStack(){
    Stack* newStack = (Stack*)calloc(1, sizeof(Stack));
    return newStack;
}
// Verifica se há elementos na pilha.
int isEmpty(Stack* stk){
    return (stk->top == 0);
}
// Verifica se a pilha está completamente preenchida.
int isFull(Stack* stk){
    return (stk->top == MAX);
}
// Insere um elemento no topo da pilha.
void push(Stack* stk, type data){
    if(!isFull(stk)){
        stk->data[stk->top++]=data;
    }
}
// Retorna um elemento do topo da pilha
type pop(Stack* stk){
    if(!isEmpty(stk)){
        return stk->data[--stk->top];
    }
    return -1;
}
/* Imprime os elementos da pilha na
 * ordem que que serão removidos.
 */
void printStack(Stack* stk){
    int i;
    printf("Stack Data:\n");
    for(i=stk->top-1; i>=0; i--){
        printf("%d\n", stk->data[i]);
    }
    printf("--X--\n\n");
}

/* ------------------------------
 * Algoritmos p/ questões
 * ------------------------------
 */
/* Adiciona todos os algarsmos de
 * um número passado como parâmetro
 * em Stack->data.
 */
void stackInt(Stack* stk, int num){
    do{
        push(stk, num%10);
        num /= 10;
    }while(num>0);
}
/* Adiciona todos os caracteres de
 * um número passado como parâmetro
 * em Stack->data.
 */
void stackString(Stack* stk, char* str){
    int i;
    for(i=0; str[i]!='\0'; i++){
        push(stk, str[i]);
    }
}
/* Verifica se a pilha passada como
 * parâmetro pode ser considerada um
 * palíndromo. Retorna 1 para SIM e
 * 0 para NÃO.
 */
int palindrome(Stack* stk){
    int i, j;
    int isPalindrome = 1; //Boolean
    for(i=0, j=stk->top-1; i<=j; i++, j--){
        if(stk->data[i] != stk->data[j]){
            isPalindrome=0;
        }
    }
    return isPalindrome;
}

/* ------------------------------
 * Main
 * ------------------------------
 */
int main(){
    Stack* stk = newStack();
    stackInt(stk, 7132);
    printStack(stk);

    stk = newStack();
    stackString(stk, "e3a1a3e");
    printf("is %s palindrome\n", (palindrome(stk))?"\b":"not");

    stk = newStack();
    stackString(stk, "h3110W0r1d");
    printf("is %s palindrome\n", (palindrome(stk))?"\b":"not");
    return 0;
}
