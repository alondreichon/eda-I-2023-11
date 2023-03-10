#include <stdio.h>
#include <stdlib.h>
void moverReina(char *tablero,int *Qx,int *Qy);
void moverRey(char *tablero, int *Kx, int *Ky);

int main(){
    int x=0, y=0, i, j, x2, y2;
    char tablero[8][8];
    short opcion = 0;


    printf("Ingrese las coordenadas y,x para iniciar la Reina\n");
    scanf("%i", &x);
    scanf("%i", &y);
    x--;
    y--;
 
    printf("Ingrese las coordenadas y,x para iniciar al Rey\n");
    scanf("%i", &x2);
    scanf("%i", &y2);
    x2--;
    y2--;


    while(opcion!=3){

        for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                if(i%2==0){
                    if(j%2==0){
                        tablero[i][j]=' ';
                    }   
                    else{
                        tablero[i][j]='#';
                    }
                }
                else{
                    if(j%2==1){
                        tablero[i][j]=' ';
                    }   
                    else{
                        tablero[i][j]='#';
                    }
                }
            }
        } 
        tablero[x][y] = 'Q';
        tablero[x2][y2] = 'K';

        printf("\n\t***Ajedrez***\n");

        for(i=0; i<8; i++){
            for(j=0; j<8;j++){
                printf("%c ",tablero[i][j]);
            }  
            printf("\n");
        } 
        printf("\n");
        
        printf("¿Que desea realizar?\n");
        printf ("1) Mover Reina.\n");
        printf ("2) Mover Rey.\n");
        printf ("3) Salir.\n");

        scanf ("%i", &opcion);

        switch (opcion)
        {
        case 1:
            moverReina(tablero[0],&x,&y);
            break;
        
        case 2:
            moverRey(tablero[0],&x2,&y2);
            break;
        case 3:
            return 0;
        default:
            printf("Opcion no valida. \n");
        }
    
    }

}

void moverReina(char *tablero, int *Qx, int *Qy){
    int i, j, Qxprov=*Qx, Qyprov=*Qy, diagonal;
    char tablero2[8][8];
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            tablero2[i][j]=*(tablero+(i*8)+j);
        }
    }
    for(i=0; i<8; i++){
        tablero2[*Qx][i]='*';
    }
    for(i=0; i<8; i++){
        tablero2[i][*Qy]='*';
    }
    while(Qxprov != 0 && Qyprov !=0){
        Qxprov--;
        Qyprov--;
    }
    diagonal = *Qy-*Qx;
    for(i=0; i<abs(diagonal-8); i++){
       tablero2[Qxprov][Qyprov]='*';
       Qxprov++;
       Qyprov++;
    }
    Qxprov = *Qx;
    Qyprov = *Qy;
    while(Qxprov != 8 && Qyprov !=0){
        Qxprov++;
        Qyprov--;
    }
    for(i=0; i<8; i++){
        if(Qxprov>=0 && Qyprov<=8){
            tablero2[Qxprov][Qyprov]='*';
        }
        Qxprov--;
        Qyprov++;
    }
    tablero2[*Qx][*Qy]='Q';
    
    printf("Los movimientos permitidos seran: \n");
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf("%c ", tablero2[i][j]);
        }
        printf("\n");
    }
    
    

}

void moverRey(char *tablero, int *Kx, int *Ky){
    int j=1, kxprov = *Kx-1, kyprov = *Ky-1, i;
    char tablero2[8][8];
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            tablero2[i][j]=*(tablero+(i*8)+j);
        }
    }
    for(i=0; i<2; i++){
        if(kxprov>=0 && kyprov >=0 && kxprov<8 && kyprov<8){
            tablero2[kxprov][kyprov]='*';
        }
        kyprov++;
    }
    for(i=0; i<2; i++){
         if(kxprov>=0 && kyprov >=0 && kxprov<8 && kyprov<8){
            tablero2[kxprov][kyprov]='*';
        }
        kxprov++;
    }
    for(i=0; i<3; i++){
         if(kxprov>=0 && kyprov >=0 && kxprov<8 && kyprov<8){
            tablero2[kxprov][kyprov]='*';
        }
        kyprov--;
    }
    if(kxprov>=0 && kyprov >=0 && kxprov<8 && kyprov<8){
        tablero2[kxprov-1][kyprov+1]='*';
    }
    tablero2[*Kx][*Ky]='K';
    printf("Los movimientos permitidos seran:\n");
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf("%c ", tablero2[i][j]);
        }
        printf("\n");
    }
    

}