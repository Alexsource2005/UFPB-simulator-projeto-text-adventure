#include <stdio.h>
#include "objetos.h"

tObjetos lista_objetos[] = {
    {"um prédio generico com vasta concentração de distúrbios mentais \nEstamos no Centro de Informática\n\n", "ao Centro de informatica", NULL, NULL},
    {"um prédio alto com sérios problemas estruturais. \nEstamos no Liepe. Uma nevóa densa cobre os corredores deste local... assustador\n\n", "ao Liepe", NULL, NULL},
    {"uma estrutura organizada feita de tijolos, com vários gatos ao redor. \nEstamos no CTDR. O único restaurante do campus se encontra aqui\n\n", "ao CTDR", NULL, NULL},
    {"uma lagoa de agua parada em uma clareira escondida nos matos.\n Voce sente uma vontade primitiva de jogar pedras lá dentro.\n\n", "ao poco da AIDS", NULL, NULL},
    {"um banheiro em que todas as privadas não tem assento.\n Pelo menos tem papel higienico...\n\n", "ao banheiro", NULL, NULL},
    {"um cano PVC solitário em meio as flores.\n", "pvc", CTDR, NULL},
    {"um jovem com uma sacola de cacarecos. Pode ser útil.\n", "jovem", AIDS, NULL},
    {"uma placa arduino UNO, parece estar em boas condições\n", "arduino", jovem, NULL},
    {"um notebook em cima de uma das mesas. não vão se importar se voce usar rapidamente, né?\n", "notebook", CI, NULL},
    {"você mesmo, apesar de tudo\n", "voce mesmo", CI, NULL},
    {"um caminho úmido de concreto\n", "ao caminho", CI, Liepe},
    {"saída passando por uma rampa para cadeirantes, seguido de um barranco de pedras desniveladas.\n Cômico.\n", "a saida", Liepe, CI},
    {"uma estrada reta até o CTDR. \nBelas flores coloridas adornam sua frente.\n", "a estrada", Liepe, CTDR},
    {"Uma estrada reta até o Liepe. \nSeu coração aquece ao ver uma joaninha pousar em uma das plantas.\n", "a saida", CTDR, Liepe},
    {"Descida que leva diretamente para dentro da mata \nVocê sente que tem algo lá.\n", "a descida", Liepe, AIDS},
    {"O caminho de volta até o liepe. \nVoce está com medo de ficar muito tempo aqui a sós.\n", "ao caminho", AIDS, Liepe},
    {"A porta que dá ao banheiro do primeiro andar.\n", " a porta", Liepe, banheiro},
    {"A porta que leva de volta ao primeiro andar do liepe.\n", "a porta", banheiro, Liepe}
};
