#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mysql.h>

void abertura();
void chuteDoJogador();
void chuteRandomico();
void gerarNumeroAleatorio();
void verificaChuteENumeroAleatorio();
void encerramento();
int isGameActive();
void jogar();
void login();
void auth();

int chute;
int chuteMaquina;
int acertou;
int encerrou = 0;
int chances = 2;
int email;
int password;

void abertura()
{
     printf("*****************************************************************************************\n");
     printf(" SEJA BEM VINDO AO JOGO DA FORCA \n");
     printf("*****************************************************************************************\n\n");
}

void gerarNumeroAleatorio(int *numeroMaquina)
{
     int segundos = time(0);
     srand(segundos);

     *numeroMaquina = segundos % 100;
}

void verificaChuteENumeroAleatorio()
{
     if (chute == chuteMaquina)
     {
          acertou = 1;
     }
     else
     {
          acertou = 0;
     }
}

void chuteDoJogador()
{
     scanf("%d", &chute);
}

void chuteRandomico()
{
     gerarNumeroAleatorio(&chuteMaquina);
}

void encerramento() {
     if (acertou)
     {
          printf("************************************ PARABENS VOCE ACERTOU ************************************\n");
          printf("                 @@  @@ \n");
          printf("                ,-@@~@-.   \n");
          printf(" _              (_, O _/   \n");
          printf("| Y~.            (__d._)    \n");
          printf("| r.|    Y@oooood@@@@@@@@oooo@F \n");
          printf(" Y ||   _Y@@@@@@P       Y@@@@f \n");
          printf(" | t_\\_/ _)@@@@@          @@@@f  __     ,--,\n");
          printf("  \\  `. / ~@@@@@    . .   @@@@  (_ `---'  ~~)\n");
          printf("   `-._/)   @@@@b__|@_@|_d@@@    _l,'~   ~~)\n");
          printf("      (,db   (   _  `-' _   )  ,d@_)---~~~~\n");
          printf("         Yb.  \\ '|\\____/|` / od@P \n");
          printf("          Y@b  \\ | nn  /','d@@P \n");
          printf("            Y@b `\\`---'/'od@P \n");
          printf("             ~@@@@`---'@@@P~\n");
          printf("               Y@@@@@@@@@~\n");
          printf("                @@@@@@@@\n");
          printf("************************************ OBRIGADO POR JOGAR ************************************\n");

     }else{
          if(chances == 0){
               printf("************************************ QUE PENA VOCE ERROU ************************************\n");
               printf("   __&__      \n");
               printf("  /     \\     \n");
               printf(" |       |    \n");
               printf(" |  (o)(o)    \n");
               printf(" C   .---_)   \n");
               printf("  | |.___|    \n");
               printf("  |  \\__/     \n");
               printf("  /_____\\     \n");
               printf(" /_____/ \\    \n");
               printf("/         \\ \n");

               printf("************************************ NUMERO DA MAQUINA : %d ************************************\n", chuteMaquina);
               printf("************************************ OBRIGADO POR JOGAR ************************************\n");
          }
     }


}

int isGameActive(){
     if (acertou)
     {
          encerrou = 1;
     }else{
          chances--;
         
          if(chances == 0){
               printf("Voce Perdeu!\n");
          }else{
               printf("Voce Errou!\n Qtd chances : %d\n", chances);
          }
     }
}

void auth(){
     
}
void jogar(){
      do
     {
          chuteRandomico(); // gera um numero aleatorio como numero de escolha da Maquina
          chuteDoJogador(); // recebe o chute do jogador
          verificaChuteENumeroAleatorio(); // verifica se o chute do jogador foi igual ao numero aleatorio gerado pela maquina
          isGameActive(); //verifica se o jogador deve continuar jogando de acordo com a quantidade de chances que ele tem
          encerramento(); // mostra mensagem personalizada (ANSCII ART)  de acordo com o resultado do jogo
     } while (chances > 0);
}
void login(){
     printf("Digite Seu email : \n");
     scanf("%d", &email);
     printf("Digite Sua senha : \n");
     scanf("%d", &password);


}
void selectOption(){
     int option;
     printf("1 - Jogar Como Visitante \n");
     printf("2 - Login\n");
     printf("3 - Registrar\n");
     printf("0 - Sair\n");
     scanf("%d", &option);

     switch (option)
     {
     case 1:
          abertura();
          jogar();
          break;
     case 2:
          login();
          break;
     default:
          printf("Opcao invalida!\n");
          break;
     }
}

int main()
{
      selectOption();
     // abertura(); // exibe a mensagem de boas vindas
     // jogar();
}
