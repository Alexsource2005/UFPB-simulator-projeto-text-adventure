#include <stdio.h>
#include "objetos.h"

tObjetos *ator_aqui(void) {
    tObjetos *obj;
    for(obj = lista_objetos; obj < fim_lista; obj++){
        if(obj->local == player->local && obj == jovem)
            return obj;
    }
    return NULL;
}


tObjetos *pega_passagem(tObjetos *origem, tObjetos *destino_f) { //verificar se certa passagem conecta dois dados locais; se houver, retorna um ponteiro para o objeto correpondente a ela.
    if(origem != NULL && destino_f != NULL){
        tObjetos *obj;
        for(obj = lista_objetos; obj < fim_lista; obj++){
            if(obj->local == origem && obj->destino == destino_f){
                return obj;
            }
        }
    }
    return NULL;
}


void imprimir_objetos(tObjetos *obj, int *cont, const char *mensagem) {
    if (*cont == 0) {
        printf("%s\n", mensagem);
    }
    printf("- %s\n", obj->descricao);
    (*cont)++;
}


int lista_objetos_presentes(tObjetos *local_atual) {
    int cont = 0;

    if (local_atual != player && local_atual != NULL) {
        for (tObjetos *obj = lista_objetos; obj < fim_lista; obj++) {
            if (obj != player && obj->local == local_atual) {
                imprimir_objetos(obj, &cont, "Você vê:");
            }
        }
    } else if (local_atual == NULL) {
        for (tObjetos *obj = lista_objetos; obj < fim_lista; obj++) {
            if (obj != player && obj->local == NULL) {
                imprimir_objetos(obj, &cont, "Locais acessiveis:");
            }
        }
    } else {
        for (tObjetos *obj = lista_objetos; obj < fim_lista; obj++) {
            if (obj != player && obj->local == local_atual) {
                imprimir_objetos(obj, &cont, "Você possui em seus bolsos:");
            }
        }
    }

    return cont; // retorna o número de objetos no local
}
