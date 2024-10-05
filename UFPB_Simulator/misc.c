#include <stdio.h>
#include "objetos.h"

int lista_objetos_presentes(tObjetos *local_atual) {
    int cont = 0;
    tObjetos *obj;
    for(obj = lista_objetos; obj < fim_lista; obj++){
        if(obj != player && obj->local == local_atual){ //exclui o objeto "jogador"
            if(cont++ == 0)
                printf("Você vê: \n");
            printf("- %s \n", obj->descricao);
        }
    }
    return cont; // retorna o número de objetos no local
}
