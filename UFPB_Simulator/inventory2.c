#include <stdbool.h>
#include <stdio.h>
#include "objetos.h"
#include "comparar.h"
#include "movimento.h"
#include "alcance.h"
#include "substantivo.h"

bool exec_darPARA(void)
{
    tObjetos *obj = pega_possesao(player, "dar", parametros[0]);

    if(obj != NULL)
    {
        tObjetos *destino = objeto_no_alcance("para quem dar isto", parametros[1]);
        if(destino != NULL)
        {
            if(destino->vida > 0)
            {
                mover_objeto(obj, destino);
            }
            else
            {
                printf("Voc� n�o pode dar um item para um objeto inanimado.\n");
            }
        }

    }
    return true;

}

bool exec_pegarDE(void)
{
    tObjetos *origem = objeto_no_alcance("de onde voc� quer pegar isso", parametros[1]);

    if(origem != NULL && visivel_existe("oque voc� quer pegar", parametros[0]) != NULL)
    {
        if(origem->vida > 0)
        {
            printf("Voc� deveria pedir ao %s antes de pegar algo que n�o lhe pertence.\n", origem->descricao);

        }
        else
        {
            mover_objeto(pega_possesao(origem, "pegar", parametros[0]), player);
        }
    }
    return true;
}

bool exec_jogarNO(void)
{
    tObjetos *obj = pega_possesao(player, "jogar", parametros[0]);

    if(obj != NULL)
    {
        tObjetos *destino = objeto_no_alcance("onde voc� quer jogar isso", parametros[1]);
        if(destino != NULL)
        {
            if(destino->vida > 0)
            {
                printf("Voc� n�o pode agredir uma pessoa inocente. � crime.\n");

            }
            else
            {
                mover_objeto(obj, destino);
            }

        }
    }
    return true;
}

bool exec_pedirPARA(void)
{
    tObjetos *pessoa_origem = objeto_no_alcance("para quem pedir por isso.", parametros[1]);
    if(pessoa_origem != NULL)
    {
        if(pessoa_origem->vida > 0)
        {
            if(visivel_existe("oque voc� quer pedir para esta pessoa.", parametros[0]) != NULL)
            {
                mover_objeto(pega_possesao(pessoa_origem, "pedir", parametros[0]), player);
            }
        }
        else
        {
            printf("Objetos inanimados n�o falam. Voc� tomou seus rem�dios hoje.\n");
        }
    }
    return true;
}

bool exec_colocarEM(void)
{
        tObjetos *obj = pega_possesao(player, "colocar", parametros[0]);
        if(obj != NULL)
        {
            tObjetos *destino = objeto_no_alcance("onde voce quer colocar isso.", parametros[1]);
            if(destino != NULL)
            {
                if(destino->vida > 0)
                {
                    printf("Voc� deveria oferecer isso para %s educadamente.", destino->descricao);
                }
                else
                {
                    mover_objeto(obj, destino);
                }
            }

        }
}

bool exec_programar_arduino(void) {
    tObjetos *arduino_obj = visivel_existe("O que voc� quer programar", "arduino");
    tObjetos *notebook_obj = visivel_existe("Com o que voc� quer programar", "notebook");

    if (arduino_obj == NULL || notebook_obj == NULL) {
        printf("Voc� n�o tem o arduino ou o notebook para programar.\n");
        return true;
    }

    if (arduino_obj->local != player || player->local != CI) {
        printf("Voc� precisa ter o arduino e o notebook em m�os para programar.\n");
        return true;
    }

    printf("Voc� come�a a programar o arduino com o notebook...\n");
    printf("Depois de alguns minutos, voc� termina de programar o arduino.\n");
    printf("Voc� recebe um arduino pronto para ser usado.\n");

    // Remover o arduino antigo
    arduino_obj->local = NULL;

    // Adicionar o arduino pronto ao jogador
    arduino_pronto->local = player;

    return true;
}

bool exec_construir_chassi(void) {
    tObjetos *cano_obj = visivel_existe("O que voc� quer usar para construir", "cano");

    if (cano_obj == NULL || cano_obj->local != player) {
        printf("Voc� precisa ter o cano em m�os para construir o chassi.\n");
        return true;
    }

    printf("Voc� usa o cano para construir um chassi robusto...\n");
    printf("Ap�s algum tempo de trabalho, voc� termina de construir o chassi!\n");

    // Remover o cano
    cano_obj->local = NULL;

    // Adicionar o chassi ao jogador
    chassi->local = player;

    return true;
}

bool exec_construir_carro_combate(void) {
    tObjetos *chassi_obj = visivel_existe("O que voc� quer usar para construir", "chassi");
    tObjetos *arduino_pronto_obj = visivel_existe("O que mais voc� quer usar", "arduino pronto");

    if (chassi_obj == NULL || chassi_obj->local != player ||
        arduino_pronto_obj == NULL || arduino_pronto_obj->local != player) {
        printf("Voc� precisa ter o chassi e o arduino pronto em m�os para construir o carro de combate.\n");
        return true;
    }

    printf("Voc� combina o chassi com o arduino pronto...\n");
    printf("Ap�s um trabalho meticuloso, voc� finaliza a constru��o do carro de combate!\n");

    // Remover o chassi e o arduino pronto
    chassi_obj->local = NULL;
    arduino_pronto_obj->local = NULL;

    // Adicionar o carro de combate ao jogador
    carro_de_combate->local = player;

    // Condi��o de vit�ria
    printf("Parab�ns! Voc� construiu o carro de combate e venceu o jogo!\n");
    return false;  // Retorna false para encerrar o jogo
}
