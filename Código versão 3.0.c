#include <stdio.h>			
#include <stdlib.h>			
#include <string.h> 

//Entradas -> Valores inseridos pelos jogadores
//REGRA 1 -> Verificar tamanho correto da matriz
//REGRA 2 -> Verificar sobreposicao de retas
//REGRA 3 -> Contagem de pontos

//variaveis globais
int jogador=0, vencedor1=0, vencedor2=0;	

//Estrutura
typedef struct entradas{
	char nome1[50], nome2[50];
	char matriz[100][100];
	int tamanho, linha, coluna;
}entradas;

//Regra para contagem de pontos
void regra3(entradas entrada){ 
	
	if(entrada.matriz[entrada.linha][entrada.coluna] == '|'){
		if(entrada.matriz[entrada.linha][entrada.coluna-1] == '_' && entrada.matriz[entrada.linha][entrada.coluna-2] == '|' && entrada.matriz[entrada.linha-1][entrada.coluna-1] == '_')
			{ if(jogador == 0) {vencedor1++; } else {vencedor2++;} jogador = !jogador; }
	}else
		if(entrada.matriz[entrada.linha][entrada.coluna] == '|'){    //Possui erro a ser resolvido
			if(entrada.matriz[entrada.linha][entrada.coluna+1] == '_' && entrada.matriz[entrada.linha][entrada.coluna+2] == '|' && entrada.matriz[entrada.linha-1][entrada.coluna+1] == '_')
				{ if(jogador == 0) {vencedor1++; } else {vencedor2++;} jogador = !jogador;	}
		}else
			if(entrada.matriz[entrada.linha][entrada.coluna] == '_'){
				if(entrada.matriz[entrada.linha][entrada.coluna-1] == '|' && entrada.matriz[entrada.linha][entrada.coluna+1] == '|' && entrada.matriz[entrada.linha-1][entrada.coluna] == '_')
					{ if(jogador == 0) {vencedor1++; } else {vencedor2++;} jogador = !jogador;	}
			}else
				if(entrada.matriz[entrada.linha][entrada.coluna] == '_'){	//Possui erro a ser resolvido
					if(entrada.matriz[entrada.linha+1][entrada.coluna-1] == '|' && entrada.matriz[entrada.linha+1][entrada.coluna+1] == '|' && entrada.matriz[entrada.linha+1][entrada.coluna] == '_')
						{ if(jogador == 0) {vencedor1++; } else {vencedor2++;} jogador = !jogador;	}
				}
}	

//Regra para sobreposição de retas
int regra2(entradas entrada){ 
	
	if(entrada.matriz[entrada.linha][entrada.coluna] == '|' || entrada.matriz [entrada.linha][entrada.coluna] == '_')
		{ printf("Coordenada invalida! Tente novamente...\n"); return 1; }
	return 0;	
}

//Regra para inserir tamanho correto da matriz
int regra1(entradas entrada){ 
																
	if(entrada.tamanho<5 || entrada.tamanho>36)
		{ printf("Tamanho invalido! Tente novamente...\n"); return 1; }
    return 0;	
}

//Função que imprime as coordenadas
char coordenada(entradas entrada, int i, int j){
	
	if(i == 0){												//Transforma numeros duplos em letras (linhas)
		if(j >= 10) { entrada.matriz[i][j] = 'A'+(j-10); }		
		else { entrada.matriz[i][j] = j+'0'; }	
	}
	if(j == 0){												//Transforma numeros duplos em letras (colunas)
		if(i >= 10){ entrada.matriz[i][j] = 'A'+(i-10);		
		}else { entrada.matriz[i][j] = i+'0'; }
	}	
	return entrada.matriz[i][j];
}

//Função para imprimir a matriz
void imprimirMatriz(entradas entrada){
		
	for(int i=0; i<entrada.tamanho; i++){
		for(int j=0; j<entrada.tamanho+1; j++){
		
			if(entrada.matriz[i][j] != '_' && entrada.matriz[i][j] != '|'){ entrada.matriz[i][j] = '.'; }	//Inseri caracteres que forma a matriz
								
			entrada.matriz[i][j] = coordenada(entrada, i, j);
							
			if(j != entrada.tamanho) { printf(" %c", entrada.matriz[i][j]); }		//Imprimi a matriz
			else  { printf("\n"); }	
		}
	}	
}

//Função para leitura de informações
entradas leitura(entradas entrada){
	
	printf("Qual o nome do jodador 1?\n");
	scanf("%s", entrada.nome1);

	printf("\nQual o nome do jodador 2?\n");
	scanf("%s", entrada.nome2);

	while(1){
		printf("\nInsira o tamanho do jogo (entre 5 e 36):\n");
		scanf("%d", &entrada.tamanho);
		
		if(regra1(entrada) == 0) { break; }	//Verifica se o tamanho inserido é valido
	}	
	return entrada;
}

//Função principal do jogo
void jogo(){
	system("cls");

	printf("----------------------------------------------------------\n");
	printf("|########################################################|\n");
	printf("|###############                        #################|\n");
	printf("|###############   JOGO DOS PONTINHOS   #################|\n");
	printf("|###############                        #################|\n");
	printf("|########################################################|\n");
	printf("----------------------------------------------------------\n\n");
	
	entradas entrada;								//Define variavel 'entrada' para struct
	entrada = leitura(entrada);						//Chama a função leitura

	while(1){
		system("cls");
		imprimirMatriz(entrada);					//Chama a função jogada
		
		printf("\n%s = %d\n", entrada.nome1, vencedor1);
		printf("%s = %d\n", entrada.nome2, vencedor2);	
		
		while(1){									//Repetição até o jogador inserir a linha e coluna adequada
		
			if(jogador == 0) printf("\n%s, digite linha e coluna:\n", entrada.nome1);
			else printf("\n%s, digite linha e coluna:\n", entrada.nome2);
												
			scanf("%d %d", &entrada.linha, &entrada.coluna);
				
			if(regra2(entrada) == 0) { break; }		//Verifica se há sobreposição de retas
		}
					
		if(entrada.coluna % 2 == 0)							
			entrada.matriz [entrada.linha][entrada.coluna] = '_';
		else if(entrada.coluna % 2 != 0)
			entrada.matriz [entrada.linha][entrada.coluna] = '|';
		
		regra3(entrada);	
		jogador = !jogador;			// Alterna nome dos jogadores
	}
}

//Funcao de instruções
void instrucoes(){
	system("cls");
	
	printf("\n____________________________________COMO JOGAR____________________________________");
	printf("\n\nCada jogador deve fazer uma reta ('|' vertical, ou '_' horizontal) nas coordenadas.");
	printf("\nGanha aquele que fechar o maior numero de quadrados!\n\n");
	printf("\n______________________________________REGRAS______________________________________");
	printf("\n\n1 - Nao pode sobrepor retas.");
	printf("\n2 - Um quadrado so podera ser completado caso ja houver 3 lados preenchidos.");
	printf("\n3 - Caso o jogador complete um quadrado, tera o direito de fazer uma nova reta.\n\n");			
}

//Funcao main (principal) com menu, onde cada funcao é chamada  dentro da sua opcao
int main(){
	int opcaoMenu;

	do{
		system("cls");
		printf("\n\tMenu\n\nO que voce quer fazer?\n\n1 - Iniciar o Jogo\n2 - Ver Instrucoes\n3 - Sair do jogo\n-->\n"); 		
		scanf(" %i",&opcaoMenu); 

		switch(opcaoMenu){ 						
			case 1: 			
				jogo(); break;
				
			case 2:
				instrucoes();
				system("pause");
				
			case 3: 			
				system("cls");			
				printf("\n\n\nJogo encerrado!\n\n\n"); break; 	
					
			default: 			
				printf("\nOpcao invalida, tente novamente!\n"); 
				system("pause");
		}
	}while(opcaoMenu != 3);
} 
