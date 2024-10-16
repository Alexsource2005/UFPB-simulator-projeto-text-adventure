#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "objetos.h"
#include "misc.h"
#include "substantivo.h"
#include "comparar.h"
#include "survive.h"
#include <stdlib.h>

bool exec_olhar_aoredor(void){
    printf("Voc� est� em %s.\n", player->local->descricao);
    lista_objetos_presentes(player->local);

    printf("\nSeu status:\n");
    printf("Energia: %d\n", energia);
    printf("Sanidade: %d\n", sanidade);
    printf("Fome: %d\n", fome);
    printf("Necessidade de ir ao banheiro: %d\n", necessidade_banheiro);

    return true;
}

bool exec_olhar(void) {
    setlocale(LC_ALL, " ");
        tObjetos *obj = visivel_existe("Oque voce quer olhar", parametros[0]);

        switch(pega_distancia(player, obj)){
        case dist_AquiContido:
            printf("Dificil de ver, tente pegar primeiro.\n");
            break;

        case dist_AliDoLado:
            printf("Muito longe. Se aproxime, por favor. \n");
            break;

        case dist_NaoAqui:
            printf("Voc� n�o v� nenhum %s aqui.\n", parametros[0]);
            break;

        case dist_objetoNaoReconhecido:
            // j� vai ser resolvido pela fun��o "visivel_existe"
            break;

        default:
            printf("%s\n", obj->detalhes);
            lista_objetos_presentes(obj);

        }
    return true;
}


static void mover_jogador(tObjetos *passagem){
    printf("%s\n", passagem->texto_GO);
    if(passagem->destino != NULL) {
        player->local = passagem->destino;
        printf("\n");
        exec_olhar_aoredor();
    }
}

bool exec_ir(void) {
    setlocale(LC_ALL, " ");
    tObjetos *obj = visivel_existe("Onde voce quer ir ", parametros[0]);

    switch(pega_distancia(player, obj)){
    case dist_AliDoLado:
        if (energia > 10 && fome < 95) {
            loseEnergia(6); addFome(5);// Mover-se consome 10 de energia e 5 de fome
            mover_jogador(pega_passagem(player->local, obj));

            // Chance aleat�ria de perder sanidade ao se mover
            if (rand() % 100 < 20) { // 20% de chance
                loseSanidade(10);
                printf("Voc� sente um arrepio ao se mover. Sua sanidade diminuiu um pouco.\n");
            }

            // Aumenta a necessidade de ir ao banheiro
            addBanheiro(3);

            // Verifica se o jogador precisa urgentemente ir ao banheiro
            if (necessidade_banheiro >= 80) {
                printf("Voc� est� sentindo uma urg�ncia em ir ao banheiro!\n");
            }
        } else {
            printf("Voc� est� muito cansado ou com muita fome para se mover agora.\n");
            if (energia <= 10) {
                char resposta[10];
                printf("Voc� gostaria de tirar um cochilo r�pido para recuperar um pouco de energia? (sim/nao): ");
                scanf("%s", resposta);
                if (strcmp(resposta, "sim") == 0) {
                    energia += 20;
                    if (energia > 100) energia = 100;
                    fome += 10;
                    if (fome > 100) fome = 100;
                    printf("Voc� tirou um cochilo r�pido. Energia atual: %d, Fome atual: %d\n", energia, fome);
                }
            }
        }
        break;

    case dist_NaoAqui:
        printf("Voce n�o v� nenhum %s aqui.\n", parametros[0]);
        break;

    case dist_objetoNaoReconhecido:
        // a fun��o visivel_existe j� lida com esse caso
        break;

    default:
        if (energia > 10 && fome < 95) {
            loseEnergia(6); addFome(5);// Mover-se consome 10 de energia e 5 de fome
            mover_jogador(obj);
        } else {
            printf("Voc� est� muito cansado ou com muita fome para se mover agora.\n");
            if (energia <= 10) {
                char resposta[10];
                printf("Voc� gostaria de tirar um cochilo r�pido para recuperar um pouco de energia? (sim/n�o): ");
                scanf("%s", resposta);
                if (strcmp(resposta, "sim") == 0) {
                    energia += 20;
                    if (energia > 100) energia = 100;
                    fome += 10;
                    if (fome > 100) fome = 100;
                    printf("Voc� tirou um cochilo r�pido. Energia atual: %d, Fome atual: %d\n", energia, fome);
                }
            }
        }
    }

    // Verifica o status ap�s o movimento
    if (!checkStatus()) {
        printf("Voc� n�o consegue mais continuar... Fim de jogo.\n");
        return false; // Isso encerrar� o jogo
    }

    return true;
}
