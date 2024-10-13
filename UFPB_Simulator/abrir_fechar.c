#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include "alcance.h"
#include "comparar.h"

bool exec_abrir(void) {
    tObjetos *obj = objeto_no_alcance("oque voce quer abrir", parametros[0]);

    if(obj != NULL)
        (*obj->abrir)();
    return true;
}

bool exec_fechar(void) {
    tObjetos *obj = objeto_no_alcance("oque voce quer fechar", parametros[0]);

    if(obj != NULL)
        (*obj->fechar)();
    return true;
}
