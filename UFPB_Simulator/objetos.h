
typedef struct objeto {
    const char *descricao;
    const char **rotulos; // agora será uma lista de rótulos possiveis para cada objeto
    struct objeto *local; //ponteiro para o local onde o objeto se encontra
    struct objeto *destino; // exclusivo das passagens de local a local
    struct objeto *aparente; // exclusivo para passagens que levam a locais inesperados ou que serão bloqueados
    const char *detalhes; // detalhes que aparecerão ao examinar um objeto de perto
    const char *conteudo; // para objetos que irão conter outro objeto
    const char *texto_GO; //mensagem fofa única para cada local
    int peso; // peso de cada objeto
    int capacidade; // capacidade de carga de cada ator
    int vida; //não sei se será necessário, mas bora
    void (*abrir)(void);
    void (*fechar) (void);
} tObjetos;

extern tObjetos lista_objetos[];

#define CI	(lista_objetos + 0)
#define Liepe	(lista_objetos + 1)
#define CTDR	(lista_objetos + 2)
#define AIDS	(lista_objetos + 3)
#define banheiro	(lista_objetos + 4)
#define pvc	(lista_objetos + 5)
#define jovem	(lista_objetos + 6)
#define arduino	(lista_objetos + 7)
#define notebook	(lista_objetos + 8)
#define player	(lista_objetos + 9)
#define into_liepe	(lista_objetos + 10)
#define exit_liepe	(lista_objetos + 11)
#define into_ctdr	(lista_objetos + 12)
#define exit_ctdr	(lista_objetos + 13)
#define into_aids	(lista_objetos + 14)
#define exit_aids	(lista_objetos + 15)
#define porta_aberta_para_banheiro	(lista_objetos + 16)
#define porta_fechada_para_banheiro	(lista_objetos + 17)
#define porta_aberta_para_liepe	(lista_objetos + 18)
#define porta_fechada_para_liepe	(lista_objetos + 19)
#define block_ci	(lista_objetos + 20)
#define block_liepe	(lista_objetos + 21)
#define block_ctdr	(lista_objetos + 22)
#define block_aids	(lista_objetos + 23)
#define block_banheiro	(lista_objetos + 24)

#define fim_lista	(lista_objetos + 25)
