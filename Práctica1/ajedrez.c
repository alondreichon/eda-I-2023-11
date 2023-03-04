#include <stdio.h>

/* Programa para ilustrar los movimientos permitidos para las piezas de ajedrez alifl y torre*/
void moverAlfil();
void moverTorre();

int columnas[8];
int filas[8];

 
int main(){
  char tablero[8][8];
short opcion = 0;
 int x, y;			// x columna, y fila .
  int a, b, c, d, e, f, g;
  //TORRE
    if ((x == 0 && y == 0) ||
		(x == 7 && y == 0) ||
		(x == 0 && y == 7) || (x == 7 && y == 7))
	    {
	      printf ("T");
	    }
      //ALFIL
	  else
	    if ((x == 0 && y == 2) ||
		(x == 7 && y == 2) ||
		(x == 0 && y == 5) || (x == 7 && y == 5))
	    {
	      printf ("A");
	    } 
  
while (1){
      
printf ("\n\t*** Ajedrez ***\n");
      
printf ("¿Que desea realizar?\n");
      
printf ("1) Mover Alfil.\n");
      
printf ("2) Mover Torre.\n");
      
printf ("3) Salir.\n");
      
scanf ("%hd", &opcion);
      
switch (opcion){
	
    case 1:
    moverAlfil();
    break;
	
    case 2:
    moverTorre();
	  break;
	
    case 3:
	  return 0;
	default:
	  printf ("Opcion no valida.\n");
	

        }
 
    }
    return 0;
}

void moverAlfil(){
 int col, fil, i, j, k=0;
 
     printf("Ingrese las coordenadas:\n");
      printf("Ingrese el valor de x:\n"); 
      scanf("%i",&col);
        printf("Ingrese el valor de y:\n"); 
        scanf("%i",&fil);
        char tablero[col][fil];
        char posiciones[col*fil];
        
    for (i=0 ; i<col ; i++)
    for (j=0 ; j<fil ; j++)
    tablero[i][j] = posiciones[k++];

}


void moverTorre(){
    int col, fil, i, j, k=0;
    printf("Ingrese las coordenadas:\n");
      printf("Ingrese la coordenada en x:\n"); 
      scanf("%i",&col);
        printf("Ingrese la coordenada en y:\n"); 
        scanf("%i",&fil);
    char tablero[col][fil];
    char posiciones[col*fil];
       
    for (i=0 ; i<col ; i++)
    for (j=0 ; j<fil ; j++)
    tablero[i][j] = posiciones[k++];
printf("Los movimientos de la Torre seran: \n");
for (i=0 ; i<col ; i++)
 for (j=0 ; j<fil ; j++)
 printf("%c", tablero[j][i]);
 printf("\n");
    if (i==col && j==fil){
        tablero[i][j]="T";
    }
   
}
