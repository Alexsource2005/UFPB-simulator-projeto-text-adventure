#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "objetos.h"
#include "misc.h"
#include "substantivo.h"
#include "movimento.h"

void exec_pegar(char *substantivo){
    tObjetos *obj = visivel_existe("Oque voce quer pegar", substantivo); //verificar se o objeto existe no sistema e se é visivel ao jogador

    switch(pega_distancia(player, obj))
    {
    case dist_SiProprio:
        printf("Você não deveria fazer isso com você mesmo.\n");
        break;

    case dist_Posse:
        printf("Você já tem %s em seus bolsos.\n", obj->descricao);
        break;

    case dist_AliDoLado:
        printf("Tá muito longe, se aproxime para poder pegar.\n");
        break;

    case dist_objetoNaoReconhecido:
        // a função visivel_existe já lida com isso
      break;

    default:
        if (obj->local != NULL && obj->local->vida > 0) //condição de ter vida maior que 0 identifica se o local que o objeto se encontra é um NPC
      {
         printf("Você deveria pedir ao %s antes de pegar algo que não te pertence.\n", obj->local->descricao);
      }
      else
      {
         mover_objeto(obj, player);
      }

    }
}

void exec_jogar(char *substantivo){
    if(player->local == AIDS)
        mover_objeto(pega_possesao(player, "jogar", substantivo), AIDS); //em teoria isso é só pra jogar pedras na fossa
    else
        printf("Não tem local adequado para jogar esse objeto.\n");
}


void exec_pedir(char *substantivo){
    mover_objeto(pega_possesao(ator_aqui(), "pedir", substantivo), player); //implementar
}

void exec_dar(char *substantivo) {
    mover_objeto(pega_possesao(player, "dar", substantivo), ator_aqui()); //implementar
}

void exec_checar(char *substantivo){
    if(strcasecmp(substantivo, "inventario") == 0){
        if(lista_objetos_presentes(player) == 0)
            printf("Voce não tem nada nos bolsos.\n");
        else
            lista_objetos_presentes(player);

    } else if(strcasecmp(substantivo, "mapa") == 0) {
        lista_objetos_presentes(NULL);

    } else {
        tObjetos *obj = visivel_existe("Oque voce quer checar", substantivo);
        if(obj == NULL) {

        } else {
            printf("se trata de %s", obj->descricao);
        }
    }
}
