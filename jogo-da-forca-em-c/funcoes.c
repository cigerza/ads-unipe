#include <stdio.h>
#include "funcoes.h"

void forca(int estado);
void jogar();
void abrir_arquivo();
void ranking();
void creditos();

FILE *file;

struct ranki{
    char nome[30];
    int pontuacao;

}r;


void forca(int estado) {
    if(estado==0) {
		printf("\n---------------");
		printf("\n|             |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n--");
	} else if(estado==1) {
	    printf("\n---------------");
		printf("\n|             |");
		printf("\n|             o");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n--");
	} else if(estado==2) {
	    printf("\n---------------");
		printf("\n|             |");
		printf("\n|             o");
		printf("\n|             |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n--");
	} else if(estado==3) {
	    printf("\n---------------");
		printf("\n|             |");
		printf("\n|             o");
		printf("\n             -|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n--");
	} else if(estado==4) {
	    printf("\n---------------");
		printf("\n|             |");
		printf("\n|             o");
		printf("\n|            -|-");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n--");
	} else if(estado==5) {
	    printf("\n---------------");
		printf("\n|             |");
		printf("\n|             o");
		printf("\n|            -|-");
		printf("\n|            /");
		printf("\n|");
		printf("\n|");
		printf("\n--");
	} else if(estado==6) {
	    printf("\n---------------");
		printf("\n|             |");
		printf("\n|             o");
		printf("\n|            -|-");
		printf("\n|            / \\");
		printf("\n|");
		printf("\n|         GAME OVER!");
		printf("\n--       Sua pontuacao e: %d", r.pontuacao);
	}
}




void jogar() {
    abrir_arquivo(); //Abre o arquivo para a gravação

    char palavra_secreta[50], palavra_tela[50];
    int erros=0, correta=0, pontuacao_final=0, pontuacao_inicial=100;
    char letra;
    printf("JOGADOR 1:\n");
    printf("\n Insira a palavra secreta a ser descoberta pelo Jogador 2: ");
    scanf("%s", &palavra_secreta);
    system("cls");

    printf("Digite seu nome jogador 2: ");
    fflush(stdin);
    fgets(r.nome, 30, stdin);
    system("cls");


    strcpy(palavra_tela, palavra_secreta);  //copia a palavra secreta para a palavra que vai aparecer na tela



    for(int i=0; i<strlen(palavra_tela); i++) { //substitui a palavra secreta por underscores

        palavra_tela[i]='_';
    }

    while(1) {
            //imprime a forca sem erros e ja inicia os chutes das letras
            forca(erros);

            printf("\n A palavra secreta e: ");


            for(int i=0; i<strlen(palavra_tela); i++) {

                printf("%c ", palavra_tela[i]);

            }


            printf("\n \n Digite a letra desejada: ");
            scanf(" %c", &letra);
            system("cls");



            int errou=1;  // essa variavel errou vai ser 1 quando o jogador errar e 0 quando acertar.

            for(int i=0; i<strlen(palavra_tela); i++) { // esse for compara a letra digitada em todos os indices da palavra secreta
                if(letra==palavra_secreta[i]) { // entra no if se vc acertou a letra.
                    palavra_tela[i]=letra;
                    errou=0;
                    printf("A pontuacao e: %d", r.pontuacao);


                }


            }

            if(errou==1) { // se nao acertou, incrementa o erro.
                erros++;
                pontuacao_final=pontuacao_inicial - (erros*10);
                r.pontuacao=pontuacao_final;
                printf("A pontuacao e: %d", r.pontuacao);

            }
            if(erros==6){ //Jogador não pontua pq usou todas as chances
                r.pontuacao=0;
            }
            if(erros==0){  // Se jogador acerta todas as letras de primeira.
                r.pontuacao=pontuacao_inicial;

            }


            //Compara as palavras e se forem iguais imprime o acerto.
            if(strcmp(palavra_tela, palavra_secreta)==0) {


                printf("\n Voce acertou! ");
                for(int i=0; i<strlen(palavra_tela); i++) {

                    printf("%c ", palavra_tela[i]);
                }
                printf("\n");
                printf("\n Parabens!! Voce venceu %s!", r.nome);
                printf("\n");
                break;
            }

            if(erros==6) {
                forca(erros);
                break;
            }
    }

    //Escreve os dados no arquivo
    fprintf(file,"\nNome: %s", r.nome);
    fprintf(file,"  Pontuacao: %d\n", r.pontuacao);


    //Fecha o arquivo.
    fclose(file);
}

void abrir_arquivo(){   //Essa função cria o arquivo "ranking.txt" para a gravação de todos os usuarios e suas pontuações

    file = fopen("ranking.txt", "a");

    if(file == NULL){
        printf("Erro na abertura do Arquivo\n");
        system("pause");
        exit(0);
    }
}

void ranking() {

    //system("ranking.txt");   //Exibe a lista dos jogadores salvas no arquivo.

    file = fopen("ranking.txt", "r");  //Exibe a lista dos jogadores salvas no arquivo.
    int ch;
    while((ch=fgetc(file)) !=EOF)
        printf("%c", ch);

    fclose(file);
}

void creditos() {
    printf("\n CREDITOS \n");
    printf("\n Jogo da forca desenvolvido em C para a disciplina Tecnica de Desenvolvimento de Algoritmos, Turma 2020.2, Unipe. \n");
    printf("\n Equipe: \n");
    printf("\n Carolina Cigerza de Camargo");
    printf("\n Fabio Franca Lucena Filho");
    printf("\n Raissa Batista dos Santos Silva");
    printf("\n Weslley Primola Nogueira \n");
}

