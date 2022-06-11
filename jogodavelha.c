#include <stdio.h>
#include <stdlib.h>

int verificarVelha(char tab[3][3], char v);
void bannerInicial(void);
void mostrarTabuleiro(char tab[3][3]);

int main(void) {
  char tabuleiro[3][3];
  int l, c;

  // msg com instruções de uso
  bannerInicial();

  for (l = 0; l < 3; l++) {
    for (c = 0; c < 3; c++) {

      printf("Digite o valor da posicao [%d, %d]: ", l + 1, c + 1);

      tabuleiro[l][c] = getchar();
      // TODO: ignorar o '\n' de outra forma
      // consumindo o '\n' do ENTER
      getchar();

      // visualizando o tabuleiro logo após
      // a inserção do usuário.
      mostrarTabuleiro(tabuleiro);
    }
  }
  if (verificarVelha(tabuleiro, 'x'))
    printf("\n\nParabens o jogador que usou 'x' venceu\n");
  else {
    if (verificarVelha(tabuleiro, 'o'))
      printf("\n\nParabens o jogador que usou 'o' venceu\n");
    else {
      printf("\n\nDeu velha");
    }
  }
  return 0;
}

int verificarVelha(char tab[3][3], char v) {
  // TODO:
  // verificação do vencedor em (loop + if/else) ao invés
  // de múltiplos ifs, também devemos checar o vencedor
  // após terceira inserção de dados, não apenas no final
  // das inserços de 'x's e 'o's.

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

void bannerInicial(void) {
  puts(""
       "Jogo da velha\
  \n\nUse 'x' ou 'o' para jogar;\
  \n\nRegrinhas do jogo:\
  \n1- Cada jogador tem uma vez de jogar!\
  \n2- Ganha primeiro quem fazer uma linha \
  \nou diagonal com a sua forma escolhida sendo X ou O\n");
}

void mostrarTabuleiro(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("[%2c]", tabuleiro[i][j]);

      // caso a coluna for a última, pula uma linha
      if (j == 2)
        puts("");
    }
  }
}
