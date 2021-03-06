#include <stdio.h>			
#include <stdlib.h>			
#include <string.h> 

//variaves globais
int num_linha, num_coluna, tam_jogo, cont=0, jog=0;  // variaveis globais usadas no jogo
int opcaoMenu;   // variável des ecolha para inicia jogo, ver instrucoes ou sair

//Declaracao subrotinas
void Jogo();	  // Função que inicializa o jogo												
int instrucoes();   // Função onde é posível ver regras do jogo

//Função que imprime as coordenadas
char coordenada(int tam_jogo, int i, int j){			//Funcao que gera o tamanho do jogo(matriz) a ser jogada
	char matriz[i][j];

	if(i == 0){
		if(j >= 10){
			matriz[i][j] = 'A'+(j-10);		//Transforma numeros compostos em letras
		}else
			matriz[i][j] = j+'0';
	}	
	if(j == 0){
		if(i >= 10){
			matriz[i][j] = 'A'+(i-10);		//Transforma numeros compostos em letras
		}else
			matriz[i][j] = i+'0';
	}
	return matriz[i][j];    // Retorna o tamanho da matriz
}

//Funcao que inicia jogo
int jogo(){
	char jogador1[50], jogador2[50]; 	// variveis que jogadores 1 e 2 com tamnho de 50 caractes

system("cls");

printf("----------------------------------------------------------\n");
printf("|########################################################|\n");
printf("|###############                        #################|\n");
printf("|###############   JOGO DOS PONTINHOS   #################|\n");			//Logotipo do jogo
printf("|###############                        #################|\n");
printf("|########################################################|\n");
printf("----------------------------------------------------------\n\n");

printf("Qual o nome do jodador 1?\n");   //Define o nome do jogador 1
scanf("%s", jogador1);

printf("\nQual o nome do jodador 2?\n"); // Define o nome do jogador 2
scanf("%s", jogador2);

printf("\nInsira o tamanho do jogo (entre 5 e 36):\n");    // define o tamanho do jogo a se jogar , onde pode gerar matrizes de 5 a 36
scanf("%d", &tam_jogo);
	
system("cls");

char matriz[tam_jogo][tam_jogo];

while(1){
	for(int i=0; i<tam_jogo; i++){
		for(int j=0; j<tam_jogo+1; j++){

			if(cont == 0 && j%2 == 0)
				matriz[i][j] = ' ';
			else if(cont == 0)
				matriz[i][j] = '.';
				
			if((j != tam_jogo+1 && i == 0) || (i != tam_jogo+1 && j == 0))
				matriz[i][j] = coordenada(tam_jogo, i, j);
			
			if(j != tam_jogo)
				printf(" %c", matriz[i][j]);
			else
				printf("\n");

		}	
	}
			cont = 1;
			if(jog == 0)
				printf("\n%s, digite linha e coluna:\n", jogador1);	// Informa a linha que se que formar a | (pipe)  ou - (travessão)
			else
				printf("\n%s, digite linha e coluna:\n", jogador2);	// Informa a coluna que se que formar a | (pipe)  ou - (travessão)
							
			scanf("%d %d", &num_linha, &num_coluna);
					
			if(num_coluna % 2 == 0)							//Adiciona | em colunas pontilhadas e _ em espaços vazios
				matriz[num_linha][num_coluna] = '_';
			if(num_coluna % 2 != 0)
				matriz[num_linha][num_coluna] = '|';
					
			jog = !jog;			// Alterna nome dos jogadores
			system("cls");
		}	
		return 0;
	}

//Funcao de instruções
int instrucoes(){
		system("cls");
																//Infomacões sobre as regras do jogo
		while(1){
			printf("\n____________________________________COMO JOGAR____________________________________");
			printf("\n\nCada jogador deve fazer uma reta ('|' vertical, ou '_' horizontal) nas coordenadas.");
			printf("\nGanha aquele que fechar o maior numero de quadrados!\n\n");
			printf("\n______________________________________REGRAS______________________________________");
			printf("\n\n1 - Nao pode sobrepor retas.");
			printf("\n2 - Um quadrado so podera ser completado caso ja houver 3 lados preenchidos.");
			printf("\n3 - Caso o jogador complete um quadrado, tera o direito de fazer uma nova reta.\n\n");			
			break;
		}
}

//Funcao main (principal) com menu, onde cada funcao é chamada  dentro da sua opcao
int main(){
   int opcaoMenu;

    do
    {
        printf("\n\tO que voce quer fazer?\n\n");
        printf("1. Iniciar o Jogo\n");
        printf("2.  Ver Instrucoes\n");
        printf("0. Sair\n");

        scanf("%d", &opcaoMenu); 	//ler a varivel opcaoMenu
        system("cls || clear");		//limpa o console

        switch(opcaoMenu)
        {
            case 1:			
                jogo();			//Função que incializa o jogo
                break;

            case 2:
                instrucoes();	// Função para instruções
                break;


            case 0:			//Opção que encerra o programa exibindo mensagem jogo encerrado
                system("cls");			
		        printf("\n\n\nJogo enecerrado!\n\n\n"); 				
		        return 0; 			
		        break; 	

            default:
                printf("Digite uma opcao valida\n");  // Retorna mensagem de opção inválida caso usuario digite um valor diderente de 1, 2, 0.
        }
    } while(opcaoMenu);
} 
