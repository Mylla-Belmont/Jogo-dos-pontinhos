#include <stdio.h>			
#include <stdlib.h>			
#include <string.h> 

//Caso queira diminuir o tamanho da matriz para testar o jogo de forma mais rápida,
//basta alterar o valor da variavel tamanho (função jogo) para 5 [int tamanho = 5], 
//e alterar o valor de comparação da condição cont (função regra 4) para 16 [if(cont == 5)]

//ENTRADAS -> Valores inseridos pelos jogadores
//REGRA 1 -> Verificar sobreposicao de retas
//REGRA 2 -> Verificar se coordenada é válida
//REGRA 3 -> Contagem de pontos
//REGRA 4 -> Finalizar jogo

//Estrutura
typedef struct entradas{
	char matriz[100][100];
	char nome1[50], nome2[50];
	int linha, coluna;
}entradas;

//Regra para finalizar o jogo
int regra4(entradas entrada, int tamanho){
	int cont=0;	
		
	for(int i=0; i<tamanho; i++)
		for(int j=0; j<=tamanho; j++)
			if(entrada.matriz[i][j] == '|' || entrada.matriz[i][j] == '_' || entrada.matriz[i][j] == '*') 
				cont++;

	if(cont == 81)  //Matriz possui 81 pontos a serem preenchidos
		return 1; 	 
	
	return 0;
}

//Regra para contagem de pontos e jogador fazer uma jogada novamente caso tenha conseguido pontos 
int regra3(entradas entrada, int vencedor){ 
	
	if(entrada.matriz[entrada.linha][entrada.coluna] == '|'){	//Condições para verificar de acordo com a ultima jogada
		if(entrada.matriz[entrada.linha][entrada.coluna-1] == '_' && entrada.matriz[entrada.linha][entrada.coluna-2] == '|' && entrada.matriz[entrada.linha-1][entrada.coluna-1] == '_')
			return vencedor=1; 	
	}
	if(entrada.matriz[entrada.linha][entrada.coluna] == '|'){    
		if(entrada.matriz[entrada.linha][entrada.coluna+1] == '_' && entrada.matriz[entrada.linha][entrada.coluna+2] == '|' && entrada.matriz[entrada.linha-1][entrada.coluna+1] == '_')
			return vencedor=1;	
	}
	if(entrada.matriz[entrada.linha][entrada.coluna] == '_'){
		if(entrada.matriz[entrada.linha][entrada.coluna-1] == '|' && entrada.matriz[entrada.linha][entrada.coluna+1] == '|' && entrada.matriz[entrada.linha-1][entrada.coluna] == '_')
			return vencedor=1;	
	}
	if(entrada.matriz[entrada.linha][entrada.coluna] == '_'){	
		if(entrada.matriz[entrada.linha+1][entrada.coluna-1] == '|' && entrada.matriz[entrada.linha+1][entrada.coluna+1] == '|' && entrada.matriz[entrada.linha+1][entrada.coluna] == '_')
			return vencedor=1;	
	}
	return 0;
}	

//Regra para validação de coordenada
int regra2(entradas entrada, int tamanho){ 
	if(entrada.linha >= tamanho || entrada.coluna >= tamanho || entrada.linha <= 0 || entrada.coluna <= 0){
		printf("Coordenada invalida! Tente novamente...\n"); 
		return 1; 
	}
	return 0;	
}

//Regra para sobreposição de retas
int regra1(entradas entrada){ 
	if(entrada.matriz[entrada.linha][entrada.coluna] == '|' || entrada.matriz [entrada.linha][entrada.coluna] == '_' || entrada.matriz [entrada.linha][entrada.coluna] == '*'){
		printf("Essa coordenada ja foi usada! Tente novamente...\n"); 
		return 1; 
	}
	return 0;	
}

char inserirCaracter(entradas entrada){
	
	if((entrada.linha == 1) && (entrada.coluna % 2 != 0))	//Não permite inserir caracteres em coordenadas inutilizaveis (impossiveis de fechar um quadrado)
		entrada.matriz [entrada.linha][entrada.coluna] = '*';
	else if(entrada.coluna % 2 == 0) 
		entrada.matriz [entrada.linha][entrada.coluna] = '_'; 
	else if(entrada.coluna % 2 != 0) 
		entrada.matriz [entrada.linha][entrada.coluna] = '|'; 
	
	return entrada.matriz [entrada.linha][entrada.coluna];
}

//Função que imprime as coordenadas
char coordenada(entradas entrada, int i, int j){
	
	if(i == 0) { entrada.matriz[i][j] = j+'0'; }  	//Coordenadas para linhas									
	if(j == 0) { entrada.matriz[i][j] = i+'0'; }	//Coordenadas para colunas
		
	return entrada.matriz[i][j];
}

//Função para imprimir a matriz
void imprimirMatriz(entradas entrada, int tamanho){
	
	for(int i=0; i<tamanho; i++){
		for(int j=0; j<=tamanho; j++){
			
			if(entrada.matriz[i][j] != '_' && entrada.matriz[i][j] != '|' && entrada.matriz[i][j] != '*')	//Faz desenho da matriz com pontos
				entrada.matriz[i][j] = '.';
								
			entrada.matriz[i][j] = coordenada(entrada, i, j);		//Chama funçao para inserir coordenadas na matriz
							
			if(j != tamanho) { printf(" %c", entrada.matriz[i][j]); }		//Imprimi a matriz
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

	return entrada;
}

//Função principal do jogo
void jogo(){
	system("cls");
	printf(".........................................................\n");
	printf("................                        .................\n");
	printf("................   JOGO DOS PONTINHOS   .................\n");
	printf("................                        .................\n");
	printf(".........................................................\n\n");
	
	entradas entrada;								//Define variavel 'entrada' para struct
	entrada = leitura(entrada);						//Chama a função leitura
	
	int tamanho=10, jogador=0, vencedor, vencedor1=0, vencedor2=0;
	
	do{
		system("cls");
		imprimirMatriz(entrada, tamanho);					//Chama a função jogada
		
		printf("\n%s = %d\n", entrada.nome1, vencedor1);
		printf("%s = %d\n", entrada.nome2, vencedor2);	
		
			do{									//Repetição até o jogador inserir a linha e coluna adequada
				do{	
					if(jogador == 0) printf("\n%s, digite linha e coluna:\n", entrada.nome1);
					else printf("\n%s, digite linha e coluna:\n", entrada.nome2);
												
					scanf("%d %d", &entrada.linha, &entrada.coluna);
			
				}while(regra2(entrada, tamanho) != 0);				//Verifica se entrada das coordenadas é válida 
			}while(regra1(entrada) != 0); 							//Verifica se há sobreposição de retas

		entrada.matriz[entrada.linha][entrada.coluna] = inserirCaracter(entrada);
		vencedor = regra3(entrada, vencedor);						//Chama função para contagem de pontos
		
		if(vencedor == 1){
			if(jogador == 0){
				vencedor1 += vencedor; 
				jogador = !jogador;			//Altera o jogador para fazer mais uma jogada
			}else{
				vencedor2 += vencedor; 
				jogador = !jogador;
			}
		} jogador = !jogador;										// Alterna nome dos jogadores
		
	}while(regra4(entrada, tamanho) == 0);

	//Arte para final de jogo e exibição do ganhador
	system("cls");
	printf("                        ............................\n");
	printf("....................................................\n");
	printf("...................FIM DE JOGO!.....................\n");
	printf("....................................................\n");
	
	if(vencedor1 == vencedor2){						//Bloco para verifica quem é o ganhador
		printf("......................EMPATE!\n\n");
	}else if(vencedor1 > vencedor2){
		printf("....................Parabens %s!\n\n", entrada.nome1);
	}else if(vencedor2 > vencedor1){
		printf("....................Parabens %s!\n\n", entrada.nome2);
	} system("pause");
}

//Funcao de instruções
void instrucoes(){
	system("cls");
	printf("\n...................................COMO JOGAR........................................");
	printf("\n\nCada jogador uma reta nas coordenadas.");
	printf("\nAs retas estao posicionadas na horizontal e vertical.");
	printf("\nGanha aquele que fechar o maior numero de quadrados!\n\n");
	printf("\n.....................................REGRAS..........................................");
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
				system("pause");		//Permite voltar para o menu sem reiniciar o jogo
			
			case 3: 			
				system("cls");			
				printf("\n\n\nJogo encerrado!\n\n\n"); break; 	
			
			default: 			
				printf("\nOpcao invalida, tente novamente!\n"); 
				system("pause");		//Permite voltar para o menu sem reiniciar o jogo
		}
	}while(opcaoMenu != 3);
} 
