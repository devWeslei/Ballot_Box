#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int principal, voto1, voto2, vere1 = 0, vere2 = 0, vere3 = 0, nulo1 = 0, pref1 = 0, pref2 =0, nulo2 = 0;

void voltar(void){   //procedimento para voltar ao inicio.
	system("pause");
	system("cls");
	main();
}

void flush_in(void){  //procedimento para limpar o buffer caso usuario digite erroneamente outros caracteres.
    int ch;
    do{ch = fgetc(stdin);
	}while(ch  != EOF && ch != '\n' );
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	principal = 0;   //resetando a variavel, caso proximo usuario digite valor invalido nao considere o valor da variavel que o usuario passado deixou.
	printf("Escolhas as opções:\n");
	printf("1 - Votar.\n");
	printf("2 - Apurar os votos.\n");
	printf("3 - Sair.\n");
	scanf("%d",&principal, stdin);
	flush_in();
	setbuf(stdin,NULL);
	
	//menu principal
	switch (principal){
		case 1:
			voto1 = 0;   //resetando a variavel, caso proximo usuario digite valor invalido nao considere o valor da variavel que o usuario passado deixou.
			system("cls");
			printf("Qual seu voto para Vereador?\n");
			printf("111 - Vereador Joao do Frete. \n");
    		printf("222 - Vereador Maria da Pamonha. \n");
			printf("333 - Vereador Ze da Farmacia. \n");
			printf("444 - Voto Nulo.\n");
			printf("Digite o seu voto:\n");
			scanf("%d",&voto1, stdin);
			setbuf(stdin,NULL);  //setbuf para limpar o buffer.
				
			switch(voto1){
				case 111:
					printf("Você votou em Joao do Frete!\n\n");
					vere1++;
					break;
				case 222:
					printf("Você votou em Maria da Pamonha!\n\n");
					vere2++;
					break;
				case 333:
					printf("Você votou em Ze da Farmacia!\n\n");
					vere3++;
					break;
				case 444:
					printf("Você votou Nulo!\n\n");
					nulo1++;
					break;
				default:
					printf("Voto inválido!\n\n");
					flush_in();
					setbuf(stdin,NULL);
					break;
			}
			
			voto2 = 0;
			printf("Qual seu voto para Prefeito?\n");
			printf("11 - Prefeito Dr. Zureta.\n");
    		printf("22 - Prefeito Senhor Gomes.\n");
			printf("44 - Voto nulo.\n");
			printf("Digite o seu voto:\n");
			scanf("%d",&voto2, stdin);
			setbuf(stdin,NULL);
			
			switch (voto2){
				case 11:
					printf("Você votou em Prefeito Dr. Zureta!\n\n");
					printf("obrigado por participar!\n\n");
					pref1++;
					voltar();
					break;
				case 22:
					printf("Você votou em Prefeito Senhor Gomes!\n\n");
					printf("obrigado por participar!\n\n");
					pref2++;
					voltar();
					break;
				case 44:
					printf("Você votou nulo!\n\n");
					printf("obrigado por participar!\n\n");
					nulo2++;
					voltar();
					break;
				default:
					printf("Voto inválido!\n\n");
					flush_in();
					setbuf(stdin,NULL);
					voltar();
					break;
			}
			break;	
			
		case 2:
			system("cls");
			printf("Apuração para Vereador:\n");
			printf("Vereador Joao do Frete - %i votos.\n", vere1);
			printf("Vereador Maria da Pamonha - %i votos.\n", vere2);
			printf("Vereador Ze da Farmacia - %i votos.\n", vere3);
			printf("Votos nulos - %i votos\n", nulo1);
			printf("------------------------------------\n");
			printf("Apuração para Prefeito:\n");
			printf("Prefeito Dr. Zureta - %i votos.\n", pref1);
			printf("Prefeito Senhor Gomes - %i votos.\n", pref2);
			printf("Votos nulos - %i votos.\n", nulo2);
			printf("------------------------------------\n\n");
			voltar();
			break;
			
		case 3:
			system("exit");
			break;
		
		default:
			system("cls");
			printf("Por favor, digite uma das opções do menu...\n\n");
			setbuf(stdin,NULL);
			voltar();
			break;
	}
		return 0;
}
