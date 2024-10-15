#include <stdio.h>
#include "objetos.h"
#include "toggle.h"
static const char *tags0[] = { "centro de informatica", "ci", "ao ci", "ao centro de informatica", NULL};
static const char *tags1[] = { "ao liepe", "liepe", NULL};
static const char *tags2[] = { "ao ctdr", "ctdr", NULL};
static const char *tags3[] = { "ao poco da aids", "poco da aids", NULL};
static const char *tags4[] = { "ao banheiro", "banheiro", NULL};
static const char *tags5[] = { "cano pvc", "pvc", "cano", "o cano pvc", "o cano", NULL};
static const char *tags6[] = { "jovem", "o jovem", "ao jovem", "com o jovem", "jovem magricela", "ao jovem magricela", "com o jovem magricela", NULL};
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
static const char *tags25[] = { "arduino", "arduino pronto", NULL};
static const char *tags26[] = { "chassi", "estrutura", NULL};
static const char *tags27[] = { "carro de combate", "carro", "veiculo", NULL};

tObjetos lista_objetos[] = {
	{	/* 0 = CI */
		 "um pr�dio generico com vasta concentra��o de dist�rbios mentais",
		tags0,
		NULL,
		NULL,
		NULL,
		 "Este � o centro de inform�tica. Todas as aulas com respeito a computa��o acontecem aqui.\n Voc� sente sono s� de imaginar.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 9999,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 1 = Liepe */
		 "um pr�dio de dois andares com s�rios problemas estruturais",
		tags1,
		NULL,
		NULL,
		NULL,
		 "Estamos no Liepe. Uma aura sinistra envolve esse lugar como n�voa em um jogo de terror... \nAssustador.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 9999,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 2 = CTDR */
		 "uma estrutura organizada feita de tijolos, com v�rios gatos ao redor",
		tags2,
		NULL,
		NULL,
		NULL,
		 "Estamos no CTDR, O �nico restaurante do campus se encontra aqui. \nBelas flores adornam os solos deste local, al�m de ventos constantes. Eles te enchem de serenidade.",
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
		 "Voc� encara a fossa aberta e sente uma vontade primitiva de jogar algo l� dentro.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 9999,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 4 = banheiro */
		 "um banheiro em que todas as privadas n�o tem assento",
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
		 "Um cano PVC solit�rio em meio �s flores. \nPode ser reutilizado para confeccionar estruturas r�gidas.",
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
		 "O jovem est� em completo sil�ncio encarando a fossa, hipnotizado. \nTalvez, ele esteja disposto a te dar algo �til.",
		 "Ele tem",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 20,
		 100,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 7 = arduino */
		 "uma placa arduino UNO em boas condi��es",
		tags7,
		 jovem,
		NULL,
		NULL,
		 "Esse arduino ser� perfeito para confeccionar a parte el�trica do seu r�bo.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		 1,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 8 = notebook */
		 "um notebook sem supervis�o",
		tags8,
		 CI,
		NULL,
		NULL,
		 "Nimgu�m est� por perto... N�o se importariam se voc� usar esse notebook rapidinho, n�?",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		 999,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 9 = player */
		 "voc� mesmo",
		tags9,
		 CI,
		NULL,
		NULL,
		 "Apesar de tudo oque ocorreu, continua sendo voc�.",
		 "voc� tem",
		"Voce nao pode se aproximar mais que isso.",
		99,
		 20,
		 100,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 10 = into_liepe */
		 "um caminho �mido de concreto ao nordeste",
		tags10,
		 CI,
		 Liepe,
		 Liepe,
		 "Um sol escaldante bate por cima desse caminho, ainda bem que voce lembrou do protetor solar.",
		". Voce ve",
		 "Voc� anda em dire��o do Liepe, com cuidado pra n�o trope�ar em alguma pedra solta.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 11 = exit_liepe */
		 "uma sa�da passando por uma rampa para cadeirantes, seguido de um barranco de pedras desniveladas ao sul",
		tags11,
		 Liepe,
		 CI,
		 CI,
		 "voc� acha c�mico a situa��o estrutural dessa rampa.",
		". Voce ve",
		 "Voc� toma o caminho de volta ao CI, curtindo a calma moment�nea.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 12 = into_ctdr */
		 "uma estrada reta at� o CTDR ao leste",
		tags12,
		 Liepe,
		 CTDR,
		 CTDR,
		 "Belas flores adornam esse caminho at� a entrada da estrutura, que lugar bonito.",
		". Voce ve",
		 "Voc� toma rumo ao CTDR, passando a m�o em toda vegeta��o no caminho com um sorriso no rosto.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 13 = exit_ctdr */
		 "uma estrada reta at� o Liepe ao oeste",
		tags13,
		 CTDR,
		 Liepe,
		 Liepe,
		 "Belas flores adornam esse caminho at� a entrada da estrutura, que lugar bonito.",
		". Voce ve",
		 "No meio da sua caminhada ao Liepe, uma joaninha pousa em uma das flores e aquece seu cora��o.",
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
		 "Voc� sente que tem algo por l�... Vale o risco.",
		". Voce ve",
		 "Voc�, com s� um pouco de receio, desce o barranco e segue mata adentro.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 15 = exit_aids */
		 "O caminho de volta at� o liepe ao nordeste",
		tags15,
		 AIDS,
		 Liepe,
		 Liepe,
		 "O caminho de volta � menos arriscado que o caminho de ida, isso com certeza.",
		". Voce ve",
		 "voc� sobe de volta ao Liepe, sem nenhum arranh�o.",
		99,
		0,
		0,
		 ja_esta_aberto,
		nao_pode_ser_fechado
	},
	{	/* 16 = porta_aberta_para_banheiro */
		 "a porta aberta que leva ao banheiro",
		tags16,
		NULL,
		 banheiro,
		 banheiro,
		 "A porta est� aberta",
		". Voce ve",
		 "Voc� passa pela porta.",
		99,
		0,
		0,
		 ja_esta_aberto,
		 troca_porta_banheiro
	},
	{	/* 17 = porta_fechada_para_banheiro */
		 "a porta fechada que leva ao banheiro",
		tags17,
		 Liepe,
		NULL,
		 banheiro,
		 "A porta est� fechada.",
		". Voce ve",
		 "A porta est� fechada.",
		99,
		0,
		0,
		 troca_porta_banheiro,
		 ja_esta_fechado
	},
	{	/* 18 = porta_aberta_para_liepe */
		 "a porta aberta que leva ao Liepe",
		tags18,
		NULL,
		 Liepe,
		 Liepe,
		 "A porta est� aberta.",
		". Voce ve",
		 "voc� retorna ao Liepe.",
		99,
		0,
		0,
		 ja_esta_aberto,
		 troca_porta_liepe
	},
	{	/* 19 = porta_fechada_para_liepe */
		 "a porta fechada que leva ao Liepe",
		tags19,
		 banheiro,
		NULL,
		 Liepe,
		 "A porta est� fechada.",
		". Voce ve",
		 "A porta est� fechada.",
		99,
		0,
		0,
		 troca_porta_liepe,
		 ja_esta_fechado
	},
	{	/* 20 = block_ci */
		 "N�o tem nada para ver por aqui",
		tags20,
		 CI,
		NULL,
		NULL,
		 "Al�m daqui s� a rua que leva � rua principal e � entrada do submundo, al�m do local de equita��o. \nNada de seu interesse.",
		". Voce ve",
		 "Voc� n�o tem motivo pra vir por aqui.",
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
		 "As paredes de concreto s�o bem r�gidas",
		". Voce ve",
		 "As paredes te impedem de seguir por aqui.",
		99,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 22 = block_ctdr */
		 "Nada de interesse al�m daqui",
		tags22,
		 CTDR,
		NULL,
		NULL,
		 "Mata densa cobre os limites do CTDR.",
		". Voce ve",
		 "A mata n�o te permite passar por aqui.",
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
		 "Mata densa est� por todos os seus arredores.",
		". Voce ve",
		 "Voc� n�o quer ir por a�... Voc� ainda tem amor a pr�pria vida.",
		99,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 24 = block_banheiro */
		 "Nada al�m disso",
		tags24,
		 banheiro,
		NULL,
		NULL,
		 "� s� um banheiro, n�o tem nada al�m disso.",
		". Voce ve",
		 "Voc� d� de cara com a parede. Deixa de ser besta.",
		99,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 25 = arduino_pronto */
		 "Um arduino UNO pronto pra ser usado",
		tags25,
		 NULL,
		NULL,
		NULL,
		 "Este arduino est� pronto pra ser usado em meu projeto.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		 1,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 26 = chassi */
		 "um chassi robusto",
		tags26,
		 NULL,
		NULL,
		NULL,
		 "Um chassi bem constru�do, pronto para ser a base de um carro de combate.",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		 2,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	},
	{	/* 27 = carro_de_combate */
		 "um carro de combate impressionante",
		tags27,
		 NULL,
		NULL,
		NULL,
		 "Um carro de combate completo, combinando um chassi robusto com um arduino programado. � uma obra-prima da engenharia improvisada!",
		". Voce ve",
		"Voce nao pode se aproximar mais que isso.",
		 3,
		0,
		0,
		nao_pode_ser_aberto,
		nao_pode_ser_fechado
	}
};
