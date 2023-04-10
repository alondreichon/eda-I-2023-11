#include <stdio.h>
#include <stdlib.h>

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

void formarse(struct Pila* pila){
    if(isFull(pila)){
        printf("Ya no hay turnos disponibles...\n");
    }else{
        pila->top++;
        pila->arreglo[pila->top] = pila->top + 1;
        printf("El elemento se encuentra formado en la cola con el turno %d.\n", pila->arreglo[pila->top]);
    }
}

int main(){
    short opcion = 0;
    struct Pila* pila = createStack(10);

    while (1){
        printf ("\n\t*** Sistema de Turnos ***\n");
      
        printf ("Opciones disponibles: \n");
      
        printf ("1) Formarse.\n");
      
        printf ("2) Salir.\n");
      
        scanf ("%hd", &opcion);
      
        switch (opcion){
	
    case 1:
    formarse(pila);
    break;
	
    case 2:
	  return 0;
	default:
	  printf ("Opcion no valida.\n");
	
        }
 
    }

}

