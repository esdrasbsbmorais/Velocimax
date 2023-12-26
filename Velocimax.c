#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

struct Carro {
  int posicao_x;
  int posicao_y;
};

// Aqui estou definindo uma função chamada MENU, a qual é a seleção inicial do
// jogo.
int MENU() {
  int opcao, n1, n2, x;
  do { // Aqui estou usando a estrutura de repetição while para obter as
       // escolhas do usuario e imprimir a logo do jogo.

    printf("-------------------------------------------------------------------"
           "-\n");
    printf(" _    __          __                  _                            "
           " \n");
    printf("| |  / /  ___    / /  ____   _____   (_)   ____ ___   ____ _   _  "
           "__\n");
    printf("| | / /  / _ \\  / /  / __ \\ / ___/  / /   / __ `__ \\ / __ `/  | "
           "|/_/\n");
    printf("| |/ /  /  __/ / /  / /_/ // /__   / /   / / / / / // /_/ /  _>  < "
           " \n");
    printf("|___/   \\___/ /_/   \\____/ \\___/  /_/   /_/ /_/ /_/ \\__,_/  "
           "/_/|_|  \n");
    printf("-------------------------------------------------------------------"
           "-\n");
    printf("\nOla, seja bem-vindo ao projeto de algoritmos!\n");
    printf("\n1 - INICIAR!\n");
    printf("\n2 - COMO JOGAR?\n");
    printf("\n3 - SAIR\n");
    printf("------------------------------\n\n");
    scanf("%d", &opcao);
    // Na sequência de printfs a cima, eu escrevo quais as opções e oque cada
    // uma significa e peço para o usuário informar um número de 1 a 3.
    switch (
        opcao) { // Aqui faço um switch/case, para deixar meu menu funcional.
    case 1: // case 1, limpa o console usando o comando system("clear") e leva
            // para a função INICIAR.
      system("clear");
      INICIAR();
      break;
    case 2: // case 2, limpa o console usando o comando system("clear") e leva
            // para a função COMOJOGAR.
      system("clear");
      COMOJOGAR();
      break;
    case 3: // case 3, limpa o console usando o comando system("clear") e
            // finaliza o loop.
      system("clear");
      exit(0);
      break;
    default:
      system("clear");
      printf(
          "\nOpção invalida. Tente novamente.\n\n"); // Se o número digitado for
                                                     // diferente de 1 a 3, ele
                                                     // retorna um erro e pede
                                                     // para ele inserir o
                                                     // numero novamente.
      break;
    }
  } while (opcao != 3);
  return 0;
}

// Essa função retorna para a função MENU.
int RETORNO() {
  int x;
  printf("\nPara voltar ao menu pressione: '1'\n\n");
  scanf("%d", &x);

  if (x == 1) { // Nesse if, caso seja digitado o número 1, retorna a função
                // MENU, caso contrario ele pede para o usuário digitar um
                // número valido e pergunta o número novamente.
    system("clear");
    return MENU();
  } else {
    printf("\nFavor digitar um número valido\n");
  }
  return RETORNO();
}

// Essa função permite retornar ao menu ou jogar o jogo novamente.
int JOGAR_NOVAMENTE() {
  int x;
  printf("\nPara voltar ao menu pressione: '1'\nPara tentar novamente "
         "pressione '2'\n\n");
  scanf("%d", &x);

  if (x ==
      1) { // Nesse if, caso seja digitado o número 1, retorna a função MENU.
    system("clear");
    return MENU();
  } else if (x == 2) { // Nesse if, caso seja digitado o número 2, permite jogar
                       // novamente caso contrario retorna um erro e pede para
                       // inserir um número valido.
    INICIAR();
  } else {
    printf("\nFavor digitar um número valido\n");
  }
  return JOGAR_NOVAMENTE();
}

// Essa função serve como complemento da função GANHOU, permite que o usuário
// volte ao MENU.
int ERROU() {
  int x;
  printf("\nPara voltar ao menu pressione: '1'\n\n");
  scanf("%d", &x);

  if (x == 1) { // Nesse if, caso seja digitado o número 1, retorna a função
                // MENU, caso contrario ele pede para o usuário digitar um
                // número valido e pergunta o número novamente.
    system("clear");
    return MENU();
  } else {
    printf("\nFavor digitar um número valido\n");
  }
  return ERROU();
}

// Essa função serve para agradecer o usuário por jogar esse jogo e retorna
// a função ERROU.
int GANHOU() {
  printf("\n\nCaro jogador,\n\n");
  printf("Gostaria de expressar minha gratidão pelo tempo que você gastou em "
         "meu jogo.\n");
  printf("Sei que existem muitas opções,\nmas você escolheu jogar o meu jogo e "
         "isso significa muito para mim.\n\n");
  printf("Atenciosamente,\n");
  printf("Equipe de desenvolvimento.\n\n");

  ERROU();
}

// Essa função introduz um guia básico sobre o jogo e envia o usuário para a
// função INICIARJOGO.
int INICIAR() {
  printf("\nO objetivo do jogo é chegar na linha de chegada sem bater em "
         "nenhum obstáculo.\n\n");
  printf("Para controlar seu veículo, use as teclas \"a\" e \"d\"\npara mover "
         "o carro para a esquerda e para a direita, respectivamente.\n\n");
  printf("Por favor, desative o:\n");
  printf(" _____________ \n");
  printf("|||Caps Lock ||\n");
  printf("|||__________||\n");
  printf("|/___________\\|\n\n");
printf(" ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ ____\n");
printf("||V |||A |||M |||O |||S |||       |||C |||O |||R |||R |||E |||R ||\n");
printf("||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__|||__||\n");
printf("|/__\\|/__\\|/__\\|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|\n");

  printf("\nPara iniciar o jogo pressione: '1'\n\n");
  INICIARJOGO();
}

// Essa função verifica oque foi pressionado e inicia o jogo.
int INICIARJOGO() {
  int x;
  scanf("%d", &x);
  if (x == 1) {
    system("clear");
    JOGO();
  } else {
    printf("\nFavor digitar um número valido\n");
  }
  return INICIARJOGO();
}

// Função serve para ler as teclas pressionadas pelo usuário sem bloquear o programa.
int GETCH() {
  struct termios antigo, novo;
  int tecla;

  tcgetattr(STDIN_FILENO, &antigo); //Recebe as configurações antigas.
  novo = antigo; //Cria uma cópia das configurações antigas.
  novo.c_lflag &= ~(ICANON | ECHO); //Desabilita o modo canônico e o eco automático.
  tcsetattr(STDIN_FILENO, TCSANOW, &novo);

  tecla = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &antigo);
  return tecla;
}

// Função onde defino a matriz e imprimo a pista do jogo, sendo 0 a primeira linha da pista, 1 o local onde o carro pode andar, 2 o centro da pista e 3 os obstáculos.
int IMPRIMIR_PISTA(struct Carro carro) {
  int a, b;

  int matriz[10][5] = {{0, 1, 2, 1, 0}, 
                      {0, 1, 2, 1, 0}, 
                      {0, 1, 2, 1, 0},
                      {0, 1, 2, 1, 0}, 
                      {0, 1, 2, 1, 0}, 
                      {0, 3, 2, 1, 0},
                      {0, 1, 2, 1, 0}, 
                      {0, 1, 2, 1, 0}, 
                      {0, 1, 2, 1, 0},
                      {0, 1, 2, 3, 0}};

  system("clear"); // limpa a tela

  for (a = 0; a < 10; a++) {
    for (b = 0; b < 5; b++) {

      if((a == carro.posicao_x && b == carro.posicao_y) && matriz[a][b] == 3) {
        system("clear"); // limpa a tela
        printf("Ops, você bateu!\n");
        return JOGAR_NOVAMENTE();
      }

        if(matriz[a][b] == 0) {
                printf("||");
        } else if(a == carro.posicao_x && b == carro.posicao_y) {
                printf("  |_|  ");
        } else if(matriz[a][b] == 1) {
                printf("       ");
        } else if(matriz[a][b] == 2) {
                printf("|");
        } else if(matriz[a][b] == 3) {
                printf("   X   ");
        }
      }          
      printf("\n");
    }

  printf("█ █ █ █ █ █ █ █ █ █\n");
  printf(" █ █ █ █ █ █ █ █ █ \n");
  printf("█ █ █ █ █ █ █ █ █ █\n\n");
  if(carro.posicao_x == 10){
    system("clear"); // limpa a tela
    printf("você ganhou!\n");
    return GANHOU();
  }
  return 1;
}

// Essa função recebe as teclas da função GETCH e imprime o carro no console.
int JOGO() {
  struct Carro carro;
  carro.posicao_x = 0; // Posição onde o carro aparecerá x.
  carro.posicao_y = 1; // Posição onde o carro aparecerá y.
  char comando;

  IMPRIMIR_PISTA(carro);

  while (1) { // loop infinito apaga, imprime e move o carro para a posições corretas.

    comando = GETCH(); // lê uma tecla pressionada pelo usuário.

    if (comando == 'a') { // move o carro para a esquerda.
      if(carro.posicao_y - 2 <= 1) {
        carro.posicao_y = 1;
      } else {
        carro.posicao_y = 3;
      }
        carro.posicao_x++;
      if(IMPRIMIR_PISTA(carro) == 0) {
        break;
      }
    } else if (comando == 'd') { // move o carro para a direita.
      if(carro.posicao_y + 2 >= 3) {
        carro.posicao_y = 3;
      } else {
        carro.posicao_y = 1;
      }
        carro.posicao_x++;
      if(IMPRIMIR_PISTA(carro) == 0) {
        break;
      }
    } else if (comando == 'q') { // se o usuário digitar 'q', finaliza o programa.
      system("clear");
      break;
    }
  }

  return 0;
}


// Essa função explica como o jogo funciona e retorna para a função RETORNO.
int COMOJOGAR() {
  int x;
  printf("\nObjetivo: O objetivo do jogo é cruzar a linha de chegada\n sem "
         "bater em nenhum obstáculo.\n\n");
  printf("Regras:\n\n");
  printf("1. O jogador deve controlar um carro, movendo-o entre 2 pistas.\n\n");
  printf(
      "2. Para controlar seu veículo, use as teclas \"a\" e \"d\"\npara mover "
      "o carro para a esquerda e para a direita, respectivamente.\n\n");
  printf("3. O jogador deve evitar tocar em qualquer obstáculo, pois isso fará "
         "com que você bata o carro e termine o jogo.\n\n");
  printf("4. O jogo termina quando o carro bate em um obstáculo\nou quando "
         "cruzar a linha de chegada.\n\n");

  printf("██████   ██████   █████      ███████  ██████  ██████  ████████ "
         "███████\n");
  printf("██   ██ ██    ██ ██   ██     ██      ██    ██ ██   ██    ██    ██\n");
  printf(
      "██████  ██    ██ ███████     ███████ ██    ██ ██████     ██    █████\n");
  printf("██   ██ ██    ██ ██   ██          ██ ██    ██ ██   ██    ██    ██\n");
  printf("██████   ██████  ██   ██     ███████  ██████  ██   ██    ██    "
         "███████\n");

  { RETORNO(); }
  return 0;
}

// Aqui é onde começa a execução do jogo e na linha de baixo eu chamo a função
// MENU.
int main() { MENU(); return 0; } 
