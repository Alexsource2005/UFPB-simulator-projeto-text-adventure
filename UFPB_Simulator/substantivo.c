#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "objetos.h"
#include "misc.h"

static bool objeto_tem_rotulo(tObjetos *obj, const char *substantivo) {
   if(substantivo != NULL && *substantivo != '\0'){ // verificando se o substantivo não é vazio ou apenas um "enter"
        const char **rotulo;
        for(rotulo = obj->rotulo; *rotulo != NULL; rotulo++){ // passando por cada lista de rotulos predefinidos
            if(strcasecmp(*rotulo, substantivo) == 0)
                return true;
        }
   }
   return false;
}

static tObjetos substantivo_ambiguo; //isso serve para retornar um único endereço caso tenha dois objetos com o mesmo rotulo em um local (uma moeda de ouro e outra de prata na mesma sala)

static tObjetos *pega_objeto(const char *substantivo, tObjetos *origem, tDistancia dist_maxima) { //verifica se o objeto que o jogador deseja interagir existe;
    tObjetos *obj, *res = NULL;                            // Se existir, retorna um ponteiro para o objeto especifico, senão, retorna NULL
    for(obj = lista_objetos; obj < fim_lista; obj++){
        if(objeto_tem_rotulo(obj, substantivo) && pega_distancia(origem, obj) <= dist_maxima) { //apenas considera visiveis objetos que estejam a uma certa distancia(menor ou igual) da origem. Qualquer objeto mais longe será ignorado
                res = res == NULL ? obj : &substantivo_ambiguo;                                                                   //A distancia estar em um enum permite que usemos que quanto maior o número, maior a distancia
           }
    }
    return res;
}

tObjetos *visivel_existe(const char *intencao, const char *substantivo) {
    tObjetos *obj = pega_objeto(substantivo, player, dist_AliDoLado); // chama um objeto que esteja no "campo de visão" do jogador. Ou seja, na mesma sala ou uma sala conectada

    if(obj == NULL){
        if(pega_objeto(substantivo, player, dist_NaoAqui) == NULL){
            printf("Eu não entendo %s.\n", intencao);
        } else {
            printf("Você não vê nenhum %s aqui.\n", substantivo);
        }
    } else if(obj == &substantivo_ambiguo){
        printf("Por favor, especifique a qual %s voce se refere.\n", substantivo);
        obj == NULL;
    }

    return obj;
}

tObjetos *pega_possesao(tObjetos *origem, const char *verbo, const char *substantivo) {
    tObjetos *obj = NULL;

    if(origem == NULL) {
        printf("Eu não entendo quem voce quer %s.\n", verbo);

    } else if ((obj = pega_objeto(substantivo, origem, dist_PosseContido)) == NULL){ // chamar a função com dist_PosseContido limita a seleção de objetos para todos aqueles que o jogador possui(incluindo ele mesmo)
        if(pega_objeto(substantivo, player, dist_NaoAqui) == NULL){
            printf("Eu não entendo oque você quer %s.\n", verbo);
        } else if(origem == player){
            printf("Voce não possui nenhum %s em seus bolsos.\n", substantivo);
        } else {
            printf("Parece que não tem nenhum %s que você possa conseguir do %s.\n",substantivo, origem->descricao);
        }

    } else if(obj == &substantivo_ambiguo){
        printf("Por favor, especifique qual %s você quer %s.\n", substantivo, verbo);
        obj == NULL;
    } else if(obj == origem) {
        printf("Voce não deveria fazer isso com %s.\n", obj->rotulo);
        obj = NULL;
    }
    return obj;
}
