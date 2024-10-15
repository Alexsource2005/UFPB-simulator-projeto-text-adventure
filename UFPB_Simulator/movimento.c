#include <stdbool.h>
#include <stdio.h>
#include "objetos.h"
#include "misc.h"

static int peso_dos_conteudos(tObjetos *container) {
    int soma = 0;
    tObjetos *obj;
    for(obj = lista_objetos; obj < fim_lista; obj++){
        if(esta_segurando(container, obj))
            soma += obj->peso;
    }
    return soma;
}

static void descreve_movimento(tObjetos *obj, tObjetos *destino) {
    if (destino == player->local) {
        printf("Voc� jogou %s na fossa.\n", obj->descricao);

    } else if (destino != player) {
        printf(destino->vida > 0 ? "Voc� d� %s para %s.\n" : "Voc� coloca %s no %s.\n", obj->descricao, destino->descricao);

    } else if(obj->local == player->local) {
        printf("Voc� pegou %s.\n", obj->descricao);

    } else {
        printf("Voc� pega %s do %s.\n", obj->descricao, obj->local->descricao);
    }
}


void mover_objeto(tObjetos *obj, tObjetos *destino) {
    if (obj == NULL)
    {
        printf("Objeto n�o encontrado para mover.\n");
        return; // Retorna imediatamente se obj for NULL

    }
    else if (destino == NULL)
    {
        printf("N�o tem ningu�m aqui para dar isto.\n");
        return; // Retorna se destino for NULL

    }
    else if(destino->capacidade == 0)
    {
        printf("Isso n�o encaixa direito aqui.");
    }
    else if(obj->peso > destino->capacidade)
    {
        printf("Isso � muito pesado pra carregar.\n");

    }
    else if(obj->peso + peso_dos_conteudos(destino) > destino->capacidade)
    {
        printf("Isso excederia a capacidade.\n");
    }
    else
    {
        descreve_movimento(obj, destino);
        obj->local = destino; // Move o objeto para o novo destino
    }
}
