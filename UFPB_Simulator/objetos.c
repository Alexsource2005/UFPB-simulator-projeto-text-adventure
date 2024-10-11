#include <stdio.h>
#include "objetos.h"
#include "toggle.h"
static const char *tags0[] = { "centro de informatica", "ci", "ao ci", "ao centro de informatica", NULL};
static const char *tags1[] = { "ao liepe", "liepe", NULL};
static const char *tags2[] = { "ao ctdr", "ctdr", NULL};
static const char *tags3[] = { "ao poco da aids", "poco da aids", NULL};
static const char *tags4[] = { "ao banheiro", "banheiro", NULL};
static const char *tags5[] = { "cano pvc", "pvc", "cano", "o cano pvc", "o cano", NULL};
static const char *tags6[] = { "jovem", "ao jovem", "com o jovem", "jovem magricela", "ao jovem magricela", "com o jovem magricela", NULL};
static const char *tags7[] = { "arduino", "o arduino", NULL};
static const char *tags8[] = { "notebook", "o notebook", NULL};
static const char *tags9[] = { "voce", "voce mesmo", "si", "si proprio", NULL};
static const char *tags10[] = { "caminho", "ao caminho", "nordeste", "caminho umido", "ao caminho umido", "norte", "leste", NULL};
static const char *tags11[] = { "saida", "a saida", "sul", NULL};
static const char *tags12[] = { "estrada", "a estrada", "leste", NULL};
static const char *tags13[] = { "estrada", "a estrada", "leste", NULL};
static const char *tags14[] = { "descida", "a descida", "sudoeste", "sul", "leste", NULL};
static const char *tags15[] = { "caminho", "o caminho", "nordeste", "norte", "leste", NULL};
static const char *tags16[] = { "porta", "a porta", NULL};
static const char *tags17[] = { "porta", "a porta", NULL};
static const char *tags18[] = { "porta", "a porta", NULL};
static const char *tags19[] = { "porta", "a porta", NULL};
static const char *tags20[] = { "sul", "sudoeste", "sudeste", "oeste", "noroeste", "pra fora", NULL};
static const char *tags21[] = { "norte", "nordeste", "noroeste", NULL};
static const char *tags22[] = { "leste", "norte", "sul", "nordeste", "noroeste", "sudoeste", "sudeste", NULL};
static const char *tags23[] = { "oeste", "sul", "sudeste","sudoeste", "mato", "mata", "alem", NULL};
static const char *tags24[] = { "norte", "sul", "leste", "oeste", "nordeste", "noroeste", "sudeste", "sudoeste", NULL};

tObjetos lista_objetos[] = {
	{	/* 0 = CI */
		 "um prédio generico com vasta concentração de distúrbios mentais",
		tags0,
		NULL,
		NULL,
		NULL,
		 "Este é o centro de informática. Todas as aulas com respeito a computação acontecem aqui.\n Você sente sono só de imaginar.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 9999,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 1 = Liepe */
		 "um prédio de dois andares com sérios problemas estruturais",
		tags1,
		NULL,
		NULL,
		NULL,
		 "Estamos no Liepe. Uma aura sinistra envolve esse lugar como névoa em um jogo de terror... \nAssustador.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 9999,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 2 = CTDR */
		 "uma estrutura organizada feita de tijolos, com vários gatos ao redor",
		tags2,
		NULL,
		NULL,
		NULL,
		 "Estamos no CTDR, O único restaurante do campus se encontra aqui. \nBelas flores adornam os solos deste local, além de ventos constantes. Eles te enchem de serenidade.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 9999,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 3 = AIDS */
		 "uma lagoa de agua parada em uma clareira escondida nos matos",
		tags3,
		NULL,
		NULL,
		NULL,
		 "Você encara a fossa aberta e sente uma vontade primitiva de jogar algo lá dentro.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 9999,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 4 = banheiro */
		 "um banheiro em que todas as privadas não tem assento",
		tags4,
		NULL,
		NULL,
		NULL,
		 "A privacidade repentina estranhamente te acalma. \nPelo menos tem papel higienico.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 9999,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 5 = pvc */
		 "um cano PVC",
		tags5,
		 CTDR,
		NULL,
		NULL,
		 "Um cano PVC solitário em meio às flores. \nPode ser reutilizado para confeccionar estruturas rígidas.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		 1,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 6 = jovem */
		 "um jovem magricela com uma sacola de cacarecos",
		tags6,
		 AIDS,
		NULL,
		NULL,
		 "O jovem está em completo silêncio encarando a fossa, hipnotizado. \nTalvez, ele esteja disposto a te dar algo útil.",
		 "Ele tem",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 20,
		 100,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 7 = arduino */
		 "uma placa arduino UNO em boas condições",
		tags7,
		 jovem,
		NULL,
		NULL,
		 "Esse arduino será perfeito para confeccionar a parte elétrica do seu rôbo.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		 1,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 8 = notebook */
		 "um notebook sem supervisão",
		tags8,
		 CI,
		NULL,
		NULL,
		 "Nimguém está por perto... Não se importariam se você usar esse notebook rapidinho, né?",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		 999,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 9 = player */
		 "você mesmo",
		tags9,
		 CI,
		NULL,
		NULL,
		 "Apesar de tudo oque ocorreu, continua sendo você.",
		 "você tem",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 20,
		 100,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 10 = into_liepe */
		 "um caminho úmido de concreto ao nordeste",
		tags10,
		 CI,
		 Liepe,
		 Liepe,
		 "Um sol escaldante bate por cima desse caminho, ainda bem que voce lembrou do protetor solar.",
		". Voce ve",
		 "Você anda em direção do Liepe, com cuidado pra não tropeçar em alguma pedra solta.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 11 = exit_liepe */
		 "uma saída passando por uma rampa para cadeirantes, seguido de um barranco de pedras desniveladas ao sul",
		tags11,
		 Liepe,
		 CI,
		 CI,
		 "você acha cômico a situação estrutural dessa rampa.",
		". Voce ve",
		 "Você toma o caminho de volta ao CI, curtindo a calma momentânea.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 12 = into_ctdr */
		 "uma estrada reta até o CTDR ao leste",
		tags12,
		 Liepe,
		 CTDR,
		 CTDR,
		 "Belas flores adornam esse caminho até a entrada da estrutura, que lugar bonito.",
		". Voce ve",
		 "Você toma rumo ao CTDR, passando a mão em toda vegetação no caminho com um sorriso no rosto.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 13 = exit_ctdr */
		 "uma estrada reta até o Liepe ao oeste",
		tags13,
		 CTDR,
		 Liepe,
		 Liepe,
		 "Belas flores adornam esse caminho até a entrada da estrutura, que lugar bonito.",
		". Voce ve",
		 "No meio da sua caminhada ao Liepe, uma joaninha pousa em uma das flores e aquece seu coração.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 14 = into_aids */
		 "uma descida que leva diretamente para dentro da mata, ao sudoeste",
		tags14,
		 Liepe,
		 AIDS,
		 AIDS,
		 "Você sente que tem algo por lá... Vale o risco.",
		". Voce ve",
		 "Você, com só um pouco de receio, desce o barranco e segue mata adentro.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 15 = exit_aids */
		 "O caminho de volta até o liepe ao nordeste",
		tags15,
		 AIDS,
		 Liepe,
		 Liepe,
		 "O caminho de volta é menos arriscado que o caminho de ida, isso com certeza.",
		". Voce ve",
		 "você sobe de volta ao Liepe, sem nenhum arranhão.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 16 = porta_aberta_para_banheiro */
		 "A porta aberta que leva ao banheiro",
		tags16,
		NULL,
		 banheiro,
		 banheiro,
		 "A porta está aberta",
		". Voce ve",
		 "Você passa pela porta.",
		99,
		0,
		0,
		 ja_esta_aberto,
		 troca_porta_banheiro
	},
	{	/* 17 = porta_fechada_para_banheiro */
		 "A porta fechada que leva ao banheiro",
		tags17,
		 Liepe,
		NULL,
		 banheiro,
		 "A porta está fechada.",
		". Voce ve",
		 "A porta está fechada.",
		99,
		0,
		0,
		 troca_porta_banheiro,
		 ja_esta_fechado
	},
	{	/* 18 = porta_aberta_para_liepe */
		 "A porta aberta que leva ao Liepe",
		tags18,
		NULL,
		 Liepe,
		 Liepe,
		 "A porta está aberta.",
		". Voce ve",
		 "você retorna ao Liepe.",
		99,
		0,
		0,
		 ja_esta_aberto,
		 troca_porta_liepe
	},
	{	/* 19 = porta_fechada_para_liepe */
		 "A porta fechada que leva ao Liepe",
		tags19,
		 banheiro,
		NULL,
		 Liepe,
		 "A porta está fechada.",
		". Voce ve",
		 "A porta está fechada.",
		99,
		0,
		0,
		 troca_porta_liepe,
		 ja_esta_fechado
	},
	{	/* 20 = block_ci */
		 "Não tem nada para ver por aqui",
		tags20,
		 CI,
		NULL,
		NULL,
		 "Além daqui só a rua que leva à rua principal e à entrada do submundo, além do local de equitação. \nNada de seu interesse.",
		". Voce ve",
		 "Você não tem motivo pra vir por aqui.",
		99,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 21 = block_liepe */
		 "Apenas paredes de concreto",
		tags21,
		 Liepe,
		NULL,
		NULL,
		 "As paredes de concreto são bem rígidas",
		". Voce ve",
		 "As paredes te impedem de seguir por aqui.",
		99,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 22 = block_ctdr */
		 "Nada de interesse além daqui",
		tags22,
		 CTDR,
		NULL,
		NULL,
		 "Mata densa cobre os limites do CTDR.",
		". Voce ve",
		 "A mata não te permite passar por aqui.",
		99,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 23 = block_aids */
		 "Mata densa por todo lugar",
		tags23,
		 AIDS,
		NULL,
		NULL,
		 "Mata densa está por todos os seus arredores.",
		". Voce ve",
		 "Você não quer ir por aí... Você ainda tem amor a própria vida.",
		99,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 24 = block_banheiro */
		 "Nada além disso",
		tags24,
		 banheiro,
		NULL,
		NULL,
		 "É só um banheiro, não tem nada além disso.",
		". Voce ve",
		 "Você dá de cara com a parede. Deixa de ser besta.",
		99,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	}
};
