#include <stdio.h>
#include "objetos.h"

static void descreve_movimento(tObjetos *obj, tObjetos *destino) {
    if (destino == player->local) {
        printf("Voc� jogou %s na fossa.\n", obj->rotulo);
    } else if (destino == jovem) {
        printf("Voc� d� %s %s.\n", obj->rotulo, destino->rotulo);
    } else {
        printf("Voc� colocou %s em %s.\n", obj->rotulo, destino->rotulo);
    }
}

void mover_objeto(tObjetos *obj, tObjetos *destino) {
    if (obj == NULL) {
        printf("Objeto n�o encontrado para mover.\n");
        return; // Retorna imediatamente se obj for NULL
    }

    if (destino == NULL) {
        printf("N�o tem ningu�m aqui para dar isto.\n");
        return; // Retorna se destino for NULL
    }

    if (obj->local == NULL) {
        printf("Isso � muito pesado para carregar.\n");
        return; // Retorna se o objeto n�o tem um local definido
    }

    descreve_movimento(obj, destino);
    obj->local = destino; // Move o objeto para o novo destino
}
