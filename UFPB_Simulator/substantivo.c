#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "objetos.h"

static bool objeto_tem_rotulo(tObjetos *obj, const char *substantivo) {
    return substantivo != NULL && *substantivo != '\0' && strcasecmp(substantivo, obj->rotulo) == 0; //compara oque foi escrito com os rotulos predefinidos
}

static tObjetos *pega_objeto(const char *substantivo) { //verifica se o objeto que o jogador deseja interagir existe;
    tObjetos *obj, *res = NULL;                            // Se existir, retorna um ponteiro para o objeto especifico, sen�o, retorna NULL
    for(obj = lista_objetos; obj < fim_lista; obj++){
        if(objeto_tem_rotulo(obj, substantivo)) {
                return obj;
           }
    }
    return res;
}

tObjetos *visivel_existe(const char *intencao, const char *substantivo) {
    tObjetos *obj = pega_objeto(substantivo);

    if(obj == NULL){
        printf("Eu n�o entendo %s\n", intencao);
    } else if (!(obj == player ||  // o objeto ser o jogador o torna v�sivel, claro
              obj == player->local || // o local em que o jogador atualmente est�
              obj->local == player || // objetos que o jogador tem no invent�rio
              obj->local == player->local ||  //objetos presentes no mesmo local que o jogador
              obj->local == NULL || // qualquer local que o jogador tenha acesso
              obj->local->local == player || //objetos dentro de outro objeto que o jogador tem no invent�rio
              obj->local->local == player->local)) // objetos dentro de outro objeto que est� no mesmo local que o jogador
    {
        printf("Voce n�o v� nenhum %s aqui.\n", substantivo);
        obj = NULL;
    }
    return obj;
}
