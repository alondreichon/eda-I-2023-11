#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data) {
  if (last != NULL) return last;

  // asigna memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // se asigna dato al nuevo nodo
  newNode->data = data;

  // se asigna como last al nuevo nodo
  last = newNode;

  // se crea enlace a si mismo
  last->next = last;

  return last;
}

// agregar nodo por el frente
struct Node* addFront(struct Node* last, int data) {
  // se revisa si la lista está vacía
  if (last == NULL) return addToEmpty(last, data);

  // se asigna memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // se agrega dato al nuevo nodo
  newNode->data = data;

  // se guarda la direccion del primer nodo actual en el nuevo nodo
  newNode->next = last->next;

  // se hace al nuevo nodo como la cabeza
  last->next = newNode;

  return last;
}

// agregar nodo al final
struct Node* addEnd(struct Node* last, int data) {
  // se revisa si el nodo está vacío
  if (last == NULL) return addToEmpty(last, data);

  // se asigna memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // se agrega dato al nuevo nodo
  newNode->data = data;

  // se almacena la dirección del nodo cabeza al siguiente del nuevo nodo
  newNode->next = last->next;

  // se apunta el actual último nodo al nuevo nodo
  last->next = newNode;

  // se hace al nuevo nodo como el último nodo
  last = newNode;

  return last;
}

// insertar nodo después de un nodo específico
struct Node* addAfter(struct Node* last, int data, int item) {
  // se revisa si la lista está vacía
  if (last == NULL) return NULL;

  struct Node *newNode, *p;

  p = last->next;
  do {
  // si se encontró el elemento, se coloca el nuevo nodo después de él
    if (p->data == item) {
      // se asigna memoria al nuevo nodo
      newNode = (struct Node*)malloc(sizeof(struct Node));

      // se agrega dato al nodo
      newNode->data = data;

      // se hace como siguiente el nodo actual siguiente del nuevo nodo
      newNode->next = p->next;

      // se pone al nuevo nodo como el siguiente de p
      p->next = newNode;

      // si p es el último nodo, se hace al nuevo nodo como el último nodo
      if (p == last) last = newNode;
      return last;
    }

  p = p->next;
  } while (p != last->next);

  printf("\nEl nodo dado no esta presente en la lista");
  return last;
}

// borrar un nodo
void deleteNode(struct Node** last, int key) {
  // si la lista ligada está vacía
  if (*last == NULL) return;

  // si la lista contiene solo un nodo
  if ((*last)->data == key && (*last)->next == *last) {
    free(*last);
    *last = NULL;
    return;
  }

  struct Node *temp = *last, *d;

  // si se va a eliminar el último
  if ((*last)->data == key) {
    // encontrar el nodo antes del último nodo
    while (temp->next != *last) temp = temp->next;

    // apuntar un nodo temporal al siguiente del último es decir el primer nodo
    temp->next = (*last)->next;
    free(*last);
    *last = temp->next;
  }

  // recorrido al nodo que va a ser eliminado
  while (temp->next != *last && temp->next->data != key) {
    temp = temp->next;
  }

  // si el nodo a eliminar se encuentra
  if (temp->next->data == key) {
    d = temp->next;
    temp->next = d->next;
    free(d);
  }
}

void traverse(struct Node* last) {
  struct Node* p;

  if (last == NULL) {
    printf("La lista esta vacía");
    return;
  }

  p = last->next;

  do {
  printf("%d ", p->data);
  p = p->next;

  } while (p != last->next);
}

void buscar(struct Node* last, int value) {
  if (last == NULL) {
    printf("La lista esta vacía\n");
    return;
  }

  struct Node* p = last->next;
  int found = 0;

  do {
    if (p->data == value) {
      printf("El elemento %d sí se encuentra en la estructura!\n", value);
      found = 1;
      break;
    }
    p = p->next;
  } while (p != last->next);

  if (!found) {
    printf("El elemento %d no se encuetra en la estructura...\n", value);
  }
}

int main() {
  struct Node* last = NULL;

  // Agregar algunos valores a la lista enlazada circular
  last = addEnd(last, 3);
  last = addEnd(last, 6);
  last = addEnd(last, 13);
  last = addEnd(last, 28);

  int valor;
  printf("Bienvenido, va realizar una busqueda...\n");
  printf("Ingrese un valor: ");
  scanf("%d", &valor);

  buscar(last, valor);

  printf("\nMostrando estructura:\n");
    traverse(last);
    printf("\n");
  return 0;
}
