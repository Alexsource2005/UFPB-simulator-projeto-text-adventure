#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "objetos.h"
#include "misc.h"
#include "substantivo.h"

void exec_olhar(const char* substantivo) {
    setlocale(LC_ALL, " ");
    if(substantivo != NULL && strcasecmp(substantivo, "ao redor") == 0) { //verifica se o usuário quer olhar ao redor
        printf("Você está em %s", player->local->descricao);
        lista_objetos_presentes(player->local);
    } else {
        tObjetos *obj = visivel_existe("Oque voce quer olhar", substantivo);

        switch(pega_distancia(player, obj)){
        case dist_AquiContido:
            printf("Dificil de ver, tente pegar primeiro.\n");
            break;

        case dist_AliDoLado:
            printf("Muito longe. Se aproxime, por favor. \n");
            break;

        case dist_NaoAqui:
            printf("Você não vê nenhum %s aqui.\n", substantivo);
            break;

        case dist_objetoNaoReconhecido:
            // já vai ser resolvido pela função "visivel_existe"
            break;

        default:
            printf("%s\n", obj->detalhes);
            lista_objetos_presentes(obj);

        }
    }
}

static void mover_jogador(tObjetos *passagem){
    printf("%s\n", passagem->texto_GO);
    if(passagem->destino != NULL) {
        player->local = passagem->destino;
        printf("\n");
        exec_olhar("ao redor");
    }
}

void exec_ir(const char* substantivo) {
    setlocale(LC_ALL, " ");
    tObjetos *obj = visivel_existe("Onde voce quer ir ", substantivo); //tentar colocar um while aqui pra testar

    switch(pega_distancia(player, obj)){
    case dist_AliDoLado:
        mover_jogador(pega_passagem(player->local, obj));
        break;

    case dist_NaoAqui:
        printf("Voce não vê nenhum %s aqui.\n", substantivo);
        break;

    case dist_objetoNaoReconhecido:
        // a função visivel_existe já lida com esse caso
        break;

    default:
        mover_jogador(obj);
    }
}
