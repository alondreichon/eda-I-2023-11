#include <stdio.h>

void moverReina();
void moverRey();
void moverReina1();
void pintaTablero();
void inicializarTablero();
int col=0, fil=0;
int x, y; // x columna, y fila.
char tablero[8][8];

int main(){


short opcion=0;

    while(1){
        printf("\n\t***Ajedrez***\n");
        printf("¿Que desea realizar?\n");
        printf ("1) Mover Reina.\n");
      
        printf ("2) Mover Rey.\n");
      
        printf ("3) Salir.\n");
      
        scanf ("%hd", &opcion);
    
    inicializarTablero();

    switch (opcion){
	
    case 1:
    moverReina();
    pintaTablero();
    break;
	
    case 2:
    moverRey();
    pintaTablero();
	  break;
	
    case 3:
	    return 0;
	default:
	  printf ("Opcion no valida.\n");
	
        }
    }
    return 0;
}

void moverReina(){
    printf("Ingrese las coordenadas:\n");
      printf("Ingrese la coordenada en x:\n"); 
      scanf("%i",&fil);
        printf("Ingrese la coordenada en y:\n"); 
        scanf("%i",&col);
        tablero[col][fil]='Q';
      
        
}

void moverRey(){
     printf("Ingrese las coordenadas:\n");
      printf("Ingrese la coordenada en x:\n"); 
      scanf("%i",&fil);
        printf("Ingrese la coordenada en y:\n"); 
        scanf("%i",&col);
        tablero[col][fil]='R';
       
       
}

void pintaTablero(){

    for (int i=1 ; i<=8 ; i++){

        for (int j=1 ; j<=8 ; j++){
        printf("%c", tablero[i][j]);
        }
            printf("\n");
    }
    
}

void inicializarTablero(){
    for (int i=0 ; i<=8 ; i++)
    for (int j=0 ; j<=8 ; j++)
    tablero[i][j] = '-';
}

void moverReina1(){
 int col=8, fil=8, i, j, k=0;
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
printf("Los movimientos de la Reina seran: \n");


  	if ((x==0 && y==3) || (x==7 && y==3))
            {
	      printf ("Q");
	    }
	    
	    else{
                printf(" *");
            }

    }
