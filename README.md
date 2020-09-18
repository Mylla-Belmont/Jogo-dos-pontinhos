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
