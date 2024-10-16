#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include <stdlib.h>

bool loseFome(int howMuch);
void addFome(int fomeValue);

bool loseEnergia(int howMuch);
void addEnergia(int energiaValue);

void loseSanidade(int howMuch);
void addSanidade(int sanidadeValue);

bool loseBanheiro(int howMuch);

bool checkStatus();

bool itsAlive = true;

char *whereIm = "Liepe";

int fome = 0, energia = 100, sanidade = 100, necessidade_banheiro = 0;


/////////////// Fome



bool loseFome(int howMuch) {
    if (fome > howMuch) {
        fome -= howMuch;
        return true;
    }
    return false;
}

void addFome(int fomeValue){ // Função para adicionar fome
    fome += fomeValue;

    if (fome > 100){
        fome = 100;
    }
}


bool exec_eat(){ // Função do comando para comer

    addFome(-30);

    printf("Voce achou uma bolacha no seu bolso e a comeu!\n");
    printf("Voce esta comido agora: sua atual fome eh (%d)\n", fome);
    return true;
}



/////////////// Energia



bool loseEnergia(int howMuch) {
    if (energia > howMuch) {
        energia -= howMuch;
        return true;
    }
    return false;
}

void addEnergia(int energiaValue){ // Função para adicionar energia

    energia += energiaValue;

}



bool exec_sleep(void) {
    // Verifica se o jogador está no CTDR
    if (player->local != CTDR) {
        printf("Voce so pode dormir no CTDR. Encontre um lugar mais confortavel para descansar.\n");
        return true;
    }

    // Verifica se o jogador tem energia suficientemente baixa para dormir
    if (energia > 80) {
        printf("Voce nao esta cansado o suficiente para dormir agora.\n");
        return true;
    }

    // Cálculo da recuperação de energia e aumento da fome
    int energiaRecuperada = 100 - energia;  // Recupera até o máximo de 100
    int fomeAumentada = energiaRecuperada / 5;  // Aumenta a fome proporcionalmente à energia recuperada

    energia = 100;  // Recupera toda a energia
    fome += fomeAumentada;
    if (fome > 100) fome = 100;  // Limita a fome a 100

    printf("Voce dormiu e recuperou sua energia. Agora voce esta completamente descansado!\n");
    printf("Sua fome aumentou para %d.\n", fome);

    // Chance de recuperar um pouco de sanidade
    if (rand() % 100 < 30) {  // 30% de chance
        int sanidadeRecuperada = 10 + (rand() % 11);  // Recupera entre 10 e 20 de sanidade
        addSanidade(sanidadeRecuperada);
        printf("Voce teve sonhos agradáveis e recuperou um pouco de sanidade.\n");
    }

    // Reseta a necessidade de ir ao banheiro
    necessidade_banheiro = 0;
    printf("Voce aproveitou para usar o banheiro e se sente aliviado.\n");

    return true;
}



/////////////// Sanidade



void loseSanidade(int howMuch) { // Função para perda de sanidade
    sanidade -= howMuch;
}


void addSanidade(int sanidadeValue){ // Função para adicionar sanidade

    sanidade += sanidadeValue;

}




/////////////// Banheiro



bool addBanheiro(int howMuch) { // Função para perda de Banheiro
    necessidade_banheiro += howMuch;
    if (necessidade_banheiro < 100){
        // Caso tenha Banheiro para perder ainda
        return true;
    }
    else{
        printf("Você está se cagando \n"); // Um simples output só pra saber quando está zerado
        return false;
    }

}



bool exec_banheiro(void) {
    // Verifica se o jogador está no banheiro
    if (player->local != banheiro) {
        printf("Voce nao esta em um banheiro. Encontre um banheiro adequado para aliviar suas necessidades.\n");
        return true;
    }

    // Verifica se o jogador realmente precisa usar o banheiro
    if (necessidade_banheiro <= 20) {
        printf("Voce nao esta com muita vontade de ir ao banheiro agora.\n");
        return true;
    }

    // Usa o banheiro
    int alivio = necessidade_banheiro;
    necessidade_banheiro = 0;

    printf("Voce usa o banheiro e se sente aliviado. Sua necessidade foi reduzida em %d pontos.\n", alivio);

    // Chance de recuperar um pouco de sanidade
    if (rand() % 100 < 20) {  // 20% de chance
        int sanidadeRecuperada = 5 + (rand() % 6);  // Recupera entre 5 e 10 de sanidade
        addSanidade(sanidadeRecuperada);
        printf("Voce se sente muito melhor após usar o banheiro. Sua sanidade aumentou um pouco.\n");
    }

    // Pequena chance de algo inusitado acontecer
    if (rand() % 100 < 5) {  // 5% de chance
        printf("Enquanto usa o banheiro, você nota uma mensagem engraçada escrita na parede. Isso te faz sorrir.\n");
        addSanidade(2);
    }

    return true;
}



// Checkar cada ação se o player tá com os status ok
bool checkStatus() {
    if (energia <= 0 || fome >= 100 || sanidade <= 0 || necessidade_banheiro >= 100) {
        printf("Você nao sobreviveu as dificuldades da UFPB!\n");
        if (energia <= 0) printf("Sua falta de energia acabou te consumindo e te levou a morte \n");
        if (fome >= 100) printf("Voce morreu de fome.\n");
        if (sanidade <= 0) printf("Voce acabou se matando de tao louco ficou. \n");
        if (necessidade_banheiro >= 100) printf("Voce acabou se cagando, o que fez morrer de vergonha (mesmo sem ninguem ter visto isso, burrokkkkkkkkkkk) \n");
        return false;
    }
    return true;
}

// perder sanidade e aumentar vontade de ir no banheiro a cada 5 turnos
void update_status() {
    static int turns = 0;
    turns++;

    if (turns % 5 == 0) { // A cada 5 turnos
        loseSanidade(5);
        addBanheiro(10);
    }
}
