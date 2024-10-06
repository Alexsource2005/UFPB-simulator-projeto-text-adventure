#include <stdio.h>
#include "objetos.h"
#include "misc.h"
#include "substantivo.h"
#include "movimento.h"

void exec_pegar(char *substantivo){
    tObjetos *obj = visivel_existe("Oque voce quer pegar", substantivo); //verificar se o objeto existe no sistema e se � visivel ao jogador

    if(obj == NULL){

    } else if(obj == player){
        printf("N�o fa�a isso consigo mesmo.\n");

    } else if(obj->local == player){
        printf("Voc� j� est� em posse desse objeto.\n");

    } else if(obj->local == jovem) {
        printf("Voc� deveria falar %s antes de pegar algo que n�o te pertence.", obj->local->rotulo);

    } else {
        mover_objeto(obj, player); //implementar fun��o de mudar local do objeto
    }
}

void exec_jogar(char *substantivo){
    if(player->local == AIDS)
        mover_objeto(pega_possesao(player, "jogar", substantivo), AIDS); //em teoria isso � s� pra jogar pedras na fossa
    else
        printf("N�o tem local adequado para jogar esse objeto.\n");
}


void exec_pedir(char *substantivo){
    mover_objeto(pega_possesao(ator_aqui(), "pedir", substantivo), player); //implementar
}

void exec_dar(char *substantivo) {
    mover_objeto(pega_possesao(player, "dar", substantivo), ator_aqui()); //implementar
}

void exec_checar(char *substantivo){
    if(strcasecmp(substantivo, "o inventario") == 0){
        if(lista_objetos_presentes(player) == 0)
            printf("Voce n�o tem nada nos bolsos.\n");
        else
            lista_objetos_presentes(player);

    } else if(strcasecmp(substantivo, "o mapa") == 0) {
        lista_objetos_presentes(NULL);

    } else {
        tObjetos *obj = visivel_existe("Oque voce quer checar", substantivo);
        if(obj == NULL) {

        } else {
            printf("se trata de %s", obj->descricao);
        }
    }
}
