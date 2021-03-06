
#include <stdio.h>			
#include <stdlib.h>			
#include <string.h> 

//variaves globais
char posicao;
int num_linha, num_coluna, tam_jogo, cont=0, jog=0;
int menu;

//Declaracao subrotinas
void Jogo();													
int instrucoes();														


//Funcao que inicia jogo
int jogo(){

printf("----------------------------------------------------------\n");
printf("|########################################################|\n");
printf("|###############                        #################|\n");
printf("|###############   JOGO DOS PONTINHOS   #################|\n");
printf("|###############                        #################|\n");
printf("|########################################################|\n");
printf("----------------------------------------------------------\n\n");

printf("Insira o tamanho do jogo:\n");
scanf("%d", &tam_jogo);
	
char matriz[tam_jogo][tam_jogo];

while(1){
		for(int i=0; i<tam_jogo+1; i++){
			for(int j=0; j<tam_jogo+1; j++){

				if(cont == 0)
					matriz[i][j] = '.';

				if(j != tam_jogo)
					printf("%c", matriz[i][j]);
				else
					printf("%c\n", matriz[i][j]);

			}	
		}
				cont = 1;
				printf("\nJogador %d, digite linha, coluna e a posicao:\n", jog);
				scanf("%d %d %c", &num_linha, &num_coluna, &posicao);

				if(posicao == 'h')
					matriz[num_linha][num_coluna] = '_';
				if(posicao == 'v')
					matriz[num_linha][num_coluna] = '|';

				jog = !jog;

		}	
		return 0;
	}

//Funcao de ajuda sobre jogo dos pontinhos
int instrucoes(){
			while(1){
                    printf("\n_____________________________O QUE E O JOGO DOS PONTINHOS?_______________________________");
                    printf("\n\t Cada jogador deve fazer uma reta nas coordenadas...\n");
                    printf("\n_____________________________  O OBJETIVO  _______________________________");
                    printf("\n\n\t O objetivo e fechar o maior numero de quadrados!\n\n");
                    printf("____________________________________________________________________________\n\n");
                    break;
}
}

//Funcao main (principal) com menu, onde cada opcao eu chamo as funcoes desejadas 
int main(){
   int opcaoMenu;
   inicio:
	//menu inicial - mostrar opcoes

while(1) 	
{ 

system("cls");
printf("\n\tMenu\n\nO que voce quer fazer?\n\n1 - Iniciar o Jogo\n2 - Ver Instrucoes\n3 - Sair do jogo\n--> "); 		
printf("\n");
scanf(" %i",&opcaoMenu); 

switch(opcaoMenu) 		
{ 						
	case 1: 			
		{
		jogo();
		}
		
	case 2:
		
		{
			// Função para instruções
		instrucoes();
		system("pause");
		goto inicio; // rotulo que retorna para inicio do menu 
		}
		
	case 3: 			
		{
			system("cls");			
			printf("\n\n\nJogo enecerrado!\n\n\n"); 				
			return 0; 			
			break; 	
			
		}
	default: 			
		{
					
				printf("\nOpcao invalida, tente novamente !"); 
				system("pause");			
		}	
	        }
	} 
}
