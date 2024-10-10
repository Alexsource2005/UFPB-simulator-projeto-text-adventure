#include <stdio.h>
#include "objetos.h"

static char const *tags0[] = {"centro de informatica", "ci", "ao ci", "ao centro de informatica", NULL};
static char const *tags1[] = {"ao liepe", "liepe", NULL};
static char const *tags2[] = {"ao ctdr", "ctdr", NULL};
static char const *tags3[] = {"ao poco da aids", "poco da aids", NULL};
static char const *tags4[] = {"ao banheiro", "banheiro", NULL};
static char const *tags5[] = {"cano pvc", "pvc", "cano", "o cano pvc", "o cano", NULL};
static char const *tags6[] = {"jovem", "ao jovem", "com o jovem", "jovem magricela", "ao jovem magricela", "com o jovem magricela", NULL};
static char const *tags7[] = {"arduino", "o arduino", NULL};
static char const *tags8[] = {"notebook", "o notebook", NULL};
static char const *tags9[] = {"voce", "voce mesmo", "si", "si proprio", NULL};
static char const *tags10[] = {"caminho", "ao caminho", "nordeste", "caminho umido", "ao caminho umido", "norte", "leste", NULL};
static char const *tags11[] = {"saida", "a saida", "sul", NULL};
static char const *tags12[] = {"estrada", "a estrada", "leste", NULL};
static char const *tags13[] = {"estrada", "a estrada", "oeste", NULL};
static char const *tags14[] = {"descida", "a descida", "sudoeste", "sul", "leste", NULL};
static char const *tags15[] = {"caminho", "o caminho", "nordeste", "norte", "leste", NULL};
static char const *tags16[] = {"porta", "a porta", NULL};
static char const *tags17[] = {"porta", "a porta", NULL};
static char const *tags18[] = {"sul", "sudoeste", "sudeste", "oeste", "noroeste", "pra fora", NULL};
static char const *tags19[] = {"norte", "nordeste", "noroeste", NULL};
static char const *tags20[] = {"leste", "norte", "sul", "nordeste", "noroeste", "sudoeste", "sudeste", NULL};
static char const *tags21[] = {"oeste", "sul", "sudeste","sudoeste", "mato", "mata", "alem", NULL};
static char const *tags22[] = {"norte", "sul", "leste", "oeste", "nordeste", "noroeste", "sudeste", "sudoeste", NULL};

tObjetos lista_objetos[] = {
    {"um prédio generico com vasta concentração de distúrbios mentais.\n", tags0, NULL, NULL},
    {"um prédio alto com sérios problemas estruturais.\n", tags1, NULL, NULL},
    {"uma estrutura organizada feita de tijolos, com vários gatos ao redor.\n", tags2, NULL, NULL},
    {"uma lagoa de agua parada em uma clareira escondida nos matos.\n", tags3, NULL, NULL},
    {"um banheiro em que todas as privadas não tem assento.\n", tags4, NULL, NULL},
    {"um cano PVC solitário em meio as flores.\n", tags5, CTDR, NULL},
    {"um jovem magricela com uma sacola de cacarecos.\n", tags6, AIDS, NULL},
    {"uma placa arduino UNO em boas condições\n", tags7, jovem, NULL},
    {"um notebook em cima de uma das mesas.\n", tags8, CI, NULL},
    {"você mesmo, apesar de tudo\n", tags9, CI, NULL},
    {"um caminho úmido de concreto ao nordeste\n", tags10, CI, Liepe},
    {"uma saída passando por uma rampa para cadeirantes, seguido de um barranco de pedras desniveladas ao sul.\n", tags11, Liepe, CI},
    {"uma estrada reta até o CTDR ao leste.\n", tags12, Liepe, CTDR},
    {"uma estrada reta até o Liepe ao oeste.\n", tags13, CTDR, Liepe},
    {"uma descida que leva diretamente para dentro da mata, ao sudoeste.\n", tags14, Liepe, AIDS},
    {"O caminho de volta até o liepe ao nordeste.\n", tags15, AIDS, Liepe},
    {"A porta que dá ao banheiro do primeiro andar.\n", tags16, Liepe, banheiro},
    {"A porta que leva de volta ao primeiro andar do liepe.\n", tags17, banheiro, Liepe},
    {"Não tem nada além disso.\n", tags18, CI, NULL},
    {"Apenas paredes de concreto.\n", tags19, Liepe, NULL},
    {"Nada de interesse além disso.\n", tags20, CTDR, NULL},
    {"Mata densa por todo lugar.\n", tags21, AIDS, NULL},
    {"Nada além disso.\n", tags22, banheiro, NULL}
};
