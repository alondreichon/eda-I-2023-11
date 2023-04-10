#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Pila {
    int top;
    unsigned capacity;
    int* arreglo;
};

struct Pila* createStack(unsigned capacity)
{
    struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila));
    pila->capacity = capacity;
    pila->top = -1;
    pila->arreglo = (int*)malloc(pila->capacity * sizeof(int));
    return pila;
}

int isFull(struct Pila* pila)
{
    return pila->top == pila->capacity -1;
}

int isEmpty(struct Pila* pila)
{
    return pila->top == -1;
}

void push(struct Pila* pila, int item)
{
    if (isFull(pila)) {
        printf("La pila está llena\n");
    } else {
        pila->top++;
        pila->arreglo[pila->top] = item;
    }
}

int pop(struct Pila* pila)
{
    if (isEmpty(pila)) {
        printf("La pila está vacía\n");
        return -1;
    } else {
        int item = pila->arreglo[pila->top];
        pila->top--;
        return item;
    }
}

struct Cola {
    int front, rear, size;
    unsigned capacity;
    int* arreglo;
};

struct Cola* createQueue(unsigned capacity)
{
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->capacity = capacity;
    cola->front = 0;
    cola->rear = -1;
    cola->size = 0;
    cola->arreglo = (int*)malloc(cola->capacity * sizeof(int));
    return cola;
}

int isQueueFull(struct Cola* cola)
{
    return cola->size == cola->capacity;
}

int isQueueEmpty(struct Cola* cola)
{
    return cola->size == 0;
}

void enqueue(struct Cola* cola, int item)
{
    if (isQueueFull(cola)) {
        printf("La cola está llena\n");
    } else {
        cola->rear = (cola->rear + 1) % cola->capacity;
        cola->arreglo[cola->rear] = item;
        cola->size++;
    }
}

int dequeue(struct Cola* cola)
{
    if (isQueueEmpty(cola)) {
        printf("La cola está vacía\n");
        return -1;
    } else {
        int item = cola->arreglo[cola->front];
        cola->front = (cola->front + 1) % cola->capacity;
        cola->size--;
        return item;
    }
}

void formarse(struct Pila* pila,struct Cola* cola, int* ultimo_formado )
{
    int turno = pop(pila);
    if (turno != -1) {
        enqueue(cola, turno);
        printf("El elemento se encuentra formado en la cola con el turno %d.\n", turno);
        *ultimo_formado = turno;
    } else {
        printf("Ya no hay turnos disponibles...\n");
    }
}

int peek(struct Pila* pila)
{
	if (isEmpty(pila))
		return INT_MIN;
	return pila->arreglo[pila->top];
}

int main(){
    short opcion = 0;
    struct Pila* pila = createStack(10);
    for (int i = 10; i >= 1; i--) {
        push(pila, i);
    }
    
    struct Cola* cola = createQueue(10);
    int ultimo_formado = -1; 
    
    while (1){
        printf ("\n\t*** Sistema de Turnos ***\n");
      
        printf ("\tOpciones disponibles: \n");
      
        printf ("\t1) Formarse.\n");
      
        printf ("\t2) Salir.\n");
      
        scanf ("%hd", &opcion);
      
        switch (opcion){
	
    case 1:
    formarse(pila, cola, &ultimo_formado);
    break;
	
    case 2:
    printf("El ultimo elemento en el tope de la pila es: %d\n", peek(pila));
    printf("El ultimo elemento formado en la cola es %d.\n", ultimo_formado);
	  return 0;
	default:
	  printf ("Opcion no valida.\n");
	
        }
 
    }
    
 

}
