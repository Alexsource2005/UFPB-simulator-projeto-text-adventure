#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include "misc.h"

bool esta_segurando(tObjetos *container, tObjetos *obj) { //uma função auxiliar para indicar se um objeto está contido em algum lugar (jogador ou uma bolsa)
    return obj != NULL && obj->local == container;
}

tObjetos *ator_aqui(void) {
    tObjetos *obj;
    for(obj = lista_objetos; obj < fim_lista; obj++){
        if(esta_segurando(player->local, obj) && obj != player && obj->vida > 0)
            return obj;
    }
    return NULL;
}


tObjetos *pega_passagem(tObjetos *origem, tObjetos *destino_f) { //verificar se certa passagem conecta dois dados locais; se houver, retorna um ponteiro para o objeto correpondente a ela.
    if(origem != NULL && destino_f != NULL){
        tObjetos *obj;
        for(obj = lista_objetos; obj < fim_lista; obj++){
            if(esta_segurando(destino_f, obj) && obj->aparente == destino_f){
                return obj;

            }
        }
    }
    return NULL;
}

tDistancia pega_distancia(tObjetos *origem, tObjetos *destino){
    return destino == NULL ? dist_objetoNaoReconhecido :
            destino == origem ? dist_SiProprio :
            destino->local == origem ? dist_Posse :
            destino == origem->local ? dist_Local :
            destino->local == origem->local ? dist_Aqui :
            pega_passagem(origem->local, destino) != NULL ? dist_AliDoLado :
            destino->local == NULL ? dist_NaoAqui :
            destino->local->local == origem ? dist_PosseContido :
            destino->local->local == origem->local ? dist_AquiContido :
                dist_NaoAqui;
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
    tObjetos *obj;

   for (obj = lista_objetos; obj < fim_lista; obj++) {
      if (obj != player && esta_segurando(local_atual, obj))
      {
         if (cont++ == 0)
         {
            printf("%s:\n", local_atual->conteudo);
         }
         printf("- %s\n", obj->descricao);
      }
   }
    return cont; // retorna o número de objetos no local
}
