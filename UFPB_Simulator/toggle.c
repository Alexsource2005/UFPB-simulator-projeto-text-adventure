#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"

static void troca_locais(const char *verbo1, tObjetos *obj1, const char *verbo2, tObjetos *obj2)
{
    tObjetos *tmp = obj1->local;
    tObjetos *obj = tmp != NULL ? obj1 : obj2;
    const char *verbo = tmp != NULL ? verbo1 : verbo2;
    obj1->local = obj2->local;
    obj2->local = tmp;

    if(verbo != NULL)
        printf("Você %s %s.\n", verbo, obj->descricao);
}

void nao_pode_ser_aberto(void)    { printf("Isso não pode ser aberto.\n");    }
void nao_pode_ser_fechado(void)    { printf("Isso não pode ser fechado.\n");    }

void ja_esta_aberto(void)     { printf("Isso já está aberto.\n");     }
void ja_esta_fechado(void)   { printf("Isso já está fechado.\n");   }

void ainda_esta_aberto(void)       { printf("That is still open.\n");       }

void troca_porta_banheiro(void){
    troca_locais(NULL,porta_aberta_para_liepe, NULL, porta_fechada_para_liepe);
    troca_locais("fecha", porta_aberta_para_banheiro, "abre", porta_fechada_para_banheiro);
}

void troca_porta_liepe(void){
    troca_locais(NULL,porta_aberta_para_banheiro, NULL, porta_fechada_para_banheiro);
    troca_locais("fechar", porta_aberta_para_liepe, "abrir", porta_fechada_para_liepe);
}
