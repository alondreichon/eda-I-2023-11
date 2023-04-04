#include <stdio.h>
#include <stdlib.h>
void formarse();

int main(){
    short opcion = 0;

    while (1){
        printf ("\n\t*** Sistema de Turnos ***\n");
      
        printf ("Elija una opcion: \n");
      
        printf ("1) Formarse.\n");
      
        printf ("2) Salir.\n");
      
        scanf ("%hd", &opcion);
      
        switch (opcion){
	
    case 1:
    formarse();
    break;
	
    case 2:
	  return 0;
	default:
	  printf ("Opcion no valida.\n");
	
        }
 
    }

}

formarse(){
    return 0;
}