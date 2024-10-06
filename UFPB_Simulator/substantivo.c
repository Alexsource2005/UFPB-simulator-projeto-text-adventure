#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "objetos.h"

static bool objeto_tem_rotulo(tObjetos *obj, const char *substantivo) {
    return substantivo != NULL && *substantivo != '\0' && strcasecmp(substantivo, obj->rotulo) == 0; //compara oque foi escrito com os rotulos predefinidos
}

static tObjetos *pega_objeto(const char *substantivo) { //verifica se o objeto que o jogador deseja interagir existe;
    tObjetos *obj, *res = NULL;                            // Se existir, retorna um ponteiro para o objeto especifico, senão, retorna NULL
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
        printf("Eu não entendo %s\n", intencao);
    } else if (!(obj == player ||  // o objeto ser o jogador o torna vísivel, claro
              obj == player->local || // o local em que o jogador atualmente está
              obj->local == player || // objetos que o jogador tem no inventário
              obj->local == player->local ||  //objetos presentes no mesmo local que o jogador
              obj->local == NULL || // qualquer local que o jogador tenha acesso
              obj->local->local == player || //objetos dentro de outro objeto que o jogador tem no inventário
              obj->local->local == player->local)) // objetos dentro de outro objeto que está no mesmo local que o jogador
    {
        printf("Voce não vê nenhum %s aqui.\n", substantivo);
        obj = NULL;
    }
    return obj;
}

tObjetos *pega_possesao(tObjetos *origem, const char *verbo, const char *substantivo) {
    tObjetos *obj = NULL;

    if(origem == NULL) {
        printf("Eu não entendo oque voce quer %s.\n", verbo);

    } else if ((obj = pega_objeto(substantivo)) == NULL){
        printf("Eu não entendo oque voce quer %s.\n", verbo);

    } else if(obj == origem) {
        printf("Voce não deveria fazer isso com %s.\n", obj->rotulo);
        obj = NULL;

    } else if(obj->local != origem) {
        if(origem == player){
            printf("Voce não possui nenhum %s.\n", substantivo);

        } else {
            printf("Não existe nenhum %s que voce possa pegar do %s.\n", substantivo, origem->rotulo);

        }
        obj = NULL;
    }
    return obj;
}
