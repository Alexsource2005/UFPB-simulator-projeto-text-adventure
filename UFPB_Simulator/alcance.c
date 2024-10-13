#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include "misc.h"
#include "substantivo.h"

tObjetos *objeto_no_alcance(const char *intencao, const char *substantivo){
    tObjetos *obj = visivel_existe(intencao, substantivo);

    switch(pega_distancia(player, obj)) {
    case dist_SiProprio:
        printf("Você não deveria fazer isso consigo mesmo.\n");
        break;

    case dist_PosseContido:
    case dist_AquiContido:
        printf("Você tem que pegar isso de dentro do %s primeiro.\n", obj->local->descricao);
        break;

    case dist_AliDoLado:
        printf("Muito longe, por favor se aproxime.\n");
        break;

    case dist_NaoAqui:
    case dist_objetoNaoReconhecido:
        //visivel_existe lida com isso
        break;

    default:
        return obj;
    }
    return NULL;
}
