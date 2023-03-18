#include <stdio.h>
#include <stdlib.h>

void moverCaballo();
void moverAlfil();
void moverTorre();
void moverReina();
void moverRey();

void pintaTablero();


short opcion = 0;

char tablero[8][8];

int main(){
    

    while (1){
      
    printf ("\n\t*** Ajedrez ***\n");
      
    printf ("¿Que desea realizar?\n");
      
    printf ("1) Caballo.\n");   
      
    printf ("2) Alfil.\n");

    printf("3) Torre. \n");

    printf("4) Reina. \n");

    printf("5) Rey. \n");
      
    printf ("6) Salir.\n");
      
    scanf ("%hd", &opcion);
    
      
switch (opcion){
	
    case 1:
    moverCaballo();
   
    break;
	
    case 2:
    moverAlfil();
   
	  break;

    case 3:
    moverTorre();
   
    break;

    case 4:
    moverReina();
  
    break;

    case 5:
    moverRey();
   
    break;

    case 6:
	  return 0;
	default:
	  printf ("Opcion no valida.\n");
	
        }
 
    }
    return 0;
}

int movimientosValidos(int x, int y){
    if(x <0 || y < 0 || x >7 || y >7){
        return 0;
    }
    return 1;
}

struct caballo{
    int x; 
    int y; 
};



void movimientosCaballo(struct caballo c, char tablero[8][8]){
    int i, j, x, y;
    int dx[]= {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[]={1, -1, 1, -1, 2, -2, 2, -2 };

    for (i = 0; i < 8; i++) {
        x = c.x + dx[i];
        y = c.y + dy[i];

        if (movimientosValidos(x, y)) {
            tablero[x][y] = '*';
        }
    }
}

void moverCaballo(){
   char tablero[8][8];
    struct caballo c;
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
            else {
                if (j % 2 == 1) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
        }
    }


    printf("Ingrese las coordenadas del Caballo: \n");
   
    printf("Ingrese la coordenada en x:\n");
           scanf("%d", &c.x);

    printf("Ingrese la coordenada en y:\n");
      scanf("%d",&c.y);
      
    printf("Los movimientos permitidos seran: \n");
    printf("\n");
    movimientosCaballo(c, tablero);
    pintaTablero(tablero);

    return 0;
    
}

struct alfil{
    int x;
    int y;
};


void movimientosAlfil(struct alfil a, char tablero[8][8]){
    int i, j, x, y;
    int dx[] = {1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1};

    for (i = 0; i < 4; i++) {
        x = a.x;
        y = a.y;
        
        while (movimientosValidos(x, y)) {
            x += dx[i];
            y += dy[i];

            if (movimientosValidos(x, y)) {
                tablero[x][y] = '*';

                if (tablero[x][y] != ' ') {
                    break;
                }
            }
        }
        
    }
}


void moverAlfil(){
    char tablero[8][8];
    struct alfil a;
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
            else {
                if (j % 2 == 1) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
        }
    }

    printf("Ingrese las coordenadas del Alfil: \n");
   
    printf("Ingrese la coordenada en x:\n");
    scanf("%d", &a.x);

    printf("Ingrese la coordenada en y:\n");
    scanf("%d",&a.y);
      
    printf("Los movimientos permitidos seran: \n");
    printf("\n");
    movimientosAlfil(a, tablero);
    pintaTablero(tablero);

    return 0;  
   
}

struct torre{
    int x;
    int y;
};

void movimientosTorre(struct torre t,char tablero[8][8]){
    int i, x, y;

    for (i = 0; i < 8; i++) {
        x = t.x;
        y = i;

        if (movimientosValidos(x, y)) {
            tablero[x][y] = '*';

            if (tablero[x][y] != ' ') {
                break;
            }
        }
    }

 
    for (i = 0; i < 8; i++) {
        x = i;
        y = t.y;

        if (movimientosValidos(x, y)) {
            tablero[x][y] = '*';

            if (tablero[x][y] != ' ') {
                break;
            }
        }
    }
}
    
void moverTorre(){
    char tablero[8][8];
    struct torre t;
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
            else {
                if (j % 2 == 1) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
        }
    }

    printf("Ingrese las coordenadas de la Torre: \n");
   
    printf("Ingrese la coordenada en x:\n");
    scanf("%d", &t.x);

    printf("Ingrese la coordenada en y:\n");
    scanf("%d", &t.y);
      
    printf("Los movimientos permitidos seran: \n");
    printf("\n");
    movimientosTorre(t, tablero);
    pintaTablero(tablero);

    return 0;
}

struct reina{
    int x;
    int y;
};

void movimientosReina(struct reina q, char tablero[8][8]){
    int i, x, y;

    for (i = 0; i < 8; i++) {
        x = q.x;
        y = i;

        if (movimientosValidos(x, y)) {
            tablero[x][y] = '*';

            if (tablero[x][y] != ' ') {
                break;
            }
        }
    }
    
    for (i = 0; i < 8; i++) {
        x = i;
        y = q.y;

        if (movimientosValidos(x, y)) {
            tablero[x][y] = '*';

            if (tablero[x][y] != ' ') {
                break;
            }
        }
    }
    
    for (i = 0; i < 8; i++) {
        x = q.x + i;
        y = q.y + i;

        if (movimientosValidos(x, y)) {
            tablero[x][y] = '*';

            if (tablero[x][y] != ' ') {
                break;
            }
        }
    }
    
    for (i = 0; i < 8; i++) {
        x = q.x - i;
        y = q.y + i;

        if (movimientosValidos(x, y)) {
            tablero[x][y] = '*';

            if (tablero[x][y] != ' ') {
                break;
            }
        }
    }
    
}

void moverReina(){
   char tablero[8][8];
    struct reina q;
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
            else {
                if (j % 2 == 1) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
        }
    }

    printf("Ingrese las coordenadas de la Reina: \n");
   
    printf("Ingrese la coordenada en x:\n");
    scanf("%d", &q.x);

    printf("Ingrese la coordenada en y:\n");
    scanf("%d", &q.y);
      
    printf("Los movimientos permitidos seran: \n");
    printf("\n");
    movimientosReina(q, tablero);
    pintaTablero(tablero);

    return 0;
}

struct rey{
    int x;
    int y;
};

void movimientosRey(struct rey k, char tablero[8][8]){
    int i, j, x, y;
    int dx[]= {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[]= {1, 0, -1, 1, -1, 1, 0, -1};

    for (i = 0; i < 8; i++) {
        x = k.x + dx[i];
        y = k.y + dy[i];

        if (movimientosValidos(x, y)) {
            tablero[x][y] = '*';
        }
    }
}

void moverRey(){
    char tablero[8][8];
    struct rey k;
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
            else {
                if (j % 2 == 1) {
                    tablero[i][j] = ' ';
                }
                else {
                    tablero[i][j] = '#';
                }
            }
        }
    }
    
    printf("Ingrese las coordenadas del Rey: \n");
   
    printf("Ingrese la coordenada en x:\n");
    scanf("%d", &k.x);

    printf("Ingrese la coordenada en y:\n");
    scanf("%d", &k.y);
      
    printf("Los movimientos permitidos seran: \n");
    printf("\n");
    movimientosRey(k, tablero);
    pintaTablero(tablero);

    return 0;
}


void pintaTablero(char tablero[8][8]) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}
