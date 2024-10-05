typedef struct objeto {
    const char *descricao;
    const char *rotulo;
    struct objeto *local; //ponteiro para o local onde o objeto se encontra
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

#define fim_lista (lista_objetos + 10) // aumentar o número conforme coloca mais objetos
