#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char* descricao;  // descrição que aparecerá ao olhar ao redor
    char* rotulo; // nome do local
} tlocal;

tlocal locais[] = {
    {"Um prédio generico com vasta concentração de distúrbios mentais\n", "ao Centro de informatica"},
    {"Um prédio alto com sérios problemas estruturais.\n uma nevóa densa cobre os corredores deste local... assustador\n", "ao Liepe"},
    {"Uma estrutura organizada feita de tijolos, com vários gatos ao redor.\n O único restaurante do campus se encontra aqui\n", "ao CTDR"},
    {"Uma lagoa de agua parada em uma clareira escondida nos matos.\n Voce sente uma vontade primitiva de jogar pedras lá dentro.\n", "ao poco da AIDS"},
    {"Um banheiro em que todas as privadas não tem assento.\n Pelo menos tem papel higienico...\n", "ao banheiro"}
}; // struct com todos os locais acessiveis do jogo

#define num_locais (sizeof(locais) / sizeof(*locais))

static unsigned int local_jogador = 0;

void exec_olhar(const char* substantivo) {
    setlocale(LC_ALL, " ");
    if(substantivo != NULL && strcasecmp(substantivo, "ao redor") == 0) { //verifica se o usuário quer olhar ao redor
        printf("Você está em %s", locais[local_jogador].descricao);
    } else {
        printf("Eu não sei oque voce quer que eu veja.\n");
    }
}

void exec_ir(const char* substantivo) {
    setlocale(LC_ALL, " ");
    unsigned int i = 0;

    for(i=0; i<num_locais; i++) {
            if(substantivo != NULL && strcasecmp(substantivo, locais[i].rotulo) == 0) {
                if(i == local_jogador) {
                    printf("voce já está nesse local.\n");
                } else {
                    printf("Ok!\n");
                    local_jogador = i;
                    exec_olhar("ao redor");
                }
                return;
            }
    }
    printf("Eu não conheço esse lugar.\n");
}
