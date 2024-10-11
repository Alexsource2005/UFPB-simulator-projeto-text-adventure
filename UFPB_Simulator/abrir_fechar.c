#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include "alcance.h"

void exec_abrir(const char *substantivo) {
    tObjetos *obj = objeto_no_alcance("oque voce quer abrir", substantivo);

    if(obj != NULL)
        (*obj->abrir)();
}

void exec_fechar(const char *substantivo) {
    tObjetos *obj = objeto_no_alcance("oque voce quer fechar", substantivo);

    if(obj != NULL)
        (*obj->fechar)();
}
