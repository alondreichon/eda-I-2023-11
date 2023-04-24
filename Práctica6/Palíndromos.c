#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char palabras[100];

struct Dequeue {
    char palabras[100];
    int front;
    int rear;
};

struct Dequeue* createDeque() {
    struct Dequeue* deq = (struct Dequeue*)malloc(sizeof(struct Dequeue));
    deq->front = -1;
    deq->rear = -1;
    return deq;
}

int isFull(struct Dequeue* deq) {
    if(deq->front == 0 && deq->rear == palabras[100]-1) {
        return 1;
    }
    if(deq->front == deq->rear + 1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct Dequeue* deq) {
    if(deq->front == -1) {
        return 1;
    }
    return 0;
}


void insertFront(struct Dequeue* deq, char palabra1) {
    if(isFull(deq)) {
        printf("Cola doble llena\n");
        return;
    }
    if(deq->front == -1) {
        deq->front = 0;
        deq->rear = 0;
    }
    else if(deq->front == 0) {
        deq->front = palabras[100] - 1;
    }
    else {
        deq->front = deq->front - 1;
    }
    deq->palabras[deq->front] = palabra1;
}

char deleteFront(struct Dequeue* deq) {
    if(isEmpty(deq)) {
        printf("Cola doble vacia\n");
        return '\0';
    }
    char palabra1 = deq->palabras[deq->front];
    if(deq->front == deq->rear) {
        deq->front = -1;
        deq->rear = -1;
    }
    else if(deq->front == palabras[100]-1) {
        deq->front = 0;
    }
    else {
        deq->front = deq->front + 1;
    }
    return palabra1;
}

void insertRear(struct Dequeue* deq, char palabra1) {
    if(isFull(deq)) {
        printf("Cola doble llena\n");
        return;
    }
    if(deq->front == -1) {
        deq->front = 0;
        deq->rear = 0;
    }
    else if(deq->rear == palabras[100]-1) {
        deq->rear = 0;
    }
    else {
        deq->rear = deq->rear + 1;
    }
    deq->palabras[deq->rear] = palabra1;
}

char deleteRear(struct Dequeue* deq) {
    if(isEmpty(deq)) {
        printf("Cola doble vacia\n");
        return '\0';
    }
    char palabra1 = deq->palabras[deq->rear];
    if(deq->front == deq->rear) {
        deq->front = -1;
        deq->rear = -1;
    }
    else if(deq->rear == 0) {
        deq->rear = palabras[100] - 1;
    }
    else {
        deq->rear = deq->rear - 1;
    }
    return palabra1;
}

int palindromo(char* str) {
    int len = strlen(str);
    struct Dequeue* deq = createDeque();
    for(int i = 0; i < len; i++) {
        if(isalpha(str[i])) {
            char c = tolower(str[i]);
            insertRear(deq, c);
        }
    }
    while(deq->front != deq->rear && deq->front != deq->rear + 1) {
        char first = deleteFront(deq);
        char last = deleteRear(deq);
        if(first != last) {
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[100];

    printf("****Bienvenido al Revisor de Palabras****\n");
    printf("Ingrese la palabra:\n");
    scanf("%s",  str);
    if(palindromo(str)){
    printf("La palabra %s es Palindromo!\n", str);
    }else{
        printf("La palabra %s no es Palindromo.\n", str);
    }
    return 0;
}
