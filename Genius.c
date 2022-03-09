#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include "pilha.h"
#include "colors.h"
#define MAXSIZE 5

int main(){

	//Inicialização das pilhas
	Pilha A;
	Pilha B;
	Pilha C;

	iniPilha(&A);
	iniPilha(&B);
	iniPilha(&C);

	//Definindo tamanho do jogo
	int tam;
	system("cls");
	/*
	printf("Tamanho do jogo: ");
	scanf("%d", &tam);
	*/
	system("cls");
	foreground(RED);
	printf("\n SEJAM BEM VINDOS AO GENIUS! made by Eduardo Pires and Rafael Roesler Otto");
    printf("\n");
    style(RESETALL);
    foreground(BLUE);
    printf("\n Disciplina: Algoritmos e Estrutura de Dados 1");
    printf("\n Professor(a): Luciane Telinski Wiedermann Agner");
    printf("\n");
    style(RESETALL);
    foreground(GREEN);
    printf("\n Dificuldades:");
    printf("\n Facil - Tamanho do jogo eh igual a 5 combinacoes");
    printf("\n Medio - Tamanho do jogo eh igual a 7 combinacoes");
    printf("\n Dificil - Tamanho do jogo eh igual a 10 combinacoes");
    printf("\n");
    printf("\n");
    style(RESETALL);

	//Definindo dificuldade do jogo
	int num, ans, i = 0;
	srand(time(NULL));
	//campo();
	foreground(YELLOW);
	printf(" Selecione a dificuldade do jogo!\n");
	printf(" 1 - Facil\n 2 - Medio\n 3 - Dificil\n");
	scanf("%d", &ans);
	style(RESETALL);
	switch(ans){
		case 1:
			tam = 5;
			for(i = 0; i <tam; i++){
				num = rand()%4;
				push(&A, num);
			}
			break;
		case 2:
			tam = 7;
			for(i = 0; i <tam; i++){
				num = rand()%4;
				push(&A, num);
			}
			break;
		case 3:
			tam = 10;
			for(i = 0; i <tam; i++){
				num = rand()%4;
				push(&A, num);
			}
			break;
	}
	system("cls");

	//Inicio do programa
	int cont = 1, cont2, ans1, aux;
	float slp = 1;
	i = -1;
	while(cont <= tam){
		if(fullPilha(&A) != 1){
			for(i; i < cont-1; i++){
				push(&B, pop(&A));
			}
		}
		//listar(&B);
		imprimeGenius(&B);
		printf("\n");
		printf("\n");
		//sleep(slp);
		slp = slp+0.25;//colocar no listar
		system("cls");
		cont2 = 0;
		while(cont2 < cont){
			printf("\n");
			printaVazio();
			printf("\n");
			printf("Resposta: ");
			scanf("%d", &ans1);
			mostraResposta(ans1);
			push(&C, ans1);
			cont2++;
		}
		compara2(&B, &C);
		if(cont < tam){
            while(nullPilhaTeste(&C) == 0){
                pop(&C);
            }
		}
		system("cls");
		cont++;
	}

	//Final do jogo

	//Matheus Hudziak

	printf("PARABENS! VOCE GANHOU!\n");
	printf("\n");
	printf("Sua Resposta:\n");
	listar(&C);
	printf("\n");
	printf("Resposta Correta:\n");
	listar(&B);
	Beep(2000,1000);
	system("pause");
}
