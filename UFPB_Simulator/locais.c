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
        printf("Eu não sei oque voce quer que eu veja.\n");
    }
}

void exec_ir(const char* substantivo) {
    setlocale(LC_ALL, " ");
    tObjetos *obj = visivel_existe("Onde voce quer ir ", substantivo);

    if(obj == NULL){

    } else if(pega_passagem(player->local, obj) != NULL){
        printf("OK.\n");
      player->local = obj;
      exec_olhar("ao redor");

    } else if(obj->local != player->local){
        printf("Voce não vê nenhum %s aqui.\n", substantivo);

    } else if(obj->descricao != NULL){
        printf("OK.\n");
        player->local = obj->destino;
        exec_olhar("ao redor");

    } else {
        printf("Impossivel se aproximar mais que isso.\n");
    }
}
