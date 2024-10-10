typedef struct objeto {
    const char *descricao;
    const char **rotulo; // agora será uma lista de rótulos possiveis para cada objeto
    struct objeto *local; //ponteiro para o local onde o objeto se encontra
    struct objeto *destino; // exclusivo das passagens de local a local
} tObjetos;

extern tObjetos lista_objetos[];

#define CI (lista_objetos + 0)
#define Liepe (lista_objetos + 1)
#define CTDR (lista_objetos + 2)
#define AIDS (lista_objetos + 3)
#define banheiro (lista_objetos + 4)
#define pvc (lista_objetos + 5)
#define jovem (lista_objetos + 6)
#define arduino (lista_objetos + 7)
#define notebook (lista_objetos + 8)
#define player (lista_objetos + 9)

// passagens
#define into_liepe (lista_objetos + 10)
#define exit_liepe (lista_objetos + 11)
#define into_ctdr (lista_objetos + 12)
#define exit_ctdr (lista_objetos + 13)
#define into_aids (lista_objetos + 14)
#define exit_aids (lista_objetos + 15)
#define into_banheiro (lista_objetos + 16)
#define exit_banheiro (lista_objetos + 17)

// "paredes" que impedem o jogador de continuar além do esperado
#define block_ci (lista_objetos + 18)
#define block_liepe (lista_objetos + 19)
#define block_ctdr (lista_objetos + 20)
#define block_aids (lista_objetos + 21)
#define block_banheiro (lista_objetos + 22)

#define fim_lista (lista_objetos + 23) // aumentar o número conforme coloca mais objetos
