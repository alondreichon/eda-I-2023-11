#include <stdio.h>

void insertar();

void eliminar();

int main(){
short opcion = 0;
 
while (1){
      
printf ("1) Insertar.\n");
      
printf ("2) Eliminar.\n");
      
printf ("3) Salir.\n");
      
scanf ("%hd", &opcion);
      
switch (opcion){
	
    case 1:
    insertar();
    break;
	
    case 2:
    eliminar();
	  break;
	
    case 3:
	  return 0;
	default:
	  printf ("Opcion no valida.\n");
	
        }
 
    }
    return 0;
}

void insertar(){
    printf("hola\n");
}


void eliminar(){
    printf("No\n");
}