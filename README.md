# Jogo-dos-pontinhos

N° de jogadores: 2
Tempo de jogo: Indeterminado (ou até completar a matriz)
Como jogar:
	Cada jogador deverá fazer uma reta (vertical ou horizontal) entre dois pontos. Ganha aquele que
	completar o maior número de quadradinhos.

Regras:
	– Cada jogador deverá fazer apenas uma única reta.
	– Não pode sobrepor retas.
	– Um quadrado só poderá ser completado caso já houver 3 lados preenchidos.
	– Caso o jogador complete um quadrado, terá o direito de fazer uma nova reta, e, dependendo
	das possibilidades, fechar mais de um quadrado.

Como representar isso na linguagem C?
	– Uma matriz de tamanho N x N (no exemplo a seguir segue a matriz 10 x 10)

. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .

	– Cada ponto, dependendo da escolha do jogador, será substituído por: _ ou |.

. . . . . . . . . . .
. . . . . . . . . . . 
. . . . . . . . . . .
. . . . . . . . . . .
. | . . . . . . . . .
. . . . | | . . . . .
. . . . . . . . . . .
. . . _ . . . . . . .
. . | . | . . . . . .
. . . _ . . . . . . .
. . . . . . . . . . .

	– Para facilitar a identificação das coordenadas, a matriz será formada com 1 coluna e 1 linha a
	mais, sendo coluna [i] preenchido por C1, C2, …, Cn, e linha [j] preenchido por L1, L2, …, Ln.

	C1 C2 C3 C4 C5 C6 C7
L1 . . . . . . . . . .
L2 . . . . . . . . . .
L3 . . . . . . . . . .
L4 . . . . . . . . . .
L5 | . . . . . . . . .
L6 . . . | | . . . . .

Requisitos (até o momento):
	– Matriz;
	– Funções;
	– Strings;
	– Estruturas condicionais;

A seguir um exemplo básico do código:
#include <stdio.h>
int main(){
char posicao;
int num_linha, num_coluna, tam_jogo, cont=0, jog=0;
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
Se matriz[x][y] != ‘_’ ou matriz[x][y] != ‘|’
Então será uma jogada inválida e o jogador deverá tentar novamente.
Se linha ou coluna for > que tamanho da tabela
Então será uma jogada inválida e o jogador deverá tentar novamente.
Se houver 3 caracteres (2 | e 1 _ ou 1 | e 2_)
Então contador de vencedor incrementará mais um.
Obs: Outras funções e características do código serão adicionadas com o desenvolver do projeto.
Execução do código
