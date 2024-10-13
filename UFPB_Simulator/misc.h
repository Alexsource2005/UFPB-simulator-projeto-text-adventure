#include <stdbool.h>

typedef enum {
    dist_SiProprio,
    dist_Posse,
    dist_PosseContido,
    dist_Local,
    dist_Aqui,
    dist_AquiContido,
    dist_AliDoLado,
    dist_NaoAqui,
    dist_objetoNaoReconhecido

}tDistancia;

extern bool esta_segurando(tObjetos *container, tObjetos *obj);
extern tObjetos *pega_passagem(tObjetos *origem, tObjetos *destino);
extern tDistancia pega_distancia(tObjetos *origem, tObjetos *destino);
extern int lista_objetos_presentes(tObjetos *local_atual);
extern tObjetos *ator_aqui(void);
