#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void jogar();

int main(){
    jogar();
    return 0;
}

void jogar()
{
    while (true)
    {
        srand(time(NULL));
        int numeroSecreto = rand() % 100;
        int nivel, tentativas, rodada = 0;
        int chute;
        bool ganhou;

        printf("Vamos definir a dificuldade do seu jogo: digite (1) para o nivel facil, (2) para o nivel medio e (3) para o nivel dificil: \n");
        scanf("%d", &nivel);
        if (nivel == 1)
        {
            tentativas = 20;
        }
        else if (nivel == 2)
        {
            tentativas = 10;
        }
        else if(nivel == 3)
        {
            tentativas = 5;
        }
        else if(nivel >=0 || nivel > 3)
        {
            tentativas = 1;
            printf("Vi que voce nao digitou um numero de 1 a 3, voce e rebelde hein. Te deixarei com apenas 1 tentativa para aprender!\n");
        }
        printf("Certo, agora vamos comecar: \n");

        for (rodada = 1; rodada <= tentativas; rodada++)
        {
            printf("Tentativa %d de %d. Digite um numero entre 1 e 100: \n",rodada, tentativas);
            scanf("%d", &chute);

            int acerto = chute == numeroSecreto;
            int maior = chute > numeroSecreto;
            int menor = chute < numeroSecreto;
            
            if (acerto)
            {
                printf("Parabens, voce acertou!\n");
                ganhou = true;
                break;
            }
            else if (menor)
            {
                printf("Seu chute foi menor que o numero secerto!\n");
            }
            else if(maior){
                printf("Seu chute foi maior que o numero secreto!\n");
            }
            if (rodada == tentativas)
            {
                ganhou = false;
            }
            
        }
        if (ganhou)
        {
            printf("Voce ganhou!!! Voce precisou de %d tentativas para acertar! :)\n", rodada);
        }
        else{
            printf("Parece que as %d tentativas nao foram o suficiente... O numero secreto era %d. Voce perdeu! :(\n", tentativas, numeroSecreto);
        }

        int repete = 0;
        printf("Voce deseja jogar novamente? Digite (1) para sim e (2) para nao: \n");
        scanf("%d", &repete);

        if (repete == 1)
        {
            printf("Entao bora la!\n");
            continue;
        }
        else
        {
            break;
        }
    }
}