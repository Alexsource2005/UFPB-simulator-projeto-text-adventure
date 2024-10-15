#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "objetos.h"
#include "misc.h"
#include "substantivo.h"
#include "movimento.h"
#include "comparar.h"
#include "survive.h"

bool exec_pegar(void){
    tObjetos *obj = visivel_existe("Oque voce quer pegar", parametros[0]); //verificar se o objeto existe no sistema e se � visivel ao jogador

    switch(pega_distancia(player, obj))
    {
    case dist_SiProprio:
        printf("Voc� n�o deveria fazer isso com voc� mesmo.\n");
        break;

    case dist_Posse:
        printf("Voc� j� tem %s em seus bolsos.\n", obj->descricao);
        break;

    case dist_AliDoLado:
        printf("T� muito longe, se aproxime para poder pegar.\n");
        break;

    case dist_objetoNaoReconhecido:
        // a fun��o visivel_existe j� lida com isso
      break;

    default:
        if (obj->local != NULL && obj->local->vida > 0) //condi��o de ter vida maior que 0 identifica se o local que o objeto se encontra � um NPC
      {
         printf("Voc� deveria pedir ao %s antes de pegar algo que n�o te pertence.\n", obj->local->descricao);
      }
      else
      {
         mover_objeto(obj, player);
      }

    }
    return true;
}


bool exec_jogar(void){
    if(player->local == AIDS){
        mover_objeto(pega_possesao(player, "jogar", parametros[0]), AIDS); //s� pra jogar algo na fossa (pedras)
        // Adicionar sanidade (quantidade pode ser mudada do jeito que preferir)
        addSanidade(30);}
    else
        printf("N�o tem local adequado para jogar esse objeto.\n");
    return true;
}


bool exec_pedir(void){
    mover_objeto(pega_possesao(ator_aqui(), "pedir", parametros[0]), player);
    return true;
}

bool exec_dar(void) {
    mover_objeto(pega_possesao(player, "dar", parametros[0]), ator_aqui());
    return true;
}

bool exec_inventario(void)
{
   if (lista_objetos_presentes(player) == 0)
   {
      printf("Voc� n�o tem nada nos bolsos.\n");
   }
   return true;
}

