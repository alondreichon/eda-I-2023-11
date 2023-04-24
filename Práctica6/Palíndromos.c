#include <stdio.h>
#include <stdlib.h>

void inicializar(){
    char palabra[20];
    printf("Ingrese la palabra:\n");
    scanf("%s",  palabra);
    printf("La palabra %s es ...", palabra);
}


int main(){
    printf("****Bienvenido al Revisor de Palabras****\n");
    inicializar();
    return 0;
}
