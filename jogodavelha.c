#include <stdio.h>
#include <stdlib.h>

int verificarVelha(char tab[3][3], char v) {
  if ((tab[0][0] == v) && (tab[0][1] == v) && (tab[0][2] == v))
    return 1;
  if ((tab[1][0] == v) && (tab[1][1] == v) && (tab[1][2] == v))
    return 1;
  if ((tab[2][0] == v) && (tab[2][1] == v) && (tab[2][2] == v))
    return 1;

  if ((tab[0][0] == v) && (tab[1][0] == v) && (tab[2][0] == v))
    return 1;
  if ((tab[0][1] == v) && (tab[1][1] == v) && (tab[2][1] == v))
    return 1;
  if ((tab[0][2] == v) && (tab[1][2] == v) && (tab[2][2] == v))
    return 1;

  if ((tab[0][0] == v) && (tab[1][1] == v) && (tab[2][2] == v))
    return 1;
  if ((tab[0][2] == v) && (tab[1][1] == v) && (tab[2][0] == v))
    return 1;

  return 0;
}

int main(void) {
  char tabuleiro[3][3];
  int l, c;
  printf("Jogo da velha");
  printf("\n\nUse X ou O para jogar");
  printf("\n\nRegrinhas do jogo: ");
  printf("\n1- Cada jogador tem uma vez de jogar! ");
  printf("\n2- Ganha primeiro quem fazer uma linha ou diagonal com a sua forma "
         "escolhida sendo X ou O");
  for (l = 0; l < 3; l++) {
    for (c = 0; c < 3; c++) {

      printf("Digite o valor da posicao [%d, %d]: ", l + 1, c + 1);
      fflush(stdin);
      scanf("%c", &tabuleiro[l][c]);
    }
  }
  if (verificarVelha(tabuleiro, 'x'))
    printf("\n\nParabens o jogador que usou 'x' venceu");
  else {
    if (verificarVelha(tabuleiro, 'o'))
      printf("\n\nParabens o jogador que usou 'o' venceu");
    else {
      printf("\n\nDeu velha");
    }
  }
  return 0;
}