#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funcoes.h"

int main() {
    int op = -1;
	do {
		printf("\n --- JOGO DA FORCA --- \n");
		printf("\n---------------");
		printf("\n|             |");
		printf("\n|             o");
		printf("\n|            -|-");
		printf("\n|            / \\");
		printf("\n|");
		printf("\n--");
        printf("\n \n O que voce quer fazer? \n");
        printf("\n 1 - Iniciar jogo");
        printf("\n 2 - Ver ranking");
        printf("\n 3 - Ver creditos");
        printf("\n 0 - Encerrar programa \n \n");
		scanf("%d", &op);
		switch(op){
			case 0:
				system("cls");
				printf("Fim do Programa. \n");
				break;
			case 1:
                system("cls");
				jogar();
                break;
			case 2:
                system("cls");
				ranking();
				exit(0);
				break;
			case 3:
                system("cls");
				creditos();
				exit(0);
				break;
			default:
				system("cls");
				printf("Opcao Invalida.");
				break;
		}
	} while(op!=0);
    return 0;
}
