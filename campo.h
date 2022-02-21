#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include "colors.h"
#define MAX 50

void fimDeJogo(){
    int lin = 13, col  = 15, cont = 0;
    char campo[lin][col];
    int i, j;
    while(cont < 4){
        //Circulo Central
        campo[6][5] = 111;
        campo[6][6] = 111;
        campo[6][7] = 111;
        campo[6][8] = 111;
        campo[6][9] = 111;
        campo[5][6] = 111;
        campo[5][7] = 111;
        campo[5][8] = 111;
        campo[4][7] = 111;
        campo[7][6] = 111;
        campo[7][7] = 111;
        campo[7][8] = 111;
        campo[8][7] = 111;

        //Bordas
        for(j = 3; j < 12; j++){
            campo[1][j] = 46;
        }
        for(j = 3; j < 12; j++){
            campo[11][j] = 46;
        }
        for(i = 3; i < 10; i++){
            campo[i][13] = 46;
        }
        for(i = 3; i < 10; i++){
            campo[i][1] = 46;
        }
        for(i = 2; i < 4; i++){
            campo[i][7] = 46;
        }
        for(i = 9; i < 11; i++){
            campo[i][7] = 46;
        }
        for(j = 2; j < 5; j++){
            campo[6][j] = 46;
        }
        for(j = 10; j < 13; j++){
            campo[6][j] = 46;
        }

        //Bordas Diagonais
        campo[3][2] = 46;
        campo[2][2] = 46;
        campo[2][3] = 46;
        campo[2][11] = 46;
        campo[2][12] = 46;
        campo[3][12] = 46;
        campo[9][12] = 46;
        campo[10][12] = 46;
        campo[10][11] = 46;
        campo[9][2] = 46;
        campo[10][2] = 46;
        campo[10][3] = 46;

        //Meio
        campo[4][8] = 46;
        campo[5][9] = 46;
        campo[7][9] = 46;
        campo[8][8] = 46;
        campo[8][6] = 46;
        campo[7][5] = 46;
        campo[5][5] = 46;
        campo[4][6] = 46;

        //definindo as cores
        if(cont == 0){
            campo[5][2] = 48;
            campo[5][3] = 48;
            campo[5][4] = 48;
            campo[4][2] = 48;
            campo[4][3] = 48;
            campo[4][4] = 48;
            campo[4][5] = 48;
            campo[3][3] = 48;
            campo[3][4] = 48;
            campo[3][5] = 48;
            campo[3][6] = 48;
            campo[2][4] = 48;
            campo[2][5] = 48;
            campo[2][6] = 48;
        }else{
            if(cont == 1){
                campo[5][10] = 49;
                campo[5][11] = 49;
                campo[5][12] = 49;
                campo[4][9] = 49;
                campo[4][10] = 49;
                campo[4][11] = 49;
                campo[4][12] = 49;
                campo[3][8] = 49;
                campo[3][9] = 49;
                campo[3][10] = 49;
                campo[3][11] = 49;
                campo[2][8] = 49;
                campo[2][9] = 49;
                campo[2][10] = 49;
            }else{
                if(cont == 2){
                    campo[7][2] = 50;
                    campo[7][3] = 50;
                    campo[7][4] = 50;
                    campo[8][2] = 50;
                    campo[8][3] = 50;
                    campo[8][4] = 50;
                    campo[8][5] = 50;
                    campo[9][3] = 50;
                    campo[9][4] = 50;
                    campo[9][5] = 50;
                    campo[9][6] = 50;
                    campo[10][4] = 50;
                    campo[10][5] = 50;
                    campo[10][6] = 50;
                }else{
                    if(cont == 3){
                        campo[10][8] = 51;
                        campo[10][9] = 51;
                        campo[10][10] = 51;
                        campo[9][8] = 51;
                        campo[9][9] = 51;
                        campo[9][10] = 51;
                        campo[9][11] = 51;
                        campo[8][9] = 51;
                        campo[8][10] = 51;
                        campo[8][11] = 51;
                        campo[8][12] = 51;
                        campo[7][10] = 51;
                        campo[7][11] = 51;
                        campo[7][12] = 51;
                    }
                }
            }
        }
        for(i = 0; i < lin; i++){
            for(j = 0; j < col; j++){
                if(campo[i][j] != '0' && campo[i][j] != '1' && campo[i][j] != '2' && campo[i][j] != '3' && campo[i][j] != 'o' && campo[i][j] != '.'){
                    campo[i][j] = 255;
                }
            }
        }
        foreground(GREEN);
        printf("   GA");
        style(UNDERLINE);
        style(RESETALL);
        foreground(RED);
        printf("ME ");
        style(UNDERLINE);
        style(RESETALL);
        foreground(YELLOW);
        printf("OV");
        style(UNDERLINE);
        style(RESETALL);
        foreground(BLUE);
        printf("ER\n");
        style(UNDERLINE);
        style(RESETALL);
        for(i = 0; i < lin; i++){
            for(j = 0; j < col; j++){
                if(campo[i][j] == '0'){
                    foreground(GREEN);
                    printf("%c", campo[i][j]);
                    style(RESETALL);
                }else{
                    if(campo[i][j] == 49){
                        foreground(RED);
                        printf("%c", campo[i][j]);
                        style(RESETALL);
                    }else{
                        if(campo[i][j] == 50){
                            foreground(YELLOW);
                            printf("%c", campo[i][j]);
                            style(RESETALL);
                        }else{
                            if(campo[i][j] == 51){
                                foreground(BLUE);
                                printf("%c", campo[i][j]);
                                style(RESETALL);
                            }else{
                                printf("%c", campo[i][j]);
                            }
                        }
                    }
                }
            }
            printf("\n");
        }
        //int ans = aux;
        //printf("Resposta: %d\n", ans);
        sleep(1);
        system("cls");
        cont++;
    }
}

