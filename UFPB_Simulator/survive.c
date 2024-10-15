#include <stdio.h>
#include <stdbool.h>

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

int fome = 2, energia = 100, sanidade = 100, banheiro = 100;


/////////////// Fome



bool loseFome(int howMuch) { // Função para perda de fome
    fome -= howMuch;

    if (fome > 0){
        printf("Fome: %d\n", fome); // Caso tenha fome para perder ainda
        return true;
    }
    else{
        // Um simples output só pra saber quando está zerado
        return false;
    }
}


void addFome(int fomeValue){ // Função para adicionar fome
    fome += fomeValue;

    if (fome > 100){
        fome = 100;
    }
}


bool exec_eat(){ // Função do comando para comer

    addFome(30);

    printf("Você está comido agora: sua atual fome é (%d)\n", fome);
    return true;
}



/////////////// Energia



bool loseEnergia(int howMuch) { // Função para perda de fome
    energia -= howMuch;
    if (energia > 0){
        printf("Energia: %d\n", energia); // Caso tenha Energia para perder ainda
        return true;
    }
    else{
        printf("Tá sem energia \n"); // Um simples output só pra saber quando está zerado
        return false;
    }

}

void addEnergia(int energiaValue){ // Função para adicionar energia

    energia += energiaValue;

}



bool exec_sleep(void) { // Função para o comando de dormir

    if (energia > 80) {
        fome -= 2;  // Sono rápido, pequeno aumento de fome
        printf("Você teve um sono rápido: seu alimento diminuiu para (%d)\n", fome);
    }
    else if (energia > 60) {
        fome -= 5;  // Sono moderado, aumento moderado de fome
        printf("Você teve um sono moderado: seu alimento diminuiu para (%d)\n", fome);
    }
    else {
        fome -= 10;  // Sono profundo, grande aumento de fome
        printf("Você dormiu profundamente: seu alimento diminuiu para (%d)\n", fome);
    }

    return true; // Retorna true indicando que a função foi executada com sucesso
}




/////////////// Sanidade



void loseSanidade(int howMuch) { // Função para perda de sanidade
    sanidade -= howMuch;
    if (sanidade > 0){
        printf("Sanidade: %d\n", sanidade); // Caso tenha Sanidade para perder ainda
    }

}


void addSanidade(int sanidadeValue){ // Função para adicionar sanidade

    sanidade += sanidadeValue;

}




/////////////// Banheiro



bool loseBanheiro(int howMuch) { // Função para perda de Banheiro
    banheiro -= howMuch;
    if (banheiro > 0){
        printf("Banheiro: %d\n", banheiro); // Caso tenha Banheiro para perder ainda
        return true;
    }
    else{
        printf("Você está se cagando \n"); // Um simples output só pra saber quando está zerado
        return false;
    }

}



bool exec_banheiro(void){ // Ação de usar o banheiro
    if (banheiro <= 80){
        printf("Finalmente um momento de alivio, agora posso voltar");
        banheiro = 100;
        return true;
    }
    else{
        printf("Você fez força mas nada saiu, melhor esperar um pouco mais");
        return true;
    }


    return false;
}



// Checkar cada ação se o player tá com os status ok

bool checkStatus(){
    if (fome <= 0)
    {
        printf("Você morreu de fome \n");
        return false;
    }

    if (sanidade <= 0)
    {
        printf("Você acabou se matando de tão louco estava \n");
        return false;
    }

    if (energia <= 0)
    {
        printf("Sua falta de energia acabou te consumindo e te levou a morte \n");
        return false;
    }

    if (banheiro <= 0)
    {
        printf("Você acabou se cagando, o que fez morrer de vergonha (mesmo sem ninguém ter visto isso, burrokkkkkkkkkkk) \n");
        return false;
    }



    return true;
}
